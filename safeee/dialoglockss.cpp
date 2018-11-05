#include "dialoglockss.h"
#include "ui_dialoglockss.h"

Dialoglockss::Dialoglockss(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialoglockss)
{
    ui->setupUi(this);
}

Dialoglockss::~Dialoglockss()
{
    delete ui;
}
