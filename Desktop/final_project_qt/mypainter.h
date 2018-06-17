#ifndef MYPAINTER_H
#define MYPAINTER_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <mybutton.h>


namespace Ui {
class MyPainter;
}

class MyPainter : public QWidget
{
    Q_OBJECT

public:
    explicit MyPainter(QWidget *parent = 0);
    MyButton* button;
    MyButton* button1;
    void paintEvent(QPaintEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

    QVector<QVector<QPoint>>lines;
    ~MyPainter();

signals:

public slots:
    void setMyPenColorRed();
    void setMyPenColorYellow();
    void setMyPenColorGreen();
    void setMyPenColorBlue();
    void clearLines();
    void setWidth(double x);
private:
    QColor MyPenColor;
    int width;
    Ui::MyPainter *ui;
};

#endif // MYPAINTER_H
