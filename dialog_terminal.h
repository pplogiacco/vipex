#ifndef DIALOG_TERMINAL_H
#define DIALOG_TERMINAL_H

#include <QDialog>

namespace Ui {
class DialogTerminal;
}

class DialogTerminal : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTerminal(QWidget *parent = nullptr);
    ~DialogTerminal();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogTerminal *ui;
};

#endif // DIALOG_TERMINAL_H
