/********************************************************************************
** Form generated from reading UI file 'dialog_serialsync.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SERIALSYNC_H
#define UI_DIALOG_SERIALSYNC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_Dialog_SerialSync
{
public:
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
    QLabel *lb_in;
    QLabel *label_15;
    QLabel *lb_firmware;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *lb_out;
    QLabel *label_19;
    QLabel *lb_eeprom;
    QLabel *label_20;
    QLabel *lb_serial;
    QDialogButtonBox *buttonBox;
    QProgressBar *pBar;
    QPlainTextEdit *logBox;

    void setupUi(QDialog *Dialog_SerialSync)
    {
        if (Dialog_SerialSync->objectName().isEmpty())
            Dialog_SerialSync->setObjectName(QString::fromUtf8("Dialog_SerialSync"));
        Dialog_SerialSync->resize(392, 410);
        groupBox_2 = new QGroupBox(Dialog_SerialSync);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 371, 151));
        lb_modules = new QLabel(groupBox_2);
        lb_modules->setObjectName(QString::fromUtf8("lb_modules"));
        lb_modules->setGeometry(QRect(270, 20, 21, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lb_modules->setFont(font);
        lb_rules = new QLabel(groupBox_2);
        lb_rules->setObjectName(QString::fromUtf8("lb_rules"));
        lb_rules->setGeometry(QRect(270, 100, 21, 21));
        lb_rules->setFont(font);
        lb_memory = new QLabel(groupBox_2);
        lb_memory->setObjectName(QString::fromUtf8("lb_memory"));
        lb_memory->setGeometry(QRect(90, 80, 41, 20));
        lb_memory->setFont(font);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(170, 40, 91, 16));
        lb_hardware = new QLabel(groupBox_2);
        lb_hardware->setObjectName(QString::fromUtf8("lb_hardware"));
        lb_hardware->setGeometry(QRect(80, 20, 51, 20));
        lb_hardware->setFont(font);
        lb_cycle = new QLabel(groupBox_2);
        lb_cycle->setObjectName(QString::fromUtf8("lb_cycle"));
        lb_cycle->setGeometry(QRect(90, 120, 41, 21));
        lb_cycle->setFont(font);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(170, 20, 91, 16));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(170, 60, 91, 16));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(170, 100, 91, 20));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 80, 71, 16));
        lb_total = new QLabel(groupBox_2);
        lb_total->setObjectName(QString::fromUtf8("lb_total"));
        lb_total->setGeometry(QRect(270, 40, 21, 21));
        lb_total->setFont(font);
        lb_in = new QLabel(groupBox_2);
        lb_in->setObjectName(QString::fromUtf8("lb_in"));
        lb_in->setGeometry(QRect(270, 60, 21, 21));
        lb_in->setFont(font);
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 40, 61, 16));
        lb_firmware = new QLabel(groupBox_2);
        lb_firmware->setObjectName(QString::fromUtf8("lb_firmware"));
        lb_firmware->setGeometry(QRect(80, 40, 51, 20));
        lb_firmware->setFont(font);
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 20, 61, 16));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 120, 71, 20));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(170, 80, 91, 16));
        lb_out = new QLabel(groupBox_2);
        lb_out->setObjectName(QString::fromUtf8("lb_out"));
        lb_out->setGeometry(QRect(270, 80, 21, 21));
        lb_out->setFont(font);
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 100, 71, 16));
        lb_eeprom = new QLabel(groupBox_2);
        lb_eeprom->setObjectName(QString::fromUtf8("lb_eeprom"));
        lb_eeprom->setGeometry(QRect(90, 100, 41, 20));
        lb_eeprom->setFont(font);
        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 60, 71, 16));
        lb_serial = new QLabel(groupBox_2);
        lb_serial->setObjectName(QString::fromUtf8("lb_serial"));
        lb_serial->setGeometry(QRect(80, 60, 51, 20));
        lb_serial->setFont(font);
        buttonBox = new QDialogButtonBox(Dialog_SerialSync);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 370, 361, 31));
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        buttonBox->setCenterButtons(true);
        pBar = new QProgressBar(Dialog_SerialSync);
        pBar->setObjectName(QString::fromUtf8("pBar"));
        pBar->setGeometry(QRect(10, 280, 381, 23));
        pBar->setValue(24);
        logBox = new QPlainTextEdit(Dialog_SerialSync);
        logBox->setObjectName(QString::fromUtf8("logBox"));
        logBox->setGeometry(QRect(10, 170, 371, 101));

        retranslateUi(Dialog_SerialSync);

        QMetaObject::connectSlotsByName(Dialog_SerialSync);
    } // setupUi

    void retranslateUi(QDialog *Dialog_SerialSync)
    {
        Dialog_SerialSync->setWindowTitle(QCoreApplication::translate("Dialog_SerialSync", "Dialog", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Dialog_SerialSync", "Dispositivo", nullptr));
        lb_modules->setText(QCoreApplication::translate("Dialog_SerialSync", "?", nullptr));
        lb_rules->setText(QCoreApplication::translate("Dialog_SerialSync", "?", nullptr));
        lb_memory->setText(QCoreApplication::translate("Dialog_SerialSync", "?", nullptr));
        label_10->setText(QCoreApplication::translate("Dialog_SerialSync", "Porte attive......:", nullptr));
        lb_hardware->setText(QCoreApplication::translate("Dialog_SerialSync", "?", nullptr));
        lb_cycle->setText(QCoreApplication::translate("Dialog_SerialSync", "?", nullptr));
        label_11->setText(QCoreApplication::translate("Dialog_SerialSync", "Moduli abilitati....:", nullptr));
        label_12->setText(QCoreApplication::translate("Dialog_SerialSync", "Porte IN...........:", nullptr));
        label_13->setText(QCoreApplication::translate("Dialog_SerialSync", "Regole impostate.:", nullptr));
        label_14->setText(QCoreApplication::translate("Dialog_SerialSync", "SRAM (KB)...:", nullptr));
        lb_total->setText(QCoreApplication::translate("Dialog_SerialSync", "?", nullptr));
        lb_in->setText(QCoreApplication::translate("Dialog_SerialSync", "?", nullptr));
        label_15->setText(QCoreApplication::translate("Dialog_SerialSync", "Firmware..:", nullptr));
        lb_firmware->setText(QCoreApplication::translate("Dialog_SerialSync", "?", nullptr));
        label_16->setText(QCoreApplication::translate("Dialog_SerialSync", "Hardware..: ", nullptr));
        label_17->setText(QCoreApplication::translate("Dialog_SerialSync", "Ciclo (ms).....:", nullptr));
        label_18->setText(QCoreApplication::translate("Dialog_SerialSync", "Porte OUT........:", nullptr));
        lb_out->setText(QCoreApplication::translate("Dialog_SerialSync", "?", nullptr));
        label_19->setText(QCoreApplication::translate("Dialog_SerialSync", "EEprom (KB)..:", nullptr));
        lb_eeprom->setText(QCoreApplication::translate("Dialog_SerialSync", "?", nullptr));
        label_20->setText(QCoreApplication::translate("Dialog_SerialSync", "Serial......:", nullptr));
        lb_serial->setText(QCoreApplication::translate("Dialog_SerialSync", "?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_SerialSync: public Ui_Dialog_SerialSync {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SERIALSYNC_H
