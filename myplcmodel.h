#ifndef MYPLCMODEL_H
#define MYPLCMODEL_H

#include <QIcon>
#include <QtWidgets>
#include <QTreeWidget>
#include <QStandardItemModel>

#include "myplc.h"

#include "dialog_editport.h"
#include "dialog_editmodule.h"
#include "dialog_editrule.h"

#include "qmetatype.h"





#define ITEM_NCOLUMNS   12

                            // ITEM DATA:
#define I_SYNC          0       // uC Syncronized
#define I_TYPE          1       // Element type
#define I_ENAB          2       // Enable/Disable item
#define I_ALIAS         3       // Text alias

                            // Element's Coulumns defs:
#define IE_IDX          4       // uC index
#define IE_TYPE         5       // Module/port type
#define IE_ADDR         6       // maddr/saddr

                            // Module
#define IE_NPORT        7       // number of ports
#define IE_MOPT1        8       // Hw option1
#define IE_MOPT2        9       // Hw option2

                            // Port
#define IE_IO           7       // port I/O
#define IE_DVAL         8       // port default value
#define IE_MIDX         9       // port module idx ref

                            // Rule
#define IE_RLC          7      // Rule condition/action
#define IE_IPE          8      // Rule Idx Port to evaluate    (PIn)
#define IE_IPA          9      // Rule Idx Port to act/change  (POut)

                            // DEVICE DATA
#define ID_SERIAL       4
#define ID_SOFTWARE     5
#define ID_HARDWARE     6
#define ID_CYCLE        7
#define ID_MEMORY       8
#define ID_EEPROM       9
#define ID_MODULES      10
#define ID_PORTS        11
#define ID_RULES        12






// ---------------------------------------------------------------------------------------------
//                                                                           D A T A   M O D E L
// ---------------------------------------------------------------------------------------------



typedef enum {
        DEVICE, // Root
        MODULE,
        PORT,
        RULE
             } itemtype_t;

typedef struct {
  itemtype_t type;          // rule condition coding
     QString alias;
        bool enable;        // index innput port
        bool sync;

        union {
            vs_module_t module;
              vs_port_t port;
              vs_rule_t rule;
              };
               } itemdata_t;


Q_DECLARE_METATYPE(itemdata_t);







class MyPlcItem
{
public:
    explicit MyPlcItem();  // Root const QStringList columheaders);
    explicit MyPlcItem(itemtype_t it, MyPlcItem *parent = nullptr);

    explicit MyPlcItem(const vs_module_t &data, MyPlcItem *parent = nullptr);
    explicit MyPlcItem(module_t mtype, word_t maddr=0, word_t opt1=0,word_t opt2=0, bool ena = false, MyPlcItem *parent = nullptr);

    explicit MyPlcItem(const vs_port_t &data, MyPlcItem *parent = nullptr);
    explicit MyPlcItem(const vs_rule_t &data, MyPlcItem *parent = nullptr);

    ~MyPlcItem()
    {
      free(m_rawdata);
      qDeleteAll(m_childs);

    }


    // generic Data Model
    void appendChild(MyPlcItem *child);
    MyPlcItem *child(int row);
    void deleteAllChild();

    int row() const;           // Model row number
    int childCount() const;
    int childNumber() const;   // Number of child in parent vector

    int columnCount() const;   // Number of field column

    inline MyPlcItem *parent() { return (m_parent); }

    QVariant data(int nfield) const;
    bool setData(int nfield, const QVariant &value);

    // specific MyPlc
    inline itemtype_t itemType() { return (m_type); }


private:
    MyPlcItem *m_parent;
    QVector<MyPlcItem*> m_childs;

    itemtype_t m_type;
    char *m_rawdata;

    itemdata_t m_data;
    //MyPlcAbstractItemData *m_data = nullptr;

};






class MyPlcModel    : public QAbstractItemModel
{
      Q_OBJECT

public slots:
    void buildItems();

public:
    MyPlcModel(QObject *parent = nullptr);
    ~MyPlcModel()  override;

    // Re-implements QAbstractModel
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QModelIndex index(int row, int column,const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index = QModelIndex()) const override;

    // Implements MyPlc

    // ! void deleteAllItems();
    //
    void setDeviceInfo(const vs_info_t &info);
    void getDeviceInfo(vs_info_t *info);
    inline MyPlcItem *rootDevice() { return (m_root); }

    bool setModule(const vs_module_t &module);
    bool setPort(vs_port_t &port);
    bool setRule(vs_rule_t &rule );

    bool loadData(QDataStream *out);    // Files
    bool saveData(QDataStream *in);

private:
    MyPlcItem *getItem(const QModelIndex &index) const;
    MyPlcItem *m_root = new MyPlcItem(DEVICE);
    vs_info_t m_info;
};



#endif // MYPLCMODEL_H













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
