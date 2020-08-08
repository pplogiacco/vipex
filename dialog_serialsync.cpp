#include "dialog_serialsync.h"
#include "ui_dialog_serialsync.h"

#include <QMessageBox>
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

#define MAGIC_SERIAL "A"


Dialog_SerialSync::Dialog_SerialSync(MyPlcDevice *myplc, const QString comport, const bool rwcmd, QWidget *parent) :
    QDialog(parent),
    l_device(myplc),    
    l_rwcmd(rwcmd),
    ui(new Ui::Dialog_SerialSync)
{
    ui->setupUi(this);
    l_serial = new QSerialPort();

    // Events

    connect(l_serial, &QSerialPort::errorOccurred, this, &Dialog_SerialSync::serialError);
    connect(l_serial, &QSerialPort::readyRead, this, &Dialog_SerialSync::onReceive);
    // connect(this,SIGNAL(connected(&p)),this,SLOT(onConnect(&p)));

    // Log
    ui->logBox->document()->setMaximumBlockCount(100);
    QPalette p = palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::green);
    ui->logBox->setReadOnly(true);
    ui->logBox->setPalette(p);

    serialBegin(comport);   // Start handshake

}



Dialog_SerialSync::~Dialog_SerialSync()
{
    delete l_serial;
    delete ui;
}


void Dialog_SerialSync::serialBegin(const QString com)
{
    l_serial->setPortName(com);
    l_serial->setBaudRate(QSerialPort::Baud57600);
    l_serial->setDataBits(QSerialPort::Data8);
    l_serial->setParity(QSerialPort::NoParity);
    l_serial->setStopBits(QSerialPort::OneStop);
    l_serial->setFlowControl(QSerialPort::NoFlowControl);
    //m_serial->setFlowControl( QSerialPort::HardwareControl );
    //ui->flowControlBox->addItem(tr("None"), QSerialPort::NoFlowControl);
    //ui->flowControlBox->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    //ui->flowControlBox->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);

    if (l_serial->open(QIODevice::ReadWrite)) {

        ui->logBox->insertPlainText( QStringLiteral("Cerca dispositivo su %1... \n").arg(com) );
        l_serial->setDataTerminalReady(true);   // Reset Nanoboard
        Sleep(2);                               // few time
        l_serial->setDataTerminalReady(false);
        //Sleep(1500);                            // Wait to restart and send MAGIC to set _VISIO_ mode
        Sleep(1800);
        l_serial->write(MAGIC_SERIAL);
        l_serial->flush();                      // Ensure sending
        l_serial->waitForBytesWritten(1000);
                                                // Wait answare onSerialReceive...
    }   
    // start timer
}


void Dialog_SerialSync::onReceive()
{
    char indata[_VS_PKT_SIZE];
    itemdata_t rxopt;

    if( l_serial->read(indata,_VS_PKT_SIZE) == _VS_PKT_SIZE ) {

        vs_pkt_t pkt;
        memcpy(&(pkt.cmd), &(indata[0]), _VS_PKT_SIZE);

        switch ( pkt.cmd  )
        {
                 case _RETRIEVE:      // uC -> PC
                      break;

                 case _INFO: // DEVICE         // uC connected !!
                      ui->logBox->insertPlainText( QStringLiteral("rcv _INFO \n") );

                      if (!l_connected)

                          if ( onConnect(pkt) )
                           {
                             rxopt.type = DEVICE;
                             rxopt.device = pkt.info;
                             l_device->updateItem(rxopt); // SYNCDATA_T

                           }
                      break;

                 case _MODULE:        // Trasfer module
                      ui->logBox->insertPlainText( QStringLiteral("rcv _MODULE \n") );
                      if (l_connected)
                      {
                      pb_count++;
                      ui->pBar->setValue(pb_count);
                      rxopt.type = MODULE;
                      rxopt.module = pkt.module;
                      if ( l_device->updateItem(rxopt) ) // SYNCDATA_T
                      {
                         ui->logBox->insertPlainText( QStringLiteral("Update module %1 (%2)\n").arg(rxopt.module.mtype).arg(rxopt.module.maddr) );
                      } else {
                         ui->logBox->insertPlainText( QStringLiteral("Error: module %1 (%2)\n").arg(rxopt.module.mtype).arg(rxopt.module.maddr) );
                      }
                      }
                      break;

                 case _PORT:          // Trasfer port
                      ui->logBox->insertPlainText(  QStringLiteral("rcv _PORT: \n") );
                      if (l_connected)
                      {
                      pb_count++;
                      ui->pBar->setValue(pb_count);
                      rxopt.type = PORT;
                      rxopt.port = pkt.port;

                      if ( l_device->updateItem(rxopt) ) // SYNCDATA_T
                      {
                           ui->logBox->insertPlainText( QStringLiteral("Update P%1 (mod:%2)\n").arg(rxopt.port.paddr).arg(rxopt.port.imod) );
                      } else {
                          ui->logBox->insertPlainText( QStringLiteral("Error: P%1 (mod:%2)\n").arg(rxopt.port.paddr).arg(rxopt.port.imod) );
                      }
                      }
                      break;

                 case _RULE:           // Trasfer rule
                      ui->logBox->insertPlainText(  QStringLiteral("rcv _RULE \n") );
                      if (l_connected)
                      {
                      pb_count++;
                      ui->pBar->setValue(pb_count);
                      rxopt.type = RULE;
                      rxopt.rule = pkt.rule;
                      l_device->updateItem(rxopt);  // SYNCDATA_T
                      }
                      break;

                 case _COMPLETE:
                      ui->logBox->insertPlainText(  QStringLiteral("rcv _COMPLETE \n") );
                      // Procedure completed;
                      l_device->syncComplete(l_rwcmd);
                      break;
        } // switch
    } // Packet

    if( l_serial->bytesAvailable() >= _VS_PKT_SIZE )
        onReceive();
}


bool Dialog_SerialSync::onConnect(const vs_pkt_t &pkt)
{
    l_connected = true;
    bool sync = true;

    if ( ! l_device->syncIsDevice(pkt.info) )  // compare devices received and local device info
    {
     sync = false;
     QMessageBox msgBox;
     msgBox.setText(tr("Dispositivo Hw: %1: ,Fw: %2, Ser: %3").arg(pkt.info.hardware).arg(pkt.info.firmware).arg(pkt.info.serial));
     msgBox.setInformativeText("Vuoi sincronizzazre ugualmente ?");
     msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
     msgBox.setDefaultButton(QMessageBox::Yes);

      if ( msgBox.exec() == QMessageBox::Yes )
       {
        updateLabels( pkt.info );
        if ( l_rwcmd )  // REwrite
          {
              pb_max = l_device->itemCount();
              pb_count = 0;
              ui->pBar->setRange(pb_count,pb_max);
              ui->pBar->setValue(pb_count);

          } else {    // Retrieve

              pb_max = pkt.info.modules + pkt.info.p_in +pkt.info.p_out + pkt.info.rules;
              pb_count = 0;
              ui->pBar->setRange(pb_count,pb_max);
              ui->pBar->setValue(pb_count);
              ui->pBar->reset();

              vs_pkt_t cmd;
              cmd.cmd = _RETRIEVE;
              sendPacket(&cmd);
          }
        sync = true;
       } // ok sync
    } // in-sync
  return (sync);
}


void Dialog_SerialSync::sendPacket(vs_pkt_t *pkt)
{
   char *outdata = (char*) pkt;
   l_serial->write(outdata,_VS_PKT_SIZE);
   l_serial->flush();
   l_serial->waitForBytesWritten(500);
}


void Dialog_SerialSync::serialEnd()
{
    if (l_serial->isOpen())
        l_serial->close();
}


void Dialog_SerialSync::serialProtocolError(QString error)
{
        QMessageBox::critical(this,tr("Critical Error"), error);
        // serialClose();
}


void Dialog_SerialSync::serialError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), l_serial->errorString());
        serialEnd();
    }
}


void Dialog_SerialSync::updateLabels(const vs_info_t &dev)
{

    switch (dev.hardware) {
           case HW_NBV30:      // uC -> PC
                ui->lb_hardware->setText("NBv30");
                break;
    }
    ui->lb_firmware->setText(QStringLiteral("%1.%1").arg(_ByteVer(dev.firmware))
                                                    .arg(_ByteRel(dev.firmware)));
    ui->lb_serial->setNum(dev.serial);
    ui->lb_memory->setNum(dev.memory*1024);
    ui->lb_eeprom->setNum(dev.eprom*1024);
    ui->lb_cycle->setNum(dev.cycle<<1 );
    ui->lb_modules->setNum(dev.modules );
    ui->lb_total->setNum(dev.p_in+dev.p_out);
    ui->lb_in->setNum( dev.p_in );
    ui->lb_out->setNum( dev.p_out );
    ui->lb_rules->setNum( dev.rules );
}







 /*

void DialogSerialSync::cmdRewrite()
{

   l_device->rebuild(); // update wdatas

    vs_pkt_t pkt;
    pkt.cmd = _REWRITE;
    pkt.rewrite.mode = _VS_REWRITE_BEGIN;
    pkt.rewrite.nmo = l_device->device.wdatas.nmo;
    pkt.rewrite.npi = l_device->device.wdatas.npi;
    pkt.rewrite.npo = l_device->device.wdatas.npo;
    pkt.rewrite.nrl = l_device->device.wdatas.nrl;
    sendPacket(&pkt);

    // Send all enabled modules, ports and rules

     idx_t  i,j;
     pkt.cmd = _MODULE;
     for (i = 0; i < l_device->device.nModules; i++ )       // Renumber active modules
       if (  l_device->device.modules[i].enabled )
       {
        pkt.module.idx = l_device->device.modules[i].idx;
        pkt.module.mtype = l_device->device.modules[i].mtype;
        pkt.module.addr = l_device->device.modules[i].addr;
        sendPacket(&pkt);
       }


     pkt.cmd = _PORT;
     for (i = 0; i < l_device->device.nModules; i++ )        // Renumber active modules
         if ( l_device->device.modules[i].enabled ) {
             for (j = 0; j < l_device->device.modules[i].nports; j++ )
              if ( l_device->device.modules[i].ports[j].enabled && l_device->device.modules[i].ports[j].io )         // Only In enabled ports
              {
                pkt.port.io = In;
                pkt.port.imodule = l_device->device.modules[i].idx;
                pkt.port.subaddr = l_device->device.modules[i].ports[j].subaddr;
                pkt.port.ptype =  l_device->device.modules[i].ports[j].ptype;
                pkt.port.defval =  l_device->device.modules[i].ports[j].defval;
                sendPacket(&pkt);
              }
          }

     pkt.cmd = _PORT;
     for (i = 0; i < l_device->device.nModules; i++ )        // Renumber active modules
         if ( l_device->device.modules[i].enabled ) {
             for (j = 0; j < l_device->device.modules[i].nports; j++ )
              if ( l_device->device.modules[i].ports[j].enabled && !l_device->device.modules[i].ports[j].io ) {         // Only In enabled ports
                pkt.port.io = Out;
                pkt.port.imodule = l_device->device.modules[i].idx;
                pkt.port.subaddr = l_device->device.modules[i].ports[j].subaddr;
                pkt.port.ptype =  l_device->device.modules[i].ports[j].ptype;
                pkt.port.defval =  l_device->device.modules[i].ports[j].defval;
                ui->logBox->insertPlainText(  QStringLiteral("snd _PORT \n") );
                sendPacket(&pkt);
              }
         }


     pkt.cmd = _RULE;
     for (i = 0; i < l_device->device.nRules; i++ ) {      // Reassign rules port's idx
         if ( l_device->device.rules[i].enabled ) {
            pkt.rule.rl = l_device->device.rules[i].rl;
            pkt.rule.pin = l_device->device.rules[i].pi.iport;
            pkt.rule.pout = l_device->device.rules[i].po.iport;
            ui->logBox->insertPlainText(  QStringLiteral("snd _RULE \n") );
            sendPacket(&pkt);
         }
     }

    // ----------------------------

    pkt.cmd = _REWRITE;
    pkt.rewrite.mode = _VS_REWRITE_END;
    sendPacket(&pkt);

}

*/


/* SERIAL MAIN WINDOWS




void MainWindow::serialError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), l_serial->errorString());
        serialClose();
    }
}


#define MAGIC_SERIAL "A"

bool MainWindow::serialOpen()
{
    l_serial->setPortName(cbxSerialPort->currentText());
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
        //ui->logBox->insertPlainText( QStringLiteral("Try to connect on %1... \n").arg(ui->serialPortInfoListBox->currentText()) );
        l_serial->setDataTerminalReady(true);   // Reset Nanoboard
        Sleep(2);
        l_serial->setDataTerminalReady(false);
        Sleep(1500);                            // Set MyPlc in _VISIO_ mode
        l_serial->write(MAGIC_SERIAL);
        l_serial->waitForBytesWritten(1000);
        // wait response...
        // io ok return true else false...
        return (true);
    } else {
        // QMessageBox::critical(this, tr("Errore:"), l_serial->errorString());
        return (false);
    }
}


void MainWindow::serialClose()
{
    if (l_serial->isOpen())
        l_serial->close();

   // ui->pbConnect->setVisible(true);
   // ui->pbDisconnect->setVisible(false);
   // ui->selectBox->setEnabled(true);
}


bool MainWindow::serialSendPacket(vs_pkt_t *pkt)
{
   char *outdata = (char*) pkt;
   l_serial->write(outdata,_VS_PKT_SIZE);
   l_serial->flush();
   l_serial->waitForBytesWritten(500);
   return (true);
}


void MainWindow::on_actionConnect_triggered(bool checked)
{
    if ( checked )  // Connect
    {
        if ( serialOpen() )
        {
           cbxSerialPort->setEnabled(false);
           m_ui->actionRewrite->setEnabled(true);
           m_ui->actionRetrieve->setEnabled(true);
           // Try to connect
        }

    } else {    // Disconnect

     // serial CLose
     serialClose();
     cbxSerialPort->setEnabled(true);
     m_ui->actionRewrite->setEnabled(false);
     m_ui->actionRetrieve->setEnabled(false);

    }

}


*/




void Dialog_SerialSync::on_buttonBox_clicked(QAbstractButton *button)
{
    // emit ....
    serialEnd();
    this->close();
}
