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
    QAction *actionRetrieve;
    QAction *actionRewrite;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *lb_alias;
    QLabel *label_14;
    QLabel *label_2;
    QLabel *lb_filename;
    QLabel *label_12;
    QLabel *lb_status;
    QTabWidget *tabView;
    QWidget *tab1;
    QGroupBox *groupBox_2;
    QLabel *lb_hardware;
    QLabel *label_3;
    QLabel *lb_cycle;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label;
    QLabel *lb_eprom;
    QLabel *lb_firmware;
    QLabel *label_11;
    QLabel *lb_serial;
    QLabel *lb_memory;
    QLabel *label_10;
    QLabel *lb_rules;
    QLabel *label_9;
    QLabel *lb_modules;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *lb_pout;
    QLabel *label_4;
    QLabel *lb_total;
    QLabel *label_15;
    QLabel *lb_pin;
    QGroupBox *groupBox_5;
    QLabel *lb_modules_2;
    QLabel *label_13;
    QLabel *label_16;
    QLabel *lb_pin_2;
    QLabel *lb_rules_2;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *lb_pout_2;
    QLabel *lb_total_2;
    QLabel *label_19;
    QWidget *tab2;
    QTreeView *viewModules;
    QWidget *tab3;
    QTreeView *viewRules;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuTools;
    QMenu *menuMyPlc;
    QStatusBar *statusbar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 509);
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
        icon6.addFile(QString::fromUtf8("images/serial5.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        actionRetrieve = new QAction(MainWindow);
        actionRetrieve->setObjectName(QString::fromUtf8("actionRetrieve"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("images/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRetrieve->setIcon(icon9);
        actionRewrite = new QAction(MainWindow);
        actionRewrite->setObjectName(QString::fromUtf8("actionRewrite"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("images/down-red.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRewrite->setIcon(icon10);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 581, 51));
        lb_alias = new QLabel(groupBox);
        lb_alias->setObjectName(QString::fromUtf8("lb_alias"));
        lb_alias->setGeometry(QRect(50, 20, 111, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lb_alias->setFont(font);
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 20, 51, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 20, 51, 21));
        lb_filename = new QLabel(groupBox);
        lb_filename->setObjectName(QString::fromUtf8("lb_filename"));
        lb_filename->setGeometry(QRect(210, 20, 91, 20));
        lb_filename->setFont(font);
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(320, 20, 41, 21));
        lb_status = new QLabel(groupBox);
        lb_status->setObjectName(QString::fromUtf8("lb_status"));
        lb_status->setGeometry(QRect(370, 20, 101, 20));
        lb_status->setFont(font);
        tabView = new QTabWidget(centralwidget);
        tabView->setObjectName(QString::fromUtf8("tabView"));
        tabView->setGeometry(QRect(10, 70, 581, 361));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabView->sizePolicy().hasHeightForWidth());
        tabView->setSizePolicy(sizePolicy1);
        tabView->setMinimumSize(QSize(200, 50));
        tabView->setMaximumSize(QSize(600, 380));
        tabView->setIconSize(QSize(18, 17));
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        groupBox_2 = new QGroupBox(tab1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 10, 161, 281));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        groupBox_2->setFont(font1);
        lb_hardware = new QLabel(groupBox_2);
        lb_hardware->setObjectName(QString::fromUtf8("lb_hardware"));
        lb_hardware->setGeometry(QRect(110, 20, 51, 20));
        lb_hardware->setFont(font);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 40, 91, 16));
        lb_cycle = new QLabel(groupBox_2);
        lb_cycle->setObjectName(QString::fromUtf8("lb_cycle"));
        lb_cycle->setGeometry(QRect(110, 120, 31, 21));
        lb_cycle->setFont(font);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 100, 91, 16));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 120, 91, 20));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 91, 16));
        lb_eprom = new QLabel(groupBox_2);
        lb_eprom->setObjectName(QString::fromUtf8("lb_eprom"));
        lb_eprom->setGeometry(QRect(110, 100, 31, 20));
        lb_eprom->setFont(font);
        lb_firmware = new QLabel(groupBox_2);
        lb_firmware->setObjectName(QString::fromUtf8("lb_firmware"));
        lb_firmware->setGeometry(QRect(110, 40, 51, 20));
        lb_firmware->setFont(font);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 60, 91, 16));
        lb_serial = new QLabel(groupBox_2);
        lb_serial->setObjectName(QString::fromUtf8("lb_serial"));
        lb_serial->setGeometry(QRect(110, 60, 51, 20));
        lb_serial->setFont(font);
        lb_memory = new QLabel(groupBox_2);
        lb_memory->setObjectName(QString::fromUtf8("lb_memory"));
        lb_memory->setGeometry(QRect(110, 80, 31, 20));
        lb_memory->setFont(font);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 80, 91, 16));
        lb_rules = new QLabel(groupBox_2);
        lb_rules->setObjectName(QString::fromUtf8("lb_rules"));
        lb_rules->setGeometry(QRect(110, 240, 31, 21));
        lb_rules->setFont(font);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 200, 91, 16));
        lb_modules = new QLabel(groupBox_2);
        lb_modules->setObjectName(QString::fromUtf8("lb_modules"));
        lb_modules->setGeometry(QRect(110, 160, 31, 21));
        lb_modules->setFont(font);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 240, 101, 20));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 220, 91, 16));
        lb_pout = new QLabel(groupBox_2);
        lb_pout->setObjectName(QString::fromUtf8("lb_pout"));
        lb_pout->setGeometry(QRect(110, 220, 31, 21));
        lb_pout->setFont(font);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 160, 91, 16));
        lb_total = new QLabel(groupBox_2);
        lb_total->setObjectName(QString::fromUtf8("lb_total"));
        lb_total->setGeometry(QRect(110, 180, 31, 21));
        lb_total->setFont(font);
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 180, 91, 16));
        lb_pin = new QLabel(groupBox_2);
        lb_pin->setObjectName(QString::fromUtf8("lb_pin"));
        lb_pin->setGeometry(QRect(110, 200, 31, 21));
        lb_pin->setFont(font);
        groupBox_5 = new QGroupBox(tab1);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(360, 10, 161, 281));
        lb_modules_2 = new QLabel(groupBox_5);
        lb_modules_2->setObjectName(QString::fromUtf8("lb_modules_2"));
        lb_modules_2->setGeometry(QRect(110, 160, 31, 21));
        lb_modules_2->setFont(font);
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 220, 91, 16));
        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 160, 91, 16));
        lb_pin_2 = new QLabel(groupBox_5);
        lb_pin_2->setObjectName(QString::fromUtf8("lb_pin_2"));
        lb_pin_2->setGeometry(QRect(110, 200, 31, 21));
        lb_pin_2->setFont(font);
        lb_rules_2 = new QLabel(groupBox_5);
        lb_rules_2->setObjectName(QString::fromUtf8("lb_rules_2"));
        lb_rules_2->setGeometry(QRect(110, 240, 31, 21));
        lb_rules_2->setFont(font);
        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 200, 91, 16));
        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 240, 101, 20));
        lb_pout_2 = new QLabel(groupBox_5);
        lb_pout_2->setObjectName(QString::fromUtf8("lb_pout_2"));
        lb_pout_2->setGeometry(QRect(110, 220, 31, 21));
        lb_pout_2->setFont(font);
        lb_total_2 = new QLabel(groupBox_5);
        lb_total_2->setObjectName(QString::fromUtf8("lb_total_2"));
        lb_total_2->setGeometry(QRect(110, 180, 31, 21));
        lb_total_2->setFont(font);
        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 180, 91, 16));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("images/lamp.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabView->addTab(tab1, icon11, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        viewModules = new QTreeView(tab2);
        viewModules->setObjectName(QString::fromUtf8("viewModules"));
        viewModules->setGeometry(QRect(0, 0, 571, 321));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("images/connector.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabView->addTab(tab2, icon12, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QString::fromUtf8("tab3"));
        viewRules = new QTreeView(tab3);
        viewRules->setObjectName(QString::fromUtf8("viewRules"));
        viewRules->setGeometry(QRect(0, 0, 541, 321));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8("images/runner.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabView->addTab(tab3, icon13, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 21));
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
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

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
        menuMyPlc->addAction(actionSerialConnect);
        menuMyPlc->addSeparator();
        mainToolBar->addAction(actionFileOpen);
        mainToolBar->addAction(actionFileSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSerialConnect);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAddModule);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionClean);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRetrieve);
        mainToolBar->addAction(actionRewrite);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        tabView->setCurrentIndex(1);


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
        actionClean->setText(QCoreApplication::translate("MainWindow", "Clean", nullptr));
        actionRetrieve->setText(QCoreApplication::translate("MainWindow", "Retrieve", nullptr));
        actionRewrite->setText(QCoreApplication::translate("MainWindow", "Rewrite", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Progetto", nullptr));
        lb_alias->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Alias:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "File.:", nullptr));
        lb_filename->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Stato ..:", nullptr));
        lb_status->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
#if QT_CONFIG(accessibility)
        tab1->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Dispositivo", nullptr));
        lb_hardware->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Firmware.........:", nullptr));
        lb_cycle->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Eprom (KB)......:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Ciclo (ms)........:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Hardware.........: ", nullptr));
        lb_eprom->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        lb_firmware->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Serial.............:", nullptr));
        lb_serial->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        lb_memory->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "SRAM (KB)......:", nullptr));
        lb_rules->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Porte IN..........:", nullptr));
        lb_modules->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Regole...........:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Porte OUT.......:", nullptr));
        lb_pout->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Moduli ............:", nullptr));
        lb_total->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Porte attive.....:", nullptr));
        lb_pin->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Locale", nullptr));
        lb_modules_2->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Porte OUT.......:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Moduli ............:", nullptr));
        lb_pin_2->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        lb_rules_2->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Porte IN..........:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Regole...........:", nullptr));
        lb_pout_2->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        lb_total_2->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Porte attive.....:", nullptr));
        tabView->setTabText(tabView->indexOf(tab1), QCoreApplication::translate("MainWindow", "Generale", nullptr));
        tabView->setTabText(tabView->indexOf(tab2), QCoreApplication::translate("MainWindow", "Moduli && Porte", nullptr));
        tabView->setTabText(tabView->indexOf(tab3), QCoreApplication::translate("MainWindow", "Regole (Condizione-Azione)", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Aiuto", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Strumenti", nullptr));
        menuMyPlc->setTitle(QCoreApplication::translate("MainWindow", "MyPlc", nullptr));
        mainToolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
