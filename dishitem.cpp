#include "dishitem.h"
#include "ui_dishitem.h"
#include<QDebug>

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

void DishItem::setDish(Dish* dish){
    this->dish = dish;
    ui->lb_name->setText(dish->name);
    ui->lb_price->setText("$" + QString::number(dish->price));
    ui->lb_keys->setText(dish->getkeys());

    QPixmap image = QPixmap(dish->path);
    qDebug()<< dish->path;
    image = image.scaled( 210,192,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->lb_img->setPixmap(image);
}
