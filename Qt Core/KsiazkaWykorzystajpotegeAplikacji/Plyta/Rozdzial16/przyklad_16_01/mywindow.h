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
protected slots:
    void MessageBoxAbout ();
    void MessageBoxCritical ();
    void MessageBoxInformation ();
    void MessageBoxQuestion ();
    void MessageBoxWarning ();
    void MessageBoxAboutQt ();
    void ErrorMessage ();
protected:
    QErrorMessage *errorMessage;
};        

#endif // __MYWINDOW_H__
