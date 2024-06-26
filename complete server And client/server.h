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
  //  Server(const Server & serv);
    void is_connect();
    QHostAddress getIp();
    void writeServer(QString data );
      QString get_data();

private slots:
    void newConnection();
     void readyread();
private:
    QTcpServer *server;
    QTcpSocket *socket;
    QByteArray data;

};
extern Server gserver;
#endif // SERVER_H
