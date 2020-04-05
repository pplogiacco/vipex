/********************************************************************************
** Form generated from reading UI file 'dialog_serial.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SERIAL_H
#define UI_DIALOG_SERIAL_H

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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogSerial
{
public:
    QGroupBox *selectBox;
    QGridLayout *gridLayout;
    QComboBox *serialPortInfoListBox;
    QPlainTextEdit *logBox;
    QPushButton *pbConnect;
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
    QPushButton *pbRetrieve;
    QDialogButtonBox *buttonBox;
    QPushButton *pbRewrite;
    QPushButton *pbDisconnect;

    void setupUi(QDialog *DialogSerial)
    {
        if (DialogSerial->objectName().isEmpty())
            DialogSerial->setObjectName(QString::fromUtf8("DialogSerial"));
        DialogSerial->resize(351, 342);
        selectBox = new QGroupBox(DialogSerial);
        selectBox->setObjectName(QString::fromUtf8("selectBox"));
        selectBox->setGeometry(QRect(10, 10, 331, 51));
        gridLayout = new QGridLayout(selectBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        serialPortInfoListBox = new QComboBox(selectBox);
        serialPortInfoListBox->setObjectName(QString::fromUtf8("serialPortInfoListBox"));

        gridLayout->addWidget(serialPortInfoListBox, 0, 0, 1, 1);

        logBox = new QPlainTextEdit(DialogSerial);
        logBox->setObjectName(QString::fromUtf8("logBox"));
        logBox->setGeometry(QRect(10, 70, 181, 211));
        pbConnect = new QPushButton(DialogSerial);
        pbConnect->setObjectName(QString::fromUtf8("pbConnect"));
        pbConnect->setGeometry(QRect(20, 310, 71, 21));
        groupBox_2 = new QGroupBox(DialogSerial);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(200, 70, 141, 211));
        lb_modules = new QLabel(groupBox_2);
        lb_modules->setObjectName(QString::fromUtf8("lb_modules"));
        lb_modules->setGeometry(QRect(110, 110, 21, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lb_modules->setFont(font);
        lb_rules = new QLabel(groupBox_2);
        lb_rules->setObjectName(QString::fromUtf8("lb_rules"));
        lb_rules->setGeometry(QRect(110, 190, 21, 21));
        lb_rules->setFont(font);
        lb_memory = new QLabel(groupBox_2);
        lb_memory->setObjectName(QString::fromUtf8("lb_memory"));
        lb_memory->setGeometry(QRect(70, 70, 61, 20));
        lb_memory->setFont(font);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 130, 91, 16));
        lb_hardware = new QLabel(groupBox_2);
        lb_hardware->setObjectName(QString::fromUtf8("lb_hardware"));
        lb_hardware->setGeometry(QRect(70, 30, 61, 16));
        lb_hardware->setFont(font);
        lb_cycle = new QLabel(groupBox_2);
        lb_cycle->setObjectName(QString::fromUtf8("lb_cycle"));
        lb_cycle->setGeometry(QRect(110, 90, 21, 21));
        lb_cycle->setFont(font);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 110, 91, 16));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 150, 91, 16));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 190, 91, 20));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 70, 61, 16));
        lb_total = new QLabel(groupBox_2);
        lb_total->setObjectName(QString::fromUtf8("lb_total"));
        lb_total->setGeometry(QRect(110, 130, 21, 21));
        lb_total->setFont(font);
        lb_in = new QLabel(groupBox_2);
        lb_in->setObjectName(QString::fromUtf8("lb_in"));
        lb_in->setGeometry(QRect(110, 150, 21, 21));
        lb_in->setFont(font);
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 50, 61, 16));
        lb_firmware = new QLabel(groupBox_2);
        lb_firmware->setObjectName(QString::fromUtf8("lb_firmware"));
        lb_firmware->setGeometry(QRect(70, 50, 61, 20));
        lb_firmware->setFont(font);
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 30, 61, 16));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 90, 91, 20));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 170, 91, 16));
        lb_out = new QLabel(groupBox_2);
        lb_out->setObjectName(QString::fromUtf8("lb_out"));
        lb_out->setGeometry(QRect(110, 170, 21, 21));
        lb_out->setFont(font);
        pbRetrieve = new QPushButton(DialogSerial);
        pbRetrieve->setObjectName(QString::fromUtf8("pbRetrieve"));
        pbRetrieve->setGeometry(QRect(100, 310, 71, 21));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbRetrieve->setIcon(icon);
        pbRetrieve->setIconSize(QSize(20, 20));
        buttonBox = new QDialogButtonBox(DialogSerial);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(240, 310, 111, 21));
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        buttonBox->setCenterButtons(true);
        pbRewrite = new QPushButton(DialogSerial);
        pbRewrite->setObjectName(QString::fromUtf8("pbRewrite"));
        pbRewrite->setGeometry(QRect(180, 310, 71, 21));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/down-red.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbRewrite->setIcon(icon1);
        pbRewrite->setIconSize(QSize(20, 20));
        pbDisconnect = new QPushButton(DialogSerial);
        pbDisconnect->setObjectName(QString::fromUtf8("pbDisconnect"));
        pbDisconnect->setGeometry(QRect(20, 310, 71, 21));

        retranslateUi(DialogSerial);

        QMetaObject::connectSlotsByName(DialogSerial);
    } // setupUi

    void retranslateUi(QDialog *DialogSerial)
    {
        DialogSerial->setWindowTitle(QCoreApplication::translate("DialogSerial", "Dialog", nullptr));
        selectBox->setTitle(QCoreApplication::translate("DialogSerial", "Serial Port", nullptr));
        pbConnect->setText(QCoreApplication::translate("DialogSerial", "Collega", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DialogSerial", "MyPlc", nullptr));
        lb_modules->setText(QCoreApplication::translate("DialogSerial", "...", nullptr));
        lb_rules->setText(QCoreApplication::translate("DialogSerial", "...", nullptr));
        lb_memory->setText(QCoreApplication::translate("DialogSerial", "...", nullptr));
        label_10->setText(QCoreApplication::translate("DialogSerial", "Porte disponibili...:", nullptr));
        lb_hardware->setText(QCoreApplication::translate("DialogSerial", "...", nullptr));
        lb_cycle->setText(QCoreApplication::translate("DialogSerial", "...", nullptr));
        label_11->setText(QCoreApplication::translate("DialogSerial", "Moduli abilitati.....:", nullptr));
        label_12->setText(QCoreApplication::translate("DialogSerial", "Porte IN...........:", nullptr));
        label_13->setText(QCoreApplication::translate("DialogSerial", "Regole impostate.:", nullptr));
        label_14->setText(QCoreApplication::translate("DialogSerial", "Memoria...:", nullptr));
        lb_total->setText(QCoreApplication::translate("DialogSerial", "...", nullptr));
        lb_in->setText(QCoreApplication::translate("DialogSerial", "...", nullptr));
        label_15->setText(QCoreApplication::translate("DialogSerial", "Firmware..:", nullptr));
        lb_firmware->setText(QCoreApplication::translate("DialogSerial", "...", nullptr));
        label_16->setText(QCoreApplication::translate("DialogSerial", "Hardware.: ", nullptr));
        label_17->setText(QCoreApplication::translate("DialogSerial", "Ciclo (ms)..........:", nullptr));
        label_18->setText(QCoreApplication::translate("DialogSerial", "Porte OUT........:", nullptr));
        lb_out->setText(QCoreApplication::translate("DialogSerial", "...", nullptr));
        pbDisconnect->setText(QCoreApplication::translate("DialogSerial", "Scollega", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSerial: public Ui_DialogSerial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SERIAL_H
