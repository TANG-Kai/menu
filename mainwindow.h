#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"dish.h"
#include"check.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pb_gotonext_clicked();
    void dish_added(QString name);
    void update_filter(QAbstractButton*);
private:
    Ui::MainWindow *ui;
    check checkwindow;
};

#endif // MAINWINDOW_H
