#include "play.h"
#include "ui_play.h"
#include "server.h"
#include "client.h"
#include "game.h"
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
    ui->losecardlardlabel_2->hide();
    ui->losecardlardlabel_14->hide();
    ui->losecardlardlabel_3->hide();
    ui->losecardlardlabel_5->hide();
    ui->losecardlardlabel_4->hide();
    ui->losecardlardlabel_6->hide();
    ui->losecardlardlabel_7->hide();
    ui->losecardlardlabel_8->hide();
    ui->losecardlardlabel_9->hide();
    gPlayer.set_nobat(0);
    gPlayer.set_takeWin(0);
    gPlayer.set_point(0);
    gPlayer.set_pointOpponent(0);
   // ui->cardButton_1->setEnabled(false);
   // ui->cardButton_2->setEnabled(false);
   // ui->cardButton_3->setEnabled(false);
   // ui->cardButton_4->setEnabled(false);
   // ui->cardButton_5->setEnabled(false);
   //ui->cardButton_6->setEnabled(false);
    //ui->cardButton_7->setEnabled(false);
    //ui->cardButton_8->setEnabled(false);
    //ui->cardButton_9->setEnabled(false);
    //ui->cardButton_10->setEnabled(false);
    //ui->cardButton_11->setEnabled(false);
    //ui->cardButton_12->setEnabled(false);
    //ui->cardButton_13->setEnabled(false);
    //ui->cardButton_14->setEnabled(false);

}

play::~play()
{
    delete ui;
}
int starttime=0;
void play:: timerStart(){
    if(starttime==20){
        timer->stop();
    }
    else{
        starttime++;
        ui->time_label->setText(QString::number(starttime)+"s");
    }
}

void play::showlabel2(QString image){
    ui->played_label_2->show();
    ui->played_label_2->setStyleSheet(image);
}

void play::on_pushButton_play_clicked()
{
    starttime=0;
   timer = new QTimer;
   connect(timer,SIGNAL(timeout()),this,SLOT(timerStart()));
   timer->start(1000);
    ui->lineEdit_predicet->setEnabled(false);
    ui->pushButton_play->setEnabled(false);
    gPlayer.set_predict_win(ui->lineEdit_predicet->text().toInt());
     ui->played_label_1->hide();
     ui->played_label_2->hide();
     ui->pushButton_randcard->setEnabled(true);

}

void play::on_pushButton_start_clicked()
{
    gPlayer.set_countCard(gPlayer.get_turn()*2);
    ui->pushButton_start->hide();
    ui->lineEdit_predicet->setEnabled(true);
    ui->pushButton_play->setEnabled(true);
     gPlayer.set_coin(gPlayer.get_coin()-50);
     game game1;
     game1.howStart();
     if(gPlayer.get_role()=="server"){
         int r = gPlayer.get_stratCard().get_value();
         QString c = QString::number(r);
         QString b = "border-image: url(:/parrot"+c;
         QString d = b+".jpg)";
          ui->played_label_1->show();
          ui->played_label_1->setStyleSheet(d);
          gserver.wait(3000);
          r = gserver.get_data().toInt();
         // gserver.set_data("/");
          if(gPlayer.get_stratCard().get_value()>gserver.get_data().toInt()){
            gPlayer.set_start(1);
            gPlayer.set_nobat(1);
          }
           c = QString::number(r);
           b = "border-image: url(:/parrot"+c;
           d = b+".jpg)";
           ui->played_label_2->show();
           ui->played_label_2->setStyleSheet(d);
         }
     else{
        int a= gclient.get_data().toInt();
        //gclient.set_data("/");
        if(a<gPlayer.get_stratCard().get_value()){
            gPlayer.set_start(1);
            gPlayer.set_nobat(1);
        }
        int r = gPlayer.get_stratCard().get_value();
        QString c = QString::number(r);
        QString b = "border-image: url(:/parrot"+c;
        QString d = b+".jpg)";
         ui->played_label_1->show();
         ui->played_label_1->setStyleSheet(d);
          r = gclient.get_data().toInt();
          c = QString::number(r);
          b = "border-image: url(:/parrot"+c;
          d = b+".jpg)";
          ui->played_label_2->show();
          ui->played_label_2->setStyleSheet(d);
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
     }
}


void play::on_pushButton_randcard_clicked()
{
    ui->lineEdit_predicet->setEnabled(true);
    ui->pushButton_play->setEnabled(true);
    game game1;
    gPlayer.set_turn(gPlayer.get_turn()+1);
    game1.set_dore(gPlayer.get_turn());
    gPlayer.set_countCard(gPlayer.get_turn()*2);
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
    gPlayer.set_turn(gPlayer.get_turn()+1);

}
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

void play::on_cardButton_1_clicked()
{
    game game1;
    game1.set_dore(gPlayer.get_turn());
    if(gPlayer.get_nobat()==0){
        QMessageBox msgBox;
        msgBox.setText("It is not your turn.");
        msgBox.exec();
    }
   else{
      // starttime=0;
       //timer = new QTimer;
      // connect(timer,SIGNAL(timeout()),this,SLOT(timerStart()));
      // timer->start(1000);
        if(gPlayer.get_start()){
            QList<card> playercards=gPlayer.get_playerCards();
             gPlayer.set_playedCard(gPlayer.get_playerCards()[0]);
             gPlayer.set_nobat(0);
        int r = playercards[0].get_value();
         QString a=playercards[0].get_type();
         QString c = QString::number(r);
         QString b = "border-image: url(:/"+a;
         QString d = b+c;
         QString g=d+".jpg)";
         ui->played_label_1->show();
         ui->played_label_1->setStyleSheet(g);
         ui->cardButton_1->hide();
         if(gPlayer.get_role()=="server"){
              gserver.set_data("/");
              gserver.writeClient(g);

              QString a;
              a=gPlayer.get_playedCard().get_type();
              a+='^'+QString::number(gPlayer.get_playedCard().get_value());
              gserver.writeClient(a); // khode carde befrest
              gserver.get_data();
              gserver.wait();
               gserver.get_data();
         }
         if(gPlayer.get_role()=="client"){
              gclient.set_data("/");
              gclient.writeClient(g);
              QString a;
              a=gPlayer.get_playedCard().get_type();
              a+='^'+QString::number(gPlayer.get_playedCard().get_value());
              gclient.writeClient(a); // khode carde befrest
              gclient.wait();

        }
        }

      if(game1.isValid()){
          QList<card> playercards=gPlayer.get_playerCards();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[0]);
           gPlayer.set_nobat(0);
        int r = playercards[0].get_value();
         QString a=playercards[0].get_type();
         QString c = QString::number(r);
         QString b = "border-image: url(:/"+a;
         QString d = b+c;
         QString g=d+".jpg)";
         //to baghie baid taghir bedim
         ui->played_label_1->show();
         ui->played_label_1->setStyleSheet(g);
         ui->cardButton_1->hide();
         qInfo()<<g;
         gPlayer.set_countCard(gPlayer.get_countcard()-1);
         if(gPlayer.get_role()=="server"){
             //gserver.writeClient(g);// akse carde befrest
             QString a;
             a=gPlayer.get_playedCard().get_type();
             a+='^'+QString::number(gPlayer.get_playedCard().get_value());
             gserver.writeClient(a);  // khode carde befrest
             gserver.wait();
         }
         if(gPlayer.get_role()=="client"){
             //gclient.writeClient(g); // akse carde befrest
             QString a;
             a=gPlayer.get_playedCard().get_type();
             a+='^'+QString::number(gPlayer.get_playedCard().get_value());
             gclient.writeClient(a); // khode carde befrest
             gclient.wait();
         }
         ui->cardlabel_1->hide();                                               //to baghie baid taghir bedim
            if( game1.playerWin()){
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
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==1)
                    ui->losecardlardlabel_1->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==2)
                    ui->losecardlardlabel_2->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==3)
                    ui->losecardlardlabel_3->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==4)
                    ui->losecardlardlabel_4->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==5)
                    ui->losecardlardlabel_5->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==6)
                    ui->losecardlardlabel_6->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==7)
                    ui->losecardlardlabel_7->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==8)
                    ui->losecardlardlabel_8->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==9)
                    ui->losecardlardlabel_9->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==10)
                    ui->losecardlardlabel_10->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==11)
                    ui->losecardlardlabel_11->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==12)
                    ui->losecardlardlabel_12->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==13)
                    ui->losecardlardlabel_13->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==14)
                    ui->losecardlardlabel_14->show();
            }

            if(gPlayer.get_countcard()==0){
                game1.scoring();
                if(gPlayer.get_role()=="server"){
                    gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                    gserver.wait(3000);
                }
                if(gPlayer.get_role()=="client"){
                    gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                    gclient.wait(3000);
                }
                 ui->mypointlabel->setText(QString::number(gPlayer.get_point()));
                 ui->pointlabel_2->setText(QString::number(gPlayer.get_pointOpponent()));
                 ui->pushButton_randcard->setEnabled(true);
                // ui->played_label_1->hide();
               //  ui->played_label_2->hide();
                 //hidLosecard();

                 if(game1.get_dore()==7){
                 if(gPlayer.get_pointOpponent()<gPlayer.get_point()){
                     //ui bordi
                     gPlayer.set_win(gPlayer.get_win()+1);
                     gPlayer.set_coin(gPlayer.get_coin()+100);
                 }
                 else{
                     //ui bakht
                       gPlayer.set_lose(gPlayer.get_lose()+1);
                 }
                  saveFile();
                 }

            }
            //ui->played_label_1->hide();
            //ui->played_label_2->hide();
    }

}
}



void play::on_cardButton_2_clicked()
{
    game game1;
    game1.set_dore(gPlayer.get_turn());
    if(gPlayer.get_nobat()==0){
        QMessageBox msgBox;
        msgBox.setText("It is not your turn.");
        msgBox.exec();
    }
     else{
      // starttime=0;
     //  timer = new QTimer;
      // connect(timer,SIGNAL(timeout()),this,SLOT(timerStart()));
       timer->start(1000);
        if(gPlayer.get_start()){
                gPlayer.set_nobat(0);
                QList<card> playercards=gPlayer.get_playerCards();
                 gPlayer.set_playedCard(gPlayer.get_playerCards()[1]);
        int r = playercards[1].get_value();
         QString a=playercards[1].get_type();
         QString c = QString::number(r);
         QString b = "border-image: url(:/"+a;
         QString d = b+c;
         QString g=d+".jpg)";
         //to baghie baid taghir bedim
         ui->played_label_1->show();
         ui->played_label_1->setStyleSheet(g);
         ui->cardButton_2->hide();

         if(gPlayer.get_role()=="server"){
             gserver.writeClient(g);
              gserver.set_data("/");
              QString a;
              a=gPlayer.get_playedCard().get_type();
              a+='^'+QString::number(gPlayer.get_playedCard().get_value());
              gserver.writeClient(a);  // khode carde befrest
              gserver.wait();
         }
         if(gPlayer.get_role()=="client"){
             gclient.writeClient(g);
             QString a;
             a=gPlayer.get_playedCard().get_type();
             a+='^'+QString::number(gPlayer.get_playedCard().get_value());
             gclient.writeClient(a); // khode carde befrest
             gclient.wait();
              gclient.set_data("/");
        }
        }
      if(game1.isValid()){
          QList<card> playercards=gPlayer.get_playerCards();
           gPlayer.set_playedCard(gPlayer.get_playerCards()[1]);
              gPlayer.set_nobat(0);
        int r = playercards[1].get_value();
         QString a=playercards[1].get_type();
         QString c = QString::number(r);
         QString b = "border-image: url(:/"+a;
         QString d = b+c;
         QString g=d+".jpg)";
         //to baghie baid taghir bedim
         ui->played_label_1->show();
         ui->played_label_1->setStyleSheet(g);
         ui->cardButton_2->hide();
          gPlayer.set_countCard(gPlayer.get_countcard()-1);
         if(gPlayer.get_role()=="server"){
             gserver.writeClient(g);
             QString a;
             a=gPlayer.get_playedCard().get_type();
             a+='^'+QString::number(gPlayer.get_playedCard().get_value());
             gserver.writeClient(a);// akse carde befrest
         }
         if(gPlayer.get_role()=="client"){
             gclient.writeClient(g);// akse carde befrest
             QString a;
             a=gPlayer.get_playedCard().get_type();
             a+='^'+QString::number(gPlayer.get_playedCard().get_value());
             gclient.writeClient(a); // khode carde befrest
         }
         ui->cardlabel_2->hide();                                               //to baghie baid taghir bedim
            if( game1.playerWin()){
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
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==1)
                    ui->losecardlardlabel_1->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==2)
                    ui->losecardlardlabel_2->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==3)
                    ui->losecardlardlabel_3->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==4)
                    ui->losecardlardlabel_4->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==5)
                    ui->losecardlardlabel_5->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==6)
                    ui->losecardlardlabel_6->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==7)
                    ui->losecardlardlabel_7->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==8)
                    ui->losecardlardlabel_8->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==9)
                    ui->losecardlardlabel_9->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==10)
                    ui->losecardlardlabel_10->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==11)
                    ui->losecardlardlabel_11->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==12)
                    ui->losecardlardlabel_12->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==13)
                    ui->losecardlardlabel_13->show();
                if(gPlayer.get_turn()*2-gPlayer.get_takeWin()==14)
                    ui->losecardlardlabel_14->show();
            }

            if(gPlayer.get_countcard()==0){
                game1.scoring();
                if(gPlayer.get_role()=="server"){
                    gserver.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                    gserver.wait(3000);
                }
                if(gPlayer.get_role()=="client"){
                    gclient.writeClient(QString::number(gPlayer.get_point())+"+*point*");
                    gclient.wait(3000);
                }
                 ui->mypointlabel->setText(QString::number(gPlayer.get_point()));
                 ui->pointlabel_2->setText(QString::number(gPlayer.get_pointOpponent()));
                 ui->pushButton_randcard->setEnabled(true);
               //  ui->played_label_1->hide();
                // ui->played_label_2->hide();
                // hidLosecard();

                 if(game1.get_dore()==7){
                 if(gPlayer.get_pointOpponent()<gPlayer.get_point()){
                     //ui bordi
                     gPlayer.set_win(gPlayer.get_win()+1);
                     gPlayer.set_coin(gPlayer.get_coin()+100);
                 }
                 else{
                     //ui bakht
                       gPlayer.set_lose(gPlayer.get_lose()+1);
                 }
                  saveFile();
                 }

            }
            //ui->played_label_1->hide();
            //ui->played_label_2->hide();
    }
 }
}






play *uiPlay;
