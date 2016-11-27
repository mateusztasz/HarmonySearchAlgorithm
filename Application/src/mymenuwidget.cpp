#include "mymenuwidget.h"

myMenuWidget::myMenuWidget(QWidget *parent)
{

    this->setStyleSheet("background-color:gray;");
    int pp = parent->pos().rx();

    this->setGeometry(pp,pp,parent->width(),parent->height());

    this->show();
    image = new QLabel(this);
    QPixmap *p = new QPixmap("://icon.ico");

    image->setPixmap(*p);
    image->setGeometry(this->width()/2 - 64, -128,this->width(),this->height());
    image->setPixmap(p->scaled(this->width()/4,this->height()/4,Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QPushButton *HS_Standard = new QPushButton(this);
    HS_Standard->setText("Standard HS");
    HS_Standard->setGeometry(this->width()/2 - 128, this->height()/2 + 100 , 100,100);
}
