#include "welcome.h"
#include "ui_welcome.h"

welcome::welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::welcome)
{
    ui->setupUi(this);
}

welcome::~welcome()
{
    delete ui;
}

void welcome::on_chinese_clicked()
{
    this->close();
    Mwindow.show();
}

void welcome::on_english_clicked()
{
    this->close();
    Mwindow.show();
}

void welcome::on_french_clicked()
{
    this->close();
    Mwindow.show();
}
