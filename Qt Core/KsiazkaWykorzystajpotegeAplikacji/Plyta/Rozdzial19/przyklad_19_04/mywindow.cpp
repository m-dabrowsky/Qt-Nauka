#include "mywindow.h"

MyWindow::MyWindow ()
{
    setupUi (this);
    
    // utworzenie po³¹czenia z baz¹ danych
    db = QSqlDatabase::addDatabase ("QIBASE");
    db.setDatabaseName ("TEST.FDB");
    db.setUserName ("SYSDBA");
    db.setPassword ("masterkey");
 
    // obs³uga b³êdu po³¹czenia
    if (!db.open())
        DBError (db.lastError ());

    // po³¹czenia sygna³-gniazdo
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

// obs³uga b³êdu bazy danych

void MyWindow::DBError (QSqlError error)
{
    QMessageBox::critical (this,"B³¹d",error.driverText () + "\n" + error.databaseText ());
}
