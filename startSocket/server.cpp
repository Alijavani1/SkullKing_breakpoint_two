#include "server.h"

Server::Server(QObject *parent)
    : QObject{parent}
{
}

Server::Server(const Server & serv){
    server = serv.server;
    socket = serv.socket;
}

void Server:: newConnection(){
    while (server->hasPendingConnections()) {
        socket = server->nextPendingConnection();
    }
}

QHostAddress Server::getIp(){
    auto ip = QHostInfo::fromName(QHostInfo::localHostName()).addresses();
    return ip[1];
}

int Server::is_connect(){
   server = new QTcpServer(this);

   if(server->listen(QHostAddress::Any, 8080))
   {
      connect(server, &QTcpServer::newConnection, this, &Server::newConnection);
      return 1;
  }
   else
   {
        return 0;
   }
}
