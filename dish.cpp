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
    if(spiciness>=1 && spiciness<=4)
        output += QString("Mildly hot") + ", ";
    else if(spiciness >=5)
        output+= QString("Hot") + ", ";

    int max;
    if(keyword->size()>3) max = 3;
    else max = keyword->size();
    for(int i=0;i<max;i++){
            if(i<max-1)
                output += keyword->at(i) + ",";
            else
                output += keyword->at(i);
    }
    return output;
}

double Dish::getprice() const{
    return price;
}
