#include "play.h"
#include "ui_play.h"
#include "server.h"
#include "client.h"
#include "game.h"
#include"menue.h"
play::play(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::play)
{
    ui->setupUi(this);
    ui->cardButton_1->hide();    ui->cardlabel_1->hide();       ui->wincardlabel_10->hide();
    ui->cardButton_10->hide();   ui->cardlabel_10->hide();       ui->wincardlabel_12->hide();
    ui->cardButton_11->hide();   ui->cardlabel_11->hide();      ui->wincardlabel_14->hide();
    ui->cardButton_12->hide();   ui->cardlabel_12->hide();      ui->wincardlabel_1->hide();
    ui->cardButton_13->hide();   ui->cardlabel_13->hide();      ui->wincardlabel_11->hide();
    ui->cardButton_14->hide();   ui->cardlabel_14->hide();       ui->wincardlabel_13->hide();
    ui->cardButton_2->hide();    ui->cardlabel_9->hide();       ui->wincardlabel_2->hide();
    ui->cardButton_3->hide();    ui->cardlabel_2->hide();       ui->wincardlabel_3->hide();
    ui->cardButton_4->hide();    ui->cardlabel_3->hide();       ui->wincardlabel_5->hide();
    ui->cardButton_5->hide();    ui->cardlabel_4->hide();       ui->wincardlabel_4->hide();
    ui->cardButton_6->hide();    ui->cardlabel_5->hide();       ui->wincardlabel_6->hide();
    ui->cardButton_7->hide();    ui->cardlabel_6->hide();       ui->wincardlabel_7->hide();
    ui->cardButton_8->hide();    ui->cardlabel_7->hide();       ui->wincardlabel_8->hide();
    ui->cardButton_9->hide();    ui->cardlabel_8->hide();       ui->wincardlabel_9->hide();
    ui->losecardlardlabel_1->hide();    ui->played_label_1->hide();
    ui->losecardlardlabel_10->hide();   ui->played_label_2->hide();
    ui->losecardlardlabel_11->hide();   ui->pushButton_play->setEnabled(false);
    ui->losecardlardlabel_12->hide();   ui->lineEdit_predicet->setEnabled(false);
    ui->losecardlardlabel_13->hide();    ui->pushButton_randcard->setEnabled(false);
    ui->losecardlardlabel_2->hide();     ui->pushButton_start->hide();
    ui->losecardlardlabel_14->hide();    ui->pushButton_randcard->hide();
    ui->losecardlardlabel_3->hide();     ui->pushButton_play->hide();
    ui->losecardlardlabel_5->hide();
    ui->losecardlardlabel_4->hide();
    ui->losecardlardlabel_6->hide();
    ui->losecardlardlabel_7->hide();
    ui->losecardlardlabel_8->hide();
    ui->losecardlardlabel_9->hide();
    ui->wood_label->hide();
        ui->win_Label->hide();
        ui->addcoin_label->hide();
        ui->coin_label->hide();
        ui->close_button_2->hide();
        ui->Resume_button->hide();
        ui->label_6->hide();
        ui->timeResume_lbl->hide();
        ui->error_btn->hide();
        ui->error_label->hide();
        ui->error_label_2->hide();

        ui->stickerButton_2->hide();
        ui->stickerButton_3->hide();
        ui->stickerButton_4->hide();
        ui->stickerButton_1->hide();
        ui->frame_stiker->hide();
        ui->label_image->hide();
        ui->chat_button->setEnabled(false);

    if(gPlayer.get_role()=="server"){
        ui->pushButton_start->show();
        ui->pushButton_play->show();
    }
}

play::~play()
{
    delete ui;
}
void play::show_win(){
    ui->wood_label->show();
    ui->win_Label->show();
    ui->addcoin_label->show();
    ui->coin_label->show();
    ui->close_button_2->show();
    ui->win_Label->setStyleSheet("border-image: url(:/winlabel.png)");
    ui->addcoin_label->setText("+100");
}

void play::show_lose(){
    ui->wood_label->show();
    ui->win_Label->show();
    ui->addcoin_label->show();
    ui->coin_label->show();
    ui->close_button_2->show();
    ui->win_Label->setStyleSheet("border-image: url(:/loseLabel.png)");
    ui->addcoin_label->setText("-100");
}

void play::show_stop(){
    ui->wood_label->show();
    ui->coin_label->show();
    ui->addcoin_label->show();
    ui->Resume_button->show();
    ui->label_6->show();
    ui->timeResume_lbl->show();
    ui->addcoin_label->setText(QString::number(gPlayer.get_coin()));
}
void play::hide_stop(){
    ui->wood_label->hide();
    ui->coin_label->hide();
    ui->addcoin_label->hide();
    ui->close_button_2->hide();
    ui->Resume_button->hide();
    ui->label_6->hide();
    ui->timeResume_lbl->hide();
    ui->addcoin_label->setText(QString::number(gPlayer.get_coin()));
}

void play ::showError(QString error){
    ui->error_btn->show();
    ui->error_label->show();
    ui->error_label_2->show();
    ui->error_label_2->setText(error);
}
void play:: show_clientPlay(){
    ui->pushButton_play->show();
}
void play ::show_startBtn(){
    on_pushButton_start_clicked();
}

void play::show_randomBtn(){
    gclient.wait(4000);
    on_pushButton_randcard_clicked();
}
//*********************************************************************************************
void play:: Enable_false(){
     ui->cardButton_1->setEnabled(false);
     ui->cardButton_2->setEnabled(false);
     ui->cardButton_3->setEnabled(false);
     ui->cardButton_4->setEnabled(false);
     ui->cardButton_5->setEnabled(false);
     ui->cardButton_6->setEnabled(false);
     ui->cardButton_7->setEnabled(false);
     ui->cardButton_8->setEnabled(false);
     ui->cardButton_9->setEnabled(false);
     ui->cardButton_10->setEnabled(false);
     ui->cardButton_11->setEnabled(false);
     ui->cardButton_12->setEnabled(false);
     ui->cardButton_13->setEnabled(false);
     ui->cardButton_14->setEnabled(false);
     ui->pushButton_randcard->setEnabled(false);
     ui->pushButton_play->setEnabled(false);
     ui->lineEdit_predicet->setEnabled(false);
     ui->stop_button->setEnabled(false);
     ui->close_button->setEnabled(false);
     ui->stickerButton_2->setEnabled(false);
     ui->stickerButton_3->setEnabled(false);
     ui->stickerButton_4->setEnabled(false);
     ui->stickerButton_1->setEnabled(false);
     ui->chat_button->setEnabled(false);
}
void play:: Enable_true(){
    ui->cardButton_1->setEnabled(true);
    ui->cardButton_2->setEnabled(true);
    ui->cardButton_3->setEnabled(true);
    ui->cardButton_4->setEnabled(true);
    ui->cardButton_5->setEnabled(true);
    ui->cardButton_6->setEnabled(true);
    ui->cardButton_7->setEnabled(true);
    ui->cardButton_8->setEnabled(true);
    ui->cardButton_9->setEnabled(true);
    ui->cardButton_10->setEnabled(true);
    ui->cardButton_11->setEnabled(true);
    ui->cardButton_12->setEnabled(true);
    ui->cardButton_13->setEnabled(true);
    ui->cardButton_14->setEnabled(true);
    ui->pushButton_randcard->setEnabled(true);
    ui->pushButton_play->setEnabled(true);
    ui->lineEdit_predicet->setEnabled(true);
    ui->stop_button->setEnabled(true);
    ui->close_button->setEnabled(true);
    ui->stickerButton_2->setEnabled(true);
    ui->stickerButton_3->setEnabled(true);
    ui->stickerButton_4->setEnabled(true);
    ui->stickerButton_1->setEnabled(true);
    ui->chat_button->setEnabled(true);

}
void play:: close(){
    gPlayer.set_win(gPlayer.get_win()+1);
    gPlayer.set_coin(gPlayer.get_coin()+100);
    saveFile();
    Enable_false();
    show_win();
}

void play:: randomCard(){
    game game1;
    srand(time(NULL));
    int r = rand() %(gPlayer.get_turn()*2);
    gPlayer.set_playedCard(gPlayer.get_playerCards()[r]);
    while(!game1.isValid()||gPlayer.get_playerCards()[r].get_type()==""){
        r=rand() %(gPlayer.get_turn()*2);
         gPlayer.set_playedCard(gPlayer.get_playerCards()[r]);
    }
    if(r==0){
          on_cardButton_1_clicked();
    }
    if(r==1){
          on_cardButton_2_clicked();
    }
    if(r==2){
          on_cardButton_3_clicked();
    }
    if(r==3){
          on_cardButton_4_clicked();
    }



}
void play:: writeUsername(QString a){
    ui->usernameLabel->setText(a);
}
void play::showlabel2(QString image){
    ui->played_label_2->show();
    ui->played_label_2->setStyleSheet(image);
}


//************************************************************
//timer player
void play:: runTimer(){
    timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()),this, SLOT(startTimer()));
     timer->start(1000);
}
int timePlayer =0;
void play::startTimer(){
    ui->time_label->setText(QString::number(timePlayer));
       if(timePlayer==20){
           timePlayer=0;
           timer->stop();
           randomCard();
       }
       else{
       timePlayer++;
         ui->time_label->setText(QString::number(timePlayer));
       }
}

void play:: stopTimer(){
    ui->time_label->setText(QString::number(0));
    timer->stop();
}

//timer Stop
void play::runTimer_stop(){
    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()),this, SLOT(timer_Stop()));
    timer1->start(1000);
}
int timeStop=0;
void play::timer_Stop(){
    ui->timeResume_lbl->setText(QString::number(timeStop));
    if(timeStop==20){
        timer1->stop();
        on_Resume_button_clicked();
    }
    else{
        timeStop++;
         ui->timeResume_lbl->setText(QString::number(timeStop));
    }
}
//Sticker
void play::show_stickerlabel(QString a){
     ui->label_image->show();
     ui->label_image->setStyleSheet(a);
}

void play::on_stickerButton_2_clicked()
{
    ui->label_image->show();
    ui->label_image->setStyleSheet("border-image: url(:/sticker1.png)");
    if(gPlayer.get_role()=="server"){
        gserver.writeClient("1$");

    }
    if(gPlayer.get_role()=="client"){
        gclient.writeClient("1$");

    }
    ui->frame_stiker->hide();
    ui->stickerButton_2->hide();
    ui->stickerButton_3->hide();
    ui->stickerButton_4->hide();
    ui->stickerButton_1->hide();

}


void play::on_stickerButton_3_clicked()
{
    ui->label_image->show();
    ui->label_image->setStyleSheet("border-image: url(:/sticker2.png)");
    if(gPlayer.get_role()=="server"){
        gserver.writeClient("2$");

    }
    if(gPlayer.get_role()=="client"){
        gclient.writeClient("2$");

    }
    ui->frame_stiker->hide();
    ui->stickerButton_2->hide();
    ui->stickerButton_3->hide();
    ui->stickerButton_4->hide();
    ui->stickerButton_1->hide();

}


void play::on_stickerButton_4_clicked()
{
    ui->label_image->show();
    ui->label_image->setStyleSheet("border-image: url(:/sticker3.png)");
    if(gPlayer.get_role()=="server"){
        gserver.writeClient("3$");

    }
    if(gPlayer.get_role()=="client"){
        gclient.writeClient("3$");

    }
    ui->frame_stiker->hide();
    ui->stickerButton_2->hide();
    ui->stickerButton_3->hide();
    ui->stickerButton_4->hide();
    ui->stickerButton_1->hide();

}


void play::on_stickerButton_1_clicked()
{
    ui->label_image->show();
    ui->label_image->setStyleSheet("border-image: url(:/sticker4.png)");
    if(gPlayer.get_role()=="server"){
        gserver.writeClient("4$");

    }
    if(gPlayer.get_role()=="client"){
        gclient.writeClient("4$");

    }
    ui->frame_stiker->hide();
    ui->stickerButton_2->hide();
    ui->stickerButton_3->hide();
    ui->stickerButton_4->hide();
    ui->stickerButton_1->hide();

}
void play::on_chat_button_clicked()
{
    ui->frame_stiker->show();
    ui->stickerButton_2->show();
    ui->stickerButton_3->show();
    ui->stickerButton_4->show();
    ui->stickerButton_1->show();
}

//*******************************************************************************
void play:: hidLosecard(){
    ui->losecardlardlabel_1->hide();
    ui->losecardlardlabel_10->hide();
    ui->losecardlardlabel_11->hide();
    ui->losecardlardlabel_12->hide();
    ui->losecardlardlabel_13->hide();
    ui->losecardlardlabel_2->hide();
    ui->losecardlardlabel_14->hide();
    ui->losecardlardlabel_3->hide();
    ui->losecardlardlabel_5->hide();
    ui->losecardlardlabel_4->hide();
    ui->losecardlardlabel_6->hide();
    ui->losecardlardlabel_7->hide();
    ui->losecardlardlabel_8->hide();
    ui->losecardlardlabel_9->hide();

    ui->wincardlabel_1->hide();
    ui->wincardlabel_2->hide();
    ui->wincardlabel_3->hide();
    ui->wincardlabel_4->hide();
    ui->wincardlabel_5->hide();
    ui->wincardlabel_6->hide();
    ui->wincardlabel_7->hide();
    ui->wincardlabel_8->hide();
    ui->wincardlabel_9->hide();
    ui->wincardlabel_10->hide();
    ui->wincardlabel_11->hide();
    ui->wincardlabel_12->hide();
    ui->wincardlabel_13->hide();
    ui->wincardlabel_14->hide();
}
void play:: saveFile(){
    QVector<player>::Iterator it;
    for(it=filePlayer.begin();it!=filePlayer.end();it++){
        if(it->get_username()==gPlayer.get_username()&&it->get_phoneNumber()==gPlayer.get_phoneNumber()&&it->get_password()==gPlayer.get_password()){
            it->set_username(gPlayer.get_username());
            it->set_phoneNumber(gPlayer.get_phoneNumber());
            it->set_password(gPlayer.get_password());
            it->set_coin(gPlayer.get_coin());
            it->set_lose(gPlayer.get_lose());
            it->set_win(gPlayer.get_win());
        }
    }
    player player;

    QFile file("player.txt");
    if(file.open(QIODevice::WriteOnly)){
        for(it=filePlayer.begin();it!=filePlayer.end();it++){
            player=*it;
        QTextStream stream (&file);
        stream<<player;
        }
    }
}
//8888888888888888888888888888888888888888888888888888888888888888888888
void play::on_close_button_clicked()
{
    gPlayer.set_lose(gPlayer.get_lose()+1);
    saveFile();
    Enable_false();
    show_lose();

    if(gPlayer.get_role()=="server"){
        gserver.writeClient("close{");
    }
    if(gPlayer.get_role()=="client"){
          gclient.writeClient("close{");
    }

}

void play::on_stop_button_clicked()
{

    if(gPlayer.get_stop()>2){
       showError("cannot stop maore than 2!");
    }
    else{
        runTimer_stop();
        gPlayer.set_stop(gPlayer.get_stop()+1);

        if(gPlayer.get_role()=="server"){
            gserver.writeClient("stop}");
        }
        if(gPlayer.get_role()=="client"){
              gclient.writeClient("stop}");
        }
        if(gPlayer.get_nobat()){
            stopTimer();
        }
        Enable_false();
        timer->stop();
        show_stop();
    }
}

void play::on_Resume_button_clicked()
{
    if(gPlayer.get_role()=="server"){
        gserver.writeClient("Resume#");
    }
    if(gPlayer.get_role()=="client"){
          gclient.writeClient("Resume#");
    }
    timer1->stop();
    timeStop=0;
    hide_stop();
    Enable_true();
    if(gPlayer.get_nobat()==1){
        runTimer();
    }
}
//******************************************************************************************************
void play::on_pushButton_play_clicked()
{
    ui->chat_button->setEnabled(true);
    if(gPlayer.get_role()=="server"){
        gserver.writeClient("on_clicke_play");
        QEventLoop loop;
        connect( &gserver, &Server::readyRead, &loop, &QEventLoop::quit );
        loop.exec();
    }
    if(gPlayer.get_role()=="client"){
        gclient.writeClient("on_clicke_play");

    }
    Enable_true();
    ui->pushButton_randcard->setEnabled(true);
    ui->lineEdit_predicet->setEnabled(false);
    ui->pushButton_play->setEnabled(false);
     gPlayer.set_predict_win(ui->lineEdit_predicet->text().toInt());
     ui->played_label_1->hide();
     ui->played_label_2->hide();

     if(gPlayer.get_start()){
            runTimer();
         }
     ui->chat_button->setEnabled(true);

}

void play::on_pushButton_start_clicked()
{
    ui->pushButton_start->hide();  
    Enable_false();
    ui->lineEdit_predicet->setEnabled(true);
    ui->pushButton_play->setEnabled(true);
    gPlayer.set_coin(gPlayer.get_coin()-50);
    gPlayer.set_countCard(gPlayer.get_turn()*2);
     game game1;
     int r1,r2;
     if(gPlayer.get_role()=="server"){
         ui->usernameLabel->setText(gPlayer.get_usernameOpponent());
         ui->pushButton_randcard->show();
         r2 = game1.howStart();
         r1 = gPlayer.get_stratCard().get_value();
         QString parrotcards="client enable?"+QString::number(r2+1)+"?"+QString::number(r1);
         gserver.writeClient(parrotcards);

         QString c = QString::number(r1);
         QString b = "border-image: url(:/parrot"+c;
         QString d = b+".jpg)";
          ui->played_label_1->show();
          ui->played_label_1->setStyleSheet(d);
          c = QString::number(r2+1);
          b = "border-image: url(:/parrot"+c;
          d = b+".jpg)";
          ui->played_label_2->show();
          ui->played_label_2->setStyleSheet(d);
          if(r1>r2){
            gPlayer.set_start(1);
            gPlayer.set_nobat(1);
          }
          QEventLoop loop;
          connect( &gserver, &Server::readyRead, &loop, &QEventLoop::quit );
          loop.exec();
     }
     else if(gPlayer.get_role()=="client"){
         gclient.writeClient("on_clicke_start");
         QString c = QString::number(gPlayer.get_stratCard().get_value());
         QString b = "border-image: url(:/parrot"+c;
         QString d = b+".jpg)";
          ui->played_label_1->show();
          ui->played_label_1->setStyleSheet(d);
          c = QString::number(gPlayer.get_playcardOpponent().get_value());
          b = "border-image: url(:/parrot"+c;
          d = b+".jpg)";
          ui->played_label_2->show();
          ui->played_label_2->setStyleSheet(d);
          if(gPlayer.get_stratCard().get_value()>gPlayer.get_playcardOpponent().get_value()){
            gPlayer.set_start(1);
            gPlayer.set_nobat(1);
     }
    }

     game1.randomCard();
     QVector<QString>temp;
     for(int i=0;game1.get_dore()*2>i;i++){
        QList<card>playercards=gPlayer.get_playerCards();
        int r = playercards[i].get_value();
        QString a=playercards[i].get_type();
         QString c = QString::number(r);
         QString b = "border-image: url(:/"+a;
         QString d = b+c;
         QString g=d+".jpg)";
         temp.push_back(g);
     }

     if(game1.get_dore()==1){
         ui->cardButton_1->show();
         ui->cardButton_2->show();
         ui->cardlabel_1->show();
         ui->cardlabel_2->show();
         ui->cardButton_1->setStyleSheet(temp[0]);
         ui->cardButton_2->setStyleSheet(temp[1]);
         gPlayer.set_countCard(2);
     }

}

void play::on_pushButton_randcard_clicked()
{
    if(gPlayer.get_role()=="server"){
        gserver.writeClient("randcard");
        QEventLoop loop;
        connect( &gserver, &Server::readyRead, &loop, &QEventLoop::quit );
        loop.exec();
    }
    else if(gPlayer.get_role()=="client"){
        gclient.writeClient("randcard");
    }
    ui->pushButton_randcard->setEnabled(false);
    ui->lineEdit_predicet->setEnabled(true);
    ui->pushButton_play->setEnabled(true);
    hidLosecard();
    game game1;
    gPlayer.set_turn(gPlayer.get_turn());
    game1.set_dore(gPlayer.get_turn());
    gPlayer.set_countCard(gPlayer.get_turn()*2);
    game1.randomCard();
    QVector<QString>temp;
     QList<card>playercards=gPlayer.get_playerCards();
    for(int i=0;game1.get_dore()*2>i;i++){
       int r = playercards[i].get_value();
       QString a=playercards[i].get_type();
        QString c = QString::number(r);
        QString b = "border-image: url(:/"+a;
        QString d = b+c;
        QString g=d+".jpg)";
         temp.push_back(g);

    }

    if(game1.get_dore()==2){
        ui->cardButton_1->show();
        ui->cardButton_2->show();
        ui->cardButton_3->show();
        ui->cardButton_4->show();
        ui->cardlabel_1->show();
        ui->cardlabel_2->show();
        ui->cardlabel_3->show();
        ui->cardlabel_4->show();
        ui->cardButton_1->setStyleSheet(temp[0]);
        ui->cardButton_2->setStyleSheet(temp[1]);
        ui->cardButton_3->setStyleSheet(temp[2]);
        ui->cardButton_4->setStyleSheet(temp[3]);
    }
    if(game1.get_dore()==3){
        ui->cardButton_1->show();
        ui->cardButton_2->show();
        ui->cardButton_3->show();
        ui->cardButton_4->show();
        ui->cardButton_5->show();
        ui->cardButton_6->show();
        ui->cardlabel_1->show();
        ui->cardlabel_2->show();
        ui->cardlabel_3->show();
        ui->cardlabel_4->show();
        ui->cardlabel_5->show();
        ui->cardlabel_6->show();
        ui->cardButton_1->setStyleSheet(temp[0]);
        ui->cardButton_2->setStyleSheet(temp[1]);
        ui->cardButton_3->setStyleSheet(temp[2]);
        ui->cardButton_4->setStyleSheet(temp[3]);
         ui->cardButton_5->setStyleSheet(temp[4]);
          ui->cardButton_6->setStyleSheet(temp[5]);
    }
    if(game1.get_dore()==4){
        ui->cardButton_1->show();
        ui->cardButton_2->show();
        ui->cardButton_3->show();
        ui->cardButton_4->show();
        ui->cardButton_5->show();
        ui->cardButton_6->show();
        ui->cardButton_7->show();
        ui->cardButton_8->show();
        ui->cardlabel_1->show();
        ui->cardlabel_2->show();
        ui->cardlabel_3->show();
        ui->cardlabel_4->show();
        ui->cardlabel_5->show();
        ui->cardlabel_6->show();
        ui->cardlabel_7->show();
        ui->cardlabel_8->show();
        ui->cardButton_1->setStyleSheet(temp[0]);
        ui->cardButton_2->setStyleSheet(temp[1]);
        ui->cardButton_3->setStyleSheet(temp[2]);
        ui->cardButton_4->setStyleSheet(temp[3]);
        ui->cardButton_5->setStyleSheet(temp[4]);
        ui->cardButton_6->setStyleSheet(temp[5]);
        ui->cardButton_7->setStyleSheet(temp[6]);
         ui->cardButton_8->setStyleSheet(temp[7]);
    }
    if(game1.get_dore()==5){
        ui->cardButton_1->show();
        ui->cardButton_2->show();
        ui->cardButton_3->show();
        ui->cardButton_4->show();
        ui->cardButton_5->show();
        ui->cardButton_6->show();
        ui->cardButton_7->show();
        ui->cardButton_8->show();
        ui->cardButton_9->show();
        ui->cardButton_10->show();
        ui->cardlabel_1->show();
        ui->cardlabel_2->show();
        ui->cardlabel_3->show();
        ui->cardlabel_4->show();
        ui->cardlabel_5->show();
        ui->cardlabel_6->show();
        ui->cardlabel_7->show();
        ui->cardlabel_8->show();
         ui->cardlabel_9->show();
          ui->cardlabel_10->show();
        ui->cardButton_1->setStyleSheet(temp[0]);
        ui->cardButton_2->setStyleSheet(temp[1]);
        ui->cardButton_3->setStyleSheet(temp[2]);
        ui->cardButton_4->setStyleSheet(temp[3]);
        ui->cardButton_5->setStyleSheet(temp[4]);
        ui->cardButton_6->setStyleSheet(temp[5]);
        ui->cardButton_7->setStyleSheet(temp[6]);
         ui->cardButton_8->setStyleSheet(temp[7]);
          ui->cardButton_9->setStyleSheet(temp[8]);
           ui->cardButton_10->setStyleSheet(temp[9]);

    }
    if(game1.get_dore()==6){
        ui->cardButton_1->show();
        ui->cardButton_2->show();
        ui->cardButton_3->show();
        ui->cardButton_4->show();
        ui->cardButton_5->show();
        ui->cardButton_6->show();
        ui->cardButton_7->show();
        ui->cardButton_8->show();
        ui->cardButton_9->show();
        ui->cardButton_10->show();
         ui->cardButton_11->show();
          ui->cardButton_12->show();
        ui->cardlabel_1->show();
        ui->cardlabel_2->show();
        ui->cardlabel_3->show();
        ui->cardlabel_4->show();
        ui->cardlabel_5->show();
        ui->cardlabel_6->show();
        ui->cardlabel_7->show();
        ui->cardlabel_8->show();
         ui->cardlabel_9->show();
          ui->cardlabel_10->show();
          ui->cardlabel_11->show();
          ui->cardlabel_12->show();
        ui->cardButton_1->setStyleSheet(temp[0]);
        ui->cardButton_2->setStyleSheet(temp[1]);
        ui->cardButton_3->setStyleSheet(temp[2]);
        ui->cardButton_4->setStyleSheet(temp[3]);
        ui->cardButton_5->setStyleSheet(temp[4]);
        ui->cardButton_6->setStyleSheet(temp[5]);
        ui->cardButton_7->setStyleSheet(temp[6]);
         ui->cardButton_8->setStyleSheet(temp[7]);
          ui->cardButton_9->setStyleSheet(temp[8]);
           ui->cardButton_10->setStyleSheet(temp[9]);
            ui->cardButton_11->setStyleSheet(temp[10]);
             ui->cardButton_12->setStyleSheet(temp[11]);

    }
    if(game1.get_dore()==7){
        ui->cardButton_1->show();
        ui->cardButton_2->show();
        ui->cardButton_3->show();
        ui->cardButton_4->show();
        ui->cardButton_5->show();
        ui->cardButton_6->show();
        ui->cardButton_7->show();
        ui->cardButton_8->show();
        ui->cardButton_9->show();
        ui->cardButton_10->show();
        ui->cardButton_11->show();
        ui->cardButton_12->show();
        ui->cardButton_13->show();
        ui->cardButton_14->show();
        ui->cardlabel_1->show();
        ui->cardlabel_2->show();
        ui->cardlabel_3->show();
        ui->cardlabel_4->show();
        ui->cardlabel_5->show();
        ui->cardlabel_6->show();
        ui->cardlabel_7->show();
        ui->cardlabel_8->show();
        ui->cardlabel_9->show();
        ui->cardlabel_10->show();
        ui->cardlabel_11->show();
        ui->cardlabel_12->show();
        ui->cardlabel_13->show();
        ui->cardlabel_14->show();
        ui->cardButton_1->setStyleSheet(temp[0]);
        ui->cardButton_2->setStyleSheet(temp[1]);
        ui->cardButton_3->setStyleSheet(temp[2]);
        ui->cardButton_4->setStyleSheet(temp[3]);
        ui->cardButton_5->setStyleSheet(temp[4]);
        ui->cardButton_6->setStyleSheet(temp[5]);
        ui->cardButton_7->setStyleSheet(temp[6]);
         ui->cardButton_8->setStyleSheet(temp[7]);
          ui->cardButton_9->setStyleSheet(temp[8]);
           ui->cardButton_10->setStyleSheet(temp[9]);
            ui->cardButton_11->setStyleSheet(temp[10]);
             ui->cardButton_12->setStyleSheet(temp[11]);
             ui->cardButton_13->setStyleSheet(temp[12]);
              ui->cardButton_14->setStyleSheet(temp[13]);
    }

}
//***************************************************************************************************
void play::on_cardButton_1_clicked()
{
    if(gPlayer.get_nobat()==0){
     showError("It is not your turn!");
    }
    else{
        gPlayer.set_playedCard(gPlayer.get_playerCards()[0]);
        game game1;
        game1.set_dore(gPlayer.get_turn());

       if(gPlayer.get_start()==1){
           gPlayer.set_playedCard(gPlayer.get_playerCards()[0]);
           gPlayer.set_nobat(0);
           gPlayer.set_countCard(gPlayer.get_countCard()-1);
           timePlayer=0;
           stopTimer();

           QString type = gPlayer.get_playedCard().get_type();
           QString value = QString::number(gPlayer.get_playedCard().get_value());
           QString card = type+"^"+value;

           QString b = "border-image: url(:/"+gPlayer.get_playedCard().get_type();
           QString d = b+QString::number(gPlayer.get_playedCard().get_value());
           QString g=d+".jpg)";
           ui->played_label_1->show();
           ui->played_label_1->setStyleSheet(g);
           ui->cardButton_1->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
               QEventLoop loop;
               connect( &gserver, &Server::readyRead, &loop, &QEventLoop::quit );
               loop.exec();
               ui->cardlabel_1->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               QEventLoop loop;
               connect( &gclient, &Client::readyRead, &loop, &QEventLoop::quit );
               loop.exec();
               ui->cardlabel_1->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0){
           ui->cardlabel_1->hide();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[0]);
           gPlayer.set_nobat(0);
           gPlayer.set_countCard(gPlayer.get_countCard()-1);

           QString type = gPlayer.get_playedCard().get_type();
           QString value = QString::number(gPlayer.get_playedCard().get_value());
           QString card = type+"^"+value;

           QString b = "border-image: url(:/"+gPlayer.get_playedCard().get_type();
           QString d = b+QString::number(gPlayer.get_playedCard().get_value());
           QString card_image=d+".jpg)";

           ui->played_label_1->show();
           ui->played_label_1->setStyleSheet(card_image);
           ui->cardButton_1->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);

           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
           }

       }
       else{
        showError("Card is not valid");
       }
        timePlayer=0;
        stopTimer();
     if(game1.isValid()){
         if(game1.playerWin()){
              gPlayer.get_playerCards()[0].set_type("");


             //ui->played_label_1->hide();
             //ui->played_label_2->hide();
            timePlayer = 0;
            runTimer();
             if(gPlayer.get_takeWin()==1)
                 ui->wincardlabel_1->show();
             if(gPlayer.get_takeWin()==2)
                 ui->wincardlabel_2->show();
             if(gPlayer.get_takeWin()==3)
                 ui->wincardlabel_3->show();
             if(gPlayer.get_takeWin()==4)
                 ui->wincardlabel_4->show();
             if(gPlayer.get_takeWin()==5)
                 ui->wincardlabel_5->show();
             if(gPlayer.get_takeWin()==6)
                 ui->wincardlabel_6->show();
             if(gPlayer.get_takeWin()==7)
                 ui->wincardlabel_7->show();
             if(gPlayer.get_takeWin()==8)
                 ui->wincardlabel_8->show();
             if(gPlayer.get_takeWin()==9)
                 ui->wincardlabel_9->show();
             if(gPlayer.get_takeWin()==10)
                 ui->wincardlabel_10->show();
             if(gPlayer.get_takeWin()==11)
                 ui->wincardlabel_11->show();
             if(gPlayer.get_takeWin()==12)
                 ui->wincardlabel_12->show();
             if(gPlayer.get_takeWin()==13)
                 ui->wincardlabel_13->show();
             if(gPlayer.get_takeWin()==14)
                 ui->wincardlabel_14->show();
         }
         else{
              gPlayer.get_playerCards()[0].set_type("");

               timePlayer=0;
               stopTimer();

             if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==1)
                 ui->losecardlardlabel_1->show();
             if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==2)
                 ui->losecardlardlabel_2->show();
             if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==3)
                 ui->losecardlardlabel_3->show();
             if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==4)
                 ui->losecardlardlabel_4->show();
             if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==5)
                 ui->losecardlardlabel_5->show();
             if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==6)
                 ui->losecardlardlabel_6->show();
             if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==7)
                 ui->losecardlardlabel_7->show();
             if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==8)
                 ui->losecardlardlabel_8->show();
             if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==9)
                 ui->losecardlardlabel_9->show();
             if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==10)
                 ui->losecardlardlabel_10->show();
             if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==11)
                 ui->losecardlardlabel_11->show();
             if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==12)
                 ui->losecardlardlabel_12->show();
             if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==13)
                 ui->losecardlardlabel_13->show();
             if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==14)
                 ui->losecardlardlabel_14->show();
         }

         if(gPlayer.get_countCard()==0){
             ui->pushButton_randcard->setEnabled(true);
             ui->pushButton_randcard->setEnabled(true);
             game1.scoring();
             timePlayer=0;
             stopTimer();
             gPlayer.set_takeWin(0);

                 if(gPlayer.get_role()=="server"){
                      gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                     // gserver.set_data("/");
                      QEventLoop loop;
                      connect( &gserver, &Server::readyRead, &loop, &QEventLoop::quit );
                      loop.exec();
                 }
                 if(gPlayer.get_role()=="client"){
                      gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                      ui->pushButton_play->hide();
                     // gclient.set_data("/");
                      QEventLoop loop;
                      connect( &gclient, &Client::readyRead, &loop, &QEventLoop::quit );
                      loop.exec();
                 }


             ui->mypoint_label->setText(QString::number(gPlayer.get_point()));
             ui->pointlabel_2->setText(QString::number(gPlayer.get_pointOpponent()));

             if(gPlayer.get_point()>gPlayer.get_pointOpponent()){
                 gPlayer.set_nobat(1);
                 gPlayer.set_start(1);
             }
             else if(gPlayer.get_point()<gPlayer.get_pointOpponent()){
                 gPlayer.set_nobat(0);
                 gPlayer.set_start(0);
             }
            if(gPlayer.get_turn()==2){
                if(gPlayer.get_point()>gPlayer.get_pointOpponent()){
                    gPlayer.set_win(gPlayer.get_win()+1);
                    gPlayer.set_coin(gPlayer.get_coin()+100);
                    show_win();
                }
                else{
                    gPlayer.set_lose(gPlayer.get_lose()+1);
                    show_lose();
                }
                saveFile();
            }
         }
     }

   }
}
void play::on_cardButton_2_clicked()
{
    if(gPlayer.get_nobat()==0){
       showError("It is not your turn");
    }
    else{
        game game1;
        game1.set_dore(gPlayer.get_turn());
        gPlayer.set_playedCard(gPlayer.get_playerCards()[1]);
       if(gPlayer.get_start()==1){
           gPlayer.set_playedCard(gPlayer.get_playerCards()[1]);
           gPlayer.set_nobat(0);
           gPlayer.set_countCard(gPlayer.get_countCard()-1);
           timePlayer=0;
           stopTimer();

          QString type = gPlayer.get_playedCard().get_type();
           QString value = QString::number(gPlayer.get_playedCard().get_value());
           QString card = type+"^"+value;

           QString b = "border-image: url(:/"+gPlayer.get_playedCard().get_type();
           QString d = b+QString::number(gPlayer.get_playedCard().get_value());
           QString card_image=d+".jpg)";

           ui->played_label_1->show();
           ui->played_label_1->setStyleSheet(card_image);
           qInfo()<<ui->played_label_1->styleSheet();
           ui->cardButton_2->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
               QEventLoop loop;
               connect( &gserver, &Server::readyRead, &loop, &QEventLoop::quit );
               loop.exec();
               ui->cardlabel_2->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               gclient.set_data("/");
               QEventLoop loop;
               connect( &gclient, &Client::readyRead, &loop, &QEventLoop::quit );
               loop.exec();
               ui->cardlabel_2->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0) {
            ui->cardlabel_2->hide();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[1]);
           gPlayer.set_nobat(0);
           gPlayer.set_countCard(gPlayer.get_countCard()-1);

           QString type = gPlayer.get_playedCard().get_type();
           QString value = QString::number(gPlayer.get_playedCard().get_value());
           QString card = type+"^"+value;

           QString b = "border-image: url(:/"+gPlayer.get_playedCard().get_type();
           QString d = b+QString::number(gPlayer.get_playedCard().get_value());
           QString card_image=d+".jpg)";

           ui->played_label_1->show();
           ui->played_label_1->setStyleSheet(card_image);
           ui->cardButton_2->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
           }
       }
       else{
          showError("Card is not valid");
       }
       timePlayer=0;
         stopTimer();
       if(game1.isValid()){
           if(game1.playerWin()){
                gPlayer.get_playerCards()[2].set_type("");
                timePlayer = 0;
                runTimer();
               //_sleep(5000);
               //ui->played_label_1->hide();
               //ui->played_label_2->hide();
               if(gPlayer.get_takeWin()==1)
                   ui->wincardlabel_1->show();
               if(gPlayer.get_takeWin()==2)
                   ui->wincardlabel_2->show();
               if(gPlayer.get_takeWin()==3)
                   ui->wincardlabel_3->show();
               if(gPlayer.get_takeWin()==4)
                   ui->wincardlabel_4->show();
               if(gPlayer.get_takeWin()==5)
                   ui->wincardlabel_5->show();
               if(gPlayer.get_takeWin()==6)
                   ui->wincardlabel_6->show();
               if(gPlayer.get_takeWin()==7)
                   ui->wincardlabel_7->show();
               if(gPlayer.get_takeWin()==8)
                   ui->wincardlabel_8->show();
               if(gPlayer.get_takeWin()==9)
                   ui->wincardlabel_9->show();
               if(gPlayer.get_takeWin()==10)
                   ui->wincardlabel_10->show();
               if(gPlayer.get_takeWin()==11)
                   ui->wincardlabel_11->show();
               if(gPlayer.get_takeWin()==12)
                   ui->wincardlabel_12->show();
               if(gPlayer.get_takeWin()==13)
                   ui->wincardlabel_13->show();
               if(gPlayer.get_takeWin()==14)
                   ui->wincardlabel_14->show();
           }
           else{
                gPlayer.get_playerCards()[1].set_type("");
                timePlayer=0;
                stopTimer();
               //_sleep(5000);
               //ui->played_label_1->hide();
               //ui->played_label_2->hide();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==1)
                   ui->losecardlardlabel_1->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==2)
                   ui->losecardlardlabel_2->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==3)
                   ui->losecardlardlabel_3->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==4)
                   ui->losecardlardlabel_4->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==5)
                   ui->losecardlardlabel_5->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==6)
                   ui->losecardlardlabel_6->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==7)
                   ui->losecardlardlabel_7->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==8)
                   ui->losecardlardlabel_8->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==9)
                   ui->losecardlardlabel_9->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==10)
                   ui->losecardlardlabel_10->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==11)
                   ui->losecardlardlabel_11->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==12)
                   ui->losecardlardlabel_12->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==13)
                   ui->losecardlardlabel_13->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==14)
                   ui->losecardlardlabel_14->show();
           }

           if(gPlayer.get_countCard()==0){
                ui->pushButton_randcard->setEnabled(true);

               game1.scoring();
               timePlayer=0;
               stopTimer();
               gPlayer.set_takeWin(0);
                   if(gPlayer.get_role()=="server"){
                        gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                       // gserver.set_data("/");
                        QEventLoop loop;
                        connect( &gserver, &Server::readyRead, &loop, &QEventLoop::quit );
                        loop.exec();
                   }
                   if(gPlayer.get_role()=="client"){
                        gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                        ui->pushButton_play->hide();
                       // gclient.set_data("/");
                        QEventLoop loop;
                        connect( &gclient, &Client::readyRead, &loop, &QEventLoop::quit );
                        loop.exec();
                   }



               ui->mypoint_label->setText(QString::number(gPlayer.get_point()));
               ui->pointlabel_2->setText(QString::number(gPlayer.get_pointOpponent()));

               if(gPlayer.get_point()>gPlayer.get_pointOpponent()){
                   gPlayer.set_nobat(1);
                   gPlayer.set_start(1);
               }
               else if(gPlayer.get_point()<gPlayer.get_pointOpponent()){
                   gPlayer.set_nobat(0);
                   gPlayer.set_start(0);
               }
               if(gPlayer.get_turn()==2){
                   if(gPlayer.get_point()>gPlayer.get_pointOpponent()){
                       gPlayer.set_win(gPlayer.get_win()+1);
                       gPlayer.set_coin(gPlayer.get_coin()+100);
                       show_win();
                   }
                   else{
                       gPlayer.set_lose(gPlayer.get_lose()+1);
                       show_lose();
                   }
                   saveFile();
               }
           }
       }


    }

}
void play::on_cardButton_3_clicked()
{
    if(gPlayer.get_nobat()==0){
    showError("It is not your turn");
    }
    else{
        game game1;
        game1.set_dore(gPlayer.get_turn());
        gPlayer.set_playedCard(gPlayer.get_playerCards()[2]);
       if(gPlayer.get_start()==1){
           gPlayer.set_playedCard(gPlayer.get_playerCards()[2]);
           gPlayer.set_nobat(0);
           gPlayer.set_countCard(gPlayer.get_countCard()-1);
            timePlayer=0;
            stopTimer();

          QString type = gPlayer.get_playedCard().get_type();
           QString value = QString::number(gPlayer.get_playedCard().get_value());
           QString card = type+"^"+value;

           QString b = "border-image: url(:/"+gPlayer.get_playedCard().get_type();
           QString d = b+QString::number(gPlayer.get_playedCard().get_value());
           QString card_image=d+".jpg)";

           ui->played_label_1->show();
           ui->played_label_1->setStyleSheet(card_image);
           qInfo()<<ui->played_label_1->styleSheet();
           ui->cardButton_3->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
               QEventLoop loop;
               connect( &gserver, &Server::readyRead, &loop, &QEventLoop::quit );
               loop.exec();
               ui->cardlabel_3->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               QEventLoop loop;
               connect( &gclient, &Client::readyRead, &loop, &QEventLoop::quit );
               loop.exec();
                ui->cardlabel_3->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0){
            ui->cardlabel_3->hide();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[2]);
           gPlayer.set_nobat(0);
           gPlayer.set_countCard(gPlayer.get_countCard()-1);

           QString type = gPlayer.get_playedCard().get_type();
           QString value = QString::number(gPlayer.get_playedCard().get_value());
           QString card = type+"^"+value;

           QString b = "border-image: url(:/"+gPlayer.get_playedCard().get_type();
           QString d = b+QString::number(gPlayer.get_playedCard().get_value());
           QString card_image=d+".jpg)";

           ui->played_label_1->show();
           ui->played_label_1->setStyleSheet(card_image);
           ui->cardButton_3->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
           }
       }
       else{
          showError("Card is not valid");
       }
       timePlayer=0;
       stopTimer();
       if(game1.isValid()){
           if(game1.playerWin()){
                gPlayer.get_playerCards()[2].set_type("");
                 timePlayer = 0;
                runTimer();
               //_sleep(5000);
               //ui->played_label_1->hide();
               //ui->played_label_2->hide();
               if(gPlayer.get_takeWin()==1)
                   ui->wincardlabel_1->show();
               if(gPlayer.get_takeWin()==2)
                   ui->wincardlabel_2->show();
               if(gPlayer.get_takeWin()==3)
                   ui->wincardlabel_3->show();
               if(gPlayer.get_takeWin()==4)
                   ui->wincardlabel_4->show();
               if(gPlayer.get_takeWin()==5)
                   ui->wincardlabel_5->show();
               if(gPlayer.get_takeWin()==6)
                   ui->wincardlabel_6->show();
               if(gPlayer.get_takeWin()==7)
                   ui->wincardlabel_7->show();
               if(gPlayer.get_takeWin()==8)
                   ui->wincardlabel_8->show();
               if(gPlayer.get_takeWin()==9)
                   ui->wincardlabel_9->show();
               if(gPlayer.get_takeWin()==10)
                   ui->wincardlabel_10->show();
               if(gPlayer.get_takeWin()==11)
                   ui->wincardlabel_11->show();
               if(gPlayer.get_takeWin()==12)
                   ui->wincardlabel_12->show();
               if(gPlayer.get_takeWin()==13)
                   ui->wincardlabel_13->show();
               if(gPlayer.get_takeWin()==14)
                   ui->wincardlabel_14->show();
           }
           else{
                gPlayer.get_playerCards()[2].set_type("");
                timePlayer=0;
                stopTimer();
               //_sleep(5000);
               //ui->played_label_1->hide();
               //ui->played_label_2->hide();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==1)
                   ui->losecardlardlabel_1->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==2)
                   ui->losecardlardlabel_2->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==3)
                   ui->losecardlardlabel_3->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==4)
                   ui->losecardlardlabel_4->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==5)
                   ui->losecardlardlabel_5->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==6)
                   ui->losecardlardlabel_6->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==7)
                   ui->losecardlardlabel_7->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==8)
                   ui->losecardlardlabel_8->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==9)
                   ui->losecardlardlabel_9->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==10)
                   ui->losecardlardlabel_10->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==11)
                   ui->losecardlardlabel_11->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==12)
                   ui->losecardlardlabel_12->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==13)
                   ui->losecardlardlabel_13->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==14)
                   ui->losecardlardlabel_14->show();
           }

           if(gPlayer.get_countCard()==0){
               ui->pushButton_randcard->setEnabled(true);
               timePlayer=0;
                stopTimer();
               game1.scoring();
               gPlayer.set_takeWin(0);
                   if(gPlayer.get_role()=="server"){
                        gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                       // gserver.set_data("/");
                        QEventLoop loop;
                        connect( &gserver, &Server::readyRead, &loop, &QEventLoop::quit );
                        loop.exec();
                   }
                   if(gPlayer.get_role()=="client"){
                        gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                        ui->pushButton_play->hide();
                       // gclient.set_data("/");
                        QEventLoop loop;
                        connect( &gclient, &Client::readyRead, &loop, &QEventLoop::quit );
                        loop.exec();
                   }


               ui->mypoint_label->setText(QString::number(gPlayer.get_point()));
               ui->pointlabel_2->setText(QString::number(gPlayer.get_pointOpponent()));
               if(gPlayer.get_point()>gPlayer.get_pointOpponent()){
                   gPlayer.set_nobat(1);
                   gPlayer.set_start(1);
               }
               else if(gPlayer.get_point()<gPlayer.get_pointOpponent()){
                   gPlayer.set_nobat(0);
                   gPlayer.set_start(0);
               }
               if(gPlayer.get_turn()==2){
                   if(gPlayer.get_point()>gPlayer.get_pointOpponent()){
                       gPlayer.set_win(gPlayer.get_win()+1);
                       gPlayer.set_coin(gPlayer.get_coin()+100);
                       show_win();
                   }
                   else{
                       gPlayer.set_lose(gPlayer.get_lose()+1);
                       show_lose();
                   }
                   saveFile();
               }
           }
       }


    } 
}
void play::on_cardButton_4_clicked()
{
    if(gPlayer.get_nobat()==0){
    showError("It is not your turn");
    }
    else{
        game game1;
        game1.set_dore(gPlayer.get_turn());
        gPlayer.set_playedCard(gPlayer.get_playerCards()[3]);
       if(gPlayer.get_start()==1){
           gPlayer.set_playedCard(gPlayer.get_playerCards()[3]);
           gPlayer.set_nobat(0);
           gPlayer.set_countCard(gPlayer.get_countCard()-1);
           timePlayer=0;
           stopTimer();

          QString type = gPlayer.get_playedCard().get_type();
           QString value = QString::number(gPlayer.get_playedCard().get_value());
           QString card = type+"^"+value;

           QString b = "border-image: url(:/"+gPlayer.get_playedCard().get_type();
           QString d = b+QString::number(gPlayer.get_playedCard().get_value());
           QString card_image=d+".jpg)";

           ui->played_label_1->show();
           ui->played_label_1->setStyleSheet(card_image);
           qInfo()<<ui->played_label_1->styleSheet();
           ui->cardButton_4->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
               QEventLoop loop;
               connect( &gserver, &Server::readyRead, &loop, &QEventLoop::quit );
               loop.exec();
               ui->cardlabel_4->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               QEventLoop loop;
               connect( &gserver, &Server::readyRead, &loop, &QEventLoop::quit );
               loop.exec();
                ui->cardlabel_4->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0){
            ui->cardlabel_4->hide();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[3]);
           gPlayer.set_nobat(0);
           gPlayer.set_countCard(gPlayer.get_countCard()-1);

           QString type = gPlayer.get_playedCard().get_type();
           QString value = QString::number(gPlayer.get_playedCard().get_value());
           QString card = type+"^"+value;

           QString b = "border-image: url(:/"+gPlayer.get_playedCard().get_type();
           QString d = b+QString::number(gPlayer.get_playedCard().get_value());
           QString card_image=d+".jpg)";

           ui->played_label_1->show();
           ui->played_label_1->setStyleSheet(card_image);
           ui->cardButton_4->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
           }
       }
       else{
          showError("Card is not valid");
       }
       timePlayer=0;
         stopTimer();
       if(game1.isValid()){
           if(game1.playerWin()){
                gPlayer.get_playerCards()[3].set_type("");
               timePlayer = 0;
                runTimer();
               //_sleep(5000);
               //ui->played_label_1->hide();
               //ui->played_label_2->hide();
               if(gPlayer.get_takeWin()==1)
                   ui->wincardlabel_1->show();
               if(gPlayer.get_takeWin()==2)
                   ui->wincardlabel_2->show();
               if(gPlayer.get_takeWin()==3)
                   ui->wincardlabel_3->show();
               if(gPlayer.get_takeWin()==4)
                   ui->wincardlabel_4->show();
               if(gPlayer.get_takeWin()==5)
                   ui->wincardlabel_5->show();
               if(gPlayer.get_takeWin()==6)
                   ui->wincardlabel_6->show();
               if(gPlayer.get_takeWin()==7)
                   ui->wincardlabel_7->show();
               if(gPlayer.get_takeWin()==8)
                   ui->wincardlabel_8->show();
               if(gPlayer.get_takeWin()==9)
                   ui->wincardlabel_9->show();
               if(gPlayer.get_takeWin()==10)
                   ui->wincardlabel_10->show();
               if(gPlayer.get_takeWin()==11)
                   ui->wincardlabel_11->show();
               if(gPlayer.get_takeWin()==12)
                   ui->wincardlabel_12->show();
               if(gPlayer.get_takeWin()==13)
                   ui->wincardlabel_13->show();
               if(gPlayer.get_takeWin()==14)
                   ui->wincardlabel_14->show();
           }
           else{
                gPlayer.get_playerCards()[3].set_type("");
                timePlayer=0;
               stopTimer();
               //_sleep(5000);
               //ui->played_label_1->hide();
               //ui->played_label_2->hide();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==1)
                   ui->losecardlardlabel_1->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==2)
                   ui->losecardlardlabel_2->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==3)
                   ui->losecardlardlabel_3->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==4)
                   ui->losecardlardlabel_4->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==5)
                   ui->losecardlardlabel_5->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==6)
                   ui->losecardlardlabel_6->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==7)
                   ui->losecardlardlabel_7->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==8)
                   ui->losecardlardlabel_8->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==9)
                   ui->losecardlardlabel_9->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==10)
                   ui->losecardlardlabel_10->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==11)
                   ui->losecardlardlabel_11->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==12)
                   ui->losecardlardlabel_12->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==13)
                   ui->losecardlardlabel_13->show();
               if(gPlayer.get_turn()*2-(gPlayer.get_takeWin()+gPlayer.get_countCard())==14)
                   ui->losecardlardlabel_14->show();
           }

           if(gPlayer.get_countCard()==0){

               ui->pushButton_randcard->setEnabled(true);
                timePlayer=0;
                stopTimer();
               game1.scoring();
               gPlayer.set_takeWin(0);
                   if(gPlayer.get_role()=="server"){
                        gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                       // gserver.set_data("/");
                        QEventLoop loop;
                        connect( &gserver, &Server::readyRead, &loop, &QEventLoop::quit );
                        loop.exec();
                   }
                   if(gPlayer.get_role()=="client"){
                        gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                        ui->pushButton_play->hide();
                       // gclient.set_data("/");
                        QEventLoop loop;
                        connect( &gserver, &Server::readyRead, &loop, &QEventLoop::quit );
                        loop.exec();
                   }


               ui->mypoint_label->setText(QString::number(gPlayer.get_point()));
               ui->pointlabel_2->setText(QString::number(gPlayer.get_pointOpponent()));

               if(gPlayer.get_point()>gPlayer.get_pointOpponent()){
                   gPlayer.set_nobat(1);
                   gPlayer.set_start(1);
               }
               else if(gPlayer.get_point()<gPlayer.get_pointOpponent()){
                   gPlayer.set_nobat(0);
                   gPlayer.set_start(0);
               }
               if(gPlayer.get_turn()==2){
                   if(gPlayer.get_point()>gPlayer.get_pointOpponent()){
                       gPlayer.set_win(gPlayer.get_win()+1);
                       gPlayer.set_coin(gPlayer.get_coin()+100);
                       show_win();
                   }
                   else{
                       gPlayer.set_lose(gPlayer.get_lose()+1);
                       show_lose();
                   }
                   saveFile();
               }
           }
       }


    }
}

//***************************************************************************************************
play *uiPlay;

void play::on_error_btn_clicked()
{
    ui->error_btn->hide();
    ui->error_label->hide();
    ui->error_label_2->hide();
    Enable_true();
}




void play::on_close_button_2_clicked()
{
    temp = new menue;
    temp->show();
    hide();
}

