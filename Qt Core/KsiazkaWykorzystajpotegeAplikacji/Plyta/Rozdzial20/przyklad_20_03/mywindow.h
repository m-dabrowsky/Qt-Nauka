#include <QtGui>
#include "ui_window.h"

#ifndef __MYWINDOW_H__
#define __MYWINDOW_H__

class MyWindow: public QMainWindow, private Ui::Window
{
    Q_OBJECT
public:
    MyWindow ();
    ~MyWindow () {};
private:
    QString fileName;
    QPrinter printer;
private slots:
    void New ();
    void Open ();
    void Save ();
    void SaveAs ();
    void SavePDF ();
    void Print ();
};

#endif // __MYWINDOW_H__
