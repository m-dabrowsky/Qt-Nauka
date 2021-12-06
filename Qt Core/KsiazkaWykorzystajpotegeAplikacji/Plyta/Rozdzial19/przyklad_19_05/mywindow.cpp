#include "mywindow.h"

// konstruktor

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
    
    // utworzenie wykazu autor�w i ksi��ek 
    sqlTableModel = new QSqlTableModel (this);
    sqlTableModel -> setEditStrategy (QSqlTableModel::OnManualSubmit);
    static_cast <QSqlQueryModel*> (sqlTableModel) -> setQuery ("SELECT IMIE, NAZWISKO, TYTUL FROM AUTORZY, KSIAZKI WHERE KSIAZKI.ID_AUTORA = AUTORZY.ID_AUTORA",db);
    sqlTableModel -> setHeaderData (0,Qt::Horizontal,"Imi�");
    sqlTableModel -> setHeaderData (1,Qt::Horizontal,"Nazwisko");
    sqlTableModel -> setHeaderData (2,Qt::Horizontal,"Tytu�");
    if (sqlTableModel -> lastError().type() != QSqlError::NoError)
        DBError (sqlTableModel -> lastError());
    else
        tableView -> setModel (sqlTableModel);
    tableView -> setSelectionMode (QAbstractItemView::SingleSelection);
    tableView -> show ();

    // po��czenia sygna�-gniazdo
    connect (sqlTableModel,SIGNAL(dataChanged (QModelIndex,QModelIndex)),this,SLOT(DataChanged(QModelIndex,QModelIndex)));
    connect (pushButtonExit,SIGNAL (clicked()),qApp,SLOT (quit()));
}

// destruktor

MyWindow::~MyWindow ()
{
    db.close ();
}

// aktualizacja danych tabel

void MyWindow::DataChanged (const QModelIndex & topLeft, const QModelIndex & bottomRight)
{
    // aktualizacja imienia autora
    if (topLeft.column () == 0)
    {
        // wyszukanie numeru ID_AUTORA modyfikowanego wiersza
        QSqlQuery query (db);
        query.exec ("SELECT KSIAZKI.ID_AUTORA, IMIE, NAZWISKO, TYTUL FROM AUTORZY, KSIAZKI WHERE KSIAZKI.ID_AUTORA = AUTORZY.ID_AUTORA");
        query.seek (topLeft.row ());

        // zmiana wybranego wiersza - czyli imienia autora ksi��ki w bazie
        query.exec ("UPDATE AUTORZY SET IMIE = '" + topLeft.data ().toString () + "' WHERE ID_AUTORA = " + query.value (0).toString ());

        // ponowne wykonanie zapytania
        static_cast <QSqlQueryModel*> (sqlTableModel) -> setQuery ("SELECT IMIE, NAZWISKO, TYTUL FROM AUTORZY, KSIAZKI WHERE KSIAZKI.ID_AUTORA = AUTORZY.ID_AUTORA",db);

        // testy b��d�w
        if (sqlTableModel -> lastError().type() != QSqlError::NoError)
            DBError (sqlTableModel -> lastError());
        if (query.lastError().type() != QSqlError::NoError)
            DBError (query.lastError());
        if (db.lastError().type() != QSqlError::NoError)
            DBError (db.lastError ());
    }

    // aktualizacja nazwiska autora
    if (topLeft.column () == 1)
    {
        // wyszukanie numeru ID_AUTORA modyfikowanego wiersza
        QSqlQuery query (db);
        query.exec ("SELECT KSIAZKI.ID_AUTORA, IMIE, NAZWISKO, TYTUL FROM AUTORZY, KSIAZKI WHERE KSIAZKI.ID_AUTORA = AUTORZY.ID_AUTORA");
        query.seek (topLeft.row ());

        // zmiana wybranego wiersza - czyli nazwiska autora ksi��ki w bazie
        query.exec ("UPDATE AUTORZY SET NAZWISKO = '" + topLeft.data ().toString () + "' WHERE ID_AUTORA = " + query.value (0).toString ());
        
        // ponowne wykonanie zapytania
        static_cast <QSqlQueryModel*> (sqlTableModel) -> setQuery ("SELECT IMIE, NAZWISKO, TYTUL FROM AUTORZY, KSIAZKI WHERE KSIAZKI.ID_AUTORA = AUTORZY.ID_AUTORA",db);

        // testy b��d�w
        if (sqlTableModel -> lastError().type() != QSqlError::NoError)
            DBError (sqlTableModel -> lastError());
        if (query.lastError().type() != QSqlError::NoError)
            DBError (query.lastError());
        if (db.lastError().type() != QSqlError::NoError)
            DBError (db.lastError ());
    }

    // aktualizacja tytu�u ksi��ki
    if (topLeft.column () == 2)
    {
        // wyszukanie numeru ID_KSIAZKI modyfikowanego wiersza
        QSqlQuery query (db);
        query.exec ("SELECT ID_KSIAZKI, IMIE, NAZWISKO, TYTUL FROM AUTORZY, KSIAZKI WHERE KSIAZKI.ID_AUTORA = AUTORZY.ID_AUTORA");
        query.seek (topLeft.row ());
        
        // zmiana wybranego wiersza - czyli tytu�u ksi��ki w bazie
        query.exec ("UPDATE KSIAZKI SET TYTUL = '" + topLeft.data ().toString () + "' WHERE ID_KSIAZKI = " + query.value (0).toString ());

        // testy b��d�w
        if (sqlTableModel -> lastError().type() != QSqlError::NoError)
            DBError (sqlTableModel -> lastError());
        if (query.lastError().type() != QSqlError::NoError)
            DBError (query.lastError());
        if (db.lastError().type() != QSqlError::NoError)
            DBError (db.lastError ());
    }
}

// obs�uga b��du bazy danych

void MyWindow::DBError (QSqlError error)
{
    QMessageBox::critical (this,"B��d",error.driverText () + "\n" + error.databaseText ());
}
