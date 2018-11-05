#ifndef REGISTERED_H
#define REGISTERED_H

#include <QDialog>

namespace Ui {
class registered;
}

class registered : public QDialog
{
    Q_OBJECT

public:
    explicit registered(QWidget *parent = nullptr);
    ~registered();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::registered *ui;
};

#endif // REGISTERED_H
