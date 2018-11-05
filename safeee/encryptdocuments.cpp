#include "encryptdocuments.h"
#include "ui_encryptdocuments.h"
#include <QFileDialog >
#include <QString>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
encryptdocuments::encryptdocuments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::encryptdocuments)
{
    ui->setupUi(this);
    setWindowOpacity(0.9);


}

encryptdocuments::~encryptdocuments()
{
    delete ui;
}




void encryptdocuments::on_pushButton_clicked()
{

    QString encrypt=ui->textEditinput->toPlainText();
    QString keys=ui->lineEditkey->text();
    QByteArray key;
    key=keys.toLatin1();
    std::wstring wString = encrypt.toStdWString();
    for (int i = 0; i < wString.size(); i++)
    {
           wString[i] = wString[i] ^ key[i % key.size()];
    }

    ui->txtoutput->setText(QString::fromStdWString(wString).toUtf8());

}
void encryptdocuments::on_pushButtondec_clicked()
{
    QString encrypts=ui->textEditinput->toPlainText();
    QString keyss=ui->lineEditkey->text();
    QByteArray keys;
    keys=keyss.toLatin1();
    std::wstring wStrings = encrypts.toStdWString();
    for (int i = 0; i < wStrings.size(); i++)
    {
           wStrings[i] = wStrings[i] ^ keys[i % keys.size()];
    }

    ui->txtoutput->setText(QString::fromStdWString(wStrings).toUtf8());
}


void encryptdocuments::on_pushButton_3_clicked()
{

    QFile file("E:/123.txt");//文件命名
    if (!file.open(QFile::WriteOnly | QFile::Text))     //检测文件是否打开
    {
           QMessageBox::information(this, "Error Message", "Please Select a Text File!");
           return;
    }
    QTextStream out(&file);                 //分行写入文件
    out <<ui->txtoutput->toPlainText();
    file.close();
}

void encryptdocuments::on_pushButton_4_clicked()
{
    this->hide();
}
