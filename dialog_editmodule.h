#ifndef DIALOG_ADDMODULE_H
#define DIALOG_ADDMODULE_H

#include <QDialog>
#include <qabstractbutton.h>
#include "myplcmodels.h"


namespace Ui {
class Dialog_EditModule;
}


class Dialog_EditModule : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_EditModule(dmModules *myplc, QWidget *parent = nullptr);
    ~Dialog_EditModule();

public slots:
    void on_combo_changed(int index);
    void on_ok_clicked();

private slots:
    void on_jumpers_changed();


signals:
    void myplcChanged();

private:
    Ui::Dialog_EditModule *ui;
    dmModules *l_myplc;
};

#endif // DIALOG_ADDMODULE_H
