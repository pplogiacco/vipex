#include "myplcmodels.h"



/*********************************************************************************************
 * DATA MODELS
*********************************************************************************************/

void dmModules::test()
{
    emit beginResetModel();
    emit endResetModel();
    // emit dataChanged(index(0,0) ,index(m_root->childCount(),0) );
}


dmModules::dmModules(MyPlcDevice *device, QObject *parent)
    : QAbstractItemModel(parent)
     // m_odata(firstItem)
{
    itemdata_t nulldata;
    m_root = device->getDeviceItems();
    connect(device,SIGNAL(deviceChanged()), this, SLOT(test()) );

    // Headers
    m_headers.append("Active"); // Enabled
    m_headers.append("Sync");
    m_headers.append("Alias");
    m_headers.append("I/O");
    m_headers.append("Type");
    m_headers.append("Default");

    // Icons
    // QIconEngine
    //m_icons.append(QIcon("enabled.png"));
    //m_icons.append(QIcon("disable.png"));
    m_icons.insert(icn_enabled,QIcon("images/enabled.png"));
    m_icons.insert(icn_disabled,QIcon("images/disabled.png"));
    m_icons.insert(icn_module,QIcon("enabled.png"));
    m_icons.insert(icn_hwport,QIcon("enabled.png"));
    m_icons.insert(icn_lcnport,QIcon("enabled.png"));

}

dmModules::~dmModules()
{
    delete m_root;
}

QModelIndex dmModules::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
         return QModelIndex();

     myplcItem *parentItem;     // Create index for element !!!!
     if (!parent.isValid())
         parentItem = m_root;
     else
         parentItem = static_cast<myplcItem*>(parent.internalPointer());

     myplcItem *childItem = parentItem->child(row);
     if (childItem)
         return  createIndex(row, column, childItem);
     return QModelIndex();
}

QModelIndex dmModules::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    myplcItem *childItem = static_cast<myplcItem*>(index.internalPointer());
    myplcItem *parentItem = childItem->parent();

    if (parentItem == m_root)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int dmModules::rowCount(const QModelIndex &parent) const
{
    myplcItem *parentItem;

    if (parent.column() > 0) return 0;

    if (!parent.isValid())
        parentItem = m_root;
    else
        parentItem = static_cast<myplcItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int dmModules::columnCount(const QModelIndex &parent) const
{
    //Q_UNUSED(parent)
    //int ncol =0;
    qDebug() << QString("row %1, col%2 ").arg(parent.row()).arg(parent.column());
     if (parent.isValid())
     {
         switch ( static_cast<myplcItem*>(parent.internalPointer())->child(parent.row())->itemType() ) {
           case DEVICE:
            break;
           case MODULE:
              return (1);

           case PORT:
              return m_headers.size();

           case RULE:
            break;
          }
     }
        // return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
    //return rootItem->columnCount();
   return m_headers.size(); // Model colums hard coded
}

QVariant dmModules::data(const QModelIndex &index, int role) const
{

  // qDebug() << QString("row %1, col%2, role %3").arg(index.row()).arg(index.column()).arg(role);
    if (!index.isValid())
        return QVariant();

    //if (role == Qt::DisplayRole)
    //    return QVariant();

        //myplcItem *item = ;
        itemdata_t data = static_cast<myplcItem*>(index.internalPointer())->getItemData();

                switch (index.column() ) {
                    case 0: // Type
                        if (role == Qt::DecorationRole)
                        switch (data.type) {
                          case MODULE:
                             return m_icons.at(icn_enabled);
                          case PORT:
                             return m_icons.at(icn_disabled);
                          break;
                        }
                        if (role == Qt::DisplayRole)
                        switch (data.type) {
                          case MODULE:
                             break; // return QIcon(QPixmap(":/images/enabled.png"));
                          case PORT:
                             break; //return QIcon(QPixmap(":/images/disabled.png"));
                          break;
                        }

                    case 1: // Type
                     if (role == Qt::DisplayRole)
                        return data.alias;

                    case 2:
                     if (role == Qt::DisplayRole)
                        return data.enable;

                    case 3:
                      if (role == Qt::DisplayRole)
                        return data.sync;

                }

        /*
        switch (role) {
          case Qt::DisplayRole:
          break;
        } */

    return QVariant();



    /*
    if (index.isValid())
    switch (role) {
    case Qt::DisplayRole:

        return (getItem(index)->data(index.column()).toString()  );

    case Qt::EditRole:

        return (getItem(index)->data(index.column()));

    case Qt::FontRole:
        if (row == 0 && col == 0) { //change font only for cell(0,0)
            QFont boldFont;
            boldFont.setBold(true);
            return boldFont;
        }        break;
    case Qt::BackgroundRole:
        if (row == 1 && col == 2)  //change background only for cell(1,2)
            return QBrush(Qt::red);
        break;
    case Qt::TextAlignmentRole:
        if (row == 1 && col == 1) //change text alignment only for cell(1,1)
            return Qt::AlignRight + Qt::AlignVCenter;
        break;
    case Qt::CheckStateRole:
       if (row == 1 && col == 0) //add a checkbox to cell(1,0)
            return Qt::Checked;
        break;
    }
    return QVariant();
    */
}

/* SETDATA
bool dmModules::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return false;

    myplcItem *item = getItem(index);
    bool result = item->setData(index.column(), value);

    if (result)
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

    return result;
}
*/

QVariant dmModules::headerData(int section, Qt::Orientation orientation, int role) const
{
      // if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
      // return m_sections.at(section);
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        return m_headers.at(section);
        }

    /*    return QVariant();
        if (role == Qt::DisplayRole)
            return QString::number(section);
        if (role == Qt::DecorationRole)
            return QVariant::fromValue(services); */
        return QAbstractItemModel::headerData(section, orientation, role);

}


Qt::ItemFlags dmModules::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index);
    //Returning Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled is enough to show an editor that a cell can be selected.
    // return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}



/*********************************************************************************************
 *  RULES
*********************************************************************************************/



dmRules::dmRules(MyPlcDevice *device, QObject *parent )
    : QAbstractTableModel(parent)
     // m_odata(firstItem)
{
    itemdata_t nulldata;
    m_root = device->getDeviceItems();
    //connect(device,SIGNAL(deviceChanged()), this, SLOT(test()) );

    // Headers
    m_headers.append("Alias"); // Enabled
    m_headers.append("Attiva"); // Enabled
    m_headers.append("Condizione");
    m_headers.append("Azione");


    // Icons
    // QIconEngine
    //m_icons.append(QIcon("enabled.png"));
    //m_icons.append(QIcon("disable.png"));
    m_icons.insert(icn_enabled,QIcon("images/enabled.png"));
    m_icons.insert(icn_disabled,QIcon("images/disabled.png"));
    m_icons.insert(icn_module,QIcon("enabled.png"));
    m_icons.insert(icn_hwport,QIcon("enabled.png"));
    m_icons.insert(icn_lcnport,QIcon("enabled.png"));

};



dmRules::~dmRules()
{

};

QModelIndex dmRules::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
         return QModelIndex();

     myplcItem *parentItem = m_root;

     myplcItem *childItem = parentItem->child(row);
     if (childItem)
         return  createIndex(row, column, childItem);
     return QModelIndex();
}


QVariant dmRules::headerData(int section, Qt::Orientation orientation,int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        return m_headers.at(section);
        }
    return QAbstractTableModel::headerData(section, orientation, role);
}



QVariant dmRules::data(const QModelIndex &index, int role) const
{
    // qDebug() << QString("row %1, col%2, role %3").arg(index.row()).arg(index.column()).arg(role);
      if (!index.isValid())
          return QVariant();

          itemdata_t data = static_cast<myplcItem*>(index.internalPointer())->getItemData();

                  switch (index.column() ) {
                      case 0: // Type
                          if (role == Qt::DecorationRole)
                          switch (data.type) {
                            case MODULE:
                               return m_icons.at(icn_enabled);
                            case PORT:
                               return m_icons.at(icn_disabled);
                            break;
                          }
                          if (role == Qt::DisplayRole)
                          switch (data.type) {
                            case MODULE:
                               break; // return QIcon(QPixmap(":/images/enabled.png"));
                            case PORT:
                               break; //return QIcon(QPixmap(":/images/disabled.png"));
                            break;
                          }

                      case 1: // Type
                       if (role == Qt::DisplayRole)
                          return data.alias;

                      case 2:
                       if (role == Qt::DisplayRole)
                          return data.enable;

                      case 3:
                        if (role == Qt::DisplayRole)
                          return data.sync;

                  }


      return QVariant();
}


int dmRules::rowCount(const QModelIndex &parent) const
{
   return m_root->childCount();
}


int dmRules::columnCount(const QModelIndex &parent) const
{
    return m_headers.size();
}









// ---------------------------------------------------------------------------------------
// Implements MyPlc specific
// ---------------------------------------------------------------------------------------










/*
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





/*

bool MyPlcModel::loadData(QDataStream *in)
{
    //QDataStream stream(device);
    int rowCount, columnCount;
   stream >> rowCount;
    stream >> columnCount;

    for(int row = 0; row < rowCount; row++)
        for(int column = 0; column < columnCount; column++) {
            QString item;
            stream >> item;
          //  model->setItem(row, column, item);
        }
    return (true);
}

bool MyPlcModel::saveData(QDataStream *out)
{
   // QDataStream stream(device);
   int rowCount =   rowCount(); // model->rowCount();
    int columnCount = model->columnCount();
    stream << rowCount;
    stream << columnCount;

    for(int row = 0; row < rowCount; row++)
        for(int column = 0; column < columnCount; column++) {
            stream << model->item(row, column)->text();
        }
      return (true);
}

*/





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
