#include "memeryss.h"
#include "ui_memeryss.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>
memeryss::memeryss(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::memeryss)
{
    ui->setupUi(this);
}

memeryss::~memeryss()
{
    delete ui;
}

void memeryss::on_pushButtonsave_clicked()
{




}

void memeryss::on_pushButtonlockcc_clicked()
{

                this->hide();
                tff.show();


}

void memeryss::on_pushButton_cancer_clicked()
{
                this->hide();
                tff.show();

}
