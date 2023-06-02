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


void MainWindow::on_login_btn_clicked()
{
    //login

}


void MainWindow::on_pushButton_clicked()
{
    //forgot password
    temp1=new ForgotPass();
    temp1->show();
    hide();
}


void MainWindow::on_pushButton_2_clicked()
{
    //creat new account
    temp2=new Registery();
    temp2->show();
    hide();
}

