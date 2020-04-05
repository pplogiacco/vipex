#include "dialog_editrule.h"
#include "ui_dialogeditrule.h"

DialogEditRule::DialogEditRule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditRule)
{
    ui->setupUi(this);
}

DialogEditRule::~DialogEditRule()
{
    delete ui;
}
