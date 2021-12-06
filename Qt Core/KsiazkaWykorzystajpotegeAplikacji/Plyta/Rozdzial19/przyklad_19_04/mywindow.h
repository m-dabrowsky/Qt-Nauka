#include <QtGui>
#include <QtSql>
#include "ui_window.h"

#ifndef __MYWINDOW_H__
#define __MYWINDOW_H__

class MyWindow: public QWidget, private Ui::Form
{
    Q_OBJECT
public:
    MyWindow ();
    ~MyWindow ();
public slots:
    void Exec ();
    void Clear ();
private:
    QSqlDatabase db;
    QSqlQueryModel *queryModel;
    void DBError (QSqlError error);
};        

#endif // __MYWINDOW_H__
