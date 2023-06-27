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
    ui->wati->hide();
    ui->go_btn_2->hide();
    ui->label_temp_2->hide();
    ui->label_temp->hide();

}

role::~role()
{
    delete ui;
}

void role::on_server_btn_clicked()
{
    gserver.is_connect();
    ui->label_server->show();
    ui->setip_lbl->show();
    ui->server_btn->setEnabled(false);
    ui->client_btn->setEnabled(false);
    ui->wati->show();
    ui->setip_lbl->setText(gserver.getIp().toString());


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


    if(gclient.isconnect(ui->getip_edt->text())){
        ui->label_temp->show();
        ui->label_temp->setText("connect");
        gclient.writeClient(gPlayer.get_username());

    }
    else{
         ui->label_temp->show();
        ui->label_temp->setText(" not connect");
    }

}



void role::on_wati_clicked()
{
   if(!gserver.get_data().isEmpty()){
    ui->label_temp_2->show();
   ui->label_temp_2->setText(gserver.get_data()+" is Ready");
   ui->wati->hide();
   ui->go_btn_2->show();
    ui->label_temp->hide();
   }
   else{
       ui->label_temp->show();
       ui->label_temp->setText("Not connect");
   }

}

