#ifndef DIALOG_SERIALRETRIVE_H
#define DIALOG_SERIALRETRIVE_H


#include <QDialog>
#include <QSerialPort>
#include <QAbstractButton>
#include "myplcmodel.h"


namespace Ui {
class DialogSerial;
}


class DialogSerial : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSerial(MyPlcModel *myplc, QWidget *parent = nullptr);
    ~DialogSerial();

signals:
    void myplcChanged();

private slots:

    void serialOpen();
    void serialOnReceived();
    void serialClose();
    void serialError(QSerialPort::SerialPortError error);
    void serialProtocolError(QString error);

   void on_receivedINFO();             // Connect

    void on_pbRetrieve_clicked();      // Get uC config datas
    void on_pbRewrite_clicked();       // Send new config to uC

    void on_buttonBox_clicked(QAbstractButton *button);
    void updateLabels(const vs_info_t &infos);

private:
    Ui::DialogSerial *ui;
    QSerialPort *l_serial = nullptr;
    MyPlcModel  *l_myplc = nullptr; //

    bool connected = false;
    bool receiveddata = false;
    bool sendPacket(vs_pkt_t *pkt);

};

#endif // DIALOG_SERIALRETRIVE_H




