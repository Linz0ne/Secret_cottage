#include "forgetpassword.h"
#include "ui_forgetpassword.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QCryptographicHash>

extern QString usr_users;
forgetpassword::forgetpassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forgetpassword)
{
    ui->setupUi(this);
    setWindowOpacity(0.9);
}

forgetpassword::~forgetpassword()
{
    delete ui;
}

void forgetpassword::on_pushButton_clicked()
{

    QString userlogforget=ui->lineEusername->text();
    QString userlogforgetproblemone=ui->linepronlemone->text();
    QString userlogforgetproblemtwo=ui->lineproblemtwo->text();
    QString userlogforgetproblemthree=ui->lineproblemthree->text();

    int usr_ids;
    QString usr_users;
    QString usr_passwds;
    QString problemoone;
    QString problemttwo;
    QString problemtthree;
    QString locksd;

    QSqlQuery sql_querys;
    QString tempstring="select rowid,user,password,problem_one,problem_two,problem_three,lock from users where user='"+ui->lineEusername->text()+"';";
    qDebug()<<tempstring;
    if(!sql_querys.exec(tempstring))
    {
        qDebug()<<sql_querys.lastError();

    }
    else
    {
        while(sql_querys.next())
        {
            usr_ids = sql_querys.value(0).toInt();
            qDebug()<<usr_ids;
            usr_users = sql_querys.value(1).toString();
            qDebug()<<usr_users;
            usr_passwds= sql_querys.value(2).toString();
            usr_ids = sql_querys.value(0).toInt();
            qDebug()<<usr_ids;
            usr_users = sql_querys.value(1).toString();
            qDebug()<<usr_users;
            usr_passwds= sql_querys.value(2).toString();
            qDebug()<<usr_passwds;
            problemoone= sql_querys.value(3).toString();
            qDebug()<<problemoone;
            problemttwo= sql_querys.value(4).toString();
            qDebug()<<problemttwo;
            problemtthree= sql_querys.value(5).toString();
            qDebug()<< problemtthree;
            locksd= sql_querys.value(6).toString();
            qDebug()<< locksd;
            QByteArray byte_arrays;
            byte_arrays.append(ui->lineEditupdate->text());
            QCryptographicHash hash(QCryptographicHash::Md5);
            hash.addData(byte_arrays);  //添加数据到加密哈希值
            QByteArray result_byte_array = hash.result();  //返回最终的哈希值
            QString md5s = result_byte_array.toHex();
            qDebug()<<md5s;
           if(userlogforgetproblemone==problemoone&&userlogforgetproblemtwo==problemttwo&&userlogforgetproblemthree==problemtthree)
           {
               //ui->labelusername->setText(usr_users);
               ui->locklock->setText(locksd);
               QSqlQuery sql_queryupdate;
               QString queryupdate=QString("UPDATE users SET password = '%2' where user='"+ui->lineEusername->text()+"';").arg(md5s);
               sql_queryupdate.exec(queryupdate);
          }
        }
    }
}


