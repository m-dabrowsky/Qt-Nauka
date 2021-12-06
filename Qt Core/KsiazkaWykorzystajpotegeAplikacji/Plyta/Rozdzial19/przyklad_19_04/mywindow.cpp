#include "mywindow.h"

MyWindow::MyWindow ()
{
    setupUi (this);
    
    // utworzenie po��czenia z baz� danych
    db = QSqlDatabase::addDatabase ("QIBASE");
    db.setDatabaseName ("TEST.FDB");
    db.setUserName ("SYSDBA");
    db.setPassword ("masterkey");
 
    // obs�uga b��du po��czenia
    if (!db.open())
        DBError (db.lastError ());

    // po��czenia sygna�-gniazdo
    connect (pushButtonExec,SIGNAL (clicked()),this,SLOT (Exec()));
    connect (pushButtonClear,SIGNAL (clicked()),this,SLOT (Clear()));
}

// destruktor

MyWindow::~MyWindow ()
{
    db.close ();
}

// wykonanie zapytania SQL

void MyWindow::Exec ()
{
    queryModel = new QSqlQueryModel (table);
    queryModel -> setQuery (sqlEdit -> toPlainText(),db);
    if (queryModel -> lastError().type() != QSqlError::NoError)
        DBError (queryModel -> lastError());
    else
        table -> setModel (queryModel);
    table -> show();
}

// czyszczenie zapytania SQL

void MyWindow::Clear ()
{
     sqlEdit -> clear ();
}

// obs�uga b��du bazy danych

void MyWindow::DBError (QSqlError error)
{
    QMessageBox::critical (this,"B��d",error.driverText () + "\n" + error.databaseText ());
}
