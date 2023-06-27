#include "play.h"
#include "ui_play.h"

play::play(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::play)
{
    ui->setupUi(this);
}

play::~play()
{
    delete ui;
}
