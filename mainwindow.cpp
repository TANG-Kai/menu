#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "orderitem.h"

QWidget *wgsc;
QVBoxLayout *sclayout = new QVBoxLayout;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wgsc = new QWidget;
    sclayout->addWidget(new OrderItem);
    sclayout->addWidget(new OrderItem);
    sclayout->addWidget(new OrderItem);
    sclayout->setMargin(0);
    ui->scrollArea->widget()->setLayout(sclayout);
    ui->scrollArea->setWidgetResizable(true);
    QList<Dish> dishes_on_display;
    QList<Dish> all_dishes;

    Dish dish1("dish1",12.9);
    Dish dish2("dish2", 3.8);
    Dish dish3("dish3", 1.9);
    Dish dish4("dish4", 9.9);
    Dish dish5("dish5", 38.5);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_add_clicked()
{
    sclayout->addWidget(new OrderItem);
}
