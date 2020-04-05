/********************************************************************************
** Form generated from reading UI file 'dialogeditport.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEDITPORT_H
#define UI_DIALOGEDITPORT_H

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

class Ui_DialogEditPort
{
public:
    QDialogButtonBox *buttonBox;
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
    QLabel *label_4;

    void setupUi(QDialog *DialogEditPort)
    {
        if (DialogEditPort->objectName().isEmpty())
            DialogEditPort->setObjectName(QString::fromUtf8("DialogEditPort"));
        DialogEditPort->resize(380, 279);
        buttonBox = new QDialogButtonBox(DialogEditPort);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_2 = new QLabel(DialogEditPort);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 131, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        groupBox = new QGroupBox(DialogEditPort);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(130, 110, 120, 80));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(20, 20, 71, 17));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(20, 40, 71, 17));
        label = new QLabel(DialogEditPort);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 211, 16));
        groupBox_3 = new QGroupBox(DialogEditPort);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(250, 110, 101, 80));
        radioButton_5 = new QRadioButton(groupBox_3);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(20, 20, 51, 17));
        radioButton_6 = new QRadioButton(groupBox_3);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setGeometry(QRect(20, 40, 51, 17));
        label_6 = new QLabel(DialogEditPort);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 0, 81, 16));
        alias = new QLineEdit(DialogEditPort);
        alias->setObjectName(QString::fromUtf8("alias"));
        alias->setGeometry(QRect(10, 80, 341, 20));
        label_3 = new QLabel(DialogEditPort);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 0, 61, 16));
        checkBox = new QCheckBox(DialogEditPort);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(290, 20, 61, 17));
        groupBox_2 = new QGroupBox(DialogEditPort);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 110, 120, 80));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(20, 20, 61, 17));
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 40, 61, 17));
        label_4 = new QLabel(DialogEditPort);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(210, 20, 41, 16));
        label_4->setFont(font);

        retranslateUi(DialogEditPort);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogEditPort, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogEditPort, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogEditPort);
    } // setupUi

    void retranslateUi(QDialog *DialogEditPort)
    {
        DialogEditPort->setWindowTitle(QCoreApplication::translate("DialogEditPort", "MyPlc Port", nullptr));
        label_2->setText(QCoreApplication::translate("DialogEditPort", "Nanoboard V3", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogEditPort", "Circuito", nullptr));
        radioButton_3->setText(QCoreApplication::translate("DialogEditPort", "Sensor", nullptr));
        radioButton_4->setText(QCoreApplication::translate("DialogEditPort", "Actuator", nullptr));
        label->setText(QCoreApplication::translate("DialogEditPort", "Descrizione Porta / Circuito", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("DialogEditPort", "Condizione iniziale", nullptr));
        radioButton_5->setText(QCoreApplication::translate("DialogEditPort", "On", nullptr));
        radioButton_6->setText(QCoreApplication::translate("DialogEditPort", "Off", nullptr));
        label_6->setText(QCoreApplication::translate("DialogEditPort", "Modulo", nullptr));
        label_3->setText(QCoreApplication::translate("DialogEditPort", "Morsetto", nullptr));
        checkBox->setText(QCoreApplication::translate("DialogEditPort", "Abilitata", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DialogEditPort", "Direzione", nullptr));
        radioButton->setText(QCoreApplication::translate("DialogEditPort", "Input", nullptr));
        radioButton_2->setText(QCoreApplication::translate("DialogEditPort", "Output", nullptr));
        label_4->setText(QCoreApplication::translate("DialogEditPort", "P8", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogEditPort: public Ui_DialogEditPort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEDITPORT_H
