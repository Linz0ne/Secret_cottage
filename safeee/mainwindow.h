#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "passwordbackup.h"
#include "encryptdocuments.h"
#include "sdqwdw.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_Passwordmemo_clicked();
    void on_encryptdocuments_clicked();
    void on_memorandum_clicked();

private:
    Ui::MainWindow *ui;
    Passwordbackup psb;
    encryptdocuments enc;
    sdqwdw sd;
};
#endif // MAINWINDOW_H

