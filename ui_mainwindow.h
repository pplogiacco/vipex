/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAddModule;
    QAction *actionQuit;
    QAction *actionFileOpen;
    QAction *actionFileSave;
    QAction *actionFileSaveAs;
    QAction *actionAbout;
    QAction *actionSerialConnect;
    QAction *actionFlash_Nanoboard;
    QAction *actionClean;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QTreeView *treeView;
    QWidget *tab2;
    QListView *ruleList;
    QWidget *tab3;
    QTreeView *View;
    QGroupBox *groupBox_2;
    QLabel *lb_hardware;
    QLabel *label_3;
    QLabel *lb_cycle;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label;
    QLabel *lb_memory;
    QLabel *lb_firmware;
    QLabel *label_11;
    QLabel *lb_serial;
    QLabel *label_12;
    QLabel *lb_status;
    QGroupBox *groupBox_3;
    QLabel *label_2;
    QLabel *lb_filename;
    QLabel *lb_datetime;
    QLabel *label_13;
    QLabel *lb_title;
    QLabel *label_14;
    QGroupBox *groupBox_4;
    QLabel *lb_modules;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *lb_pin;
    QLabel *lb_rules;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *lb_pout;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuTools;
    QMenu *menuMyPlc;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(669, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(600, 500));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/ic_green.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionAddModule = new QAction(MainWindow);
        actionAddModule->setObjectName(QString::fromUtf8("actionAddModule"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/addmodule.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddModule->setIcon(icon1);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon2);
        actionFileOpen = new QAction(MainWindow);
        actionFileOpen->setObjectName(QString::fromUtf8("actionFileOpen"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/f_open2.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8("images/open.png"), QSize(), QIcon::Normal, QIcon::On);
        actionFileOpen->setIcon(icon3);
        actionFileSave = new QAction(MainWindow);
        actionFileSave->setObjectName(QString::fromUtf8("actionFileSave"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/f_save.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8("images/save (2).png"), QSize(), QIcon::Normal, QIcon::On);
        actionFileSave->setIcon(icon4);
        actionFileSaveAs = new QAction(MainWindow);
        actionFileSaveAs->setObjectName(QString::fromUtf8("actionFileSaveAs"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/f_save_as.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8("images/save_as (2).png"), QSize(), QIcon::Normal, QIcon::On);
        actionFileSaveAs->setIcon(icon5);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionSerialConnect = new QAction(MainWindow);
        actionSerialConnect->setObjectName(QString::fromUtf8("actionSerialConnect"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSerialConnect->setIcon(icon6);
        actionFlash_Nanoboard = new QAction(MainWindow);
        actionFlash_Nanoboard->setObjectName(QString::fromUtf8("actionFlash_Nanoboard"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/ic_flash.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFlash_Nanoboard->setIcon(icon7);
        actionClean = new QAction(MainWindow);
        actionClean->setObjectName(QString::fromUtf8("actionClean"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClean->setIcon(icon8);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 491, 401));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 20, 491, 380));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(200, 50));
        tabWidget->setMaximumSize(QSize(600, 380));
        tabWidget->setIconSize(QSize(18, 17));
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        treeView = new QTreeView(tab1);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(10, 10, 471, 331));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/cbreak.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab1, icon9, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        ruleList = new QListView(tab2);
        ruleList->setObjectName(QString::fromUtf8("ruleList"));
        ruleList->setGeometry(QRect(0, 0, 481, 351));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("images/lamp.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab2, icon10, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QString::fromUtf8("tab3"));
        View = new QTreeView(tab3);
        View->setObjectName(QString::fromUtf8("View"));
        View->setGeometry(QRect(10, 10, 451, 321));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("images/runner.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab3, icon11, QString());
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(510, 120, 151, 161));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        groupBox_2->setFont(font);
        lb_hardware = new QLabel(groupBox_2);
        lb_hardware->setObjectName(QString::fromUtf8("lb_hardware"));
        lb_hardware->setGeometry(QRect(110, 30, 31, 20));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        lb_hardware->setFont(font1);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 91, 16));
        lb_cycle = new QLabel(groupBox_2);
        lb_cycle->setObjectName(QString::fromUtf8("lb_cycle"));
        lb_cycle->setGeometry(QRect(110, 110, 31, 21));
        lb_cycle->setFont(font1);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 90, 91, 16));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 110, 91, 20));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 91, 16));
        lb_memory = new QLabel(groupBox_2);
        lb_memory->setObjectName(QString::fromUtf8("lb_memory"));
        lb_memory->setGeometry(QRect(110, 90, 31, 20));
        lb_memory->setFont(font1);
        lb_firmware = new QLabel(groupBox_2);
        lb_firmware->setObjectName(QString::fromUtf8("lb_firmware"));
        lb_firmware->setGeometry(QRect(110, 50, 31, 20));
        lb_firmware->setFont(font1);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 70, 91, 16));
        lb_serial = new QLabel(groupBox_2);
        lb_serial->setObjectName(QString::fromUtf8("lb_serial"));
        lb_serial->setGeometry(QRect(110, 70, 31, 20));
        lb_serial->setFont(font1);
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 130, 91, 21));
        lb_status = new QLabel(groupBox_2);
        lb_status->setObjectName(QString::fromUtf8("lb_status"));
        lb_status->setGeometry(QRect(110, 130, 31, 20));
        lb_status->setFont(font1);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(510, 10, 151, 101));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 51, 21));
        lb_filename = new QLabel(groupBox_3);
        lb_filename->setObjectName(QString::fromUtf8("lb_filename"));
        lb_filename->setGeometry(QRect(40, 70, 111, 20));
        lb_filename->setFont(font1);
        lb_datetime = new QLabel(groupBox_3);
        lb_datetime->setObjectName(QString::fromUtf8("lb_datetime"));
        lb_datetime->setGeometry(QRect(60, 50, 91, 20));
        lb_datetime->setFont(font1);
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 50, 51, 21));
        lb_title = new QLabel(groupBox_3);
        lb_title->setObjectName(QString::fromUtf8("lb_title"));
        lb_title->setGeometry(QRect(50, 30, 101, 20));
        lb_title->setFont(font1);
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 30, 51, 21));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(510, 290, 151, 121));
        lb_modules = new QLabel(groupBox_4);
        lb_modules->setObjectName(QString::fromUtf8("lb_modules"));
        lb_modules->setGeometry(QRect(110, 30, 31, 21));
        lb_modules->setFont(font1);
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 70, 91, 16));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 30, 91, 16));
        lb_pin = new QLabel(groupBox_4);
        lb_pin->setObjectName(QString::fromUtf8("lb_pin"));
        lb_pin->setGeometry(QRect(110, 50, 31, 21));
        lb_pin->setFont(font1);
        lb_rules = new QLabel(groupBox_4);
        lb_rules->setObjectName(QString::fromUtf8("lb_rules"));
        lb_rules->setGeometry(QRect(110, 90, 31, 21));
        lb_rules->setFont(font1);
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 50, 91, 16));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 90, 101, 20));
        lb_pout = new QLabel(groupBox_4);
        lb_pout->setObjectName(QString::fromUtf8("lb_pout"));
        lb_pout->setGeometry(QRect(110, 70, 31, 21));
        lb_pout->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 669, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuMyPlc = new QMenu(menubar);
        menuMyPlc->setObjectName(QString::fromUtf8("menuMyPlc"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuMyPlc->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionFileOpen);
        menuFile->addAction(actionFileSave);
        menuFile->addAction(actionFileSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionAbout);
        menuTools->addSeparator();
        menuTools->addSeparator();
        menuTools->addAction(actionFlash_Nanoboard);
        menuMyPlc->addAction(actionAddModule);
        menuMyPlc->addSeparator();
        menuMyPlc->addAction(actionSerialConnect);
        toolBar->addAction(actionFileOpen);
        toolBar->addAction(actionFileSave);
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addAction(actionSerialConnect);
        toolBar->addSeparator();
        toolBar->addAction(actionAddModule);
        toolBar->addSeparator();
        toolBar->addAction(actionClean);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAddModule->setText(QCoreApplication::translate("MainWindow", "Aggiungi Nuovo Modulo", nullptr));
#if QT_CONFIG(tooltip)
        actionAddModule->setToolTip(QCoreApplication::translate("MainWindow", "Aggiungi Modulo ", nullptr));
#endif // QT_CONFIG(tooltip)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Esci", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFileOpen->setText(QCoreApplication::translate("MainWindow", "Apri...", nullptr));
        actionFileSave->setText(QCoreApplication::translate("MainWindow", "Salva", nullptr));
#if QT_CONFIG(shortcut)
        actionFileSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFileSaveAs->setText(QCoreApplication::translate("MainWindow", "Salva come...", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "Informazioni", nullptr));
        actionSerialConnect->setText(QCoreApplication::translate("MainWindow", "&Collega", nullptr));
#if QT_CONFIG(tooltip)
        actionSerialConnect->setToolTip(QCoreApplication::translate("MainWindow", "Connessione a unit\303\240 MyPlc", nullptr));
#endif // QT_CONFIG(tooltip)
        actionFlash_Nanoboard->setText(QCoreApplication::translate("MainWindow", "Flash Nanoboard", nullptr));
        actionClean->setText(QCoreApplication::translate("MainWindow", "actionClean", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Configurazione", nullptr));
#if QT_CONFIG(accessibility)
        tab1->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        tabWidget->setTabText(tabWidget->indexOf(tab1), QCoreApplication::translate("MainWindow", "Moduli e Porte", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QCoreApplication::translate("MainWindow", "Porte attive", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab3), QCoreApplication::translate("MainWindow", "Regole", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Dispositivo", nullptr));
        lb_hardware->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Firmware.........:", nullptr));
        lb_cycle->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Memoria..........:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Ciclo (ms)........:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Hardware.........: ", nullptr));
        lb_memory->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        lb_firmware->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Serial.............:", nullptr));
        lb_serial->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Stato MyPlc.....:", nullptr));
        lb_status->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Progetto", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "File:", nullptr));
        lb_filename->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        lb_datetime->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Modifica:", nullptr));
        lb_title->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Titolo:", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Configurazione", nullptr));
        lb_modules->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Porte OUT.......:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Moduli ............:", nullptr));
        lb_pin->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        lb_rules->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Porte IN..........:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Regole...........:", nullptr));
        lb_pout->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Aiuto", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Strumenti", nullptr));
        menuMyPlc->setTitle(QCoreApplication::translate("MainWindow", "MyPlc", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
