#include <QtGui>
#include <QtSql>
#include "ui_window.h"
#include "prime.h"

#ifndef __MYWINDOW_H__
#define __MYWINDOW_H__

class MyWindow: public QDialog, private Ui::Form
{
    Q_OBJECT
public:
    MyWindow ();
    ~MyWindow () {}
public slots:
    void ExecThread ();
    void ExecStd ();
    void Info ();
};        

#endif // __MYWINDOW_H__
