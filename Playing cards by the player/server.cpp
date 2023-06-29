#include "server.h"

Server::Server(QObject *parent)
    : QObject{parent}
{

}

void Server:: newConnection(){
    while (server->hasPendingConnections()) {
        socket = server->nextPendingConnection();
    }
    connect(socket, &QTcpSocket::readyRead, this, &Server::readyread);
}

QHostAddress Server::getIp(){
    auto ip = QHostInfo::fromName(QHostInfo::localHostName()).addresses();
    return ip[1];
}

void Server::is_connect(){
    server = new QTcpServer(this);
    if(server->listen(QHostAddress::Any, 8080))
    {
       connect(server, &QTcpServer::newConnection, this, &Server::newConnection);
    }
}

void Server::readyread(){

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
    if(data.contains("+*point*")){
         qInfo()<<data;
        QString tempData = QString(data);
        QStringList s = tempData.split("+");
        gPlayer.set_pointOpponent(s[0].toLong());
   }
    if(data.contains("^")&&data.contains("gpj")){
       qInfo()<<data;
      QString tempData = QString(data);
      QStringList s = tempData.split(')');
      QStringList p =s[1].split("^");
       card opponent;
       data=s[1].toLatin1();
       opponent.set_type(p[0]);
      opponent.set_value(p[1].toInt());
       gPlayer.set_playcardOpponent(opponent);
       gPlayer.set_nobat(1);
    }

}
void Server:: wait(int seconds){
    socket->waitForReadyRead(seconds);
}
void Server:: wait(){
    while(data=="/"){
    socket->waitForReadyRead(500);
    }
}

QString Server::get_data(){
    return data;
}

void Server::writeClient(QString data){
    QByteArray a  = data.toLatin1();
    socket->write(a);
    socket->flush();
}
void Server:: set_data(QString a){
    data=a.toLatin1();
};

Server gserver;
