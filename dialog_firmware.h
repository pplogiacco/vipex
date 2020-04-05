#ifndef DIALOG_FIRMWARE_H
#define DIALOG_FIRMWARE_H

#include <QDialog>

namespace Ui {
class Dialog_firmware;
}

class Dialog_firmware : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_firmware(QWidget *parent = nullptr);
    ~Dialog_firmware();

private:
    Ui::Dialog_firmware *ui;
};

#endif // DIALOG_FIRMWARE_H
