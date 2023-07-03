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
    ui->wait_btn->hide();
    ui->showUsername_lbl->hide();
    ui->label_temp->hide();
}

role::~role()
{
    delete ui;
}

void role::on_server_btn_clicked()
{
    gserver.is_connect();
    gPlayer.set_role("server");
    ui->label_server->show();
    ui->setip_lbl->show();
    ui->server_btn->setEnabled(false);
    ui->client_btn->setEnabled(false);
    ui->showUsername_lbl->show();
    ui->wait_btn->show();
    ui->setip_lbl->setText(gserver.getIp().toString());
}


void role::on_client_btn_clicked()
{
    gPlayer.set_role("client");
    ui->connect_btn->show();
    ui->getip_edt->show();
    ui->server_btn->setEnabled(false);
    ui->client_btn->setEnabled(false);

}


void role::on_connect_btn_clicked()
{
    ui->label_temp->show();
    if(gclient.isconnect(ui->getip_edt->text())==1){
        ui->label_temp->setStyleSheet("font: 600 14pt 'Sitka Banner Semibold'; color:#2E8B57");
       ui->label_temp->setText("connect");
       gclient.writeClient(gPlayer.get_username());
       uiPlay=new play;
       uiPlay->show();
       hide();
    }
    else{
        ui->label_temp->setStyleSheet("font: 600 14pt 'Sitka Banner Semibold'; color:#DC143C");
        ui->label_temp->setText("Not connect");
    }

}

void role::on_go_btn_clicked()
{
    if(gPlayer.get_role()=="server"){
        gserver.writeClient(gPlayer.get_username()+"%");
    }
    uiPlay=new play;
    uiPlay->show();
    hide();

}

void role::on_wait_btn_clicked()
{
    ui->label_temp->show();
    if(!gserver.get_data().isEmpty()){
        ui->label_temp->setStyleSheet("font: 600 14pt 'Sitka Banner Semibold'; color:#2E8B57");
        ui->label_temp->setText("connect");
        gPlayer.set_usernameOpponent(gserver.get_data());
        if(gPlayer.get_usernameOpponent()==" ")
            ui->showUsername_lbl->setText(gserver.get_data()+" is Ready");
        else{
             ui->showUsername_lbl->setText(gPlayer.get_username()+" is Ready");
        }
        gPlayer.set_usernameOpponent(gserver.get_data());
        ui->wait_btn->hide();
        ui->go_btn->show();
    }
    else{
        ui->label_temp->setStyleSheet("font: 600 14pt 'Sitka Banner Semibold'; color:#DC143C");
        ui->label_temp->setText("Not connect");
    }
}

