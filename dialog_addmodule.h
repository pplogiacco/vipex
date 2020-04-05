#ifndef DIALOG_ADDMODULE_H
#define DIALOG_ADDMODULE_H

#include <QDialog>
#include <qabstractbutton.h>
#include "myplcmodel.h"


namespace Ui {
class Dialog_AddModule;
}


class DialogAddModule : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddModule(MyPlcModel *myplc, QWidget *parent = nullptr);
    ~DialogAddModule();

public slots:
    void on_combo_changed(int index);
    void on_jumpers_changed();
    void on_ok_clicked();

private slots:
    //void on_buttonBox_clicked(QAbstractButton *button);

    //void accept(); // override;
    //void reject(); // override;

    //void comboChange(module_t index);

    void on_J1_stateChanged(int arg1);

signals:
    void myplcChanged();

private:
    Ui::Dialog_AddModule *ui;
    MyPlcModel *l_myplc;
};

#endif // DIALOG_ADDMODULE_H
