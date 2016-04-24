#include "check.h"
#include "ui_check.h"

check::check(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::check)
{
    ui->setupUi(this);
    vlayout = new QVBoxLayout;
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);//may be changed
    ui->scrollArea->widget()->setLayout(vlayout);

}

void check::setchecklist(QList<Dish> _orderlist){
    for(int i=0;i<_orderlist.size();i++){
        order *unorder=new order();
        QPixmap platpic = QPixmap(_orderlist.at(i).getpath());//image got
        unorder->setImage(platpic);
        unorder->setName(_orderlist.at(i).getname());
        unorder->setMinimumHeight(100);
        vlayout->addWidget(unorder);
        connect(unorder,SIGNAL(changed()),this,SLOT(caltotal()));

        double temp = _orderlist.at(i).getprice()*unorder->number;
        QString stringtemp = QString::number(temp)+"$";
        unorder->price->setText(stringtemp);

    }

}

void check::caltotal(){

}

check::~check()
{
    delete ui;
}

void check::on_pushButton_5_clicked()
{
    this->close();
}

void check::on_pushButton_3_clicked()
{
    this->close();
}
