#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostInfo>
#include "play.h"
class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    //Server(const Server & serv);
    void is_connect();
    void writeClient(QString data);
    QString get_data();
    void set_data(QString a);
    QHostAddress getIp();
    void wait(int seconds);
    void wait();

private slots:
    void newConnection();
    void readyread();
signals:
    void readyRead();
private:
    QTcpServer *server;
    QTcpSocket *socket;
    QByteArray data;

};
extern Server gserver;
#endif // SERVER_H
