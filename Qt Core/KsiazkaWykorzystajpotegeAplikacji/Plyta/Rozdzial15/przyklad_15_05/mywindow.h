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
    QMenu *menu1;
};

#endif // __MYWINDOW_H__
