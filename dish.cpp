#include "dish.h"
#include "QVector"
Dish::Dish(){

    dish_ingre = new QVector <Ingrenum>();
    keyword = new QList<QString>();
    ingredient = new QList<QString>();
    saveur =  new QList<QString>();
}

Dish::Dish(QString _name ,QString _path ,double _price)
{
    name=_name;
    path=_path;
    price=_price;
    dish_ingre = new QVector <Ingrenum>();

    keyword = new QList<QString>();
    ingredient = new QList<QString>();
    saveur =  new QList<QString>();
}

bool Dish::containsKey(QString str){
    return keyword->contains(str);
}

void Dish::addkeyword(QString kw){
    keyword->append(kw);
}

void Dish::addingredient(QString ingre){
    ingredient->append(ingre);
}

void Dish::addsaveur(QString _saveur){
    saveur->append(_saveur);
}
QList<QString>* Dish::getkeys_container(){
    return keyword;
}

QString Dish::getname() const{
    return name;
}

QString Dish::getpath() const{
    return path;
}

QString Dish::getkeys() const{
    if(keyword == NULL) return NULL;
    QString output;
    for(int i=0;i<4;i++){
        if(i<keyword->size())
            output += keyword->at(i) + "\t";
    }
    return output;
}

double Dish::getprice() const{
    return price;
}
