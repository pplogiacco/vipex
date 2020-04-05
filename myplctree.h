#ifndef MYPLCTREE_H
#define MYPLCTREE_H

#include <QIcon>
#include <QtWidgets>
#include <QTreeWidget>
#include <QStandardItemModel>

#include "myplc.h"

#include "dialog_editport.h"
#include "dialog_editmodule.h"
#include "dialog_editrule.h"


// ---------------------------------------------------------------------------------------------
//                                                                           Q T r e e M y P l c
// ---------------------------------------------------------------------------------------------


class MyPlcTree : public QTreeWidget
{
    Q_OBJECT

public:
    MyPlcTree(QWidget *parent = Q_NULLPTR);
    void Inizialize();
    void setMyPlc(MyPlc *myplc);


public slots:
    void Refresh();
    void editCurrentItem();

private:

    QTreeWidgetItem* addItemModule(v_module_t *module);
    void addItemPort(QTreeWidgetItem *module, v_port_t *port);
    void addItemRule(flag_t rl, idx_t pin, idx_t pout);

    MyPlc *l_myplc = nullptr;
    QIcon folderIcon;       // Device Icon
    QIcon deviceIcon;       // Device Icon
    QIcon moduleLocIcon;    // Module Icon ( Sem16, Loconet )
    QIcon moduleSemIcon;    // Module Icon ( Sem16, Loconet )
    QIcon moduleLcnIcon;    // Module Icon ( Sem16, Loconet )
    QIcon portIcon;         // Port/Gatte Icon (  )
};





class TreeItem
{
  public:
      explicit TreeItem(const QVector<QVariant> &data, TreeItem *parent = nullptr);
      ~TreeItem();

      QVariant data(int column) const;

      TreeItem *parent();

      int childCount() const;
      TreeItem *child(int number);
      int childNumber() const;

      bool insertChildren(int position, int count, int columns);     
      bool removeChildren(int position, int count);



      int columnCount() const;
      bool insertColumns(int position, int columns);
      bool removeColumns(int position, int columns);


      bool setData(int column, const QVariant &value);

  private:
      QVector<TreeItem*> childItems;
      QVector<QVariant> itemData;
      TreeItem *parentItem;
};






class MyPlcTreeModel : public QAbstractItemModel
{
      Q_OBJECT

  public:
      MyPlcTreeModel( MyPlc *myplc, QObject *parent = nullptr);
      ~MyPlcTreeModel();

      QVariant data(const QModelIndex &index, int role) const override;
      bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

      QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
      bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

      QModelIndex index(int row, int column,const QModelIndex &parent = QModelIndex()) const override;
      QModelIndex parent(const QModelIndex &index) const override;

      int rowCount(const QModelIndex &parent = QModelIndex()) const override;
      int columnCount(const QModelIndex &parent = QModelIndex()) const override;

      Qt::ItemFlags flags(const QModelIndex &index) const override;

      bool insertColumns(int position, int columns, const QModelIndex &parent = QModelIndex()) override;
      bool removeColumns(int position, int columns, const QModelIndex &parent = QModelIndex()) override;

      bool insertRows(int position, int rows, const QModelIndex &parent = QModelIndex()) override;
      bool removeRows(int position, int rows,const QModelIndex &parent = QModelIndex()) override;

private:
    //  void setupModelData(const QStringList &lines, TreeItem *parent);
    void setMyPlc(MyPlc *myplc, TreeItem *parent);

    TreeItem *getItem(const QModelIndex &index) const;
    TreeItem *rootItem;

};



#endif // MYPLCTREE_H


