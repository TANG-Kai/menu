#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <QWidget>

namespace Ui {
class OrderItem;
}

class OrderItem : public QWidget
{
    Q_OBJECT

public:
    explicit OrderItem(QWidget *parent = 0);
    ~OrderItem();
    void setText(QString name, int quantity, double price, double amount);
    QString getname();
    int getquantity();
    QString name;
    int quantity;
    double price;
    void update();
private:
    Ui::OrderItem *ui;
};

#endif // ORDERITEM_H
