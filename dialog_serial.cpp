#include "dialog_serial.h"
#include "ui_dialog_serial.h"

//#include <QIntValidator>
#include <QMessageBox>
#include <QSerialPortInfo>
#include <QScrollBar>


#include <QString>
#ifdef Q_OS_WIN
 #include <Windows.h>
#endif

#ifdef Q_OS_LINUX
#include "qtimer.h"
void Sleep(int nms)
{
    QTime t= QTime::currentTime().start();
    while (t.elapsed() < nms)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
#endif




DialogSerial::DialogSerial(MyPlcModel *myplc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSerial),
    l_serial(new QSerialPort),
    l_myplc(myplc)
{
    ui->setupUi(this);

    ui->pbConnect->setVisible(true);
    ui->pbDisconnect->setVisible(false);
    ui->pbRewrite->setEnabled(false);
    ui->pbRetrieve->setEnabled(false);

    ui->serialPortInfoListBox->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        ui->serialPortInfoListBox->addItem(info.portName());

    // connect(ui->PortListBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &DialogSerial::showPortInfo);

    connect(ui->pbConnect, SIGNAL(clicked()), this, SLOT(serialOpen()) );
    connect(ui->pbDisconnect, SIGNAL(clicked()), this, SLOT(serialClose()) );
    connect(l_serial, &QSerialPort::errorOccurred, this, &DialogSerial::serialError);
    connect(l_serial, &QSerialPort::readyRead, this, &DialogSerial::serialOnReceived);

    //connect(SIGNAL(connected()), SLOT(on_connected()) );

    ui->logBox->document()->setMaximumBlockCount(100);
    QPalette p = palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::green);
    ui->logBox->setReadOnly(true);
    ui->logBox->setPalette(p);

}



DialogSerial::~DialogSerial()
{
    delete l_serial;
    delete ui;
}


#define MAGIC_SERIAL "A"

void DialogSerial::serialOpen()
{
    l_serial->setPortName(ui->serialPortInfoListBox->currentText());
    l_serial->setBaudRate(QSerialPort::Baud57600);
    l_serial->setDataBits(QSerialPort::Data8);
    l_serial->setParity(QSerialPort::NoParity);
    l_serial->setStopBits(QSerialPort::OneStop);
    l_serial->setFlowControl(QSerialPort::NoFlowControl);
    //m_serial->setFlowControl( QSerialPort::HardwareControl );
    //m_ui->flowControlBox->addItem(tr("None"), QSerialPort::NoFlowControl);
    //m_ui->flowControlBox->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    //m_ui->flowControlBox->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);

    if (l_serial->open(QIODevice::ReadWrite)) {

        ui->pbConnect->setVisible(false);
        ui->pbDisconnect->setVisible(true);
        ui->selectBox->setEnabled(false);

        ui->logBox->insertPlainText( QStringLiteral("Try to connect on %1... \n").arg(ui->serialPortInfoListBox->currentText()) );
        l_serial->setDataTerminalReady(true);   // Reset Nanoboard
        Sleep(2);
        l_serial->setDataTerminalReady(false);
        Sleep(1500);                            // Set MyPlc in _VISIO_ mode
        l_serial->write(MAGIC_SERIAL);
        l_serial->waitForBytesWritten(1000);
        // wait response...
        // io ok return true else false...

    } else {
        QMessageBox::critical(this, tr("Errore:"), l_serial->errorString());
    }
}





void DialogSerial::serialOnReceived()
{
    char indata[_VS_PKT_SIZE];

    if( l_serial->read(indata,_VS_PKT_SIZE) == _VS_PKT_SIZE ) {

        vs_pkt_t pkt;
        memcpy(&(pkt.cmd), &(indata[0]), _VS_PKT_SIZE);

        switch ( pkt.cmd  )
        {
                 case _RETRIEVE:      // uC -> PC
                      break;

                 case _INFO:          // Get uC detailst  
                       ui->logBox->insertPlainText( QStringLiteral("rcv _INFO \n") );
                       l_myplc->setDeviceInfo(pkt.info);

                       on_receivedINFO();
                      break;

                 case _MODULE:        // Trasfer module
                        ui->logBox->insertPlainText( QStringLiteral("rcv _MODULE \n") );
                        l_myplc->setModule(pkt.module);
                        receiveddata = true;
                      break;

                 case _PORT:          // Trasfer port
                        ui->logBox->insertPlainText(  QStringLiteral("rcv _PORT: \n") );
                        l_myplc->setPort(pkt.port);
                      break;

                 case _RULE:           // Trasfer rule
                        ui->logBox->insertPlainText(  QStringLiteral("rcv _RULE \n") );
                        l_myplc->setRule(pkt.rule);
                      break;
        } // switch

    } else {
        serialProtocolError("Invalid packet ! ");
    }
}



void DialogSerial::serialClose()
{
    if (l_serial->isOpen())
        l_serial->close();

    ui->pbConnect->setVisible(true);
    ui->pbDisconnect->setVisible(false);
    ui->selectBox->setEnabled(true);

    //if (receiveddata)
    //         emit myplcChanged();
}



void DialogSerial::serialProtocolError(QString error)
{
        QMessageBox::critical(this,tr("Critical Error"), error);
        // serialClose();
}


void DialogSerial::serialError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), l_serial->errorString());
        serialClose();
    }
}


void DialogSerial::updateLabels(const vs_info_t &infos)
{
    ui->lb_hardware->setNum( infos.hardware );
    ui->lb_firmware->setText(QStringLiteral("%1.%1").arg(infos.firmware>>5).arg(infos.firmware & 0x1F));
    ui->lb_memory->setNum( infos.memory );
    ui->lb_cycle->setNum( infos.cycle );
    ui->lb_modules->setNum( infos.modules );
    ui->lb_in->setNum( infos.p_in );
    ui->lb_out->setNum( infos.p_out );
    ui->lb_rules->setNum( infos.rules );
}



void DialogSerial::on_receivedINFO()
{
        //updateLabels( l_myplc->getDeviceInfo() );

        ui->logBox->insertPlainText(  QStringLiteral("Dispositivo MyPlc in linea !\n") );

        ui->pbRetrieve->setEnabled(true);
        ui->pbRewrite->setEnabled(true);
}



void DialogSerial::on_pbRetrieve_clicked()
{
    vs_pkt_t pkt;
    pkt.cmd = _RETRIEVE;
    sendPacket(&pkt);
}



void DialogSerial::on_pbRewrite_clicked()
{

 /*   l_myplc->rebuild(); // update wdatas

    vs_pkt_t pkt;
    pkt.cmd = _REWRITE;
    pkt.rewrite.mode = _VS_REWRITE_BEGIN;
    pkt.rewrite.nmo = l_myplc->device.wdatas.nmo;
    pkt.rewrite.npi = l_myplc->device.wdatas.npi;
    pkt.rewrite.npo = l_myplc->device.wdatas.npo;
    pkt.rewrite.nrl = l_myplc->device.wdatas.nrl;
    sendPacket(&pkt);

    // Send all enabled modules, ports and rules

     idx_t  i,j;
     pkt.cmd = _MODULE;
     for (i = 0; i < l_myplc->device.nModules; i++ )       // Renumber active modules
       if (  l_myplc->device.modules[i].enabled )
       {
        pkt.module.idx = l_myplc->device.modules[i].idx;
        pkt.module.mtype = l_myplc->device.modules[i].mtype;
        pkt.module.addr = l_myplc->device.modules[i].addr;
        sendPacket(&pkt);
       }


     pkt.cmd = _PORT;
     for (i = 0; i < l_myplc->device.nModules; i++ )        // Renumber active modules
         if ( l_myplc->device.modules[i].enabled ) {
             for (j = 0; j < l_myplc->device.modules[i].nports; j++ )
              if ( l_myplc->device.modules[i].ports[j].enabled && l_myplc->device.modules[i].ports[j].io )         // Only In enabled ports
              {
                pkt.port.io = In;
                pkt.port.imodule = l_myplc->device.modules[i].idx;
                pkt.port.subaddr = l_myplc->device.modules[i].ports[j].subaddr;
                pkt.port.ptype =  l_myplc->device.modules[i].ports[j].ptype;
                pkt.port.defval =  l_myplc->device.modules[i].ports[j].defval;
                sendPacket(&pkt);
              }
          }

     pkt.cmd = _PORT;
     for (i = 0; i < l_myplc->device.nModules; i++ )        // Renumber active modules
         if ( l_myplc->device.modules[i].enabled ) {
             for (j = 0; j < l_myplc->device.modules[i].nports; j++ )
              if ( l_myplc->device.modules[i].ports[j].enabled && !l_myplc->device.modules[i].ports[j].io ) {         // Only In enabled ports
                pkt.port.io = Out;
                pkt.port.imodule = l_myplc->device.modules[i].idx;
                pkt.port.subaddr = l_myplc->device.modules[i].ports[j].subaddr;
                pkt.port.ptype =  l_myplc->device.modules[i].ports[j].ptype;
                pkt.port.defval =  l_myplc->device.modules[i].ports[j].defval;
                ui->logBox->insertPlainText(  QStringLiteral("snd _PORT \n") );
                sendPacket(&pkt);
              }
         }


     pkt.cmd = _RULE;
     for (i = 0; i < l_myplc->device.nRules; i++ ) {      // Reassign rules port's idx
         if ( l_myplc->device.rules[i].enabled ) {
            pkt.rule.rl = l_myplc->device.rules[i].rl;
            pkt.rule.pin = l_myplc->device.rules[i].pi.iport;
            pkt.rule.pout = l_myplc->device.rules[i].po.iport;
            ui->logBox->insertPlainText(  QStringLiteral("snd _RULE \n") );
            sendPacket(&pkt);
         }
     }

    // ----------------------------

    pkt.cmd = _REWRITE;
    pkt.rewrite.mode = _VS_REWRITE_END;
    sendPacket(&pkt);
*/
}



bool DialogSerial::sendPacket(vs_pkt_t *pkt)
{
   char *outdata = (char*) pkt;
   l_serial->write(outdata,_VS_PKT_SIZE);
   l_serial->flush();
   l_serial->waitForBytesWritten(500);
   return (true);
}



void DialogSerial::on_buttonBox_clicked(QAbstractButton *button)
{
    // BTN: Close
    serialClose();
    ui->logBox->clear();
    ui->pbConnect->setEnabled(true);
    ui->pbRetrieve->setEnabled(false);
    ui->selectBox->setEnabled(true);
    this->close();
}


