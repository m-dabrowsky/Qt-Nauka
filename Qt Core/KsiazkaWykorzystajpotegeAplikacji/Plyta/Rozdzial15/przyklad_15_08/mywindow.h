#include <QtGui>
#include "ui_window.h"

#ifndef __MYWINDOW_H__
#define __MYWINDOW_H__

class MyWindow: public QMainWindow, private Ui::Window
{
    Q_OBJECT
public:
    MyWindow ();
    ~MyWindow () {}
private:
    QActionGroup *actionGroup;
};        

#endif // __MYWINDOW_H__
