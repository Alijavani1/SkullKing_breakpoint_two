#include "client.h"

Client::Client(QObject *parent)
    : QObject{parent}
{
}

int Client::isconnect(QString a){
    socket = new QTcpSocket(this);
    QHostAddress ip;
    ip.setAddress(a);
    socket->connectToHost(ip,8080);
     connect(socket, &QTcpSocket::readyRead, this, &Client::readyread);
    if(socket->waitForConnected(3000)){

       return 1;
    }
    else{
        return 0;
    }
}
void Client::readyread(){
    data = socket->readAll();
    if(data.contains("%")){
        QString tempData = QString(data);
        QStringList s = tempData.split('%');
        uiPlay->writeUsername(s[0]);
    }
    if(data=="~"){
        gPlayer.set_clickPlay("~");
    }
    if(data=="randcard"){
        uiPlay->show_randomBtn();
    }
    if(data=="close{"){
        uiPlay->close();
    }
    if(data=="stop}"||data=="Resume#"){
        if(data=="stop}"){
           uiPlay->Enable_false();
        }
        if(data=="Resume#"){
           uiPlay->Enable_true();
        }
    }


    if(data.contains("client enable")){
        QString tempData = QString(data);
        QStringList s = tempData.split('?');
        QString value1 = s[1];
        QString value2 = s[2];
        card cardparrot1;
        cardparrot1.set_type("parrot");
        cardparrot1.set_value(value1.toInt());
        gPlayer.set_StratCard(cardparrot1);
        card cardparrot2;
        cardparrot2.set_type("parrot");
        cardparrot2.set_value(value2.toInt());
        gPlayer.set_playcardOpponent(cardparrot2);
        uiPlay->show_startBtn();

    }
    if(data.contains("^")){
      QString tempData = QString(data);
      QStringList s = tempData.split('^');
       card opponent;
       opponent.set_type(s[0]);
       opponent.set_value(s[1].toInt());
       gPlayer.set_playcardOpponent(opponent);
       gPlayer.set_nobat(1);
       QString b = "border-image: url(:/"+gPlayer.get_playcardOpponent().get_type();
       QString d = b+QString::number(gPlayer.get_playcardOpponent().get_value());
       QString card_image=d+".jpg)";
       uiPlay->showlabel2(card_image);
       if(gPlayer.get_countCard()==0){
           qInfo()<<"gjhkjkl";
       }

       if(gPlayer.get_countCard()!=0){
       uiPlay->runTimer();
       }
    }
    if(data.contains("+*point*")){
         qInfo()<<data;
        QString tempData = QString(data);
        QStringList s = tempData.split("+");
        gPlayer.set_pointOpponent(s[0].toLong());
   }
}

void Client:: wait(int seconds){

    socket->waitForReadyRead(seconds);
}

void Client:: wait(){
    while(data=="/"){
      socket->waitForReadyRead(500);
    }
}

QString Client::get_data(){
    return data;
}
void Client:: set_data(QString d){
    data=d.toLatin1();
}
void Client::writeClient(QString data){
    QByteArray a  = data.toLatin1();
    socket->write(a);
    socket->flush();
}
Client gclient;
