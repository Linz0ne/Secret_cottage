#include "formlock.h"
#include "ui_formlock.h"

Formlock::Formlock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formlock)
{
    ui->setupUi(this);
}

Formlock::~Formlock()
{
    delete ui;
}
