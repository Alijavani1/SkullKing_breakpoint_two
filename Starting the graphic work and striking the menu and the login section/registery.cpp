#include "registery.h"
#include "ui_registery.h"

Registery::Registery(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Registery)
{
    ui->setupUi(this);
}

Registery::~Registery()
{
    delete ui;
}
