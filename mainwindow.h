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
    void on_pb_add_clicked();

    void on_pb_right_clicked();

    void on_pb_left_clicked();

    void on_pb_add_3_clicked();

    void on_pb_add_4_clicked();

    void on_pb_add_8_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_checkBox_5_clicked();

    void on_checkBox_7_clicked();

    void on_checkBox_6_clicked();

    void on_checkBox_clicked();

    void on_pb_gotonext_clicked();

private:
    Ui::MainWindow *ui;
    check checkwindow;
};

#endif // MAINWINDOW_H
