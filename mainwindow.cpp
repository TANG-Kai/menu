#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "orderitem.h"
#include "ingredients.h"
#include "dish.h"
#include "dishitem.h"
#include<iostream>
#include <QTextCodec>
#include<QDebug>
#include "initiate.h"
QWidget *wgsc;


QVBoxLayout *layout_dishlist = new QVBoxLayout;
QVBoxLayout *layout_orderlist = new QVBoxLayout;
void initiate(QList<Ingredients> all_ingre,QList<Ingrenum> all_ingre_n, Dish* dishlist);
void update_display_dishes(Ui::MainWindow *ui);
void update_display_list();
void update_page_pb(Ui::MainWindow *ui);

Dish *dishlist = new Dish[15];
QVector<Dish> all_dishes;
QVector<DishItem*> ditems;
QList<Ingredients> all_ingre;
QList<Ingrenum> all_ingre_n;
QList<int> candidat_list;
QList<QString> checked_keys;
int cur_page=0;

QHash<QString, int> keyHash_all;
QHash<QString, int> keyHash_chosen;

QStringList selected_keys;

class OrderData{
public:
    QString name;
    int quantity;
    double price;
    double amount;
};

QList<OrderData*> OrderList;
QList<OrderItem*> OrderItemList;

MainWindow::~MainWindow()
{
    delete ui;
}

void initiate(QList<Ingredients> all_ingre,QList<Ingrenum> all_ingre_n, Dish* dishlist);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    setFixedSize(1280,800);
    ui->setupUi(this);
    wgsc = new QWidget;
    layout_dishlist->setMargin(0);
    ui->scrollArea_menu->widget()->setLayout(layout_dishlist);
    ui->scrollArea_menu->setWidgetResizable(true);

    ui->scrollArea_orders->widget()->setLayout(layout_orderlist);
    ui->scrollArea_orders->setWidgetResizable(true);
    initiate(all_ingre, all_ingre_n, dishlist);

    for(int i=0;i<10;i++)
    {
        all_dishes.append(dishlist[i]);
        DishItem* new_ditem = new DishItem();
        new_ditem->setDish(&dishlist[i]);
        layout_dishlist->addWidget(new_ditem);
        ditems.append(new_ditem);
        connect(new_ditem, SIGNAL(buttonClicked(QString)),this, SLOT(dish_added(QString)));

        candidat_list.append(i);
        QList<QString>* keys = dishlist[i].getkeys_container();
        QString str;
        foreach(str,*keys){
            keyHash_all.insert(str, 1);
        }
    }
    QString str;
    foreach(str,keyHash_all.uniqueKeys()){
        qDebug() << str;
    }

    connect(ui->linkedbuttons_Category, SIGNAL(ClickedButton(QAbstractButton*)), this, SLOT(update_filter(QAbstractButton*)));
    connect(ui->bg_origin_of_meat,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(update_filter(QAbstractButton*)));
    connect(ui->bg_saltiness,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(update_filter(QAbstractButton*)));
    connect(ui->bg_spiciness,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(update_filter(QAbstractButton*)));

    ui->lb_amount->setText("$" + QString::number(0));
    update_filter(NULL);
}


void MainWindow::on_pb_gotonext_clicked()
{
    this->close();
    QList<Dish> orderlist;
    for(int i=0; i< OrderItemList.length();i++)
    {
        for(int j=0; j<all_dishes.size();j++){
            if(OrderItemList.at(i)->name == all_dishes.at(j).getname())
            {
                orderlist.append(all_dishes.at(j));
                break;
            }
        }
    }
    checkwindow.setchecklist(orderlist);
    checkwindow.show();
    checkwindow.exec();
    this->show();
}
Dish * search_dish(QString name){
    for(int i=0;i<all_dishes.size();i++){
        if(dishlist[i].name== name)
            return &dishlist[i];
    }
    qDebug()<<"dish not found in search_dish:"<<name;
    return NULL;
}


void MainWindow::dish_added(QString name){

    Dish* cur_dish = search_dish(name);

    OrderData od;
    od.name = cur_dish->name;
    od.price = cur_dish->price;
    od.quantity = 1;
    od.amount = od.quantity * od.price;

    qDebug()<<2;
    bool is_contained = false;

    OrderItem* odd;
    foreach(odd, OrderItemList){
        if(odd->name == cur_dish->name){
            is_contained = true;
            qDebug()<<6;
            odd->quantity++;
            odd->update();
            break;
        }
    }

    if(is_contained == false)
    {
        std::cout<<"arrived in the boucle";
        OrderItem* oi = new OrderItem;
        oi->setText(od.name, od.quantity, od.price, od.amount);
        layout_orderlist->addWidget(oi);
        OrderItemList.append(oi);
    }
    double total_amount = 0;
    OrderItem* oi;
    foreach(oi,OrderItemList){
        total_amount+= oi->quantity*oi->price;
    }
    ui->lb_amount->setText("$" + QString::number(total_amount));
}

void append_selectedkeys(QString str){
    if(str.toLower()!="all") selected_keys.append(str);
}

void MainWindow::update_filter(QAbstractButton* _q_useless){

    DishItem* di;
    foreach(di, ditems){
        di->show();
    }
    selected_keys.clear();
    //selected_keys.append(ui->linkedbuttons_Category->checkedButton()->text());
    append_selectedkeys(ui->linkedbuttons_Category->checkedButton()->text());
    append_selectedkeys(ui->bg_origin_of_meat->checkedButton()->text());
    qDebug()<<ui->bg_origin_of_meat->checkedButton()->text();
    qDebug()<<"filter_changed";
    qDebug()<<selected_keys;
    QString str;
    foreach(str, selected_keys){
        DishItem* di;
        foreach(di, ditems){
            if(!di->dish->getkeys_container()->contains(str)&&!di->dish->getkeys_container()->contains(str.toLower()))
                di->hide();
        }
    }
}


