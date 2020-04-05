#include "dialog_firmware.h"
#include "ui_dialog_firmware.h"

Dialog_firmware::Dialog_firmware(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_firmware)
{
    ui->setupUi(this);
}

Dialog_firmware::~Dialog_firmware()
{
    delete ui;
}
