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
    ui->losecardlardlabel_3->hide();      ui->play_Button->hide();
    ui->losecardlardlabel_5->hide();      ui->label_played->hide();
    ui->losecardlardlabel_4->hide();      ui->pushButton->hide();
    ui->losecardlardlabel_6->hide();      ui->label_->hide();
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

    if(gPlayer.get_role()=="server"){
        ui->pushButton_start->show();
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
       stopTimer();

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
    runTimer();

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
    if(r==4){
          on_cardButton_5_clicked();
    }
    if(r==5){
          on_cardButton_6_clicked();
    }
    if(r==6){
          on_cardButton_7_clicked();
    }
    if(r==7){
          on_cardButton_8_clicked();
    }
    if(r==8){
          on_cardButton_9_clicked();
    }
    if(r==9){
          on_cardButton_10_clicked();
    }
    if(r==10){
          on_cardButton_11_clicked();
    }
    if(r==11){
          on_cardButton_12_clicked();
    }
    if(r==12){
          on_cardButton_13_clicked();
    }
    if(r==13){
          on_cardButton_14_clicked();
    }


}
void play:: writeUsername(QString a){
    ui->usernameLabel->setText(a);
}
void play::showlabel2(QString image){
    ui->played_label_2->show();
    ui->played_label_2->setStyleSheet(image);
}
void play:: show_randomBtn(){
  on_pushButton_randcard_clicked();
}
void play::show_startBtn(){
    ui->pushButton_start->show();
}
//************************************************************
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
    ui->time_label->setText(QString::number(timePlayer));
    timePlayer=0;
    timer->stop();
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

void play::on_close_button_clicked()
{

    if(gPlayer.get_role()=="server"){
        gserver.writeClient("close{");
    }
    if(gPlayer.get_role()=="client"){
          gclient.writeClient("close{");
    }
    gPlayer.set_lose(gPlayer.get_lose()+1);
    saveFile();
    Enable_false();
   show_lose();
}

void play::on_stop_button_clicked()
{
    if(gPlayer.get_stop()>2){
        ui->pushButton->show();
        ui->label_->show();
    }
    else{
        gPlayer.set_stop(gPlayer.get_stop()+1);

        if(gPlayer.get_role()=="server"){
            gserver.writeClient("stop}");
        }
        if(gPlayer.get_role()=="client"){
              gclient.writeClient("stop}");
        }
        stopTimer();
        Enable_false();
        show_stop();
        //time
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
    hide_stop();
     Enable_true();
      runTimer();
}
//******************************************************************************************************
void play::on_pushButton_play_clicked()
{
    if(gPlayer.get_role()=="server"){
        gserver.writeClient("~");
    }
    if(gPlayer.get_role()=="client"){
        gclient.writeClient("~");
    }
    if(gPlayer.get_clickPlay()=="~"){
        gPlayer.set_clickPlay("");
    ui->lineEdit_predicet->setEnabled(false);
    ui->pushButton_play->setEnabled(false);
    gPlayer.set_predict_win(ui->lineEdit_predicet->text().toInt());
     ui->played_label_1->hide();
     ui->played_label_2->hide();
     ui->pushButton_randcard->setEnabled(false);
     if(gPlayer.get_start()){
         runTimer();
     }
    }
     else{
         ui->play_Button->show();
             ui->label_played->show();
     }

}

void play::on_pushButton_start_clicked()
{
    ui->pushButton_start->hide();
    ui->lineEdit_predicet->setEnabled(true);
    ui->pushButton_play->setEnabled(true);
    ui->pushButton_randcard->setEnabled(false);
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
     }
     else if(gPlayer.get_role()=="client"){
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
    }
    ui->pushButton_randcard->setEnabled(false);
    ui->lineEdit_predicet->setEnabled(true);
    ui->pushButton_play->setEnabled(true);
    hidLosecard();
    game game1;
    gPlayer.set_turn(gPlayer.get_turn()+1);
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
     showError("It is not your turn");
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
               gserver.set_data("/");
              gserver.wait();
               ui->cardlabel_1->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               gclient.set_data("/");
               gclient.wait();
                   ui->cardlabel_1->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0){
            ui->cardlabel_1->hide();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[0]);
           gPlayer.set_nobat(0);
           gPlayer.set_countCard(gPlayer.get_countCard()-1);
            gPlayer.set_time(0);
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


     if(game1.isValid()){
         if(game1.playerWin()){
              gPlayer.get_playerCards()[0].set_type("");
             //_sleep(5000);
             //ui->played_label_1->hide();
             //ui->played_label_2->hide();
             timePlayer=0;
             if(gPlayer.get_countCard()!=0)
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
             //_sleep(5000);
             //ui->played_label_1->hide();
             //ui->played_label_2->hide();

             timePlayer=0;
              if(gPlayer.get_countCard()!=0)
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


                 if(gPlayer.get_role()=="server"){
                      gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                     // gserver.set_data("/");
                      gserver.wait(2000);
                 }
                 if(gPlayer.get_role()=="client"){
                      gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                     // gclient.set_data("/");
                      gclient.wait(2000);
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
            if(gPlayer.get_turn()==7){
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
               gserver.set_data("/");
               gserver.wait();
               ui->cardlabel_2->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               gclient.set_data("/");
               gclient.wait();
                ui->cardlabel_2->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0) {
            ui->cardlabel_2->hide();
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

       if(game1.isValid()){
           if(game1.playerWin()){
                gPlayer.get_playerCards()[1].set_type("");
               timePlayer=0;
               if(gPlayer.get_countCard()!=0)
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
                if(gPlayer.get_countCard()!=0)
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

                   if(gPlayer.get_role()=="server"){
                        gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                       // gserver.set_data("/");
                        gserver.wait(2000);
                   }
                   if(gPlayer.get_role()=="client"){
                        gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                       // gclient.set_data("/");
                        gclient.wait(2000);
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
               if(gPlayer.get_turn()==7){
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
               gserver.set_data("/");
               gserver.wait();
               ui->cardlabel_3->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               gclient.set_data("/");
               gclient.wait();
                ui->cardlabel_3->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0){
            ui->cardlabel_3->hide();
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

       if(game1.isValid()){
           if(game1.playerWin()){
                gPlayer.get_playerCards()[3].set_type("");
               timePlayer=0;
               if(gPlayer.get_countCard()!=0)
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
                if(gPlayer.get_countCard()!=0)
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

                   if(gPlayer.get_role()=="server"){
                        gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                       // gserver.set_data("/");
                        gserver.wait(2000);
                   }
                   if(gPlayer.get_role()=="client"){
                        gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                       // gclient.set_data("/");
                       gclient.wait(2000);
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
               if(gPlayer.get_turn()==7){
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
               gserver.set_data("/");
               gserver.wait();
               ui->cardlabel_4->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               gclient.set_data("/");
               gclient.wait();
                ui->cardlabel_4->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0){
            ui->cardlabel_4->hide();
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

       if(game1.isValid()){
           if(game1.playerWin()){
                gPlayer.get_playerCards()[3].set_type("");
               timePlayer=0;
               if(gPlayer.get_countCard()!=0)
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
                if(gPlayer.get_countCard()!=0)
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

                   if(gPlayer.get_role()=="server"){
                        gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                       // gserver.set_data("/");
                        gserver.wait(2000);
                   }
                   if(gPlayer.get_role()=="client"){
                        gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                       // gclient.set_data("/");
                       gclient.wait(2000);
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
               if(gPlayer.get_turn()==7){
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
void play::on_cardButton_5_clicked()
{
    if(gPlayer.get_nobat()==0){
    showError("It is not your turn");
    }
    else{
        game game1;
        game1.set_dore(gPlayer.get_turn());
        gPlayer.set_playedCard(gPlayer.get_playerCards()[4]);
       if(gPlayer.get_start()==1){
           gPlayer.set_playedCard(gPlayer.get_playerCards()[4]);
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
           ui->cardButton_5->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
               gserver.set_data("/");
               gserver.wait();
               ui->cardlabel_5->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               gclient.set_data("/");
               gclient.wait();
                ui->cardlabel_5->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0){
            ui->cardlabel_5->hide();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[4]);
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
           ui->cardButton_5->hide();

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

       if(game1.isValid()){
           if(game1.playerWin()){
                gPlayer.get_playerCards()[4].set_type("");
               timePlayer=0;
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
                gPlayer.get_playerCards()[4].set_type("");
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
               if(gPlayer.get_role()=="server"){
                    gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                   // gserver.set_data("/");
                    gserver.wait(2000);
               }
               if(gPlayer.get_role()=="client"){
                    gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                   // gclient.set_data("/");
                    gclient.wait(2000);
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
               if(gPlayer.get_turn()==7){
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
void play::on_cardButton_6_clicked()
{
    if(gPlayer.get_nobat()==0){
    showError("It is not your turn");
    }
    else{
        game game1;
        game1.set_dore(gPlayer.get_turn());
        gPlayer.set_playedCard(gPlayer.get_playerCards()[5]);
       if(gPlayer.get_start()==1){
           gPlayer.set_playedCard(gPlayer.get_playerCards()[5]);
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
           ui->cardButton_6->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
               gserver.set_data("/");
               gserver.wait();
               ui->cardlabel_6->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               gclient.set_data("/");
               gclient.wait();
                ui->cardlabel_6->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0){
            ui->cardlabel_6->hide();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[5]);
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
           ui->cardButton_6->hide();

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

       if(game1.isValid()){
           if(game1.playerWin()){
                gPlayer.get_playerCards()[5].set_type("");
               timePlayer=0;
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
                gPlayer.get_playerCards()[5].set_type("");
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
               if(gPlayer.get_role()=="server"){
                    gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                //    gserver.set_data("/");
                    gserver.wait(2000);
               }
               if(gPlayer.get_role()=="client"){
                    gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                   // gclient.set_data("/");
                    gclient.wait(2000);
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
               if(gPlayer.get_turn()==7){
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
void play::on_cardButton_7_clicked()
{
    if(gPlayer.get_nobat()==0){
    showError("It is not your turn");
    }
    else{
        game game1;
        game1.set_dore(gPlayer.get_turn());
        gPlayer.set_playedCard(gPlayer.get_playerCards()[6]);
       if(gPlayer.get_start()==1){
           gPlayer.set_playedCard(gPlayer.get_playerCards()[6]);
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
           ui->cardButton_7->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
               gserver.set_data("/");
               gserver.wait();
               ui->cardlabel_7->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               gclient.set_data("/");
               gclient.wait();
                ui->cardlabel_7->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0){
            ui->cardlabel_7->hide();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[6]);
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
           ui->cardButton_7->hide();

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

       if(game1.isValid()){
           if(game1.playerWin()){
                gPlayer.get_playerCards()[6].set_type("");
               timePlayer=0;
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
                gPlayer.get_playerCards()[6].set_type("");
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
               if(gPlayer.get_role()=="server"){
                    gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                    gserver.set_data("/");
                    gserver.wait();
               }
               if(gPlayer.get_role()=="client"){
                    gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                    gclient.set_data("/");
                    gclient.wait();
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
               if(gPlayer.get_turn()==7){
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
void play::on_cardButton_8_clicked()
{
    if(gPlayer.get_nobat()==0){
    showError("It is not your turn");
    }
    else{
        game game1;
        game1.set_dore(gPlayer.get_turn());
        gPlayer.set_playedCard(gPlayer.get_playerCards()[7]);
       if(gPlayer.get_start()==1){
           gPlayer.set_playedCard(gPlayer.get_playerCards()[7]);
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
           ui->cardButton_8->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
               gserver.set_data("/");
               gserver.wait();
               ui->cardlabel_8->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               gclient.set_data("/");
               gclient.wait();
                ui->cardlabel_8->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0){
            ui->cardlabel_8->hide();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[7]);
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
           ui->cardButton_8->hide();

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

       if(game1.isValid()){
           if(game1.playerWin()){
                gPlayer.get_playerCards()[7].set_type("");
               timePlayer=0;
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
                gPlayer.get_playerCards()[7].set_type("");
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
               if(gPlayer.get_role()=="server"){
                    gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                  //  gserver.set_data("/");
                    gserver.wait(2000);
               }
               if(gPlayer.get_role()=="client"){
                    gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                  //  gclient.set_data("/");
                    gclient.wait(2000);
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
               if(gPlayer.get_turn()==7){
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
void play::on_cardButton_9_clicked()
{
    if(gPlayer.get_nobat()==0){
    showError("It is not your turn");
    }
    else{
        game game1;
        game1.set_dore(gPlayer.get_turn());
        gPlayer.set_playedCard(gPlayer.get_playerCards()[8]);
       if(gPlayer.get_start()==1){
           gPlayer.set_playedCard(gPlayer.get_playerCards()[8]);
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
           ui->cardButton_9->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
               gserver.set_data("/");
               gserver.wait();
               ui->cardlabel_9->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               gclient.set_data("/");
               gclient.wait();
                ui->cardlabel_9->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0){
            ui->cardlabel_9->hide();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[8]);
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
           ui->cardButton_9->hide();

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

       if(game1.isValid()){
           if(game1.playerWin()){
                gPlayer.get_playerCards()[8].set_type("");
               timePlayer=0;
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
                gPlayer.get_playerCards()[8].set_type("");
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
               if(gPlayer.get_role()=="server"){
                    gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                  //  gserver.set_data("/");
                    gserver.wait(2000);
               }
               if(gPlayer.get_role()=="client"){
                    gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                   // gclient.set_data("/");
                    gclient.wait(2000);
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

               if(gPlayer.get_turn()==7){
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
void play::on_cardButton_10_clicked()
{
    if(gPlayer.get_nobat()==0){
    showError("It is not your turn");
    }
    else{
        game game1;
        game1.set_dore(gPlayer.get_turn());
        gPlayer.set_playedCard(gPlayer.get_playerCards()[9]);
       if(gPlayer.get_start()==1){
           gPlayer.set_playedCard(gPlayer.get_playerCards()[9]);
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
           ui->cardButton_10->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
               gserver.set_data("/");
               gserver.wait();
               ui->cardlabel_10->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               gclient.set_data("/");
               gclient.wait();
                ui->cardlabel_10->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0){
            ui->cardlabel_10->hide();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[9]);
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
           ui->cardButton_10->hide();

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

       if(game1.isValid()){
           if(game1.playerWin()){
                gPlayer.get_playerCards()[9].set_type("");
               timePlayer=0;
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
                gPlayer.get_playerCards()[9].set_type("");
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
               if(gPlayer.get_role()=="server"){
                    gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                  //  gserver.set_data("/");
                    gserver.wait(2000);
               }
               if(gPlayer.get_role()=="client"){
                    gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                   // gclient.set_data("/");
                    gclient.wait(2000);
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
               if(gPlayer.get_turn()==7){
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
void play::on_cardButton_11_clicked()
{
    if(gPlayer.get_nobat()==0){
    showError("It is not your turn");
    }
    else{
        game game1;
        game1.set_dore(gPlayer.get_turn());
        gPlayer.set_playedCard(gPlayer.get_playerCards()[10]);
       if(gPlayer.get_start()==1){
           gPlayer.set_playedCard(gPlayer.get_playerCards()[10]);
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
           ui->cardButton_11->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
               gserver.set_data("/");
               gserver.wait();
               ui->cardlabel_11->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               gclient.set_data("/");
               gclient.wait();
                ui->cardlabel_11->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0){
            ui->cardlabel_11->hide();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[10]);
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
           ui->cardButton_11->hide();

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

       if(game1.isValid()){
           if(game1.playerWin()){
                gPlayer.get_playerCards()[10].set_type("");
               timePlayer=0;
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
                gPlayer.get_playerCards()[10].set_type("");
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
               if(gPlayer.get_role()=="server"){
                    gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                  //  gserver.set_data("/");
                    gserver.wait(2000);
               }
               if(gPlayer.get_role()=="client"){
                    gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                   // gclient.set_data("/");
                    gclient.wait(2000);
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
               if(gPlayer.get_turn()==7){
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
void play::on_cardButton_12_clicked()
{
    if(gPlayer.get_nobat()==0){
    showError("It is not your turn");
    }
    else{
        game game1;
        game1.set_dore(gPlayer.get_turn());
        gPlayer.set_playedCard(gPlayer.get_playerCards()[11]);
       if(gPlayer.get_start()==1){
           gPlayer.set_playedCard(gPlayer.get_playerCards()[11]);
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
           ui->cardButton_12->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
               gserver.set_data("/");
               gserver.wait();
               ui->cardlabel_12->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               gclient.set_data("/");
               gclient.wait();
                ui->cardlabel_12->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0){
            ui->cardlabel_12->hide();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[11]);
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
           ui->cardButton_12->hide();

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

       if(game1.isValid()){
           if(game1.playerWin()){
                gPlayer.get_playerCards()[11].set_type("");
               timePlayer=0;
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
                gPlayer.get_playerCards()[11].set_type("");
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
               if(gPlayer.get_role()=="server"){
                    gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                 //   gserver.set_data("/");
                    gserver.wait(2000);
               }
               if(gPlayer.get_role()=="client"){
                    gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                   // gclient.set_data("/");
                    gclient.wait(2000);
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
               if(gPlayer.get_turn()==7){
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
void play::on_cardButton_13_clicked()
{
    if(gPlayer.get_nobat()==0){
    showError("It is not your turn");
    }
    else{
        game game1;
        game1.set_dore(gPlayer.get_turn());
        gPlayer.set_playedCard(gPlayer.get_playerCards()[12]);
       if(gPlayer.get_start()==1){
           gPlayer.set_playedCard(gPlayer.get_playerCards()[12]);
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
           ui->cardButton_13->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
               gserver.set_data("/");
               gserver.wait();
               ui->cardlabel_13->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               gclient.set_data("/");
               gclient.wait();
                ui->cardlabel_13->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0){
            ui->cardlabel_13->hide();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[12]);
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
           ui->cardButton_13->hide();

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

       if(game1.isValid()){
           if(game1.playerWin()){
                gPlayer.get_playerCards()[12].set_type("");
               timePlayer=0;
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
                gPlayer.get_playerCards()[12].set_type("");
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
               if(gPlayer.get_role()=="server"){
                    gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                 //   gserver.set_data("/");
                    gserver.wait(2000);
               }
               if(gPlayer.get_role()=="client"){
                    gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                  //  gclient.set_data("/");
                    gclient.wait(2000);
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
               if(gPlayer.get_turn()==7){
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
void play::on_cardButton_14_clicked()
{
    if(gPlayer.get_nobat()==0){
    showError("It is not your turn");
    }
    else{
        game game1;
        game1.set_dore(gPlayer.get_turn());
        gPlayer.set_playedCard(gPlayer.get_playerCards()[13]);
       if(gPlayer.get_start()==1){
           gPlayer.set_playedCard(gPlayer.get_playerCards()[13]);
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
           ui->cardButton_14->hide();

           if(gPlayer.get_role()=="server"){
               gserver.writeClient(card);
               gserver.set_data("/");
               gserver.wait();
               ui->cardlabel_14->hide();
           }
           else if(gPlayer.get_role()=="client"){
               gclient.writeClient(card);
               gclient.set_data("/");
               gclient.wait();
                ui->cardlabel_14->hide();
           }
       }
       else if(game1.isValid()&&gPlayer.get_start()==0){
            ui->cardlabel_14->hide();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[13]);
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
           ui->cardButton_14->hide();

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

       if(game1.isValid()){
           if(game1.playerWin()){
                gPlayer.get_playerCards()[13].set_type("");
               timePlayer=0;
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
                gPlayer.get_playerCards()[13].set_type("");
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
               if(gPlayer.get_role()=="server"){
                    gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                   // gserver.set_data("/");
                    gserver.wait(2000);
               }
               if(gPlayer.get_role()=="client"){
                    gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                 //   gclient.set_data("/");
                    gclient.wait(2000);
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
               if(gPlayer.get_turn()==7){
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
play *uiPlay;

void play::on_error_btn_clicked()
{
    ui->error_btn->hide();
    ui->error_label->hide();
    ui->error_label_2->hide();
}

void play::on_close_button_2_clicked()
{
    temp=new menue;
    temp->show();
    hide();
}


void play::on_play_Button_clicked()
{
    ui->label_played->hide();
    ui->play_Button->hide();
}


void play::on_pushButton_clicked()
{
    ui->pushButton->hide();
    ui->label_->hide();
}

