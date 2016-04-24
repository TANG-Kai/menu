#ifndef ORDER_H
#define ORDER_H

#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <dish.h>

class order : public QWidget
{
    Q_OBJECT
public:
    explicit order(QWidget *parent = 0);
    void setImage(QPixmap);
    void setName(QString);
    void setQuantity(int);
    int number;
    QLabel *price;

signals:
    void changed();

public slots:
    void addplat();
    void moinplat();

private:
    QString name;
    int quantity;
    QPushButton *add;
    QPushButton *moindre;
    QPixmap platpic;
    QLabel *dishnum;

};

#endif // ORDER_H
