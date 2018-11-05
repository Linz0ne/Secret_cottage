#include "dialoglock.h"
#include "ui_dialoglock.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QCryptographicHash>
#include "loging.h"
#include "memeryss.h"
Dialoglock::Dialoglock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialoglock)
{
    ui->setupUi(this);
}

Dialoglock::~Dialoglock()
{
    delete ui;
}

void Dialoglock::on_pushButtonlockss_clicked()
{

}
