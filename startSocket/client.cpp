#include "client.h"

Client::Client(QObject *parent)
    : QObject{parent}
{

}

int Client::connect(QString a){
    socket = new QTcpSocket(this);
    QHostAddress ip;
    ip.setAddress(a);
    socket->connectToHost(ip,8080);
    if(socket->waitForConnected(3000)){

       return 1;
    }
    else{

        return 0;
    }
}
