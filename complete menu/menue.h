#ifndef MENUE_H
#define MENUE_H
#pragma once
#include <QMainWindow>
#include "editprofile.h"
//#include "mainwindow.h"
class MainWindow;
namespace Ui {
class menue;
}

class menue : public QMainWindow
{
    Q_OBJECT

public:
    explicit menue(QWidget *parent = nullptr);
    ~menue();

private slots:

    void on_edit_btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::menue *ui;
    editprofile *edit;
    MainWindow * temp;
};

#endif // MENUE_H
