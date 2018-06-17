# QT Final Project: Simple Painter
Disciption: a self-made mini painter using Qt. Basic functionalities include colored lines in a window when mouse is pressed and moved. The color and width of lines are adjustable and a reset button is available to clear all drawings.

Links to tutorials:

QColor Class:
http://doc.qt.io/archives/qt-4.8/qcolor.html

How to change background color of QWidget objects:
https://wiki.qt.io/How_to_Change_the_Background_Color_of_QWidget

QWidget Class
http://doc.qt.io/archives/qt-4.8/qwidget.html

Qt update() and repaint():
https://zhuanlan.zhihu.com/p/29028431

QEvent:
https://blog.csdn.net/qianqin_2014/article/details/51234752

How to use QPainter Class
https://blog.csdn.net/fanyun_01/article/details/53201084

QPainter and QPen:
https://www.youtube.com/watch?v=5JE5ek_oN_0

QMouseEvent:
http://doc.qt.io/archives/qt-4.8/qmouseevent.html

Basic drawing:
http://doc.qt.io/qt-5/qtwidgets-painting-basicdrawing-example.html

QPainter Examples:
https://blog.csdn.net/qianqin_2014/article/details/51236712

Struggles: I'm haveing a real hard time understanding how QPainterEvent works and coding for a working "reset"button took me a while because I previously just tried to clear the vector that contains all QPoints but the change won't apply immediately to the widget, that is the lines won't disappear until I click and draw a new line. Then I found out update() is probably what's missing here. Same problems with the change-color button. After update() is added in side thoes slot functions, everthing works.
