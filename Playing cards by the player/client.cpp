#include "client.h"

Client::Client(QObject *parent)
    : QObject{parent}
{
}
void Client :: set_data(QString a){
    data=a.toLatin1();
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
    if(data.contains("jpg")){
      qInfo()<<data;
      uiPlay->showlabel2(data);
    }
    if(data.contains("^")){
       qInfo()<<data;
      QString tempData = QString(data);
      QStringList s = tempData.split('^');
       card opponent;
       opponent.set_type(s[0]);
      opponent.set_value(s[1].toInt());
       gPlayer.set_playcardOpponent(opponent);
       gPlayer.set_nobat(1);
    }
    if(data.contains("^")&&data.contains("gpj")){
       qInfo()<<data;
      QString tempData = QString(data);
      QStringList s = tempData.split(')');
      data=s[1].toLatin1();
      QStringList p =s[1].split("^");
       card opponent;
       opponent.set_type(p[0]);
      opponent.set_value(p[1].toInt());
       gPlayer.set_playcardOpponent(opponent);
       gPlayer.set_nobat(1);
    }
    if(data.contains("+*point*")){
         qInfo()<<data;
        QString tempData = QString(data);
        QStringList s = tempData.split("+");
        gPlayer.set_pointOpponent(s[0].toLong());
   }
}

void Client:: wait(int seconds){
    while(data==""){
    socket->waitForReadyRead(seconds);
    }
}
void Client:: wait(){
    while(data=="/"){
    socket->waitForReadyRead(500);
    }
}

QString Client::get_data(){
    return data;
}

void Client::writeClient(QString data){
    QByteArray a  = data.toLatin1();
    socket->write(a);
    socket->flush();
}
Client gclient;
