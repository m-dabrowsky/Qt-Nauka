#include <QtGui>

#ifndef __MYWINDOW_H__
#define __MYWINDOW_H__

class MyWindow: public QMainWindow
{
    Q_OBJECT
public:
    MyWindow ();
    ~MyWindow () {}
protected:
    QAction *action11;
    QAction *action12;
    QAction *action13;
    QAction *action14;
    QAction *action15;
    QAction *action16;
    QMenu *menu1;
};

#endif // __MYWINDOW_H__
