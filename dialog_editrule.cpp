#include "dialog_editrule.h"
#include "ui_dialog_editrule.h"

Dialog_EditRule::Dialog_EditRule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_EditRule)
{
    ui->setupUi(this);
}

Dialog_EditRule::~Dialog_EditRule()
{
    delete ui;
}
