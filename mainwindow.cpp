#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "orderitem.h"
#include "ingredients.h"
#include "dish.h"
#include "dishitem.h"
#include<iostream>
#include <QTextCodec>
#include<QDebug>
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
    //layout_dishlist->addWidget(new OrderItem);
    //layout_dishlist->addWidget(new OrderItem);
    //layout_dishlist->addWidget(new OrderItem);
    layout_dishlist->setMargin(0);
    ui->scrollArea_menu->widget()->setLayout(layout_dishlist);
    ui->scrollArea_menu->setWidgetResizable(true);

    ui->scrollArea_orders->widget()->setLayout(layout_orderlist);
    ui->scrollArea_orders->setWidgetResizable(true);
    //ui->lb_name->setText("hot dog");
    //Dish *dishlist = new Dish[15];
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


}
void initiate(QList<Ingredients> all_ingre,QList<Ingrenum> all_ingre_n, Dish* dishlist){
    //initial all the ingredients
    Ingredients in_1;
    Ingrenum nu_1;
    in_1.set_ingredient("tomato",":/images/ingredients/tomato.jpeg");
    nu_1.set_ingrenum("tomato",100);
    all_ingre.append(in_1);
    all_ingre_n.append(nu_1);
    Ingredients in_2;
    Ingrenum nu_2;
    in_2.set_ingredient("porc",":/images/ingredients/porc.jpeg");
    nu_2.set_ingrenum("porc",100);
    all_ingre.append(in_2);
    all_ingre_n.append(nu_2);
    Ingredients in_3;
    Ingrenum nu_3;
    in_3.set_ingredient("sugar",":/images/ingredients/sugar.jpeg");
    nu_3.set_ingrenum("sugar",10);
    all_ingre.append(in_3);
    all_ingre_n.append(nu_3);
    Ingredients in_4;
    Ingrenum nu_4;
    in_4.set_ingredient("fish",":/images/ingredients/fish.jpeg");
    nu_4.set_ingrenum("fish",200);
    all_ingre.append(in_4);
    all_ingre_n.append(nu_4);
    Ingredients in_5;
    Ingrenum nu_5;
    in_5.set_ingredient("beef",":/images/ingredients/beef.jpeg");
    nu_5.set_ingrenum("beef",200);
    all_ingre.append(in_5);
    all_ingre_n.append(nu_5);
    Ingredients in_6;
    Ingrenum nu_6;
    in_6.set_ingredient("flour",":/images/ingredients/flour.jpeg");
    nu_6.set_ingrenum("flour",200);
    all_ingre.append(in_6);
    all_ingre_n.append(nu_6);
    Ingredients in_7;
    Ingrenum nu_7;
    in_7.set_ingredient("egg",":/images/ingredients/egg.jpeg");
    nu_7.set_ingrenum("egg",200);
    all_ingre.append(in_7);
    all_ingre_n.append(nu_7);
    Ingredients in_8;
    Ingrenum nu_8;
    in_8.set_ingredient("soy",":/images/ingredients/soy.jpeg");
    nu_8.set_ingrenum("soy",200);
    all_ingre.append(in_8);
    all_ingre_n.append(nu_8);
    Ingredients in_9;
    Ingrenum nu_9;
    in_9.set_ingredient("carrot",":/images/ingredients/carrot.jpeg");
    nu_9.set_ingrenum("carrot",200);
    all_ingre.append(in_9);
    all_ingre_n.append(nu_9);
    Ingredients in_10;
    Ingrenum nu_10;
    in_10.set_ingredient("crevette",":/images/ingredients/crevette.jpeg");
    nu_10.set_ingrenum("crevette",200);
    all_ingre.append(in_10);
    all_ingre_n.append(nu_10);
    Ingredients in_11;
    Ingrenum nu_11;
    in_11.set_ingredient("garlic",":/images/ingredients/garlic.jpeg");
    nu_11.set_ingrenum("garlic",200);
    all_ingre.append(in_11);
    all_ingre_n.append(nu_11);
    Ingredients in_12;
    Ingrenum nu_12;
    in_12.set_ingredient("ginger",":/images/ingredients/ginger.jpeg");
    nu_12.set_ingrenum("ginger",20);
    all_ingre.append(in_12);
    all_ingre_n.append(nu_12);
    Ingredients in_13;
    Ingrenum nu_13;
    in_13.set_ingredient("nut",":/images/ingredients/nut.jpeg");
    nu_13.set_ingrenum("nut",50);
    all_ingre.append(in_13);
    all_ingre_n.append(nu_13);
    Ingredients in_14;
    Ingrenum nu_14;
    in_14.set_ingredient("onions",":/images/ingredients/onions.jpeg");
    nu_14.set_ingrenum("onions",20);
    all_ingre.append(in_14);
    all_ingre_n.append(nu_14);
    Ingredients in_15;
    Ingrenum nu_15;
    in_15.set_ingredient("pineapple",":/images/ingredients/pineapple.jpeg");
    nu_15.set_ingrenum("pineapple",100);
    all_ingre.append(in_15);
    all_ingre_n.append(nu_15);
    //cout<<"get"<<in_15.getpath().toStdString()<<endl;
    Ingredients in_16;
    Ingrenum nu_16;
    in_16.set_ingredient("rice",":/images/ingredients/rice.jpeg");
    nu_16.set_ingrenum("rice",100);
    all_ingre.append(in_16);
    all_ingre_n.append(nu_16);
    //cout<<"get"<<in_16.getpath().toStdString()<<endl;
    Ingredients in_17;
    Ingrenum nu_17;
    in_17.set_ingredient("green pepper",":/images/ingredients/green pepper.jpeg");
    nu_17.set_ingrenum("pineapple",100);
    all_ingre.append(in_17);
    all_ingre_n.append(nu_17);
    //cout<<"get"<<in_17.getpath().toStdString()<<endl;
    Ingredients in_18;
    Ingrenum nu_18;
    in_18.set_ingredient("mushroom",":/images/ingredients/mushroom.jpeg");
    nu_18.set_ingrenum("mushroom",100);
    all_ingre.append(in_18);
    all_ingre_n.append(nu_18);
    //cout<<"get"<<in_18.getpath().toStdString()<<endl;



    QString dishname0 = "Hot noodle";
    dishlist[0] = Dish(dishname0,":/images/hot noodle.jpeg",9.5);
    dishlist[0].addkeyword("new");
    dishlist[0].addkeyword("salt");
    dishlist[0].addkeyword("spicy");
    dishlist[0].addkeyword("staple food");
    dishlist[0].dish_ingre->append(nu_1);
    dishlist[0].dish_ingre->append(nu_3);
    dishlist[0].dish_ingre->append(nu_15);
    dishlist[0].dish_ingre->append(nu_16);

    QString dishname1 = "Ribs sweet and sour";
    dishlist[1] = Dish(dishname1,":/images/porc.jpg",12);
    dishlist[1].addkeyword("Top 10");
    dishlist[1].addkeyword("sweet");
    dishlist[1].addkeyword("meat");
    dishlist[1].dish_ingre->append(nu_1);
    dishlist[1].dish_ingre->append(nu_2);
    dishlist[1].dish_ingre->append(nu_3);
    dishlist[1].dish_ingre->append(nu_12);
    dishlist[1].dish_ingre->append(nu_14);


    QString dishname2 = "Chicken with cashew nuts";
    dishlist[2] = Dish(dishname2,":/images/chicken.jpg",10.5);
    dishlist[2].addkeyword("new");
    dishlist[2].addkeyword("salt");
    dishlist[2].addkeyword("meat");
    dishlist[2].dish_ingre->append(nu_7);
    dishlist[2].dish_ingre->append(nu_6);
    dishlist[2].dish_ingre->append(nu_8);
    dishlist[2].dish_ingre->append(nu_9);
    dishlist[2].dish_ingre->append(nu_11);




    QString dishname3 = "Mooncake";
    dishlist[3] = Dish(dishname3,":/images/cake.jpg",8);
    dishlist[3].addkeyword("kids");
    dishlist[3].addkeyword("sweet");
    dishlist[3].addkeyword("dessert");
    dishlist[3].dish_ingre->append(nu_4);
    dishlist[3].dish_ingre->append(nu_2);
    dishlist[3].dish_ingre->append(nu_3);
    dishlist[3].dish_ingre->append(nu_5);
    dishlist[2].dish_ingre->append(nu_11);



    QString dishname4 = "Steamed fish";
    dishlist[4] = Dish(dishname4,":/images/fish.jpg",13.5);
    dishlist[4].addkeyword("Top 10");
    dishlist[4].addkeyword("spicy");
    dishlist[2].addkeyword("soup");
    dishlist[4].dish_ingre->append(nu_4);
    dishlist[4].dish_ingre->append(nu_12);
    dishlist[4].dish_ingre->append(nu_14);
    dishlist[4].dish_ingre->append(nu_9);


    QString dishname5 = "Noodles with vegetables";
    dishlist[5] = Dish(dishname5,":/images/vermicelles.jpg",9.5);
    dishlist[5].addkeyword("kids");
    dishlist[5].addkeyword("spicy");
    dishlist[5].addkeyword("staple food");
    dishlist[5].dish_ingre->append(nu_1);
    dishlist[5].dish_ingre->append(nu_2);
    dishlist[5].dish_ingre->append(nu_3);
    dishlist[5].dish_ingre->append(nu_11);

    QString dishname6 = "Spicy beef";
    dishlist[6] = Dish(dishname6,":/images/spicy beef.jpeg",9.5);
    dishlist[6].addkeyword("Top 10");
    dishlist[6].addkeyword("Spicy");
    dishlist[6].addkeyword("Meat");
    dishlist[6].dish_ingre->append(nu_5);
    dishlist[6].dish_ingre->append(nu_14);
    dishlist[6].dish_ingre->append(nu_3);
    dishlist[6].dish_ingre->append(nu_11);

    QString dishname7 = "Lettuce";
    dishlist[7] = Dish(dishname7,":/images/lettuce.jpeg",9.5);
    dishlist[7].addkeyword("new");
    dishlist[7].addkeyword("salty");
    dishlist[7].addkeyword("Vegetable");
    dishlist[7].dish_ingre->append(nu_5);
    dishlist[7].dish_ingre->append(nu_2);
    dishlist[7].dish_ingre->append(nu_3);
    dishlist[7].dish_ingre->append(nu_11);

    QString dishname8 = "Jumping buddha";
    dishlist[8] = Dish(dishname8,":/images/jumping buddha.jpeg",9.5);
    dishlist[8].addkeyword("new");
    dishlist[8].addkeyword("salt");
    dishlist[8].addkeyword("soup");
    dishlist[8].dish_ingre->append(nu_11);
    dishlist[8].dish_ingre->append(nu_12);
    dishlist[8].dish_ingre->append(nu_17);
    dishlist[8].dish_ingre->append(nu_8);
    dishlist[8].dish_ingre->append(nu_9);

    QString dishname9 = "Glutinous";
    dishlist[9] = Dish(dishname9,":/images/glutinous rice.jpeg",9.5);
    dishlist[9].addkeyword("kids");
    dishlist[9].addkeyword("sweet");
    dishlist[9].addkeyword("dessert");
    dishlist[9].dish_ingre->append(nu_1);
    dishlist[9].dish_ingre->append(nu_3);
    dishlist[9].dish_ingre->append(nu_15);
    dishlist[9].dish_ingre->append(nu_16);
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

}
