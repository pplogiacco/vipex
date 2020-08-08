#ifndef MYPLCMODELS_H
#define MYPLCMODELS_H

#include <QStringList>
#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QAbstractTableModel>   // Rules module



#include "qmetatype.h"
#include "myplc.h"

#include "dialog_editport.h"
#include "dialog_deleteeditmodule.h"
#include "dialog_editrule.h"

#include <QPixmap>
#include <QIcon>


/* Subclassing QStandardItemModel

When subclassing QStandardItem to provide custom items, it is possible to define new types for them so that they can be
distinguished from the base class. The type() function should be reimplemented to return a new type value equal to or
greater than UserType .

Reimplement data() and setData() if you want to perform custom handling of data queries and/or control how an item's data
is represented.

Reimplement clone() if you want QStandardItemModel to be able to create instances of your custom item class on demand
(see QStandardItemModel::setItemPrototype()).

Reimplement read() and write() if you want to control how items are represented in their serialized form.

Reimplement operator<() if you want to control the semantics of item comparison. operator<() determines the sorted
order when sorting items with sortChildren() or with QStandardItemModel::sort().

*/




class dmModules: public QAbstractItemModel
{
      Q_OBJECT

public:
    explicit dmModules(MyPlcDevice *device, QObject *parent = nullptr);
    ~dmModules() override;

    // Re-implements QAbstractModel
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index = QModelIndex()) const override;

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const override;

    QVariant data(const QModelIndex &index, int role) const override;

private slots:
        void test();

private:
     myplcItem *m_root = nullptr;
    QStringList m_headers;

 QVector<QIcon> m_icons;
    enum icon {
                icn_enabled  = 0,
                icn_disabled,
                icn_module,
                icn_hwport,
                icn_lcnport
              };
};





class dmVPorts : public QStandardItemModel
{
     Q_OBJECT

/*
public:
    dmVPorts(QObject *parent = nullptr);
    ~dmVPorts()  override;

    // Re-implements QAbstractModel
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;


    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    //bool setHeaderData(int section, Qt::Orientation orientation,        // Da implementare se cambia colonne dinamicamente
    //                   const QVariant &value, int role = Qt::EditRole) override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    QModelIndex index(int row, int column,const QModelIndex &parent = QModelIndex()) const override;

    QModelIndex parent(const QModelIndex &index = QModelIndex()) const override;


private:
    myplcItem *m_root = nullptr;

*/


};






class dmRules : public QAbstractTableModel
{

    Q_OBJECT

public:
    dmRules(MyPlcDevice *device, QObject *parent = nullptr);
    ~dmRules()  override;

    QModelIndex index(int row, int column, const QModelIndex &parent) const override;

    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;


private:
    myplcItem *m_root = nullptr;
   QStringList m_headers;
   QVector<QIcon> m_icons;

      enum icon {
                  icn_enabled  = 0,
                  icn_disabled,
                  icn_module,
                  icn_hwport,
                  icn_lcnport
                };

};


#endif // MYPLCMODELS_H





















/* ---------------------------------------------------------------------------------------------
//                                                                             M y P l c T r e e
// ---------------------------------------------------------------------------------------------


class MyPlcTree : public QTreeWidget
{
    Q_OBJECT

public:
    MyPlcTree(QWidget *parent = Q_NULLPTR);
    ~MyPlcTree() = default;

    void setMyPlc(MyPlc *myplc);
    void Inizialize();


public slots:
    void reloadItems();
    void updateModule();
    void updatePort(v_module_t *module, const QModelIndex &index);
    void updateRule();

private:

    QTreeWidgetItem* addItemModule(v_module_t *module);
    void addItemPort(QTreeWidgetItem *module, v_port_t *port);
    void addItemRule(flag_t rl, idx_t pin, idx_t pout);

    // QTreeWidgetItem *m_root;
    MyPlc *l_myplc = nullptr;

    QIcon ic_enabled;       // Device Icon

    };

*/









/*

class MyPlcAbstractItemData
{
public:
    explicit MyPlcAbstractItemData(itemtype_t type): l_type(type) {}
    ~MyPlcAbstractItemData() = default;

    inline itemtype_t itemType() { return (l_type); }
    inline int minChild() {return (0);}
    inline int maxChild() {return (0);}
    inline int nFileds()  {return (3);}

    inline word_t id() { return (_id); }
    inline void id(word_t x) {_id=x; }

    inline bool enabled() { return (_enabled); }
    inline void enabled(bool x) {_enabled=x; }

    inline QString alias() { return (_alias); }
    inline void alias(QString x) {_alias=x; }

    QVariant getField(int n)
    {
        switch (n)
        {
        case 0: return (_id);       // ID
        case 1: return (_enabled);  // Enabled
        case 2: return (_alias);    // Alias
        }
      return QString("[ERROR]");
    }

 protected:
    itemtype_t l_type;
    word_t _id = 0;
    bool _enabled = false;
    QString _alias = QString("[NODATA]");
};



class MyPlcPort : public MyPlcAbstractItemData
{
    explicit MyPlcPort() = default;
    ~MyPlcPort() = default;
private:

};


class MyPlcRule :  MyPlcAbstractItemData
{
public:
private:

};

class MyPlcNBV30 : public MyPlcAbstractItemData
{
public:
    MyPlcNBV30(): MyPlcAbstractItemData(MODULE)
    {
     mtype(_NBV30);
     alias("Nanoboard v3");
    }
    ~MyPlcNBV30();

    inline int minChild() {return (8);}
    inline int maxChild() {return (8);}
    inline int nFileds()  {return (5);}

    virtual QVariant getField(int n)
    {
        switch (n)
        {
        case 0: return (_id);       // ID
        case 1: return (_enabled);  // Enabled
        case 2: return (_alias);    // Alias
        case 3: return (_idx);      // uC:idx
        case 4: return (_mtype);    // uC:mtype
        }
      return QString("[ERROR]");
    }
    inline idx_t idx() { return (_idx); }
    inline void idx(idx_t x) {_idx=x; }

    inline module_t mtype() { return (_mtype); }
    inline void mtype(module_t x) {_mtype=x; }

private:
 idx_t _idx;
 module_t _mtype;
};



class MyPlcSEM16 :  public MyPlcAbstractItemData
{
public:
    MyPlcSEM16();
    ~MyPlcSEM16();

    inline int minChild() {return (16);}
    inline int maxChild() {return (16);}
    inline int nFileds()  {return (6);}

    virtual QVariant getField(int n)
    {
        switch (n)
        {
        case 0: return (_id);       // ID
        case 1: return (_enabled);  // Enabled
        case 2: return (_alias);    // Alias
        case 3: return (_idx);      // uC:idx
        case 4: return (_mtype);    // uC:mtype
        case 5: return (_maddr);    // uC:maddr
        }
      return QString("[ERROR]");
    }
    inline idx_t idx() { return (_idx); }
    inline void idx(idx_t x) {_idx=x; }

    inline module_t mtype() { return (_mtype); }
    inline void mtype(module_t x) {_mtype=x; }

    inline maddr_t maddr() { return (_maddr); }
    inline void maddr(maddr_t x) {_maddr=x; }

private:
 idx_t _idx;
 module_t _mtype;
 maddr_t _maddr;
};



class MyPlcLCNIF: MyPlcAbstractItemData
{
public:

private:


};


*/
