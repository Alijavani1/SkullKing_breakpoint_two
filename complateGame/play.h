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
class menue;
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
    void show_lose();
    void show_win();
    void show_stop();
    void hide_stop();
    void showError(QString error);
    void show_startBtn();
    void show_randomBtn();
    void show_clientPlay();
    void hidLosecard();
    void saveFile();
    void showlabel2(QString image);
    void stopTimer();
    void runTimer();
    void runTimer_stop();
    void randomCard();
    void close();
    void Enable_false();
    void Enable_true();
    void writeUsername(QString a);

    void show_stickerlabel(QString a);

public slots:
    void startTimer();
    void timer_Stop();
private slots:
    void on_pushButton_play_clicked();
    void on_pushButton_start_clicked();
    void on_pushButton_randcard_clicked();
    void on_close_button_clicked();
    void on_stop_button_clicked();
    void on_Resume_button_clicked();
    void on_chat_button_clicked();
    void on_stickerButton_2_clicked();
    void on_stickerButton_3_clicked();
    void on_stickerButton_4_clicked();
    void on_stickerButton_1_clicked();

    void on_cardButton_1_clicked();
    void on_cardButton_2_clicked();
    void on_cardButton_3_clicked();
    void on_cardButton_4_clicked();


    void on_error_btn_clicked();


    void on_close_button_2_clicked();

private:
    QTimer *timer;
    QTimer *timer1;
    Ui::play *ui;
    menue*temp;


};
extern play *uiPlay;
#endif // PLAY_H
