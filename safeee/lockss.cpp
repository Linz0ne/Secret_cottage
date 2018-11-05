#include "lock.h"
#include "ui_lock.h"
#include "loging.h"
#include "memeryss.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>


lock::lock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lock)
{
    ui->setupUi(this);
    memeryss ssa;

}
lock::~lock()
{
    delete ui;
}

void lock::on_pushButtonlock_clicked()
{   

  }
