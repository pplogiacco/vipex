#ifndef DIALOGEDITMODULE_H
#define DIALOGEDITMODULE_H

#include <QDialog>

namespace Ui {
class DialogEditModule;
}

class DialogEditModule : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditModule(QWidget *parent = nullptr);
    ~DialogEditModule();

private:
    Ui::DialogEditModule *ui;
};

#endif // DIALOGEDITMODULE_H
