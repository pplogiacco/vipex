#include "dialog_editmodule.h"
#include "ui_dialogeditmodule.h"

DialogEditModule::DialogEditModule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditModule)
{
    ui->setupUi(this);
}

DialogEditModule::~DialogEditModule()
{
    delete ui;
}
