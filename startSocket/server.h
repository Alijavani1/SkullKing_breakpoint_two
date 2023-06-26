#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostInfo>
class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    Server(const Server & serv);
    int is_connect();
    QHostAddress getIp();
private slots:
    void newConnection();
private:
    QTcpServer *server;
    QTcpSocket *socket;

};

#endif // SERVER_H
