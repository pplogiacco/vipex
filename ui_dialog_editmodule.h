/********************************************************************************
** Form generated from reading UI file 'dialog_editmodule.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_EDITMODULE_H
#define UI_DIALOG_EDITMODULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog_EditModule
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QLabel *label;
    QGroupBox *sem_addr;
    QCheckBox *J1;
    QCheckBox *J2;
    QCheckBox *J3;
    QLabel *lbJaddr;
    QLineEdit *txtAlias;
    QLabel *label_3;
    QGroupBox *lcn_opts;
    QCheckBox *lcn_opt1;
    QLabel *lb_opt1;
    QGroupBox *lcn_addr;
    QLineEdit *lineEdit;

    void setupUi(QDialog *Dialog_EditModule)
    {
        if (Dialog_EditModule->objectName().isEmpty())
            Dialog_EditModule->setObjectName(QString::fromUtf8("Dialog_EditModule"));
        Dialog_EditModule->setWindowModality(Qt::ApplicationModal);
        Dialog_EditModule->resize(270, 293);
        buttonBox = new QDialogButtonBox(Dialog_EditModule);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 260, 251, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox = new QComboBox(Dialog_EditModule);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 20, 251, 22));
        label = new QLabel(Dialog_EditModule);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 111, 16));
        sem_addr = new QGroupBox(Dialog_EditModule);
        sem_addr->setObjectName(QString::fromUtf8("sem_addr"));
        sem_addr->setGeometry(QRect(10, 100, 111, 51));
        J1 = new QCheckBox(sem_addr);
        J1->setObjectName(QString::fromUtf8("J1"));
        J1->setGeometry(QRect(10, 20, 16, 17));
        J2 = new QCheckBox(sem_addr);
        J2->setObjectName(QString::fromUtf8("J2"));
        J2->setGeometry(QRect(30, 20, 16, 17));
        J3 = new QCheckBox(sem_addr);
        J3->setObjectName(QString::fromUtf8("J3"));
        J3->setGeometry(QRect(50, 20, 16, 17));
        lbJaddr = new QLabel(sem_addr);
        lbJaddr->setObjectName(QString::fromUtf8("lbJaddr"));
        lbJaddr->setGeometry(QRect(80, 20, 41, 16));
        txtAlias = new QLineEdit(Dialog_EditModule);
        txtAlias->setObjectName(QString::fromUtf8("txtAlias"));
        txtAlias->setGeometry(QRect(10, 70, 251, 20));
        label_3 = new QLabel(Dialog_EditModule);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 91, 16));
        lcn_opts = new QGroupBox(Dialog_EditModule);
        lcn_opts->setObjectName(QString::fromUtf8("lcn_opts"));
        lcn_opts->setGeometry(QRect(10, 160, 251, 91));
        lcn_opt1 = new QCheckBox(lcn_opts);
        lcn_opt1->setObjectName(QString::fromUtf8("lcn_opt1"));
        lcn_opt1->setGeometry(QRect(10, 20, 16, 17));
        lb_opt1 = new QLabel(lcn_opts);
        lb_opt1->setObjectName(QString::fromUtf8("lb_opt1"));
        lb_opt1->setGeometry(QRect(30, 20, 211, 16));
        QFont font;
        font.setPointSize(7);
        lb_opt1->setFont(font);
        lb_opt1->setTextFormat(Qt::AutoText);
        lb_opt1->setTextInteractionFlags(Qt::NoTextInteraction);
        lcn_addr = new QGroupBox(Dialog_EditModule);
        lcn_addr->setObjectName(QString::fromUtf8("lcn_addr"));
        lcn_addr->setGeometry(QRect(130, 100, 131, 51));
        lineEdit = new QLineEdit(lcn_addr);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 20, 61, 20));

        retranslateUi(Dialog_EditModule);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_EditModule, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_EditModule, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_EditModule);
    } // setupUi

    void retranslateUi(QDialog *Dialog_EditModule)
    {
        Dialog_EditModule->setWindowTitle(QCoreApplication::translate("Dialog_EditModule", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog_EditModule", "Modulo", nullptr));
        sem_addr->setTitle(QCoreApplication::translate("Dialog_EditModule", "Jumpers", nullptr));
        J1->setText(QString());
        J2->setText(QString());
        J3->setText(QString());
        lbJaddr->setText(QCoreApplication::translate("Dialog_EditModule", "0x00", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog_EditModule", "Alias", nullptr));
        lcn_opts->setTitle(QCoreApplication::translate("Dialog_EditModule", "Options", nullptr));
        lcn_opt1->setText(QString());
        lb_opt1->setText(QCoreApplication::translate("Dialog_EditModule", "Lcn-IF as STATION (Send OPC_SW_REQ)", nullptr));
        lcn_addr->setTitle(QCoreApplication::translate("Dialog_EditModule", "Indirizzo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_EditModule: public Ui_Dialog_EditModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_EDITMODULE_H
