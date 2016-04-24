#include "ingredients.h"
#include <QVector>
Ingredients::Ingredients()
{
}
void Ingredients::set_ingredient(QString n,QString p)
{
    in_name = n;
    in_path = p;
}
QString Ingredients::getpath() const
{
    return in_path;
}
