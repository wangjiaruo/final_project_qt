#include "mybutton.h"
#include <QPainter>
#include <QMouseEvent>

MyButton::MyButton(QWidget *parent):QWidget(parent),rect(0,0,100,100),text(QString()){
    isPressed=false;
    this->setGeometry(rect);
}

MyButton::MyButton(const QString &text, QWidget *parent):QWidget(parent),rect(0,0,100,100),text(text)
{
    isPressed=false;
    this->setGeometry(rect);
}

void MyButton::mousePressEvent(QMouseEvent *ev){
    isPressed=true;
    update();
}

void MyButton::mouseReleaseEvent(QMouseEvent *ev){
    isPressed=false;
    update();
    if(rect.contains(ev->pos()))
        emit clicked();
}



void MyButton::paintEvent(QPaintEvent *){
    QPainter painter(this);
    if(isPressed)
        painter.setBrush(Qt::white);
    else
        painter.setBrush(Qt::yellow);
    painter.drawRect(rect);
    painter.drawText(rect,text,QTextOption(Qt::AlignCenter));
}
