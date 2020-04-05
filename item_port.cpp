#include "item_port.h"

ItemPort::ItemPort(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant ItemPort::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!



}

QModelIndex ItemPort::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!

}

QModelIndex ItemPort::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!

}

int ItemPort::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int ItemPort::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant ItemPort::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
