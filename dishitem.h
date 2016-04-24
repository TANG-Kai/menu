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

public:
    explicit DishItem(QWidget *parent = 0);
    ~DishItem();
    Dish* dish;
    void setDish(Dish* dish){
        this->dish = dish;
    }
signals:
    void buttonClicked(QString name);
private slots:
    void on_pb_add_clicked()
    {
        emit(buttonClicked(dish->name));
    }


private:
    Ui::DishItem *ui;
};

#endif // DISHITEM_H
