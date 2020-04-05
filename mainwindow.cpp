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

#include "dialog_addmodule.h"
#include "dialog_editport.h"
#include "dialog_editmodule.h"
#include "dialog_serial.h"

MainWindow::MainWindow(QWidget *parent)  :
            QMainWindow(parent),
            m_ui(new Ui::MainWindow),
            m_status(new QLabel),
            m_myplc(new MyPlcModel())
{

    // General
    m_ui->setupUi(this);

    setWindowTitle(tr("MyPlc"));
    const QSize availableSize = screen()->availableGeometry().size();
    resize(availableSize.width() / 2, availableSize.height() / 2);

    m_ui->statusbar->addWidget(m_status);
    statusBar()->showMessage(tr("Ready"));


    //  m_ui->myplcTree->setMyPlc(m_myplc);  // Set working data
    //  m_ui->myplcTree->Inizialize();
    // m_ui->myplcTree->reloadItems();          // create Items

    MyPlcModel *model = new MyPlcModel(m_myplc);
    m_ui->View->setModel(model);

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
    connect(m_ui->actionAddModule, &QAction::triggered, this, &MainWindow::addModule);
    connect(m_ui->actionSerialConnect, &QAction::triggered, this, &MainWindow::serialLink);
    //connect(m_ui->actionClean, &QAction::triggered, this, &MainWindow::myplcClean);


    // MyPlcTree
    // m_ui->myplcTree->setContextMenuPolicy(Qt::CustomContextMenu);  // Qt::ActionsContextMenu
    // connect(m_ui->myplcTree, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onCustomContextMenu(const QPoint &)));
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


// ***************************************************************************************
//                                                                                 F I L E
// ***************************************************************************************
//
//
void MainWindow::fileOpen()
{
    m_filename = QFileDialog::getOpenFileName(this, tr("Apri file"),
                                                    QDir::currentPath(), tr("MyPlc Files (*.plc)"));
    if (m_filename.isEmpty()) return;

    QFile file(m_filename);

    if (!file.open(QFile::ReadOnly)) {
        QMessageBox::warning(this, tr("Apri file"),
                                   tr("Impossibile leggere %1:\n%2.").arg(QDir::toNativeSeparators(m_filename),
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
                             .arg(QDir::toNativeSeparators(m_filename),
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
    m_myplc->loadData(&in);
    //*free(cbuf);
    //*refreshTree();  // Aggiorna interfaccia

    statusBar()->showMessage(tr("File loaded"), 2000);
}


void MainWindow::save()
{
    QFile file(m_filename);
    if (!file.open(QFile::WriteOnly)) {
        QMessageBox::warning(this, tr("Salva file"), tr("Impossibile salvare il file %1:\n%2.")
                                  .arg(QDir::toNativeSeparators(m_filename), file.errorString()));
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
    m_myplc->saveData(&out);
    statusBar()->showMessage(tr("File saved"), 2000);
};

void MainWindow::fileSave()
{
    if ( this->m_filename.isEmpty() ) {
        fileSaveAs();
     } else save();
}

void MainWindow::fileSaveAs()
{
    this->m_filename = QFileDialog::getSaveFileName(this, tr("Salva file con nome"),
                                                    QDir::currentPath(),
                                                    tr("MyPlc Files (*.plc)"));
    save();
 }



// ***************************************************************************************
//                                                                             S E R I A L
// ***************************************************************************************


void MainWindow::serialLink()
{
    DialogSerial dia(m_myplc);
    connect(&dia, SIGNAL(myplcChanged()), this, SLOT(refreshTree()));
    dia.exec();

}




// ***************************************************************************************
//                                                                       M Y P L C T R E E
// ***************************************************************************************


void MainWindow::onCustomContextMenu(const QPoint &punto)
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
   refreshTree();
}

void MainWindow::addModule()
{
   DialogAddModule dia(m_myplc);
   connect(&dia, SIGNAL(myplcChanged()), this, SLOT(refreshTree()));
   dia.exec();
}





void MainWindow::editItem()
{
    DialogEditPort dia;
    dia.exec();
}



void MainWindow::on_myplcTree_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
}


void MainWindow::refreshTree()
{
        /*m_ui->treeView->reloadItems();

       //  vs_info_t * info = m_myplc->getInfo();
        m_ui->lb_hardware->setNum( info->hardware );
        m_ui->lb_firmware->setText(QStringLiteral("%1.%1").arg(info->firmware>>5).arg(info->firmware & 0x1F));
        m_ui->lb_memory->setNum( info->memory );
        m_ui->lb_cycle->setNum( info->cycle );
        m_ui->lb_modules->setNum( info->modules );
        m_ui->lb_pin->setNum( info->p_in );
        m_ui->lb_pout->setNum( info->p_out );
        m_ui->lb_rules->setNum( info->rules );
        */
}






void MainWindow::on_myplcTree_doubleClicked(const QModelIndex &index)
{



}
