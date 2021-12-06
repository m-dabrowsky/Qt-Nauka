#include <QtGui>
#include "ui_window.h"

#ifndef __MYWINDOW_H__
#define __MYWINDOW_H__

class MyWindow: public QWidget, private Ui::Form
{
    Q_OBJECT
public:
    MyWindow ();
    ~MyWindow () {}
};        

#endif // __MYWINDOW_H__
