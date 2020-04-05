#ifndef DIALOGEDITRULE_H
#define DIALOGEDITRULE_H

#include <QDialog>

namespace Ui {
class DialogEditRule;
}

class DialogEditRule : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditRule(QWidget *parent = nullptr);
    ~DialogEditRule();

private:
    Ui::DialogEditRule *ui;
};

#endif // DIALOGEDITRULE_H
