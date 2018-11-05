#ifndef DIALOGLOCK_H
#define DIALOGLOCK_H

#include <QDialog>
#include "memeryss.h"
namespace Ui {
class Dialoglock;
}

class Dialoglock : public QDialog
{
    Q_OBJECT

public:
    explicit Dialoglock(QWidget *parent = nullptr);
    ~Dialoglock();

private slots:
    void on_pushButtonlockss_clicked();

private:
    Ui::Dialoglock *ui;
    memeryss lokss;
};

#endif // DIALOGLOCK_H
