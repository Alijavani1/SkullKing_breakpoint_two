#ifndef PLAY_H
#define PLAY_H

#include <QMainWindow>
#include "player.h"
#include <QTimer>
#include <QMessageBox>
#include <QFile>
//#include "server.h"
//#include "client.h"
//#include "game.h"
class game;
class Server;
class Client;
namespace Ui {
class play;
}

class play : public QMainWindow
{
    Q_OBJECT

public:
    explicit play(QWidget *parent = nullptr);
    ~play();
    void hidLosecard();
    void saveFile();
public slots:
    void showlabel2(QString image);
    void timerStart();
private slots:
    void on_pushButton_play_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_randcard_clicked();

    void on_cardButton_1_clicked();

    void on_cardButton_2_clicked();

private:
    Ui::play *ui;
    QTimer *timer;
};
extern play *uiPlay;
#endif // PLAY_H
