#ifndef MYBUTTON_H
#define MYBUTTON_H

#include<QWidget>
#include <QPainter>
#include <QMouseEvent>

class MyButton:public QWidget{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent=0);
    MyButton(const QString &text, QWidget *parent);

    QRect rect;
    QString text;
    bool isPressed;
    void paintEvent(QPaintEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

signals:
    void clicked();

};

#endif // MYBUTTON_H
