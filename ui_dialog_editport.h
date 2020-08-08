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

class Ui_Dialog_EditPort
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *lbModule;
    QLabel *label;
    QGroupBox *groupBox_3;
    QRadioButton *defOn;
    QRadioButton *defOff;
    QLabel *label_6;
    QLineEdit *lbAlias;
    QLabel *label_3;
    QCheckBox *ckEnabled;
    QGroupBox *groupBox_2;
    QRadioButton *tpT3;
    QRadioButton *tpT2;
    QRadioButton *tpT1;
    QRadioButton *tpT4;
    QRadioButton *tpT7;
    QRadioButton *tpT5;
    QRadioButton *tpT8;
    QRadioButton *tpT6;
    QLabel *lbPaddr;
    QTableView *tableView_2;
    QLabel *label_4;

    void setupUi(QDialog *Dialog_EditPort)
    {
        if (Dialog_EditPort->objectName().isEmpty())
            Dialog_EditPort->setObjectName(QString::fromUtf8("Dialog_EditPort"));
        Dialog_EditPort->resize(362, 373);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/disabled.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/images/enabled.png"), QSize(), QIcon::Selected, QIcon::On);
        Dialog_EditPort->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(Dialog_EditPort);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 340, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lbModule = new QLabel(Dialog_EditPort);
        lbModule->setObjectName(QString::fromUtf8("lbModule"));
        lbModule->setGeometry(QRect(10, 20, 151, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lbModule->setFont(font);
        label = new QLabel(Dialog_EditPort);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 211, 16));
        groupBox_3 = new QGroupBox(Dialog_EditPort);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(280, 140, 71, 71));
        defOn = new QRadioButton(groupBox_3);
        defOn->setObjectName(QString::fromUtf8("defOn"));
        defOn->setGeometry(QRect(10, 20, 51, 17));
        defOff = new QRadioButton(groupBox_3);
        defOff->setObjectName(QString::fromUtf8("defOff"));
        defOff->setGeometry(QRect(10, 40, 51, 17));
        label_6 = new QLabel(Dialog_EditPort);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 0, 81, 16));
        lbAlias = new QLineEdit(Dialog_EditPort);
        lbAlias->setObjectName(QString::fromUtf8("lbAlias"));
        lbAlias->setGeometry(QRect(10, 70, 341, 20));
        lbAlias->setMaxLength(21);
        label_3 = new QLabel(Dialog_EditPort);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 0, 61, 16));
        ckEnabled = new QCheckBox(Dialog_EditPort);
        ckEnabled->setObjectName(QString::fromUtf8("ckEnabled"));
        ckEnabled->setGeometry(QRect(280, 20, 61, 17));
        groupBox_2 = new QGroupBox(Dialog_EditPort);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 100, 261, 111));
        tpT3 = new QRadioButton(groupBox_2);
        tpT3->setObjectName(QString::fromUtf8("tpT3"));
        tpT3->setGeometry(QRect(10, 60, 111, 17));
        tpT2 = new QRadioButton(groupBox_2);
        tpT2->setObjectName(QString::fromUtf8("tpT2"));
        tpT2->setGeometry(QRect(10, 40, 121, 17));
        tpT1 = new QRadioButton(groupBox_2);
        tpT1->setObjectName(QString::fromUtf8("tpT1"));
        tpT1->setGeometry(QRect(10, 20, 121, 17));
        tpT4 = new QRadioButton(groupBox_2);
        tpT4->setObjectName(QString::fromUtf8("tpT4"));
        tpT4->setGeometry(QRect(10, 80, 111, 17));
        tpT7 = new QRadioButton(groupBox_2);
        tpT7->setObjectName(QString::fromUtf8("tpT7"));
        tpT7->setGeometry(QRect(130, 60, 131, 17));
        tpT5 = new QRadioButton(groupBox_2);
        tpT5->setObjectName(QString::fromUtf8("tpT5"));
        tpT5->setGeometry(QRect(130, 20, 141, 17));
        tpT8 = new QRadioButton(groupBox_2);
        tpT8->setObjectName(QString::fromUtf8("tpT8"));
        tpT8->setGeometry(QRect(130, 80, 131, 17));
        tpT6 = new QRadioButton(groupBox_2);
        tpT6->setObjectName(QString::fromUtf8("tpT6"));
        tpT6->setGeometry(QRect(130, 40, 131, 17));
        lbPaddr = new QLabel(Dialog_EditPort);
        lbPaddr->setObjectName(QString::fromUtf8("lbPaddr"));
        lbPaddr->setGeometry(QRect(170, 20, 41, 16));
        lbPaddr->setFont(font);
        tableView_2 = new QTableView(Dialog_EditPort);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(10, 240, 341, 91));
        label_4 = new QLabel(Dialog_EditPort);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 220, 211, 16));

        retranslateUi(Dialog_EditPort);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_EditPort, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_EditPort, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_EditPort);
    } // setupUi

    void retranslateUi(QDialog *Dialog_EditPort)
    {
        Dialog_EditPort->setWindowTitle(QCoreApplication::translate("Dialog_EditPort", "MyPlc Port", nullptr));
        lbModule->setText(QCoreApplication::translate("Dialog_EditPort", "Nanoboard V3", nullptr));
        label->setText(QCoreApplication::translate("Dialog_EditPort", "Alias porta", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Dialog_EditPort", "Stato iniziale", nullptr));
        defOn->setText(QCoreApplication::translate("Dialog_EditPort", "On", nullptr));
        defOff->setText(QCoreApplication::translate("Dialog_EditPort", "Off", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog_EditPort", "Modulo", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog_EditPort", "Morsetto", nullptr));
        ckEnabled->setText(QCoreApplication::translate("Dialog_EditPort", "Abilitata", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Dialog_EditPort", "Tipo porta", nullptr));
        tpT3->setText(QCoreApplication::translate("Dialog_EditPort", "Pulsante (0/1/0)", nullptr));
        tpT2->setText(QCoreApplication::translate("Dialog_EditPort", "Interruttore (1/0)", nullptr));
        tpT1->setText(QCoreApplication::translate("Dialog_EditPort", "Interruttore (0/1)", nullptr));
        tpT4->setText(QCoreApplication::translate("Dialog_EditPort", "Pulsante (1/0/1)", nullptr));
        tpT7->setText(QCoreApplication::translate("Dialog_EditPort", "Uscita (impulso 0/1/0)", nullptr));
        tpT5->setText(QCoreApplication::translate("Dialog_EditPort", "Uscita (bi-stato 0/1)", nullptr));
        tpT8->setText(QCoreApplication::translate("Dialog_EditPort", "Uscita (impulso 1/0/1)", nullptr));
        tpT6->setText(QCoreApplication::translate("Dialog_EditPort", "Uscita (bi-stato 1/0)", nullptr));
        lbPaddr->setText(QCoreApplication::translate("Dialog_EditPort", "P8", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog_EditPort", "Regole associate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_EditPort: public Ui_Dialog_EditPort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_EDITPORT_H
