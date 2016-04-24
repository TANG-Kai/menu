#include "dishitem.h"
#include "ui_dishitem.h"

DishItem::DishItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DishItem)
{
    ui->setupUi(this);
}

DishItem::~DishItem()
{
    delete ui;
}
