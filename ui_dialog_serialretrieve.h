/********************************************************************************
** Form generated from reading UI file 'dialog_serialretrieve.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SERIALRETRIEVE_H
#define UI_DIALOG_SERIALRETRIEVE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>

QT_BEGIN_NAMESPACE

class Ui_DialogSerialRetrieve
{
public:
    QGroupBox *selectBox;
    QGridLayout *gridLayout;
    QComboBox *serialPortInfoListBox;
    QProgressBar *progressBar;
    QPlainTextEdit *logBox;
    QPushButton *pbConnect;
    QScrollBar *verticalScrollBar;
    QGroupBox *groupBox_2;
    QLabel *lb_modules;
    QLabel *lb_rules;
    QLabel *lb_memory;
    QLabel *label_10;
    QLabel *lb_hardware;
    QLabel *lb_cycle;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *lb_total;
    QLabel *lb_ports;
    QLabel *label_15;
    QLabel *lb_firmware;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *pushButton_2;
    QPushButton *pbRetrieve;
    QPushButton *pbDisconnect;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogSerialRetrieve)
    {
        if (DialogSerialRetrieve->objectName().isEmpty())
            DialogSerialRetrieve->setObjectName(QString::fromUtf8("DialogSerialRetrieve"));
        DialogSerialRetrieve->resize(400, 401);
        selectBox = new QGroupBox(DialogSerialRetrieve);
        selectBox->setObjectName(QString::fromUtf8("selectBox"));
        selectBox->setGeometry(QRect(10, 10, 281, 51));
        gridLayout = new QGridLayout(selectBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        serialPortInfoListBox = new QComboBox(selectBox);
        serialPortInfoListBox->setObjectName(QString::fromUtf8("serialPortInfoListBox"));

        gridLayout->addWidget(serialPortInfoListBox, 0, 0, 1, 1);

        progressBar = new QProgressBar(DialogSerialRetrieve);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 330, 371, 16));
        progressBar->setValue(24);
        logBox = new QPlainTextEdit(DialogSerialRetrieve);
        logBox->setObjectName(QString::fromUtf8("logBox"));
        logBox->setGeometry(QRect(10, 70, 181, 241));
        pbConnect = new QPushButton(DialogSerialRetrieve);
        pbConnect->setObjectName(QString::fromUtf8("pbConnect"));
        pbConnect->setGeometry(QRect(300, 32, 71, 21));
        verticalScrollBar = new QScrollBar(DialogSerialRetrieve);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(370, 80, 16, 160));
        verticalScrollBar->setOrientation(Qt::Vertical);
        groupBox_2 = new QGroupBox(DialogSerialRetrieve);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(200, 70, 171, 191));
        lb_modules = new QLabel(groupBox_2);
        lb_modules->setObjectName(QString::fromUtf8("lb_modules"));
        lb_modules->setGeometry(QRect(110, 100, 31, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lb_modules->setFont(font);
        lb_rules = new QLabel(groupBox_2);
        lb_rules->setObjectName(QString::fromUtf8("lb_rules"));
        lb_rules->setGeometry(QRect(110, 160, 31, 21));
        lb_rules->setFont(font);
        lb_memory = new QLabel(groupBox_2);
        lb_memory->setObjectName(QString::fromUtf8("lb_memory"));
        lb_memory->setGeometry(QRect(70, 60, 71, 16));
        lb_memory->setFont(font);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 120, 91, 16));
        lb_hardware = new QLabel(groupBox_2);
        lb_hardware->setObjectName(QString::fromUtf8("lb_hardware"));
        lb_hardware->setGeometry(QRect(70, 20, 71, 16));
        lb_hardware->setFont(font);
        lb_cycle = new QLabel(groupBox_2);
        lb_cycle->setObjectName(QString::fromUtf8("lb_cycle"));
        lb_cycle->setGeometry(QRect(110, 80, 31, 21));
        lb_cycle->setFont(font);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 100, 91, 16));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 140, 91, 16));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 160, 91, 20));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 60, 61, 16));
        lb_total = new QLabel(groupBox_2);
        lb_total->setObjectName(QString::fromUtf8("lb_total"));
        lb_total->setGeometry(QRect(110, 120, 31, 21));
        lb_total->setFont(font);
        lb_ports = new QLabel(groupBox_2);
        lb_ports->setObjectName(QString::fromUtf8("lb_ports"));
        lb_ports->setGeometry(QRect(110, 140, 31, 21));
        lb_ports->setFont(font);
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 40, 81, 16));
        lb_firmware = new QLabel(groupBox_2);
        lb_firmware->setObjectName(QString::fromUtf8("lb_firmware"));
        lb_firmware->setGeometry(QRect(70, 40, 71, 16));
        lb_firmware->setFont(font);
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 20, 61, 16));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 80, 91, 20));
        pushButton_2 = new QPushButton(DialogSerialRetrieve);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 270, 51, 41));
        pbRetrieve = new QPushButton(DialogSerialRetrieve);
        pbRetrieve->setObjectName(QString::fromUtf8("pbRetrieve"));
        pbRetrieve->setGeometry(QRect(260, 270, 51, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../_resources/icone/accessories-text-editor.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbRetrieve->setIcon(icon);
        pbDisconnect = new QPushButton(DialogSerialRetrieve);
        pbDisconnect->setObjectName(QString::fromUtf8("pbDisconnect"));
        pbDisconnect->setEnabled(false);
        pbDisconnect->setGeometry(QRect(320, 10, 71, 21));
        buttonBox = new QDialogButtonBox(DialogSerialRetrieve);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 360, 381, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        buttonBox->setCenterButtons(true);

        retranslateUi(DialogSerialRetrieve);

        QMetaObject::connectSlotsByName(DialogSerialRetrieve);
    } // setupUi

    void retranslateUi(QDialog *DialogSerialRetrieve)
    {
        DialogSerialRetrieve->setWindowTitle(QCoreApplication::translate("DialogSerialRetrieve", "Dialog", nullptr));
        selectBox->setTitle(QCoreApplication::translate("DialogSerialRetrieve", "Serial Port", nullptr));
        pbConnect->setText(QCoreApplication::translate("DialogSerialRetrieve", "Collega", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DialogSerialRetrieve", "MyPlc", nullptr));
        lb_modules->setText(QCoreApplication::translate("DialogSerialRetrieve", "3", nullptr));
        lb_rules->setText(QCoreApplication::translate("DialogSerialRetrieve", "12", nullptr));
        lb_memory->setText(QCoreApplication::translate("DialogSerialRetrieve", "512", nullptr));
        label_10->setText(QCoreApplication::translate("DialogSerialRetrieve", "Porte disponibili...:", nullptr));
        lb_hardware->setText(QCoreApplication::translate("DialogSerialRetrieve", "Nanoboard", nullptr));
        lb_cycle->setText(QCoreApplication::translate("DialogSerialRetrieve", "46", nullptr));
        label_11->setText(QCoreApplication::translate("DialogSerialRetrieve", "Moduli abilitati.....:", nullptr));
        label_12->setText(QCoreApplication::translate("DialogSerialRetrieve", "Porte attive.......:", nullptr));
        label_13->setText(QCoreApplication::translate("DialogSerialRetrieve", "Regole impostate.:", nullptr));
        label_14->setText(QCoreApplication::translate("DialogSerialRetrieve", "Memoria...:", nullptr));
        lb_total->setText(QCoreApplication::translate("DialogSerialRetrieve", "32", nullptr));
        lb_ports->setText(QCoreApplication::translate("DialogSerialRetrieve", "7", nullptr));
        label_15->setText(QCoreApplication::translate("DialogSerialRetrieve", "Firmware..:", nullptr));
        lb_firmware->setText(QCoreApplication::translate("DialogSerialRetrieve", "2.1.34", nullptr));
        label_16->setText(QCoreApplication::translate("DialogSerialRetrieve", "Hardware.: ", nullptr));
        label_17->setText(QCoreApplication::translate("DialogSerialRetrieve", "Ciclo (ms)..........:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DialogSerialRetrieve", "Reset", nullptr));
        pbRetrieve->setText(QCoreApplication::translate("DialogSerialRetrieve", "Retrieve", nullptr));
        pbDisconnect->setText(QCoreApplication::translate("DialogSerialRetrieve", "Scollega", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSerialRetrieve: public Ui_DialogSerialRetrieve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SERIALRETRIEVE_H
