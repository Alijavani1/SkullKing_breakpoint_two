#include "play.h"
#include "ui_play.h"

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
}

play::~play()
{
    delete ui;
}

void play::on_pushButton_play_clicked()
{
    game1.set_dore(game1.get_dore()+1);
    game1.set_dore(6);
   gPlayer.set_predict_win( ui->lineEdit_predicet->text().toInt());
   game1.randomCard();
   QVector<QString>temp;
   for(int i=0;game1.get_dore()*2>i;i++){
      QList<card>playercards=gPlayer.get_playerCards();
      int r = playercards[i].get_value()+1;
      QString a=playercards[i].get_type();
       QString c = QString::number(r);

       QString b = "border-image: url(:/"+a;
       QString d = b+c;
       QString g=d+".jpg)";
        qInfo()<<g;
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

void play::on_pushButton_start_clicked()
{
    ui->pushButton_start->hide();
     gPlayer.set_coin(gPlayer.get_coin()-50);
     game1.howStart();
     if(gPlayer.get_role()=="server"){
         if(gserver.get_data()=="Start"){
             gPlayer.set_start(1);
         }
         else{
             gserver.writeClient(QString::number(gPlayer.get_stratCard().get_value()));
             }
         int r = gPlayer.get_stratCard().get_value();
         QString c = QString::number(r);
         QString b = "border-image: url(:/parrot"+c;
         QString d = b+".jpg)";
          qInfo()<<d;
          ui->played_label_1->show();
          ui->played_label_1->setStyleSheet(d);
          gserver.wait();
              r = gserver.get_data().toInt();
           qInfo()<<gserver.get_data();
           c = QString::number(r);
           b = "border-image: url(:/parrot"+c;
           d = b+".jpg)";
           qInfo()<<d;
           ui->played_label_2->show();
           ui->played_label_2->setStyleSheet(d);
         }


     else{
                gclient.writeClient(QString::number(gPlayer.get_stratCard().get_value()));


        int a= gclient.get_data().toInt();
        if(a<gPlayer.get_stratCard().get_value()){
            gPlayer.set_start(1);
        }
        else{
            gclient.writeClient("Start");
        }
        int r = gPlayer.get_stratCard().get_value();
        QString c = QString::number(r);
        QString b = "border-image: url(:/parrot"+c;
        QString d = b+".png)";
         qInfo()<<d;
         ui->played_label_1->show();
         ui->played_label_1->setStyleSheet(d);
          r = gclient.get_data().toInt();
          c = QString::number(r);
          b = "border-image: url(:/parrot"+c;
          d = b+".png)";
          qInfo()<<d;
          ui->played_label_2->show();
          ui->played_label_2->setStyleSheet(d);
     }
}

