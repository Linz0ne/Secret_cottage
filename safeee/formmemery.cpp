#include "formmemery.h"
#include "ui_formmemery.h"

Formmemery::Formmemery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formmemery)
{
    ui->setupUi(this);
}

Formmemery::~Formmemery()
{
    delete ui;
}
