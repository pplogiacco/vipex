#ifndef DIALOGEDITPORT_H
#define DIALOGEDITPORT_H

#include <QDialog>
#include <QAbstractButton>
#include "myplcmodels.h"


namespace Ui {
class Dialog_EditPort;
}


class Dialog_EditPort : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_EditPort(dmModules *model, QModelIndex index, QWidget *parent = nullptr);

    ~Dialog_EditPort();

    void setData(vs_module_t *module, const QModelIndex &index);

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_buttonBox_accepted();

signals:
    void myplcChanged(const QModelIndex &);

private:
    Ui::Dialog_EditPort *ui;
    vs_module_t *m_module = nullptr;
    QModelIndex const *m_index = nullptr;

};

#endif // DIALOGEDITPORT_H
