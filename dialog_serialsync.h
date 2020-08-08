#ifndef DIALOG_SERIALRETRIVE_H
#define DIALOG_SERIALRETRIVE_H


#include <QDialog>
#include <QSerialPort>
#include <QAbstractButton>
#include "myplcmodels.h"


namespace Ui {
class Dialog_SerialSync;
}


class Dialog_SerialSync : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_SerialSync(MyPlcDevice *myplc, const QString comport, const bool rwcmd, QWidget *parent = nullptr);
    ~Dialog_SerialSync();

signals:
    void connected(const vs_pkt_t &pkt);  // not used
    void myplcChanged();


public slots:

    void serialBegin(const QString com);    // Start handshake

    void serialEnd();

    void serialError(QSerialPort::SerialPortError error);
    void serialProtocolError(QString error);

    void updateLabels(const vs_info_t &infos);

    void on_buttonBox_clicked(QAbstractButton *button);


    void onReceive();

private:
    bool onConnect(const vs_pkt_t &pkt);

    void sendPacket(vs_pkt_t *pkt);

    MyPlcDevice *l_device = nullptr; //
    bool l_rwcmd;

    Ui::Dialog_SerialSync *ui;

    QSerialPort *l_serial = nullptr;
    bool l_connected = false;

    int pb_max;         // ProgressBar
    int pb_count;



    bool receiveddata = false;


};

#endif // DIALOG_SERIALRETRIVE_H




