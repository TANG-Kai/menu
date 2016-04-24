#ifndef INGREDIENTS_H
#define INGREDIENTS_H
#include<QString>
class Ingredients{
public:
    Ingredients();
    void set_ingredient(QString n, QString p);
    QString getpath() const;
    QString in_name;
    QString in_path;
};

#endif // INGREDIENTS_H

