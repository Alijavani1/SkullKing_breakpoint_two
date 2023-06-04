#ifndef REGISTERY_H
#define REGISTERY_H

#include <QMainWindow>
#include "player.h"

namespace Ui {
class Registery;
}

class Registery : public QMainWindow
{
    Q_OBJECT

public:
    explicit Registery(QWidget *parent = nullptr);
    void creatAccount(player &c);
    ~Registery();

private slots:
    void on_login_btn_clicked();

private:
    Ui::Registery *ui;
};
//extern player p1;
#endif // REGISTERY_H
