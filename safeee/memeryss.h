#ifndef MEMERYSS_H
#define MEMERYSS_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class memeryss;
}

class memeryss : public QDialog
{
    Q_OBJECT

public:
    explicit memeryss(QWidget *parent = nullptr);
    ~memeryss();

private slots:
    void on_pushButtonsave_clicked();

    void on_pushButtonlockcc_clicked();

    void on_pushButton_cancer_clicked();

private:
    Ui::memeryss *ui;
    MainWindow tff;

};

#endif // MEMERYSS_H
