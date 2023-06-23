#include "menue.h"
#include "ui_menue.h"

menue::menue(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menue)
{
    ui->setupUi(this);
}

menue::~menue()
{
    delete ui;
}
