#include "role.h"
#include "ui_role.h"

role::role(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::role)
{
     ui->setupUi(this);
    ui->label_server->hide();
    ui->connect_btn->hide();
    ui->getip_edt->hide();
    ui->setip_lbl->hide();
    ui->go_btn->hide();

}

role::~role()
{
    delete ui;
}

void role::on_server_btn_clicked()
{
    Server s;
    ui->label_server->show();
    ui->setip_lbl->show();
    ui->server_btn->setEnabled(false);
    ui->client_btn->setEnabled(false);
    ui->go_btn->show();
    ui->setip_lbl->setText(s.getIp().toString());
    on_go_btn_clicked(s);
}


void role::on_client_btn_clicked()
{
    ui->connect_btn->show();
    ui->getip_edt->show();
    ui->server_btn->setEnabled(false);
    ui->client_btn->setEnabled(false);

}


void role::on_connect_btn_clicked()
{

    Client client;
    if(client.connect(ui->getip_edt->text())){
        ui->label_temp->setText("connect");
    }
    else{
        ui->label_temp->setText("Not connect");
    }

}



void role::on_go_btn_clicked(Server s)
{
    if(s.is_connect()){
        ui->label_temp->setText("connect");
    }
    else{
        ui->label_temp->setText("Not connect");
    }
}

