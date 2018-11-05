#include "mainwindow.h"
#include <QApplication>
#include <loging.h>

#include <qdebug.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loging w;
    w.show();

    //添加数据库驱动、设置数据库名称、数据库登录用户名、密码
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("../database.db");
    database.setUserName("root");
    database.setPassword("123");

    //打开数据库
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        // do something
    }

    return a.exec();
}
