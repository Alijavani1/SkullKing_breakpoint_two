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
    void hidLosecard();
    void saveFile();
    void showlabel2(QString image);
    void stopTimer();
    void runTimer();
    void randomCard();
    void close();
    void Enable_false();
     void Enable_true();
     void writeUsername(QString a);
public slots:
    void startTimer();
private slots:
    void on_pushButton_play_clicked();
    void on_pushButton_start_clicked();
    void on_pushButton_randcard_clicked();
    void on_close_button_clicked();
    void on_stop_button_clicked();
    void on_Resume_button_clicked();
    void on_cardButton_1_clicked();
    void on_cardButton_2_clicked();
    void on_cardButton_3_clicked();
     void on_cardButton_4_clicked();
    void on_cardButton_5_clicked();
    void on_cardButton_6_clicked();
    void on_cardButton_7_clicked();
    void on_cardButton_8_clicked();
   void on_cardButton_9_clicked();
    void on_cardButton_10_clicked();
     void on_cardButton_11_clicked();
      void on_cardButton_12_clicked();
       void on_cardButton_13_clicked();
        void on_cardButton_14_clicked();


        void on_error_btn_clicked();



        void on_close_button_2_clicked();

        void on_play_Button_clicked();

        void on_pushButton_clicked();

private:
    QTimer *timer;
    Ui::play *ui;
    menue*temp;

};
extern play *uiPlay;
#endif // PLAY_H
