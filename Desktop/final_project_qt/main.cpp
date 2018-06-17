#include "mypainter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyPainter w;
    //w.setStyleSheet("background-color:white;");
    w.show();

    return a.exec();
}

