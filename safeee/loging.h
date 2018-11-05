#ifndef LOGING_H
#define LOGING_H
#include "mainwindow.h"
#include <forgetpassword.h>
#include <registered.h>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTimer>

namespace Ui {
class loging;
}

class loging : public QDialog
{
    Q_OBJECT

public:
    explicit loging(QWidget *parent = nullptr);
    ~loging();
    static QString hh;
    MainWindow ma;
    forgetpassword forg;
    registered reg;




private slots:
    void on_pushButtonLoging_clicked();
    void on_pushButtonExit_clicked();

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();



private:
    Ui::loging *ui;

};


#endif // LOGING_H
