/********************************************************************************
** Form generated from reading UI file 'dialog_editport.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_EDITPORT_H
#define UI_DIALOG_EDITPORT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DialogEditPort
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *lbModuleAlias;
    QGroupBox *groupBox;
    QRadioButton *rbSns;
    QRadioButton *rbAct;
    QLabel *label;
    QGroupBox *groupBox_3;
    QRadioButton *rbDefOn;
    QRadioButton *rbDefOff;
    QLabel *label_6;
    QLineEdit *lbAlias;
    QLabel *label_3;
    QCheckBox *ckEnabled;
    QGroupBox *groupBox_2;
    QRadioButton *rbIn;
    QRadioButton *rbOut;
    QLabel *lbModulePort;
    QTableView *tableView_2;
    QLabel *label_4;

    void setupUi(QDialog *DialogEditPort)
    {
        if (DialogEditPort->objectName().isEmpty())
            DialogEditPort->setObjectName(QString::fromUtf8("DialogEditPort"));
        DialogEditPort->resize(362, 373);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/disabled.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/images/enabled.png"), QSize(), QIcon::Selected, QIcon::On);
        DialogEditPort->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(DialogEditPort);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 340, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lbModuleAlias = new QLabel(DialogEditPort);
        lbModuleAlias->setObjectName(QString::fromUtf8("lbModuleAlias"));
        lbModuleAlias->setGeometry(QRect(10, 20, 151, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lbModuleAlias->setFont(font);
        groupBox = new QGroupBox(DialogEditPort);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(130, 100, 101, 80));
        rbSns = new QRadioButton(groupBox);
        rbSns->setObjectName(QString::fromUtf8("rbSns"));
        rbSns->setGeometry(QRect(20, 20, 71, 17));
        rbAct = new QRadioButton(groupBox);
        rbAct->setObjectName(QString::fromUtf8("rbAct"));
        rbAct->setGeometry(QRect(20, 40, 71, 17));
        label = new QLabel(DialogEditPort);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 211, 16));
        groupBox_3 = new QGroupBox(DialogEditPort);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(250, 100, 101, 80));
        rbDefOn = new QRadioButton(groupBox_3);
        rbDefOn->setObjectName(QString::fromUtf8("rbDefOn"));
        rbDefOn->setGeometry(QRect(20, 20, 51, 17));
        rbDefOff = new QRadioButton(groupBox_3);
        rbDefOff->setObjectName(QString::fromUtf8("rbDefOff"));
        rbDefOff->setGeometry(QRect(20, 40, 51, 17));
        label_6 = new QLabel(DialogEditPort);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 0, 81, 16));
        lbAlias = new QLineEdit(DialogEditPort);
        lbAlias->setObjectName(QString::fromUtf8("lbAlias"));
        lbAlias->setGeometry(QRect(10, 70, 341, 20));
        lbAlias->setMaxLength(21);
        label_3 = new QLabel(DialogEditPort);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 0, 61, 16));
        ckEnabled = new QCheckBox(DialogEditPort);
        ckEnabled->setObjectName(QString::fromUtf8("ckEnabled"));
        ckEnabled->setGeometry(QRect(290, 50, 61, 17));
        groupBox_2 = new QGroupBox(DialogEditPort);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 100, 101, 80));
        rbIn = new QRadioButton(groupBox_2);
        rbIn->setObjectName(QString::fromUtf8("rbIn"));
        rbIn->setGeometry(QRect(20, 20, 61, 17));
        rbOut = new QRadioButton(groupBox_2);
        rbOut->setObjectName(QString::fromUtf8("rbOut"));
        rbOut->setGeometry(QRect(20, 40, 61, 17));
        lbModulePort = new QLabel(DialogEditPort);
        lbModulePort->setObjectName(QString::fromUtf8("lbModulePort"));
        lbModulePort->setGeometry(QRect(170, 20, 41, 16));
        lbModulePort->setFont(font);
        tableView_2 = new QTableView(DialogEditPort);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(10, 210, 341, 121));
        label_4 = new QLabel(DialogEditPort);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 190, 211, 16));

        retranslateUi(DialogEditPort);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogEditPort, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogEditPort, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogEditPort);
    } // setupUi

    void retranslateUi(QDialog *DialogEditPort)
    {
        DialogEditPort->setWindowTitle(QCoreApplication::translate("DialogEditPort", "MyPlc Port", nullptr));
        lbModuleAlias->setText(QCoreApplication::translate("DialogEditPort", "Nanoboard V3", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogEditPort", "Circuito", nullptr));
        rbSns->setText(QCoreApplication::translate("DialogEditPort", "Sensor", nullptr));
        rbAct->setText(QCoreApplication::translate("DialogEditPort", "Actuator", nullptr));
        label->setText(QCoreApplication::translate("DialogEditPort", "Descrizione Porta / Circuito", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("DialogEditPort", "Condizione iniziale", nullptr));
        rbDefOn->setText(QCoreApplication::translate("DialogEditPort", "On", nullptr));
        rbDefOff->setText(QCoreApplication::translate("DialogEditPort", "Off", nullptr));
        label_6->setText(QCoreApplication::translate("DialogEditPort", "Modulo", nullptr));
        label_3->setText(QCoreApplication::translate("DialogEditPort", "Morsetto", nullptr));
        ckEnabled->setText(QCoreApplication::translate("DialogEditPort", "Abilitata", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DialogEditPort", "Direzione", nullptr));
        rbIn->setText(QCoreApplication::translate("DialogEditPort", "Input", nullptr));
        rbOut->setText(QCoreApplication::translate("DialogEditPort", "Output", nullptr));
        lbModulePort->setText(QCoreApplication::translate("DialogEditPort", "P8", nullptr));
        label_4->setText(QCoreApplication::translate("DialogEditPort", "Regole associate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogEditPort: public Ui_DialogEditPort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_EDITPORT_H
