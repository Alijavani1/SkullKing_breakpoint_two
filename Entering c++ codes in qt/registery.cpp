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
void Registery:: creatAccount(player &c){
    c.set_password(ui->password_edt->text());
    c.set_phoneNumber(ui->phonenumber->text());
    c.set_username(ui->username_edt->text());
}

void Registery::on_login_btn_clicked()
{
    //sing in
   // Registery ali;
   // ali.creatAccount(p1);
}

