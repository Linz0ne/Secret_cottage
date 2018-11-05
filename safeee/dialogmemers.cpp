#include "dialogmemers.h"
#include "ui_dialogmemers.h"

Dialogmemers::Dialogmemers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogmemers)
{
    ui->setupUi(this);
}

Dialogmemers::~Dialogmemers()
{
    delete ui;
}
