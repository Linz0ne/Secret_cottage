#include "des.h"
#include "ui_des.h"

DES::DES(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DES)
{
    ui->setupUi(this);
}

DES::~DES()
{
    delete ui;
}
