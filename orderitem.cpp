#include "orderitem.h"
#include "ui_orderitem.h"

OrderItem::OrderItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderItem)
{
    ui->setupUi(this);
}

OrderItem::~OrderItem()
{
    delete ui;
}

void OrderItem::setText(QString name, int quantity, double price, double amount){
    ui->lb_name->setText( name);
    ui->lb_quantity->setText("x" + QString::number(quantity));
    ui->lb_amount->setText("€" + QString::number(amount));
    this->name = name;
    this->price = price;
    this->quantity = quantity;
}

QString OrderItem::getname(){
    return ui->lb_name->text();
}

int OrderItem::getquantity(){
    return ui->lb_quantity->text().toInt();
}

void OrderItem::update(){
    ui->lb_quantity->setText("x" + QString::number(quantity));
    ui->lb_amount->setText("€" + QString::number(quantity * price));
}
