#include "forgotpass.h"
#include "ui_forgotpass.h"

ForgotPass::ForgotPass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ForgotPass)
{
    ui->setupUi(this);
}

ForgotPass::~ForgotPass()
{
    delete ui;
}
