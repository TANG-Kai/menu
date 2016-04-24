#ifndef DISH_H
#define DISH_H
#include"ingrenum.h"
class Dish{
public:
    Dish();
    Dish(QString ,QString ,double );
    void addkeyword(QString );
    void addingredient(QString );
    void addsaveur(QString );
    QString getname() const;
    QString getpath() const;
    QString getkeys() const;
    double getprice() const;
    QVector <Ingrenum> *dish_ingre;
    QString name;
    QString path;
    double price;
    bool containsKey(QString);
    QList<QString>* getkeys_container();
private:
    QList<QString>* keyword;
    QList<QString>* ingredient;
    QList<QString>* saveur;
};

#endif // DISH_H

