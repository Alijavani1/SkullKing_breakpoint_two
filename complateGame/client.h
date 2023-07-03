#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "play.h"
#include <QStringList>
#include <QTimer>
class Client :public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    int isconnect(QString a);
    void writeClient(QString data);
    void wait(int seconds);
    void wait();
    QString get_data();
    void set_data(QString d);
private:
    QTcpSocket *socket;
    QByteArray data;
signals:
    void showlabel2();
    void readyRead();
private slots:
    void readyread();

};

extern Client gclient;
#endif // CLIENT_H
