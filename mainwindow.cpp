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
QVBoxLayout *layout_keywordlist = new QVBoxLayout;
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

QButtonGroup bg_keys;
QStringList selected_keys;
QStringList left_keys;

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

    ui->gb_keywords->setLayout(layout_keywordlist);

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
    QStringList key_in_containers;
    QAbstractButton* qab_ite;
    foreach(qab_ite, ui->bg_origin_of_meat->buttons()){
        key_in_containers.append(qab_ite->text());
    }
    foreach(qab_ite, ui->bg_region->buttons()){
        key_in_containers.append(qab_ite->text());
    }
    foreach(qab_ite, ui->bg_spiciness->buttons()){
        key_in_containers.append(qab_ite->text());
    }
    QStringList key_as_category = QString("All,Dish,Soup,Dessert,Drink").split(",");


    QString str;
    foreach(str,keyHash_all.uniqueKeys()){
        qDebug() << str;
        if(!key_in_containers.contains(str)&& !key_as_category.contains(str))
        {
        QCheckBox * cb = new QCheckBox(str);
        layout_keywordlist->addWidget(cb);
        bg_keys.addButton(cb);
        cb->show();}
    }

    bg_keys.setExclusive(false);
    connect(ui->linkedbuttons_Category, SIGNAL(ClickedButton(QAbstractButton*)), this, SLOT(update_filter(QAbstractButton*)));
    connect(ui->bg_origin_of_meat,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(update_filter(QAbstractButton*)));
    connect(ui->bg_region,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(update_filter(QAbstractButton*)));
    connect(ui->bg_spiciness,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(update_filter(QAbstractButton*)));
    connect(&bg_keys,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(update_filter(QAbstractButton*)));

    ui->lb_amount->setText("$" + QString::number(0));
    qDebug() <<"button counts"<< bg_keys.buttons().length();
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
    if(str.toLower()!="all")
        if(!selected_keys.contains(str))
            selected_keys.append(str);
}

void MainWindow::update_filter(QAbstractButton* _q_useless){
    //initialize all dishitems
    DishItem* di;
    foreach(di, ditems){
        di->show();
    }
    //initialize and recalculate selected keys
    selected_keys.clear();
    append_selectedkeys(ui->linkedbuttons_Category->checkedButton()->text());
    append_selectedkeys(ui->bg_origin_of_meat->checkedButton()->text());
    append_selectedkeys(ui->bg_region->checkedButton()->text());
    QAbstractButton * qab_1;
    foreach(qab_1,bg_keys.buttons() ){
        if(((QCheckBox *)qab_1)->isChecked())
            append_selectedkeys(qab_1->text());
    }

    qDebug()<<ui->bg_origin_of_meat->checkedButton()->text();
    qDebug()<<"filter_changed";
    qDebug()<<selected_keys;

    //calculate the interval of spiciness
    int min_spi = 0;
    int max_spi = 10;
    QString spiciness_level = ui->bg_spiciness->checkedButton()->text();
    if(spiciness_level.toLower() == "mild"){
        min_spi = 1;
        max_spi = 4;
    }
    else if(spiciness_level.toLower() == "medium"){
        min_spi = 3;
        max_spi = 6;
    }
    else if(spiciness_level.toLower() == "hot"){
        min_spi = 5;
        max_spi = 8;
    }
    else if(spiciness_level.toLower() == "very hot"){
        min_spi = 8;
        max_spi = 10;
    }
    else if(spiciness_level.toLower() == "not spicy"){
        min_spi = 0;
        max_spi = 0;
    }

    //hide all dishes that don't correspond to spiciness
    DishItem* di_ite;
    foreach(di_ite, ditems){
        int spi = di_ite->dish->spiciness;
        if(!(min_spi<=spi && max_spi >= spi))
            di_ite->hide();
    }


    //hide all dished that don't have any selected keys
    QString str;
    foreach(str, selected_keys){
        DishItem* di;
        foreach(di, ditems){
            if(!di->dish->getkeys_container()->contains(str)&&!di->dish->getkeys_container()->contains(str.toLower()))
                di->hide();
        }
    }

    //recalculate all Keys that should appear in the key area
    DishItem* di_iterator;
    left_keys.clear();
    foreach(di_iterator, ditems){
        if(di_iterator->isVisible())
        {
            QString key;
            foreach(key,*di_iterator->dish->getkeys_container()){
                if(!(left_keys.contains(key)||left_keys.contains(key.toLower())))
                    left_keys.append(key);
            }
        }
    }
    //handle the buttons that correspond to the left_keys. hide all impossible buttons
    QAbstractButton * qab;
    foreach(qab,bg_keys.buttons() ){
        {
            qDebug()<<qab->text();
            if(left_keys.contains(qab->text())||left_keys.contains(qab->text().toLower()))
                qab->show();
            else{
                qab->hide();
                left_keys.removeAll(qab->text());
                left_keys.removeAll(qab->text().toLower());
                ((QCheckBox*)qab)->setChecked(false);
            }
        }
    }


}


