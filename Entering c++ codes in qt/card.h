#ifndef CARD_H
#define CARD_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class card;
}

class card : public QMainWindow
{
    Q_OBJECT
    friend class board;
    friend class player;

public:
    explicit card(QWidget *parent = nullptr);
        card(QString type, int value);
        card( const card&);
        int get_value();
        QString get_type();
        void operator =(const card& c);
        bool operator >(const card& c)const;
        bool operator == (const card & c)const;
    ~card();

private:
    Ui::card *ui;
    QString type;
        int value;
};

#endif // CARD_H
