#include "order.h"

order::order(QWidget *parent) : QWidget(parent)
{
    add = new QPushButton(this);
    add->setText("+");
    add->move(550,10);

    moindre = new QPushButton(this);
    moindre->setText("-");
    moindre->move(550,50);

    dishnum = new QLabel(this);
    number = 1;
    dishnum->setText(QString::number(number));
    dishnum->move(420,25);

    price = new QLabel(this);
    price->move(480,25);

    connect(add,SIGNAL(clicked()),this,SLOT(addplat()));
    connect(moindre,SIGNAL(clicked()),this,SLOT(moinplat()));
}

void order::setImage(QPixmap _platpic){
    platpic=_platpic;
    platpic = platpic.scaled(150,100,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QLabel *piclabel = new QLabel(this);
    piclabel->setPixmap(platpic);
    piclabel->move(10,10);//in
}


void order::setName(QString _name){
    name=_name;
    QLabel *namelabel = new QLabel(this);
    namelabel->setText(name);
    namelabel->move(200,20);//in constructer, cannot informe the change of name.
}

void order::setQuantity(int _quantity){
    quantity=_quantity;
}

void order::addplat(){
    number+=1;
    dishnum->setText(QString::number(number));
    emit changed();
}

void order::moinplat(){
    if(number==1){
        this->close();// ca marche?
    }
    else{
        number-=1;
        dishnum->setText(QString::number(number));
    }
    emit changed();
}
