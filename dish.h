#ifndef DISH_H
#define DISH_H
#include"ingrenum.h"
class Dish{
public:
    QString *name;
    QString *path;
    QVector<QString> *keys;
    double price;
    QVector<Ingrenum> *ing;
    Dish(QString name, double price){
        this->name = new QString(name);
        this->price = price;
        keys = new QVector<QString>();
        ing = new QVector<Ingrenum>();
    }
};

#endif // DISH_H

