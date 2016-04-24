#ifndef CHECK_H
#define CHECK_H

#include <QDialog>
#include "order.h"
#include <QVBoxLayout>

namespace Ui {
class check;
}

class check : public QDialog
{
    Q_OBJECT

public:
    explicit check(QWidget *parent = 0);
    ~check();
    void setchecklist(QList<Dish>);

private slots:
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();
    void caltotal();

private:
    Ui::check *ui;
    QVBoxLayout *vlayout;
};

#endif // CHECK_H
