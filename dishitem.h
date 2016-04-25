#ifndef DISHITEM_H
#define DISHITEM_H

#include <QWidget>
#include"dish.h"

namespace Ui {
class DishItem;
}

class DishItem : public QWidget
{
    Q_OBJECT
private:
    Ui::DishItem *ui;

public:
    explicit DishItem(QWidget *parent = 0);
    ~DishItem();
    Dish* dish;
    void setDish(Dish* dish);
    void setConstraints(QString ctrs);

signals:
    void buttonClicked(QString name);
private slots:
    void on_pb_add_clicked()
    {
        emit(buttonClicked(dish->name));
    }


};

#endif // DISHITEM_H
