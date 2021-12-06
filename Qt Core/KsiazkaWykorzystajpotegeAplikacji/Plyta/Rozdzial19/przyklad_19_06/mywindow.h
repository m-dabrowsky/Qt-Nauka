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
    void DataChanged (const QModelIndex & topLeft, const QModelIndex & bottomRight);
    void NewAuthor ();
    void NewBook ();
    void DeleteBook ();
private:
    QSqlDatabase db;
    QSqlTableModel *sqlTableModel;
    void DBError (QSqlError error);
};        

#endif // __MYWINDOW_H__
