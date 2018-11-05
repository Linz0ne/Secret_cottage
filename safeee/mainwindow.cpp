#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QToolButton>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   setWindowOpacity(0.9);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Passwordmemo_clicked()
{

    psb.show();
}

void MainWindow::on_encryptdocuments_clicked()
{

    enc.show();
}


void MainWindow::on_memorandum_clicked()
{
   sd.show();
}
