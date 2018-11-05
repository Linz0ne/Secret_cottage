#include "passwordbackup.h"
#include "ui_passwordbackup.h"
#include <QCryptographicHash>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>
Passwordbackup::Passwordbackup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Passwordbackup)
{
    ui->setupUi(this);
    setWindowOpacity(0.9);
}

Passwordbackup::~Passwordbackup()
{
    delete ui;
}

void Passwordbackup::on_pushButton_saves_clicked()
{
    /*对密码进行md加密*/

    QString st=ui->lineEdit_username->text();
    QString sst=ui->lineEdit_usernames->text();
    QString ssst=ui->lineEdit_userpassword->text();
    if(ssst.length()==6)
    {

        QByteArray byte_array;
        byte_array.append(ui->lineEdit_userpassword->text());
        QByteArray hash_byte_array = QCryptographicHash::hash(byte_array, QCryptographicHash::Sha1);
        QString md5 = hash_byte_array.toHex();
        qDebug()<<md5;

        QString pid=QString ("insert into userss(username,userpassword,rt) values('%0','%1','%2');").arg(ui->lineEdit_usernames->text()).arg(md5).arg(ui->lineEdit_username->text());
        QSqlQuery query;
        query.exec(pid);
        qDebug()<<pid;
        QMessageBox::information(NULL, "提示", "密码通过sha1加密，注册成功", QMessageBox::Yes, QMessageBox::Yes);

    }else
    {

        QMessageBox::information(NULL, "提示", "注册失败", QMessageBox::Yes, QMessageBox::Yes);
    }
}

void Passwordbackup::on_pushButton_cancerss_clicked()
{
     this->close();
}

void Passwordbackup::on_pushButtonhash_clicked()
{
    QString userget=ui->lineEdit_leibier1->text();
    QString usernames=ui->lineEdit_mingzi->text();
    QString usernamepassowrd=ui->lineEdit_3mima->text();


    int user_ids;
    QString usr_users;
    QString usr_usersname;
    QString usr_userspassword;


    QSqlQuery sql_querysd;
    QString tempstringd="select rowid,username,userpassword,rt from userss where username='"+ui->lineEdit_mingzi->text()+"';";
    qDebug()<<tempstringd;
    if(!sql_querysd.exec(tempstringd))
    {
        qDebug()<<sql_querysd.lastError();

    }
    else
    {
        while(sql_querysd.next())
        {
            user_ids = sql_querysd.value(0).toInt();
            qDebug()<<user_ids;
            usr_usersname = sql_querysd.value(1).toString();
            qDebug()<<usr_usersname;
            usr_userspassword= sql_querysd.value(2).toString();
            qDebug()<<usr_userspassword;
            usr_users= sql_querysd.value(3).toString();
            qDebug()<<usr_users;
            QByteArray byte_arrays;
            byte_arrays.append(ui->lineEdit_3mima->text());
            QCryptographicHash hash(QCryptographicHash::Sha1);
            hash.addData(byte_arrays);  //添加数据到加密哈希值
            QByteArray result_byte_array = hash.result();  //返回最终的哈希值
            QString md5s = result_byte_array.toHex();
            qDebug()<<md5s;
           if(userget==usr_users&&usernames==usr_usersname&&md5s==usr_userspassword)
           {
               ui->label_ture->setText("密码正确");
           }
           else
           {
               QMessageBox::information(NULL, "提示", "验证失败", QMessageBox::Yes, QMessageBox::Yes);
               ui->label_ture->setText("密码错误");

           }
        }
    }

}
