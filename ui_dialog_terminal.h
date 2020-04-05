/********************************************************************************
** Form generated from reading UI file 'dialog_terminal.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_TERMINAL_H
#define UI_DIALOG_TERMINAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogTerminal
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *DialogTerminal)
    {
        if (DialogTerminal->objectName().isEmpty())
            DialogTerminal->setObjectName(QString::fromUtf8("DialogTerminal"));
        DialogTerminal->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogTerminal);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        buttonBox->setCenterButtons(true);
        lineEdit = new QLineEdit(DialogTerminal);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 220, 291, 20));
        pushButton = new QPushButton(DialogTerminal);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 220, 51, 23));
        plainTextEdit = new QPlainTextEdit(DialogTerminal);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(20, 20, 351, 191));

        retranslateUi(DialogTerminal);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogTerminal, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogTerminal, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogTerminal);
    } // setupUi

    void retranslateUi(QDialog *DialogTerminal)
    {
        DialogTerminal->setWindowTitle(QCoreApplication::translate("DialogTerminal", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogTerminal", "Send", nullptr));
#if QT_CONFIG(shortcut)
        pushButton->setShortcut(QCoreApplication::translate("DialogTerminal", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class DialogTerminal: public Ui_DialogTerminal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_TERMINAL_H
