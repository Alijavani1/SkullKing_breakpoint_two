#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow:: login(player c){
    if(c.get_username()==ui->username_edt->text()){
        if(c.get_password()==ui->password_edt->text()){
            return 1;
        }
    }
    return 0;
}

void MainWindow::on_login_btn_clicked()
{
    //login

  // MainWindow reza;
  // reza.login(p1);
   // if(reza.login(p1)){
      // hide();
   // }

}


void MainWindow::on_pushButton_clicked()
{
    //forgot password
    temp1=new ForgotPass();
    temp1->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    //creat new account
    temp2=new Registery();
    temp2->show();
    hide();
}

