/********************************************************************************
** Form generated from reading UI file 'dialog_addmodule.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ADDMODULE_H
#define UI_DIALOG_ADDMODULE_H

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

class Ui_Dialog_AddModule
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QLabel *label;
    QGroupBox *gJumpers;
    QCheckBox *J1;
    QCheckBox *J2;
    QCheckBox *J3;
    QLabel *lbJaddr;
    QGroupBox *gAddress;
    QLineEdit *lineEdit;
    QLineEdit *txtAlias;
    QLabel *label_3;

    void setupUi(QDialog *Dialog_AddModule)
    {
        if (Dialog_AddModule->objectName().isEmpty())
            Dialog_AddModule->setObjectName(QString::fromUtf8("Dialog_AddModule"));
        Dialog_AddModule->setWindowModality(Qt::ApplicationModal);
        Dialog_AddModule->resize(273, 222);
        buttonBox = new QDialogButtonBox(Dialog_AddModule);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 180, 231, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox = new QComboBox(Dialog_AddModule);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 20, 251, 22));
        label = new QLabel(Dialog_AddModule);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 111, 16));
        gJumpers = new QGroupBox(Dialog_AddModule);
        gJumpers->setObjectName(QString::fromUtf8("gJumpers"));
        gJumpers->setGeometry(QRect(10, 50, 121, 51));
        J1 = new QCheckBox(gJumpers);
        J1->setObjectName(QString::fromUtf8("J1"));
        J1->setGeometry(QRect(10, 20, 16, 17));
        J2 = new QCheckBox(gJumpers);
        J2->setObjectName(QString::fromUtf8("J2"));
        J2->setGeometry(QRect(30, 20, 16, 17));
        J3 = new QCheckBox(gJumpers);
        J3->setObjectName(QString::fromUtf8("J3"));
        J3->setGeometry(QRect(50, 20, 16, 17));
        lbJaddr = new QLabel(gJumpers);
        lbJaddr->setObjectName(QString::fromUtf8("lbJaddr"));
        lbJaddr->setGeometry(QRect(80, 20, 41, 16));
        gAddress = new QGroupBox(Dialog_AddModule);
        gAddress->setObjectName(QString::fromUtf8("gAddress"));
        gAddress->setGeometry(QRect(140, 50, 121, 51));
        lineEdit = new QLineEdit(gAddress);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 20, 71, 20));
        txtAlias = new QLineEdit(Dialog_AddModule);
        txtAlias->setObjectName(QString::fromUtf8("txtAlias"));
        txtAlias->setGeometry(QRect(10, 120, 251, 20));
        label_3 = new QLabel(Dialog_AddModule);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 100, 91, 16));

        retranslateUi(Dialog_AddModule);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_AddModule, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_AddModule, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_AddModule);
    } // setupUi

    void retranslateUi(QDialog *Dialog_AddModule)
    {
        Dialog_AddModule->setWindowTitle(QCoreApplication::translate("Dialog_AddModule", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog_AddModule", "Tipo modulo ", nullptr));
        gJumpers->setTitle(QCoreApplication::translate("Dialog_AddModule", "Jumpers", nullptr));
        J1->setText(QString());
        J2->setText(QString());
        J3->setText(QString());
        lbJaddr->setText(QCoreApplication::translate("Dialog_AddModule", "0x00", nullptr));
        gAddress->setTitle(QCoreApplication::translate("Dialog_AddModule", "Address", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog_AddModule", "Alias", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_AddModule: public Ui_Dialog_AddModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ADDMODULE_H
