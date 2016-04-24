#ifndef LINKEDBUTTONS_H
#define LINKEDBUTTONS_H

#include <QWidget>
#include <QtGui>


static QString _strip_normal(
        "QPushButton {"
        "   margin: 0; padding: 10px; border: 0px;"
        "   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
        "                              stop: 0 #f6f7fa, stop: 1 #aaabae);"
        "}");
static QString _strip_checked(
        "QPushButton:checked {"
        "   background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
        "                              stop: 0 #aaabae, stop: 1 #f6f7fa);"
        "}");
static QString _strip_first(
        "QPushButton{"
        "   border-top-left-radius: 6px;"
        "   border-bottom-left-radius: 6px;"
        "}");
static QString _strip_last(
        "QPushButton{"
        "   border-top-right-radius: 6px;"
        "   border-bottom-right-radius: 6px;"
        "}");

static QString _widget_back(
        "QWidget {"
        "   background: black;"
        "}");

class LinkedButtons : public QWidget
{
    Q_OBJECT
public:
    QButtonGroup *bg;
    QHBoxLayout *hl;
    LinkedButtons(QWidget *parent = 0)
        : QWidget(parent)
    {
        /* style sheet applies to this widget and its children */
        setStyleSheet(_widget_back+_strip_normal+_strip_checked);

        /* First and last widget need special borders */
        QPushButton *first = createButton("All",   true,  _strip_first);
        QPushButton *mid = createButton("Dish",   false);
        QPushButton *mid1 = createButton("Soup",   false);
        QPushButton *mid2 = createButton("Dessert",   false);
        QPushButton *last = createButton("Drink", false, _strip_last);

        /* Button group for button selection handling */
        bg = new QButtonGroup;
        bg->addButton(first);
        bg->addButton(mid);
        bg->addButton(mid1);
        bg->addButton(mid2);
        bg->addButton(last);

        /* Layout with no spacing */
        hl = new QHBoxLayout;
        hl->addWidget(first);
        hl->addWidget(mid);
        hl->addWidget(mid1);
        hl->addWidget(mid2);
        hl->addWidget(last);

        hl->setSpacing(0);

        setLayout(hl);
        connect(bg, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(buttonClicked(QAbstractButton*)));
    }

    QPushButton *createButton(QString const& name,
                              bool checked,
                              QString const& sheet = QString())
    {
        QPushButton *pb = new QPushButton(name);
        pb->setCheckable(true);
        pb->setChecked(checked);
        if (!sheet.isEmpty())
            pb->setStyleSheet(sheet);
        return pb;
    }
    QAbstractButton * checkedButton()const
    {
        return bg->checkedButton();
    }
signals:
    void ClickedButton(QAbstractButton*);
private slots:
    void buttonClicked(QAbstractButton* qab){
        emit(ClickedButton(qab));
    }
};

#endif // LINKEDBUTTONS_H
