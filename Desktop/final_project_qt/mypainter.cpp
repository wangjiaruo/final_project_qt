#include "mypainter.h"
#include "ui_mypainter.h"
#include <QDebug>
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
#include <QPainter>


MyPainter::MyPainter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyPainter)
{
    ui->setupUi(this);
    MyPenColor = QColor(0,0,0,255);
    width=1.0;
//    button=new MyButton("Yellow",this);
//    connect(button,SIGNAL(clicked()),this,SLOT(setMyPenColorYellow()));
    //connect(button,SIGNAL(clicked()),this,SLOT(clearLines()));
    ui->doubleSpinBox->setRange(1.0,5.0);
    ui->doubleSpinBox->setSingleStep(1.0);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(setMyPenColorRed()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(setMyPenColorYellow()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(setMyPenColorGreen()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(setMyPenColorBlue()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(clearLines()));
    connect(ui->doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(setWidth(double)));
}

void MyPainter::setWidth(double x){
    width=x;
    update();
}

void MyPainter::setMyPenColorRed(){
    MyPenColor=QColor(200,11,0,250);
    update();
}

void MyPainter::setMyPenColorYellow(){
    MyPenColor=QColor(250,200,0,250);
    update();
}

void MyPainter::setMyPenColorGreen(){
    MyPenColor=QColor(100,200,0,250);
    update();
}

void MyPainter::setMyPenColorBlue(){
    MyPenColor=QColor(10,120,230,250);
    update();
}

void MyPainter::clearLines(){
    lines.clear();
    MyPenColor = QColor(0,0,0,255);
    update();
}

void MyPainter::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPen pen;
    pen.setColor(MyPenColor);
    pen.setWidth(width);
    painter.setPen(pen);


    for(int i=0;i<lines.size();++i)
    {
        const QVector<QPoint> &line=lines.at(i);
        for(int j=0;j<line.size()-1;++j)
            painter.drawLine(line.at(j),line.at(j+1));
    }
}

void MyPainter::mouseMoveEvent(QMouseEvent *ev){
    if(lines.size()==0)
    {
        QVector<QPoint> line;
        lines.append(line);
    }
    QVector<QPoint>&lastLine=lines.last();
    lastLine.append(ev->pos());
    update();
}

void MyPainter::mousePressEvent(QMouseEvent *ev){
    QVector<QPoint>line;
    lines.append(line);
    QVector<QPoint> &lastLine=lines.last();
    lastLine.append(ev->pos());
}

void MyPainter::mouseReleaseEvent(QMouseEvent *ev){
    QVector<QPoint> &lastLine=lines.last();
    lastLine.append(ev->pos());
}
MyPainter::~MyPainter()
{
    delete ui;
}
