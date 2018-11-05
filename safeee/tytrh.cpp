#include "tytrh.h"
#include "ui_tytrh.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QCryptographicHash>

#include "loging.h"
#include <QSqlTableModel>
#include <QItemSelectionModel>
#include "loging.h"
tytrh::tytrh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tytrh)
{
    ui->setupUi(this);
    setWindowOpacity(0.9);

}

tytrh::~tytrh()
{
    delete ui;
}

void tytrh::on_pushButtonsave_clicked()
{
    QSqlQuery HGGG;
    QString savessjj=QString("update users set saves='%1' where user='"+loging::hh+"' ;").arg(ui->textEditsave->toPlainText());
    HGGG.exec(savessjj);
    QMessageBox::information(NULL, "提示", "保存成功", QMessageBox::Yes, QMessageBox::Yes);   
}

void tytrh::on_pushButtonlockkk_clicked()
{
    this->close();
}

void tytrh::on_pushButtoncancer_clicked()
{
    this->close();

}

void tytrh::on_pushButton_clicked()
{
    int usr_idsg;
    QString usr_usersg;
    QString usr_passwdsg;
    QString problemooneg;
    QString problemttwog;
    QString problemtthreeg;
    QString locksdg;
    QString savess;

    QSqlQuery sql_querysg;
    QString tempstringg="select rowid,user,password,problem_one,problem_two,problem_three,lock,saves from users where user='"+loging::hh+"';";
    qDebug()<<tempstringg;
    if(!sql_querysg.exec(tempstringg))
    {
        qDebug()<<sql_querysg.lastError();

    }
    else
    {
        while(sql_querysg.next())
        {
            usr_idsg = sql_querysg.value(0).toInt();
            qDebug()<<usr_idsg;
            usr_usersg = sql_querysg.value(1).toString();
            qDebug()<<usr_usersg;
            usr_passwdsg= sql_querysg.value(2).toString();
            usr_idsg = sql_querysg.value(0).toInt();
            qDebug()<<usr_idsg;
            usr_usersg = sql_querysg.value(1).toString();
            qDebug()<<usr_usersg;
            usr_passwdsg= sql_querysg.value(2).toString();
            qDebug()<<usr_passwdsg;
            problemooneg= sql_querysg.value(3).toString();
            qDebug()<<problemooneg;
            problemttwog= sql_querysg.value(4).toString();
            qDebug()<<problemttwog;
            problemtthreeg= sql_querysg.value(5).toString();
            qDebug()<< problemtthreeg;
            locksdg= sql_querysg.value(6).toString();
            qDebug()<< locksdg;
            savess= sql_querysg.value(7).toString();
            qDebug()<< locksdg;
            ui->labelecho->setText(savess);

          }
       }


}
