#ifndef WELCOME_H
#define WELCOME_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class welcome;
}

class welcome : public QDialog
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = 0);
    ~welcome();

private slots:
    void on_chinese_clicked();

    void on_english_clicked();

    void on_french_clicked();

private:
    Ui::welcome *ui;
    MainWindow Mwindow;
};

#endif // WELCOME_H
