#include "dialog_terminal.h"
#include "ui_dialog_terminal.h"

DialogTerminal::DialogTerminal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTerminal)
{
    ui->setupUi(this);
}

DialogTerminal::~DialogTerminal()
{
    delete ui;
}

void DialogTerminal::on_pushButton_clicked()
{

}
