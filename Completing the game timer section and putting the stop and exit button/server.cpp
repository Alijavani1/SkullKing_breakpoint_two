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
    if(data=="~"){
        gPlayer.set_clickPlay("~");
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
             qInfo()<<"fyguhj";
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
