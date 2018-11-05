#include "dialoglocklock.h"
#include "ui_dialoglocklock.h"

Dialoglocklock::Dialoglocklock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialoglocklock)
{
    ui->setupUi(this);
}

Dialoglocklock::~Dialoglocklock()
{
    delete ui;
}
