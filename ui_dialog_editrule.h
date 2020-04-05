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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_DialogEditRule
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QComboBox *comboBox;
    QLabel *label;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QGroupBox *groupBox_2;
    QComboBox *comboBox_2;
    QGroupBox *groupBox_3;
    QComboBox *comboBox_3;
    QLabel *label_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;

    void setupUi(QDialog *DialogEditRule)
    {
        if (DialogEditRule->objectName().isEmpty())
            DialogEditRule->setObjectName(QString::fromUtf8("DialogEditRule"));
        DialogEditRule->resize(381, 252);
        buttonBox = new QDialogButtonBox(DialogEditRule);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 210, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(DialogEditRule);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 361, 71));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 40, 191, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 111, 16));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(220, 40, 41, 17));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(260, 40, 41, 17));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(300, 40, 41, 17));
        groupBox_2 = new QGroupBox(DialogEditRule);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 0, 361, 51));
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(10, 20, 341, 22));
        groupBox_3 = new QGroupBox(DialogEditRule);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 120, 361, 71));
        comboBox_3 = new QComboBox(groupBox_3);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(10, 40, 191, 22));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 111, 16));
        radioButton_4 = new QRadioButton(groupBox_3);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(220, 40, 41, 17));
        radioButton_5 = new QRadioButton(groupBox_3);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(260, 40, 41, 17));
        radioButton_6 = new QRadioButton(groupBox_3);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setGeometry(QRect(300, 40, 61, 17));

        retranslateUi(DialogEditRule);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogEditRule, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogEditRule, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogEditRule);
    } // setupUi

    void retranslateUi(QDialog *DialogEditRule)
    {
        DialogEditRule->setWindowTitle(QCoreApplication::translate("DialogEditRule", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogEditRule", "Ingressi", nullptr));
        label->setText(QCoreApplication::translate("DialogEditRule", "Porta In", nullptr));
        radioButton->setText(QCoreApplication::translate("DialogEditRule", "On", nullptr));
        radioButton_2->setText(QCoreApplication::translate("DialogEditRule", "Off", nullptr));
        radioButton_3->setText(QCoreApplication::translate("DialogEditRule", "Trig", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DialogEditRule", "Regola", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("DialogEditRule", "Uscite", nullptr));
        label_2->setText(QCoreApplication::translate("DialogEditRule", "Porta Out", nullptr));
        radioButton_4->setText(QCoreApplication::translate("DialogEditRule", "On", nullptr));
        radioButton_5->setText(QCoreApplication::translate("DialogEditRule", "Off", nullptr));
        radioButton_6->setText(QCoreApplication::translate("DialogEditRule", "Change", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogEditRule: public Ui_DialogEditRule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_EDITRULE_H
