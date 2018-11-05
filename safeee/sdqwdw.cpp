#include "sdqwdw.h"
#include "ui_sdqwdw.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QCryptographicHash>
#include "loging.h"

sdqwdw::sdqwdw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sdqwdw)
{
    ui->setupUi(this);
    setWindowOpacity(0.9);
    ui->lineEditlockssss->setEchoMode(QLineEdit::Password);
}

sdqwdw::~sdqwdw()
{
    delete ui;
}

void sdqwdw::on_pushButtonlocksss_clicked()
{
    int usr_idsjj;
           QString usr_usersjj;
           QString usr_passwdsjj;
           QString problemoonejj;
           QString problemttwojj;
           QString problemtthreejj;
           QString locksdjj;

           QSqlQuery sql_querysjj;
           QString tempstringjj="select rowid,user,password,problem_one,problem_two,problem_three,lock from users where user='"+loging::hh+"';";
           qDebug()<<tempstringjj;
           if(!sql_querysjj.exec(tempstringjj))
           {
               qDebug()<<sql_querysjj.lastError();

           }
           else
           {
               while(sql_querysjj.next())
               {
                   usr_idsjj = sql_querysjj.value(0).toInt();
                   qDebug()<<usr_idsjj;
                   usr_usersjj = sql_querysjj.value(1).toString();
                   qDebug()<<usr_usersjj;
                   usr_passwdsjj= sql_querysjj.value(2).toString();
                   usr_idsjj = sql_querysjj.value(0).toInt();
                   qDebug()<<usr_idsjj;
                   usr_usersjj = sql_querysjj.value(1).toString();
                   qDebug()<<usr_usersjj;
                   usr_passwdsjj= sql_querysjj.value(2).toString();
                   qDebug()<<usr_passwdsjj;
                   problemoonejj= sql_querysjj.value(3).toString();
                   qDebug()<<problemoonejj;
                   problemttwojj= sql_querysjj.value(4).toString();
                   qDebug()<<problemttwojj;
                   problemtthreejj= sql_querysjj.value(5).toString();
                   qDebug()<< problemtthreejj;
                   locksdjj= sql_querysjj.value(6).toString();
                   qDebug()<< locksdjj;
                   if(locksdjj==ui->lineEditlockssss->text())
                   {

                       this->hide();
                       sdw.show();
                       QMessageBox::information(NULL, "提示", "解锁成功", QMessageBox::Yes, QMessageBox::Yes);

                   }
               }

           }
}
