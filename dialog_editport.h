#ifndef DIALOGEDITPORT_H
#define DIALOGEDITPORT_H

#include <QDialog>
#include <QAbstractButton>
#include "myplc.h"

namespace Ui {
class DialogEditPort;
}

class DialogEditPort : public QDialog
{
    Q_OBJECT

signals:
    void myplcChanged(const QModelIndex &);

public:
    explicit DialogEditPort(QWidget *parent = nullptr);
    ~DialogEditPort();

    void setData(vs_module_t *module, const QModelIndex &index);

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_buttonBox_accepted();

private:
    Ui::DialogEditPort *ui;
    vs_module_t *m_module = nullptr;
    QModelIndex const *m_index = nullptr;

};

#endif // DIALOGEDITPORT_H
