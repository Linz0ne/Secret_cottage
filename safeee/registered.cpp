#include "registered.h"
#include "ui_registered.h"


#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QCryptographicHash>


registered::registered(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registered)
{
    ui->setupUi(this);
    setWindowOpacity(0.9);

    ui->passwordsss->setText(tr("限6位长的密码"));
     ui->lock->setText(tr("限4位长的密码"));

}

registered::~registered()
{
    delete ui;
}

void registered::on_pushButton_clicked()
{
    /*对密码进行md加密*/

    QString ss=ui->passwordsss->text();
    QString sss=ui->lock->text();

    if(ss.length()==6)
    {
        if(sss.length()==4)
        {
        QByteArray byte_array;
        byte_array.append(ui->passwordsss->text());
        QByteArray hash_byte_array = QCryptographicHash::hash(byte_array, QCryptographicHash::Md5);
        QString md5 = hash_byte_array.toHex();
        qDebug()<<md5;

        QString pid=QString ("insert into users(user,password,problem_one,problem_two,problem_three,lock) values('%0','%1','%2','%3','%4','%5');").arg(ui->userss->text()).arg(md5).arg(ui->problem_1->text()).arg(ui->problem_2->text()).arg(ui->problem_3->text()).arg(ui->lock->text());
        QSqlQuery query;
        query.exec(pid);
        QMessageBox::information(NULL, "提示", "密码通过md5加密，注册成功", QMessageBox::Yes, QMessageBox::Yes);
         }
    }else
    {

        QMessageBox::information(NULL, "提示", "注册失败", QMessageBox::Yes, QMessageBox::Yes);
    }

}

void registered::on_pushButton_2_clicked()
{
    this->close();
}
