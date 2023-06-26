#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    int connect(QString a);
private:
    QTcpSocket *socket;

};

#endif // CLIENT_H
