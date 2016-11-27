#ifndef MYMENUWIDGET_H
#define MYMENUWIDGET_H

#include <QLabel>
#include <QPushButton>
#include <QPropertyAnimation>
class myMenuWidget: public QWidget
{

    QLabel *processLabel;
    QMovie *movie;

    QWidget *welcome_page;

    QLabel *image;
    QPushButton* Menu;
    QPropertyAnimation *animation;

public:
    myMenuWidget(QWidget *parent = 0);
};

#endif // MYMENUWIDGET_H
