#ifndef LOCK_H
#define LOCK_H
#include <QDialog>
namespace Ui {
class lock;
}

class lock : public QDialog
{
    Q_OBJECT

public:
    explicit lock(QWidget *parent = nullptr);
    ~lock();

private slots:
    void on_pushButtonlock_clicked();

private:
    Ui::lock *ui;

};

#endif // LOCK_H
