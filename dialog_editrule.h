#ifndef DIALOGEDITRULE_H
#define DIALOGEDITRULE_H

#include <QDialog>

namespace Ui {
class Dialog_EditRule;
}

class Dialog_EditRule : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_EditRule(QWidget *parent = nullptr);
    ~Dialog_EditRule();

private:
    Ui::Dialog_EditRule *ui;
};

#endif // DIALOGEDITRULE_H
