#include "myplctree.h"

//Q_DECLARE_METATYPE(MyPlcElement)


MyPlcTree::MyPlcTree(QWidget *parent)
    : QTreeWidget(parent)
{
    QTreeWidgetItem *myplc = new QTreeWidgetItem();
    this->addTopLevelItem(myplc);
    this->invisibleRootItem();
}



void MyPlcTree::Inizialize() {

    QStringList labels;
    labels << tr("Porta(Morsetto)") << tr("Dir") << tr("Tipo");
    header()->setSectionResizeMode(QHeaderView::Stretch); // : ::Stretch
    setHeaderLabels(labels);
    setWordWrap(true);

    /*
    QStandardItemModel *m_model = new QStandardItemModel(this);
    m_model->setHorizontalHeaderItem(0,new QStandardItem(QString("Morsetto")));
    m_model->setHorizontalHeaderItem(1,new QStandardItem(QString("Dir")));
    m_model->setHorizontalHeaderItem(2,new QStandardItem(QString("Tipo")));
    header()->setModel(m_model);
    */

    deviceIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirClosedIcon), QIcon::Normal, QIcon::Off);
    moduleLocIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirOpenIcon), QIcon::Normal, QIcon::On);
    moduleSemIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirOpenIcon), QIcon::Normal, QIcon::On);
    moduleLcnIcon.addPixmap(style()->standardPixmap(QStyle::SP_DirOpenIcon), QIcon::Normal, QIcon::On);
    portIcon.addPixmap(style()->standardPixmap(QStyle::SP_FileIcon));
}


void MyPlcTree::setMyPlc(MyPlc *myplc)
{
  l_myplc = myplc;
}


void MyPlcTree::Refresh()
{
    int i,j;
    QTreeWidgetItem *pimod = nullptr;
    clear();

    for( i=0; i< l_myplc->device.nModules; i++ )  // Modules & Ports
    {
        pimod = addItemModule(&(l_myplc->device.modules[i]));    // Add module
        for ( j=0; j<l_myplc->device.modules[i].nports;j++ )    // Module's In ports
        {
          addItemPort(pimod,&(l_myplc->device.modules[i].ports[j]));
        }
    }
}



QTreeWidgetItem* MyPlcTree::addItemModule(v_module_t *module)     // idx_t m1 = myplc.addWiringModule(_SEM16);
{
    QTreeWidgetItem *myplcModule = new QTreeWidgetItem();
    switch (module->mtype) {
       case _NBV30:
            //myplcModule->setText(0, tr("Nanoboard_v3 (%1)").arg(module->addr));
           break;
       case _SEM16:
            //myplcModule->setText(0, tr("Sem16 - IO Expander (%1)").arg(module->addr));
           break;
       case _LCNIF:
            //myplcModule->setText(0, tr("Loconet-IF (%1)").arg(module->addr));
           break;
    }  // end-switch

    //QString *alias = new QString("P%1").arg(saddr);
   myplcModule->setText(0, QString(module->malias) + QString(" (%1)").arg(module->addr) );
   addTopLevelItem(myplcModule);
 return (myplcModule);
}



void MyPlcTree::addItemPort(QTreeWidgetItem *module, v_port_t *port) // idx_t a1 = myplc.addPort(In ,m1,_A1);
{
    QTreeWidgetItem *myplcPort = new QTreeWidgetItem();

    myplcPort->setText(1,  QString(port->palias) );
    myplcPort->setText(2, tr((port->io)?"In":"Out"));

    //myplcPort->setFlags(Qt::ItemFlag(colorCount()));
    //myplcPort->setBackground(0, Qt::red );
    myplcPort->setIcon(0,(port->enabled)?QIcon(":/images/enabled.png"):QIcon(":/images/disabled.png"));
    module->addChild(myplcPort);
}




void MyPlcTree::addItemRule(flag_t rl, idx_t pin, idx_t pout)
{

};



void MyPlcTree::editCurrentItem()
{

};




// ---------------------------------------------------------------------------------------------
//                                                                                       I T E M
// ---------------------------------------------------------------------------------------------

TreeItem::TreeItem(const QVector<QVariant> &data, TreeItem *parent)
      : itemData(data),
        parentItem(parent)
  {}


TreeItem::~TreeItem()
  {
      qDeleteAll(childItems);
  }


TreeItem *TreeItem::parent()
  {
      return parentItem;
  }



TreeItem *TreeItem::child(int number)
 {
     if (number < 0 || number >= childItems.size())
         return nullptr;
     return childItems.at(number);
 }


int TreeItem::childCount() const
  {
      return childItems.count();
  }


int TreeItem::childNumber() const
  {
      if (parentItem)
          return parentItem->childItems.indexOf(const_cast<TreeItem*>(this));
      return 0;
  }


int TreeItem::columnCount() const
 {
     return itemData.count();
 }



QVariant TreeItem::data(int column) const
 {
     if (column < 0 || column >= itemData.size())
         return QVariant();
     return itemData.at(column);
 }


bool TreeItem::setData(int column, const QVariant &value)
  {
      if (column < 0 || column >= itemData.size())
          return false;

      itemData[column] = value;
      return true;
  }


bool TreeItem::insertChildren(int position, int count, int columns)
 {
     if (position < 0 || position > childItems.size())
         return false;

     for (int row = 0; row < count; ++row) {
         QVector<QVariant> data(columns);
         TreeItem *item = new TreeItem(data, this);
         childItems.insert(position, item);
     }

     return true;
 }


bool TreeItem::removeChildren(int position, int count)
  {
      if (position < 0 || position + count > childItems.size())
          return false;

      for (int row = 0; row < count; ++row)
          delete childItems.takeAt(position);

      return true;
  }


bool TreeItem::insertColumns(int position, int columns)
{
    if (position < 0 || position > itemData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        itemData.insert(position, QVariant());

    for (TreeItem *child : qAsConst(childItems))
        child->insertColumns(position, columns);

    return true;
}


bool TreeItem::removeColumns(int position, int columns)
{
    if (position < 0 || position + columns > itemData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        itemData.remove(position);

    for (TreeItem *child : qAsConst(childItems))
        child->removeColumns(position, columns);

    return true;
}


// ---------------------------------------------------------------------------------------------
//                                                                           T R E E   M O D E L
// ---------------------------------------------------------------------------------------------



MyPlcTreeModel::MyPlcTreeModel( MyPlc *myplc, QObject *parent)
    : QAbstractItemModel(parent)
{
    QVector<QVariant> rootData;

    //for (const QString &header : headers)
    //    rootData << header;

    QStringList labels;
    rootData  << tr("Porta(Morsetto)") << tr("Dir")<< tr("Tipo");

    rootItem = new TreeItem(rootData);
    setMyPlc(myplc, rootItem);
}



MyPlcTreeModel::~MyPlcTreeModel()
{
    delete rootItem;
}



QVariant MyPlcTreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    TreeItem *item = getItem(index);

    return item->data(index.column());
}


QVariant MyPlcTreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}



bool MyPlcTreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return false;

    TreeItem *item = getItem(index);
    bool result = item->setData(index.column(), value);

    if (result)
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

    return result;
}


bool MyPlcTreeModel::setHeaderData(int section, Qt::Orientation orientation,
                              const QVariant &value, int role)
{
    if (role != Qt::EditRole || orientation != Qt::Horizontal)
        return false;

    const bool result = rootItem->setData(section, value);

    if (result)
        emit headerDataChanged(orientation, section, section);

    return result;
}


TreeItem *MyPlcTreeModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
        TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
        if (item)
            return item;
    }
    return rootItem;
}


int MyPlcTreeModel::rowCount(const QModelIndex &parent) const
{
    const TreeItem *parentItem = getItem(parent);

    return parentItem ? parentItem->childCount() : 0;
}


int MyPlcTreeModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return rootItem->columnCount();
}


Qt::ItemFlags MyPlcTreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}


QModelIndex MyPlcTreeModel::index(int row, int column, const QModelIndex &parent) const
{
     if (parent.isValid() && parent.column() != 0)
         return QModelIndex();


     TreeItem *parentItem = getItem(parent);
     if (!parentItem)
         return QModelIndex();

     TreeItem *childItem = parentItem->child(row);

     if (childItem)
         return createIndex(row, column, childItem);

     return QModelIndex();
 }


QModelIndex MyPlcTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = getItem(index);
    TreeItem *parentItem = childItem ? childItem->parent() : nullptr;

    if (parentItem == rootItem || !parentItem)
        return QModelIndex();

    return createIndex(parentItem->childNumber(), 0, parentItem);
}


void MyPlcTreeModel::setMyPlc(MyPlc *myplc, TreeItem *parent)
{
    QVector<TreeItem*> parents;

    QVector<int> indentations;
    parents << parent;
    indentations << 0;

    // Per tutti i moduli
       // Aggiungi modulo
            // per tutte le porte del modulo
            // Aggiungi porta


/*
    int number = 0;



    while (number < lines.count()) {
        int position = 0;

                                // salta caratteri vuoti
        const QString lineData = lines[number].mid(position).trimmed();

        if (!lineData.isEmpty()) {


            // Append a new item to the current parent's list of children.
            TreeItem *parent = parents.last();
            parent->insertChildren(parent->childCount(), 1, rootItem->columnCount());
            for (int column = 0; column < columnData.size(); ++column)
                parent->child(parent->childCount() - 1)->setData(column, columnData[column]);
        }
        ++number;
    }

 */

}



bool MyPlcTreeModel::removeColumns(int position, int columns, const QModelIndex &parent)
{
    beginRemoveColumns(parent, position, position + columns - 1);
    const bool success = rootItem->removeColumns(position, columns);
    endRemoveColumns();

    if (rootItem->columnCount() == 0)
        removeRows(0, rowCount());

    return success;
}



bool MyPlcTreeModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    TreeItem *parentItem = getItem(parent);
    if (!parentItem)
        return false;

    beginRemoveRows(parent, position, position + rows - 1);
    const bool success = parentItem->removeChildren(position, rows);
    endRemoveRows();

    return success;
}



bool MyPlcTreeModel::insertColumns(int position, int columns, const QModelIndex &parent)
{
    beginInsertColumns(parent, position, position + columns - 1);
    const bool success = rootItem->insertColumns(position, columns);
    endInsertColumns();

    return success;
}


bool MyPlcTreeModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    TreeItem *parentItem = getItem(parent);
    if (!parentItem)
        return false;

    beginInsertRows(parent, position, position + rows - 1);
    const bool success = parentItem->insertChildren(position,
                                                    rows,
                                                    rootItem->columnCount());
    endInsertRows();

    return success;
}































    /*
    bool VrmsTree::read(QIODevice *device)
    {
        QString errorStr;

        int errorLine;
        int errorColumn;

        if (!domDocument.setContent(device, true, &errorStr, &errorLine, &errorColumn))
        {
            QMessageBox::information( window(), tr("VRMS File"), tr("Parse error at line %1, column %2:\n%3")
                                     .arg(errorLine)
                                     .arg(errorColumn)
                                     .arg(errorStr));
            return false;
        }

        QDomElement root = domDocument.documentElement();

        if (root.tagName() != "vrms") {
            QMessageBox::information(window(), tr("VRMS File"),
                                     tr("The file is not an VRMS file."));
            return false;

        } else if (root.hasAttribute(versionAttribute())
                   && root.attribute(versionAttribute()) != QLatin1String("1.0")) {
            QMessageBox::information(window(),
                                     tr("VRMS File"),
                                     tr("The file is not an VRMS version 1.0 file."));
            return false;
        }


        clear();

        disconnect(this, &QTreeWidget::itemChanged, this, &VrmsTree::updateTreeElement);

        QDomElement child = root.firstChildElement(deviceElement()); // Apre i tag /folder
        while (!child.isNull()) {
            parseDeviceElement(child);
            child = child.nextSiblingElement(deviceElement());
        }

        connect(this, &QTreeWidget::itemChanged, this, &VrmsTree::updateTreeElement);

        return true;
    }
    */

    /*
    void MyPlcTree::updateTreeElement(const QTreeWidgetItem *item, int column)
    {
        // MyPlcElement element = item->data(0, 1 DomElementRole).value<QDomElement>();
        MyPlcElement element(_LCNIF); //  = item->data(0, 1 DomElementRole).value<QDomElement>();
        if (!element.isNull()) {

            if (column == 0) {
               // QDomElement oldTitleElement = element.firstChildElement(titleElement());
                //QDomElement newTitleElement = domDocument.createElement(titleElement());

                // QDomText newTitleText = domDocument.createTextNode(item->text(0));
                // newTitleElement.appendChild(newTitleText);

                // element.replaceChild(newTitleElement, oldTitleElement);
            } else {
               // if (element.tagName() == bookmarkElement())
               //     element.setAttribute(hrefAttribute(), item->text(1));
            }
        }
    }



    QTreeWidgetItem *MyPlcTree::createItem(const MyPlcElement &element, QTreeWidgetItem *parentItem)
    {
        QTreeWidgetItem *item;
        if (parentItem) {
            item = new QTreeWidgetItem(parentItem);
        } else {
            item = new QTreeWidgetItem(this);
        }
        item->setData(0, 1 DomElementRole, QVariant::fromValue(element));
        return item;
    }

    */





/*
#define _NBV30_NPORT 8

class MyPlcElement
{


public:

    MyPlcElement(module_t mtype = _NBV30 ) {

        switch (mtype) {
           case _NBV30:
                // _MO[nMO].mod = new ModuleNB20(nMO);      // Differetn types different implementations
                for(int i=0;i<_NBV30_NPORT;i++) {

                }
               break;

           case _SEM16:
                // _MO[nMO].mod = new ModuleSEM16(nMO, address);    // Different type different implementations
               break;

           case _LCNIF:
                // _MO[nMO].mod = new ModuleLCN(nMO, address);      // Differetn types different implementations
               break;

        }

        // CHECK FREE MEMORY
      // int required = maxmod * sizeof(module_t) + (maxin+maxout)*sizeof(port_t) + maxrls * sizeof(rule_t);
      int mem = malloc ( required );
       if ((required >>= 1) < E02_MINFREE) {
         if (mem) free (mem);
         return (E02);
       }
     // _MO = new mnode_t[maxmod];
     // _PI = new port_t[maxin];
     // _PO = new port_t[maxout];
     // _RL = new rule_t[maxrls];

    }

    ~MyPlcElement(void) {
       delete[] _MO;
       delete[] _PI;
       delete[] _PO;
       delete[] _RL;
    }

    bool isNull() {
     return true;

    }

};

*/
