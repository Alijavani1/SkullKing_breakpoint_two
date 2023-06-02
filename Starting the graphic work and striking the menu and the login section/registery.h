#ifndef REGISTERY_H
#define REGISTERY_H

#include <QMainWindow>

namespace Ui {
class Registery;
}

class Registery : public QMainWindow
{
    Q_OBJECT

public:
    explicit Registery(QWidget *parent = nullptr);
    ~Registery();

private:
    Ui::Registery *ui;
};

#endif // REGISTERY_H
