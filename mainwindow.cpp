/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include <QString>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialog_editmodule.h"
#include "dialog_editport.h"
#include "dialog_deleteeditmodule.h"
#include "dialog_serialsync.h"

#include <QSerialPortInfo>


MainWindow::MainWindow(QWidget *parent)  :
            QMainWindow(parent),
            m_ui(new Ui::MainWindow),
            m_status(new QLabel)

{

    // General
    m_ui->setupUi(this);

    setWindowTitle(tr("MyPlc"));
    const QSize availableSize = screen()->availableGeometry().size();
    resize(availableSize.width() / 2, availableSize.height() / 2);

    // Serial

    cbxSerialPort_refresh();
    m_ui->mainToolBar->insertWidget(m_ui->actionRetrieve, &cbxSerialPort);

    //m_ui->actionRewrite->setEnabled(false);
    QWidget* empty = new QLabel("  ");
    //empty->setSizePolicy(QSizePolicy::Fixed);
    m_ui->mainToolBar->insertWidget(m_ui->actionRetrieve,empty);
    //m_ui->actionRetrieve->setEnabled(false);

   // connect(l_serial, &QSerialPort::errorOccurred, this, &MainWindow::serialError);
   // connect(l_serial, &QSerialPort::readyRead, this, &MainWindow::serialOnReceived);

    m_ui->statusbar->addWidget(m_status);
    statusBar()->showMessage(tr("Ready"));


    //  m_ui->myplcTree->setMyPlc(m_myplc);  // Set working data
    //  m_ui->myplcTree->Inizialize();
    // m_ui->myplcTree->reloadItems();          // create Items
    //MyPlcModel *model = new MyPlcModel(l_myplc);

 //   dmRules *dm_rules = new dmRules(); // su dati l_myplc1
 //   m_ui->viewRules->setModel(dm_rules);


    l_myplc = new MyPlcDevice(tr("MyPlc"));

    dm_modules = new dmModules(l_myplc);     // l_myplc DATAMODEL
    m_ui->viewModules->setModel(dm_modules);

    dmRules *dm_rules = new dmRules(l_myplc);     // l_myplc DATAMODEL
    m_ui->viewRules->setModel(dm_rules);

    //m_ui->viewModules->update();
    //connect(l_myplc, deviceChanged,this,SLOT(dm_modules->test()) );

    //delegate = QtGui.QStyledItemDelegate()
    //tree.setItemDelegate(delegate)


    // Generic
    connect(m_ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(m_ui->actionQuit, &QAction::triggered, this, &MainWindow::close);

    // Files
    connect(m_ui->actionFileOpen, &QAction::triggered, this, &MainWindow::fileOpen);
    connect(m_ui->actionFileSave, &QAction::triggered, this, &MainWindow::fileSave);
    connect(m_ui->actionFileSaveAs, &QAction::triggered, this, &MainWindow::fileSaveAs);

    // MyPlc
    // connect(m_ui->actionAddModule, &QAction::triggered, this, &MainWindow::addModule);
    //connect(m_ui->actionSerialConnect, &QAction::triggered, this, &MainWindow::serialSync);
    //connect(m_ui->actionClean, &QAction::triggered, this, &MainWindow::myplcClean);


    // viewModules
    m_ui->viewModules->setContextMenuPolicy(Qt::CustomContextMenu);  // Qt::ActionsContextMenu
    connect(m_ui->viewModules, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(viewModulesContextMenu(const QPoint &)));

    // m_ui->View->setContextMenuPolicy(Qt::CustomContextMenu);
    // connect(m_ui->View, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onCustomContextMenu(const QPoint &)));

}


MainWindow::~MainWindow()
{
    delete m_ui;
}


void MainWindow::showStatusMessage(const QString &message)
{
    m_status->setText(message);
}


void MainWindow::about()
{
   QMessageBox::about(this, tr("MyPlc "),
                      tr("<b>MyPlc</b> è una implementazione... "
                         "Paolo LG "));
}


void MainWindow::refresh()
{

      //  m_ui->viewModules->update(new QModelIndex());
      m_ui->viewModules->update();
      deviceInfos_refresh();

}



// ***************************************************************************************
//                                                                     S E R I A L S Y N C
// ***************************************************************************************


void MainWindow::cbxSerialPort_refresh()
{
    cbxSerialPort.clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        cbxSerialPort.addItem(info.portName());
}


void MainWindow::deviceInfos_refresh()
{
    itemdata_t dev = l_myplc->getDeviceItems()->getItemData();
    switch (dev.device.hardware) {
           case HW_NBV30:      // uC -> PC
                m_ui->lb_hardware->setText("NBv30");
                break;
    }
    m_ui->lb_firmware->setText(QStringLiteral("%1.%1").arg(_ByteVer(dev.device.firmware))
                                                    .arg(_ByteRel(dev.device.firmware)));
    m_ui->lb_serial->setNum(dev.device.serial);
    m_ui->lb_memory->setNum(dev.device.memory*1024);
    m_ui->lb_eprom->setNum(dev.device.eprom*1024);
    m_ui->lb_cycle->setNum(dev.device.cycle<<1 );
    m_ui->lb_modules->setNum(dev.device.modules );
    m_ui->lb_total->setNum(dev.device.p_in+dev.device.p_out);
    m_ui->lb_pin->setNum(dev.device.p_in );
    m_ui->lb_pout->setNum(dev.device.p_out );
    m_ui->lb_rules->setNum(dev.device.rules );
}


void MainWindow::on_actionRetrieve_triggered(bool checked)
{
    Dialog_SerialSync syncdiag(l_myplc,cbxSerialPort.currentText(),false);
    //connect(&syncdiag, SIGNAL(syncronized()), this, SLOT(refresh()));
    syncdiag.exec();
    refresh();

}

// ***************************************************************************************
//                                                                                 F I L E
// ***************************************************************************************
//
//
void MainWindow::fileOpen()
{
    l_filename = QFileDialog::getOpenFileName(this, tr("Apri file"),
                                                    QDir::currentPath(), tr("MyPlc Files (*.plc)"));
    if (l_filename.isEmpty()) return;

    QFile file(l_filename);

    if (!file.open(QFile::ReadOnly)) {
        QMessageBox::warning(this, tr("Apri file"),
                                   tr("Impossibile leggere %1:\n%2.").arg(QDir::toNativeSeparators(l_filename),
                                   file.errorString()));
        return;
    }

    QDataStream in(&file);

    // Read and check the header
    quint32 magic;
    in >> magic;
    qint32 version;
    in >> version;      // Read the version

    if (magic != 0xA0B0C0D0) {
                             QMessageBox::warning(this, tr("Apri file"),
                             tr("Versione file non compatibile %1:\n%2.")
                             .arg(QDir::toNativeSeparators(l_filename),
                                  file.errorString()));
        return; // XXX_BAD_FILE_FORMAT;
     }

    //if (version < 100)
    //    return; // XXX_BAD_FILE_TOO_OLD;
    //if (version > 123)
    //    return; // XXX_BAD_FILE_TOO_NEW;
    //if (version <= 110)
     //   in.setVersion(QDataStream::Qt_3_2);
    //else
     //   in.setVersion(QDataStream::Qt_4_0);


    // Read the data
    //*uint nbyte = sizeof(v_device_t);
    //*char *cbuf;
    //*cbuf = (char*)malloc(nbyte);
    //*in.readBytes(cbuf,nbyte);
    //* m_myplc->setMyPlc((v_device_t*)cbuf);
    // m_myplc->loadData(&in);
    //*free(cbuf);
    //*refreshTree();  // Aggiorna interfaccia

    statusBar()->showMessage(tr("File loaded"), 2000);
}

void MainWindow::save()
{
    QFile file(l_filename);
    if (!file.open(QFile::WriteOnly)) {
        QMessageBox::warning(this, tr("Salva file"), tr("Impossibile salvare il file %1:\n%2.")
                                  .arg(QDir::toNativeSeparators(l_filename), file.errorString()));
    return;
    }

    QDataStream out(&file);

    // Write a header with a "magic number" and a version
    out << (quint32)0xA0B0C0D0;
    out << (qint32)123;
    out.setVersion(QDataStream::Qt_4_0);

    // Write the data
    //*uint nbyte = sizeof(v_device_t);
    //*char *cbuf  = (char*)malloc(nbyte);
    //*memcpy(&(cbuf[0]), m_myplc->getMyPlc(), nbyte);
    //*out.writeBytes(cbuf,nbyte);
    //*free(cbuf);
    // !!! m_myplc->saveData(&out);
    statusBar()->showMessage(tr("File saved"), 2000);
};

void MainWindow::fileSave()
{
    if ( this->l_filename.isEmpty() ) {
        fileSaveAs();
     } else save();
}

void MainWindow::fileSaveAs()
{
    this->l_filename = QFileDialog::getSaveFileName(this, tr("Salva file con nome"),
                                                    QDir::currentPath(),
                                                    tr("MyPlc Files (*.plc)"));
    save();
 }


// ***************************************************************************************
//                                                            M O D E L S    E D I T I N G
// ***************************************************************************************


void MainWindow::viewModulesContextMenu(const QPoint &punto)
{
    //QActionGroup *alignmentGroup;
    QAction *edit;     // Port/Module
    edit = new QAction(tr("&Modifica"), this);
    edit->setShortcuts(QKeySequence::New);
    edit->setStatusTip(tr("Modifica elemento"));

    QAction *enable;   // enable/disable
    enable = new QAction(tr("&Abilita/Disabilita"), this);
    enable->setShortcuts(QKeySequence::New);
    enable->setStatusTip(tr("Abilita/Disabilita"));

    connect(edit, &QAction::triggered, this, &MainWindow::editItem);
    connect(enable, &QAction::triggered, this, &MainWindow::fileOpen);

    QMenu* contextMenu = new QMenu();

    contextMenu->addAction(edit);
    contextMenu->addSeparator();
    contextMenu->addAction(enable);

    QPoint disp;
    disp.setY(120);
    disp.setX(0);
    contextMenu->exec(pos()+ punto + disp);

}

void MainWindow::myplcClean()
{
   //m_myplc->deleteAllItems();
   // refreshTree();
}



void MainWindow::editItem()
{
                    //  dm_modules,


}


void MainWindow::on_actionSerialConnect_triggered(bool checked)
{
    QProcess process;
    process.start("C:\Program Files (x86)\Arduino\arduino.exe", QStringList() << "-V");

        /*
        proc.start(command, arguments);
        if(proc.waitForStarted())
        {
        qDebug() << "Starting";
        }
        proc.waitForFinished(-1);
        qDebug() << "finish";@
        */
}


void MainWindow::on_actionAddModule_triggered(bool checked)
{
    Dialog_EditModule diag(dm_modules);
    //connect(&syncdiag, SIGNAL(syncronized()), this, SLOT(refresh()));
    diag.exec();
    refresh();
}

void MainWindow::on_viewModules_doubleClicked(const QModelIndex &index)
{

    // Dialog_EditPort dialog(dm_modules, m_ui->viewModules->currentIndex() );
    // dialog.exec();

}
