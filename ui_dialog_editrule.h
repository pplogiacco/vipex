/********************************************************************************
** Form generated from reading UI file 'dialog_editrule.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_EDITRULE_H
#define UI_DIALOG_EDITRULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_EditRule
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QComboBox *comboBox;
    QLabel *label;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QGroupBox *groupBox_3;
    QComboBox *comboBox_3;
    QLabel *label_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QCheckBox *checkBox;
    QLineEdit *alias;
    QLabel *label_3;

    void setupUi(QDialog *Dialog_EditRule)
    {
        if (Dialog_EditRule->objectName().isEmpty())
            Dialog_EditRule->setObjectName(QString::fromUtf8("Dialog_EditRule"));
        Dialog_EditRule->resize(399, 255);
        buttonBox = new QDialogButtonBox(Dialog_EditRule);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(0, 220, 391, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(Dialog_EditRule);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 70, 191, 141));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 40, 171, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 111, 16));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(10, 70, 91, 17));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 90, 101, 17));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 110, 111, 17));
        groupBox_3 = new QGroupBox(Dialog_EditRule);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(200, 70, 191, 141));
        comboBox_3 = new QComboBox(groupBox_3);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(10, 40, 171, 22));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 111, 16));
        radioButton_4 = new QRadioButton(groupBox_3);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(10, 70, 111, 17));
        radioButton_5 = new QRadioButton(groupBox_3);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(10, 90, 91, 17));
        radioButton_6 = new QRadioButton(groupBox_3);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setGeometry(QRect(10, 110, 161, 17));
        checkBox = new QCheckBox(Dialog_EditRule);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(340, 40, 61, 17));
        alias = new QLineEdit(Dialog_EditRule);
        alias->setObjectName(QString::fromUtf8("alias"));
        alias->setGeometry(QRect(10, 40, 321, 20));
        label_3 = new QLabel(Dialog_EditRule);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 141, 16));

        retranslateUi(Dialog_EditRule);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_EditRule, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_EditRule, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_EditRule);
    } // setupUi

    void retranslateUi(QDialog *Dialog_EditRule)
    {
        Dialog_EditRule->setWindowTitle(QCoreApplication::translate("Dialog_EditRule", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog_EditRule", "Condizione", nullptr));
        label->setText(QCoreApplication::translate("Dialog_EditRule", "Porta", nullptr));
        radioButton->setText(QCoreApplication::translate("Dialog_EditRule", " \303\250 On", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Dialog_EditRule", " \303\250 Off", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Dialog_EditRule", "cambia stato", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Dialog_EditRule", "Azione", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog_EditRule", "Porta", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Dialog_EditRule", "pone a  On", nullptr));
        radioButton_5->setText(QCoreApplication::translate("Dialog_EditRule", "pone a Off", nullptr));
        radioButton_6->setText(QCoreApplication::translate("Dialog_EditRule", "cambia stato", nullptr));
        checkBox->setText(QCoreApplication::translate("Dialog_EditRule", "Enable", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog_EditRule", "Alias regola", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_EditRule: public Ui_Dialog_EditRule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_EDITRULE_H
