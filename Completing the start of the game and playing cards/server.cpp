#include "server.h"

Server::Server(QObject *parent)
    : QObject{parent}
{

}

//Server::Server(const Server & serv){
  //  server = serv.server;
   // socket = serv.socket;
//}

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

}
void Server:: wait(){
    socket->waitForReadyRead(3000);
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
