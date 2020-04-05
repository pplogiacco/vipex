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
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_DialogEditModule
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *alias_2;
    QLabel *label_2;
    QGroupBox *groupBox;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QLabel *label;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QLabel *label_6;
    QLineEdit *alias;
    QLabel *label_3;
    QCheckBox *checkBox;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QDialog *DialogEditModule)
    {
        if (DialogEditModule->objectName().isEmpty())
            DialogEditModule->setObjectName(QString::fromUtf8("DialogEditModule"));
        DialogEditModule->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogEditModule);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        alias_2 = new QLineEdit(DialogEditModule);
        alias_2->setObjectName(QString::fromUtf8("alias_2"));
        alias_2->setGeometry(QRect(250, 90, 111, 20));
        label_2 = new QLabel(DialogEditModule);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 90, 47, 13));
        groupBox = new QGroupBox(DialogEditModule);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 130, 120, 80));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(20, 20, 71, 17));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(20, 40, 71, 17));
        label = new QLabel(DialogEditModule);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 47, 13));
        groupBox_3 = new QGroupBox(DialogEditModule);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(260, 130, 101, 80));
        radioButton_5 = new QRadioButton(groupBox_3);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(20, 20, 51, 17));
        radioButton_6 = new QRadioButton(groupBox_3);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setGeometry(QRect(20, 40, 51, 17));
        label_6 = new QLabel(DialogEditModule);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 70, 81, 16));
        alias = new QLineEdit(DialogEditModule);
        alias->setObjectName(QString::fromUtf8("alias"));
        alias->setGeometry(QRect(30, 40, 331, 20));
        label_3 = new QLabel(DialogEditModule);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(250, 70, 111, 16));
        checkBox = new QCheckBox(DialogEditModule);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(310, 20, 61, 17));
        groupBox_2 = new QGroupBox(DialogEditModule);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(140, 130, 120, 80));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(20, 20, 61, 17));
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 40, 61, 17));

        retranslateUi(DialogEditModule);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogEditModule, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogEditModule, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogEditModule);
    } // setupUi

    void retranslateUi(QDialog *DialogEditModule)
    {
        DialogEditModule->setWindowTitle(QCoreApplication::translate("DialogEditModule", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("DialogEditModule", "MODULE", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogEditModule", "HW Type", nullptr));
        radioButton_3->setText(QCoreApplication::translate("DialogEditModule", "Sensor", nullptr));
        radioButton_4->setText(QCoreApplication::translate("DialogEditModule", "Actuator", nullptr));
        label->setText(QCoreApplication::translate("DialogEditModule", "Port Alias", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("DialogEditModule", "Default Value", nullptr));
        radioButton_5->setText(QCoreApplication::translate("DialogEditModule", "On", nullptr));
        radioButton_6->setText(QCoreApplication::translate("DialogEditModule", "Off", nullptr));
        label_6->setText(QCoreApplication::translate("DialogEditModule", "Module", nullptr));
        label_3->setText(QCoreApplication::translate("DialogEditModule", "Port Sub-Address", nullptr));
        checkBox->setText(QCoreApplication::translate("DialogEditModule", "Enable", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DialogEditModule", "Direction", nullptr));
        radioButton->setText(QCoreApplication::translate("DialogEditModule", "Input", nullptr));
        radioButton_2->setText(QCoreApplication::translate("DialogEditModule", "Output", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogEditModule: public Ui_DialogEditModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_EDITMODULE_H
