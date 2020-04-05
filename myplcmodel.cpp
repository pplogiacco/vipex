#include "myplcmodel.h"

MyPlcItem::MyPlcItem(itemtype_t it, MyPlcItem *parent) // const QStringList columheaders)  // Root constructor
    : m_parent(parent),
      m_type(it)
{
 //
};


MyPlcItem::MyPlcItem(module_t mtype, word_t maddr, word_t opt1,word_t opt2, bool ena, MyPlcItem *parent)
    : m_parent(parent),
      m_type(itemtype_t::MODULE)
{


    //        m_data.resize(ITEM_NCOLUMNS);
            m_data[I_ID].setValue(0);
            m_data[I_TYPE].setValue(m_type);
            m_data[I_ENAB].setValue(ena);
             //
            m_data[IE_IDX].setValue(0);
            m_data[IE_TYPE].setValue(mtype);
            m_data[IE_ADDR].setValue(maddr);   // maddr
            m_data[IE_MOPT1].setValue(opt1);  // option
            m_data[IE_MOPT2].setValue(opt2);  // option

    switch ( mtype ) {
       case _NBV30:
            m_data[I_ALIAS].setValue("Nanoboard v3.0 (USB)");  // Later
            m_data[IE_NPORT].setValue(8);  // n ports
           break;
       case _SEM16:
            m_data[I_ALIAS].setValue(QString("Sem16 - IO Expander (%1)").arg(maddr));  // Later
            m_data[IE_NPORT].setValue(16);  // n ports
           break;
       case _LCNIF:

            m_data[I_ALIAS].setValue(QString("Loconet-IF %2 (%1)").arg(maddr).arg(opt1?"CTRL":"DECO"));  // Later
            m_data[IE_NPORT].setValue(8);  // n ports

           break;
    }  // end-switch
}



MyPlcItem::MyPlcItem(const vs_module_t &module, MyPlcItem *parent)
    : m_parent(parent),
      m_type(itemtype_t::MODULE)
{
    size_t size = sizeof(vs_module_t);
    m_rawdata = (char*)malloc(size);
    memcpy(m_rawdata, &module, size);

    switch ((module_t)module.mtype)
    {
         case _NBV30:
             //m_data = new MyPlcNBV30;
             //m_data->enabled(true);
             //m_data->id(module.idx);
            break;

        case _SEM16:
             //m_data = new MyPlcSEM16;
             //m_data->enabled(true);
             //m_data->id(module.idx);
             //m_data->maddr(module->addr);
            break;

        case _LCNIF:
             //m_data = new MyPlcSEM16;
             //m_data->alias("Loconet-IF");
            break;
    }

}



MyPlcItem::MyPlcItem(const vs_port_t &port, MyPlcItem *parent)
    : m_parent(parent),
      m_type(PORT)

{
    /*
    m_data.append(port->enabled);
    m_data.append(QString(port->palias));
    m_data.append(port->idx);
    m_data.append(port->ptype);
    m_data.append((saddr_t)port->subaddr);
    m_data.append((flag_t)port->io);
    m_data.append((flag_t)port->defval);
    //setIcon(0,(port->enabled)?QIcon(":/images/enabled.png"):QIcon(":/images/disabled.png"));
    */
}



MyPlcItem::MyPlcItem(const vs_rule_t &rule, MyPlcItem *parent)
    : m_type(RULE),
      m_parent(parent)
{

}




MyPlcItem *MyPlcItem::child(int number)
 {
     if (number < 0 || number >= m_childs.size())
         return nullptr;
     return m_childs.at(number);
 }

void MyPlcItem::appendChild(MyPlcItem *item)
{
    m_childs.append(item);
}


int MyPlcItem::childCount() const
  {
      return m_childs.count();
  }


void MyPlcItem::deleteAllChild()
{
  qDeleteAll(m_childs);
}


int MyPlcItem::childNumber() const
{
      if (m_parent)
          return m_parent->m_childs.indexOf(const_cast<MyPlcItem*>(this));
      return 0;
}


int MyPlcItem::columnCount() const
 {
     return m_data.count();
 }


QVariant MyPlcItem::data(int nfield) const
 {
     if (nfield < 0 || nfield >= m_data.size())
         return QVariant();
     return m_data.at(nfield);
 }


bool MyPlcItem::setData(int nfield, const QVariant &value)
  {
      if (nfield < 0 || nfield >= m_data.size())
          return false;

      m_data[nfield] = value; // static_cast<QVariant>(
      return true;
  }








/*********************************************************************************************
 *  M O D E L
*********************************************************************************************/



MyPlcModel::MyPlcModel(QObject *parent)
    : QAbstractItemModel(parent)
{

    QVector<QVariant> rootData;
    rootData.append(QString("Modulo/Porta"));
    rootData.append(QString("[No header]"));
    rootData.append(QString("[No header]"));

    m_root = new MyPlcItem();

    //emit headerDataChanged(Qt::Horizontal, 0, 2);
    //model->setHeaderData(column, Qt::Horizontal, QVariant("[No header]"), Qt::EditRole);
    buildItems();

}



MyPlcModel::~MyPlcModel()
{
    delete m_root;
}


QVariant MyPlcModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    MyPlcItem *item = getItem(index);
    return item->data(index.column());

}

bool MyPlcModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return false;

    MyPlcItem *item = getItem(index);
    bool result = item->setData(index.column(), value);

    if (result)
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

    return result;
}


QVariant MyPlcModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return m_root->data(section);

    return QVariant();
}

bool MyPlcModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (role != Qt::EditRole || orientation != Qt::Horizontal)
        return false;

    const bool result = m_root->setData(section, value);

    if (result)
        emit headerDataChanged(orientation, section, section);

    return result;
}



int MyPlcModel::rowCount(const QModelIndex &parent) const
{
    const MyPlcItem *parentItem = getItem(parent);

    return parentItem ? parentItem->childCount() : 0;
}

int MyPlcModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_root->columnCount();
}


Qt::ItemFlags MyPlcModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}


QModelIndex MyPlcModel::index(int row, int column, const QModelIndex &parent) const
{
     if (parent.isValid() && parent.column() != 0)
         return QModelIndex();

     MyPlcItem *parentItem = getItem(parent);
     if (!parentItem)
         return QModelIndex();

     MyPlcItem *childItem = parentItem->child(row);

     if (childItem)
         return createIndex(row, column, childItem);

     return QModelIndex();
}



QModelIndex MyPlcModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    MyPlcItem *childItem = getItem(index);

    MyPlcItem *parentItem = childItem ? childItem->parent() : nullptr;

    if (parentItem == m_root || !parentItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);   // childNumber() -- row()
}




MyPlcItem *MyPlcModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
        MyPlcItem *item = static_cast<MyPlcItem*>(index.internalPointer());
        if (item)
            return item;
    }
    return m_root;
}




// ---------------------------------------------------------------------------------------
// Implements MyPlc specific
// ---------------------------------------------------------------------------------------




void MyPlcModel::buildItems()
{
 // *********** Bind myplc on items ??????

}



void MyPlcModel::setDeviceInfo(const vs_info_t &info)
{

}

void MyPlcModel::getDeviceInfo(vs_info_t *info)
{

}





bool MyPlcModel::setModule(const vs_module_t &module)
{
   bool addmodule = true;
   int i = 0;
   if ( ! m_root->childCount() )
   {
    while( i<m_root->childCount() && !( m_root->child(i)->data(I_TYPE) == module.mtype && m_root->child(i)->data(IE_ADDR) == module.maddr )) {i++;}
    if ((m_root->data(I_TYPE) == module.mtype && m_root->data(IE_ADDR) == module.maddr ) ) addmodule = false;
   }
  if (addmodule) // Add module
  {
     MyPlcItem *newmodule = new MyPlcItem(module,m_root);
     m_root->appendChild(newmodule);
  }
  else  // update fields
  {
  //  m_root->child(i)->setData(IM_IDX) = module.idx;
  }
  return(true);
}

bool MyPlcModel::setPort(vs_port_t &port)
{
      return(true);
}


//int nRules();
bool MyPlcModel::setRule(vs_rule_t &rule )
{
      return(true);
}
//vs_rule_t getRule(idx_t iport);


//bool rebuildIdx();























/* Use delegate



bool Item::insertChildren(int position, int count, int column)
 {
     if (position < 0 || position > m_childs.size())
         return false;

     for (int row = 0; row < count; ++row) {
         QVector<QVariant> data(column);
         Item *item = new Item(data, this);
         m_childs.insert(position, item);
     }

     return true;
 }


bool Item::removeChildren(int position, int count)
  {
      if (position < 0 || position + count > m_childs.size())
          return false;

      for (int row = 0; row < count; ++row)
          delete m_childs.takeAt(position);

      return true;
  }
*/




int MyPlcItem::row() const
{
    if (m_parent)
        return m_parent->m_childs.indexOf(const_cast<MyPlcItem*>(this));
    return 0;
}




bool MyPlcModel::loadData(QDataStream *in)
{
    //QDataStream stream(device);
    int rowCount, columnCount;
    /*stream >> rowCount;
    stream >> columnCount;

    for(int row = 0; row < rowCount; row++)
        for(int column = 0; column < columnCount; column++) {
            QString item;
            stream >> item;
          //  model->setItem(row, column, item);
        }  */
    return (true);
}

bool MyPlcModel::saveData(QDataStream *out)
{
   // QDataStream stream(device);
 /*   int rowCount =   rowCount(); // model->rowCount();
    int columnCount = model->columnCount();
    stream << rowCount;
    stream << columnCount;

    for(int row = 0; row < rowCount; row++)
        for(int column = 0; column < columnCount; column++) {
            stream << model->item(row, column)->text();
        } */
      return (true);
}







/*

void loadModel(QIODevice *device, QStandardItemModel *model)
{
    QDataStream stream(device);
    int rowCount, columnCount;
    stream >> rowCount;
    stream >> columnCount;

    for(int row = 0; row < rowCount; row++)
        for(int column = 0; column < columnCount; column++) {
            QString item;
            stream >> item;
            model->setItem(row, column, item);
        }
}

void saveModel(QIODevice *device, QStandardItemModel *model)
{
    QDataStream stream(device);
    int rowCount = model->rowCount();
    int columnCount = model->columnCount();
    stream << rowCount;
    stream << columnCount;

    for(int row = 0; row < rowCount; row++)
        for(int column = 0; column < columnCount; column++) {
            stream << model->item(row, column)->text();
        }
}

...

QStandardItemModel myModel;

QFile file;
if(file.open(QIODevice::WriteOnly))
    saveModel(&file, &myModel);
 */






/*  ______________________________________________________________________
MyPlcTree::MyPlcTree(QWidget *parent)
    : QTreeWidget(parent)
    //  m_root(new QTreeWidgetItem())
{
    //addTopLevelItem(m_root);
    //invisibleRootItem();

}


void MyPlcTree::Inizialize() {

    QStringList labels;
    labels << tr("Porta(Morsetto)") << tr("Dir") << tr("Tipo");
    setHeaderLabels(labels);
    //header()->setSectionResizeMode(QHeaderView::Stretch);
    setWordWrap(true);

    ic_enabled.addPixmap(QPixmap("/images/enabled.png"), QIcon::Normal, QIcon::On);
    ic_enabled.addPixmap(QPixmap("/images/disabled.png"), QIcon::Normal, QIcon::Off);
}



void MyPlcTree::setMyPlc(MyPlc *myplc)
{
  l_myplc = myplc;
}



void MyPlcTree::reloadItems()
{
    int i,j;
    QTreeWidgetItem *pmod = nullptr;
    clear();

    for( i=0; i< l_myplc->device.nModules; i++ )                    // Modules & Ports
    {
        pmod = addItemModule(&(l_myplc->device.modules[i]));       // Add module
        for ( j=0; j<l_myplc->device.modules[i].nports;j++ )        // Module's In ports
        {
          addItemPort(pmod,&(l_myplc->device.modules[i].ports[j]));
        }
    }
}



QTreeWidgetItem* MyPlcTree::addItemModule(v_module_t *module)
{
    QTreeWidgetItem *myplcModule = new QTreeWidgetItem();

    myplcModule->setText(0, QString(module->malias) + QString(" (%1)").arg(module->addr) );
    addTopLevelItem(myplcModule);

 return (myplcModule);
}

void MyPlcTree::addItemPort(QTreeWidgetItem *module, v_port_t *port)
{
    QTreeWidgetItem *newPort = new QTreeWidgetItem();

    newPort->setIcon(0,(port->enabled)?QIcon(":/images/enabled.png"):QIcon(":/images/disabled.png"));
    newPort->setText(1, QString(port->palias) );
    newPort->setText(2, tr((port->io)?"In":"Out"));
    newPort->setText(3, QString(port->subaddr));
    newPort->setFlags(newPort->flags() | Qt::ItemIsEditable);
    //myplcPort->setFlags(Qt::ItemFlag(colorCount()));
    //myplcPort->setBackground(0, Qt::red );
    module->addChild(newPort);
}

void MyPlcTree::addItemRule(flag_t rl, idx_t pin, idx_t pout)
{

};



void MyPlcTree::updatePort(v_module_t *module, const QModelIndex &index)
{
 int i =0;

};

void MyPlcTree::updateModule()
{


};
void MyPlcTree::updateRule()
{


};


*/
