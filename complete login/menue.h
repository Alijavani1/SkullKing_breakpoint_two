#ifndef MENUE_H
#define MENUE_H

#include <QMainWindow>

namespace Ui {
class menue;
}

class menue : public QMainWindow
{
    Q_OBJECT

public:
    explicit menue(QWidget *parent = nullptr);
    ~menue();

private:
    Ui::menue *ui;
};

#endif // MENUE_H
