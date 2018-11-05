#include "loging.h"
#include "ui_loging.h"
#include <QMessageBox>

#include "mainwindow.h"
#include "registered.h"
#include "forgetpassword.h"

#include <QDebug>
#include <QPainter>
#include <QTime>
#include <QMessageBox>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QCryptographicHash>

#include <string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
QString loging::hh;
static int aaa;
loging::loging(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loging)
{
    ui->setupUi(this);


    setWindowOpacity(0.8);
    srand(unsigned(time(NULL)));
    aaa=rand()%(1000-100)+100;
    ui->label_cap->setText(QString::number(aaa));
    QFont font("Courier",24);
    ui->label_cap->setFont(font);

    ui->lineEditUserpassword->setEchoMode(QLineEdit::Password);

}
loging::~loging()
{
    delete ui;
}

void loging::on_pushButtonLoging_clicked()
{

    QString userlog=ui->lineEditUsername->text();
    hh=ui->lineEditUsername->text();
    int SS=ui->lineEdit_input->text().toInt();

    QByteArray byte_array;
    byte_array.append(ui->lineEditUserpassword->text());
    QByteArray hash_byte_array = QCryptographicHash::hash(byte_array, QCryptographicHash::Md5);
    QString md5password = hash_byte_array.toHex();

    int usr_id;
    QString usr_user;
    QString usr_passwd;
    QSqlQuery sql_query;
    QString tempstring="select rowid,user,password from users where user='"+ui->lineEditUsername->text()+"';";
    qDebug()<<tempstring;
    if(!sql_query.exec(tempstring))
    {
        qDebug()<<sql_query.lastError();

    }
    else
    {

        while(sql_query.next())
        {
            usr_id = sql_query.value(0).toInt();
            qDebug()<<usr_id;
            usr_user = sql_query.value(1).toString();
            qDebug()<<usr_user;
            usr_passwd= sql_query.value(2).toString();
            qDebug()<<usr_passwd;

        if(userlog==usr_user&&md5password==usr_passwd)
        {
            qDebug()<<userlog;
            qDebug()<<usr_user;
            qDebug()<<md5password;
            qDebug()<<usr_passwd;

            if(SS==aaa)
            {
                qDebug()<<SS;
                qDebug()<<aaa;
                qDebug()<<sql_query.lastError();
                this->close();
                ma.show();
                QMessageBox::information(NULL, "提示", "登陆成功", QMessageBox::Yes, QMessageBox::Yes);

            }
        }
        else
        {

            QMessageBox::information(NULL, "提示", "登陆失败", QMessageBox::Yes, QMessageBox::Yes);
        }

        }


    }

}
void loging::on_pushButtonExit_clicked()
{
      qDebug("CancelBtn_Clicked start");
      done(Rejected);
      qDebug("CancelBtn_Clicked end");
}

void loging::on_commandLinkButton_clicked()
{
    reg.show();
}

void loging::on_commandLinkButton_2_clicked()
{
    forg.show();
}

