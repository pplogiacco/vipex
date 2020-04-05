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


// ---------------------------------------------------------------------------------------------
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



// ---------------------------------------------------------------------------------------------
//                                                                           D A T A   M O D E L
// ---------------------------------------------------------------------------------------------

typedef enum {
        PORT,
        MODULE,
        RULE
             } itemtype_t;

class MyPlcItem
{
    explicit MyPlcItem(const vs_module_t *module, MyPlcItem *parent = nullptr);
    explicit MyPlcItem(const vs_port_t *port, MyPlcItem *parent = nullptr);
    explicit MyPlcItem(const vs_rule_t *rule, MyPlcItem *parent = nullptr);
    ~MyPlcItem();

    void appendChild(MyPlcItem *child);
    MyPlcItem *child(int row);
    void deleteAllChild();

    int row() const;
    int childCount() const;
    int columnCount() const;
    MyPlcItem *parent();

    QVariant data(int nfield) const;
    bool setData(int nfield, const QVariant &value);

    inline itemtype_t itemType() { return (m_type); }

private:

    QVector<MyPlcItem*> m_childs;
    itemtype_t m_type;
    MyPlcItem *m_data;
    MyPlcItem *m_parent;
};


class MyPlcAbstractModule :  MyPlcItem
{
public:
};


class MyPlcPort :  MyPlcItem
{
public:
private:
     MyPlcAbstractModule *m_module;

};


class MyPlcRule :  MyPlcItem
{
public:
private:

};

class MyPlcNBV30 : MyPlcAbstractModule
{
public:

private:


};


class MyPlcSEM16 : MyPlcAbstractModule
{
public:

private:


};

class MyPlcLCNIF: MyPlcAbstractModule
{
public:

private:


};






class MyPlcModel : public QAbstractItemModel
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

    QModelIndex index(int row, int column,const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;


    // Implements MyPlc specific

    vs_info_t getDeviceInfo();
    void setDeviceInfo(vs_info_t &info);

    //int nModules();
    //vs_module_t getModule(idx_t imodule);
    bool setModule(vs_module_t &module);
    //int nModulePorts(int module);

    //vs_port_t getModulePort(idx_t imodule,int nport);


    //int nPortsIn();
    //int nPortsOut();
    //vs_port_t getPort(flag_t io, idx_t iport);
    bool setPort(vs_port_t &port);


    //int nRules();
    bool setRule(vs_rule_t &rule );
    //vs_rule_t getRule(idx_t iport);


    bool loadData(QDataStream *out);
    bool saveData(QDataStream *in);

    //bool rebuildIdx();


private:
    MyPlcItem *getItem(const QModelIndex &index) const;
    //MyPlcItem *m_root = nullptr;
    vs_info_t m_info;
};



#endif // MYPLCMODEL_H


