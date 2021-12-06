#include "mywindow.h"
#include "ui_newauthor.h"
#include "ui_newbook.h"

// konstruktor

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
    
    // utworzenie wykazu autorów i ksi¹¿ek 
    sqlTableModel = new QSqlTableModel (this);
    sqlTableModel -> setEditStrategy (QSqlTableModel::OnManualSubmit);
    static_cast <QSqlQueryModel*> (sqlTableModel) -> setQuery ("SELECT IMIE, NAZWISKO, TYTUL FROM AUTORZY, KSIAZKI WHERE KSIAZKI.ID_AUTORA = AUTORZY.ID_AUTORA",db);
    sqlTableModel -> setHeaderData (0,Qt::Horizontal,"Imiê");
    sqlTableModel -> setHeaderData (1,Qt::Horizontal,"Nazwisko");
    sqlTableModel -> setHeaderData (2,Qt::Horizontal,"Tytu³");
    if (sqlTableModel -> lastError().type() != QSqlError::NoError)
        DBError (sqlTableModel -> lastError());
    else
        tableView -> setModel (sqlTableModel);
    tableView -> setSelectionMode (QAbstractItemView::SingleSelection);
    tableView -> show ();
    
    // po³¹czenia sygna³-gniazdo
    connect (sqlTableModel,SIGNAL(dataChanged (QModelIndex,QModelIndex)),this,SLOT(DataChanged(QModelIndex,QModelIndex)));  
    connect (pushButtonNewAuthor,SIGNAL (clicked()),this,SLOT (NewAuthor()));
    connect (pushButtonNewBook,SIGNAL (clicked()),this,SLOT (NewBook()));
    connect (pushButtonDeleteBook,SIGNAL (clicked()),this,SLOT (DeleteBook()));
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

        // zmiana wybranego wiersza - czyli imienia autora ksi¹¿ki w bazie
        query.exec ("UPDATE AUTORZY SET IMIE = '" + topLeft.data ().toString () + "' WHERE ID_AUTORA = " + query.value (0).toString ());

        // ponowne wykonanie zapytania
        static_cast <QSqlQueryModel*> (sqlTableModel) -> setQuery ("SELECT IMIE, NAZWISKO, TYTUL FROM AUTORZY, KSIAZKI WHERE KSIAZKI.ID_AUTORA = AUTORZY.ID_AUTORA",db);

        // testy b³êdów
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

        // zmiana wybranego wiersza - czyli nazwiska autora ksi¹¿ki w bazie
        query.exec ("UPDATE AUTORZY SET NAZWISKO = '" + topLeft.data ().toString () + "' WHERE ID_AUTORA = " + query.value (0).toString ());
        
        // ponowne wykonanie zapytania
        static_cast <QSqlQueryModel*> (sqlTableModel) -> setQuery ("SELECT IMIE, NAZWISKO, TYTUL FROM AUTORZY, KSIAZKI WHERE KSIAZKI.ID_AUTORA = AUTORZY.ID_AUTORA",db);

        // testy b³êdów
        if (sqlTableModel -> lastError().type() != QSqlError::NoError)
            DBError (sqlTableModel -> lastError());
        if (query.lastError().type() != QSqlError::NoError)
            DBError (query.lastError());
        if (db.lastError().type() != QSqlError::NoError)
            DBError (db.lastError ());
    }

    // aktualizacja tytu³u ksi¹¿ki
    if (topLeft.column () == 2)
    {
        // wyszukanie numeru ID_KSIAZKI modyfikowanego wiersza
        QSqlQuery query (db);
        query.exec ("SELECT ID_KSIAZKI, IMIE, NAZWISKO, TYTUL FROM AUTORZY, KSIAZKI WHERE KSIAZKI.ID_AUTORA = AUTORZY.ID_AUTORA");
        query.seek (topLeft.row ());
        
        // zmiana wybranego wiersza - czyli tytu³u ksi¹¿ki w bazie
        query.exec ("UPDATE KSIAZKI SET TYTUL = '" + topLeft.data ().toString () + "' WHERE ID_KSIAZKI = " + query.value (0).toString ());

        // testy b³êdów
        if (sqlTableModel -> lastError().type() != QSqlError::NoError)
            DBError (sqlTableModel -> lastError());
        if (query.lastError().type() != QSqlError::NoError)
            DBError (query.lastError());
        if (db.lastError().type() != QSqlError::NoError)
            DBError (db.lastError ());
    }
}

// dodanie nowego autora

void MyWindow::NewAuthor ()
{
    // utworzenie okna dialogowego
    QDialog dialog;
    Ui::DialogNewAuthor newAuthor;
    newAuthor.setupUi (&dialog);
    
    // wyœwietlenie okna dialogowego
    if (dialog.exec () == QDialog::Accepted)
    {
        // ustalenie numeru identyfikatora nowego rekordu
        // (wyszukujemy maksimum i zwiêkszamy je o 1)
        QSqlQuery query (db);
        query.exec ("SELECT ID_AUTORA FROM AUTORZY");
        int ID_AUTORA = 0;
        while (query.next()) 
        {
            if (query.value (0).toInt () > ID_AUTORA)
                ID_AUTORA = query.value (0).toInt ();
        }        
        ID_AUTORA++;
       
        // dodanie nowego autora
        query.exec ("INSERT INTO AUTORZY VALUES (" + QString::number (ID_AUTORA) + ",'" + newAuthor.lineEditIMIE -> text () + "','" + newAuthor.lineEditNAZWISKO -> text () + "')");

        // testy b³êdów
        if (query.lastError().type() != QSqlError::NoError)
            DBError (query.lastError());
        if (db.lastError().type() != QSqlError::NoError)
            DBError (db.lastError ());
    }
}

// dodanie nowej ksi¹¿ki

void MyWindow::NewBook ()
{
    // utworzenie okna dialogowego
    QDialog dialog;
    Ui::DialogNewBook newBook;
    newBook.setupUi (&dialog);

    // utworzenie listy autorów
    QSqlQueryModel sqlQueryModel (this);
    sqlQueryModel.setQuery ("SELECT * FROM AUTORZY",db);
    sqlQueryModel.setHeaderData (1,Qt::Horizontal,"Imiê");
    sqlQueryModel.setHeaderData (2,Qt::Horizontal,"Nazwisko");
    newBook.treeView -> setModel (&sqlQueryModel);
    newBook.treeView -> setColumnHidden (0,true);
    
    // wyœwietlenie okna dialogowego
    if (dialog.exec () == QDialog::Accepted)
    {
        // sprawdzenie, czy wybrano autora ksi¹¿ki
        QModelIndex modelIndex = newBook.treeView -> currentIndex ();
        if (modelIndex.row () >= 0)
        {
            // ustalenie numeru identyfikatora nowego rekordu
            // (wyszukujemy maksimum i zwiêkszamy je o 1)
            QSqlQuery query (db);
            query.exec ("SELECT ID_KSIAZKI FROM KSIAZKI");
            int ID_KSIAZKI = 0;
            while (query.next()) 
            {
                if (query.value (0).toInt () > ID_KSIAZKI)
                    ID_KSIAZKI = query.value (0).toInt ();
            }
            ID_KSIAZKI++;
                              
            // ustalenie numeru ID_AUTORA wybranego autora ksi¹¿ki
            query.exec ("SELECT ID_AUTORA FROM AUTORZY");
            query.seek (modelIndex.row ());
            QString ID_AUTORA = query.value(0).toString ();
        
            // wstawienie rekordu z now¹ ksi¹¿k¹
            query.exec ("INSERT INTO KSIAZKI VALUES (" + QString::number (ID_KSIAZKI) + "," + ID_AUTORA + ",'" + newBook.lineEditTYTUL -> text () + "')");

            // ponowne wykonanie zapytania
            static_cast <QSqlQueryModel*> (sqlTableModel) -> setQuery ("SELECT IMIE, NAZWISKO, TYTUL FROM AUTORZY, KSIAZKI WHERE KSIAZKI.ID_AUTORA = AUTORZY.ID_AUTORA",db);

            // testy b³êdów
            if (query.lastError().type() != QSqlError::NoError)
                DBError (query.lastError());
            if (db.lastError().type() != QSqlError::NoError)
                DBError (db.lastError ());
        }  
    }
}

// usuniêcie bie¿¹cej ksi¹¿ki

void MyWindow::DeleteBook ()
{
    // ustalenie numeru usuwanego (bie¿¹cego) wiersza
    QModelIndex modelIndex = tableView -> currentIndex ();
    
    // na wszelki wypadek prosimy u¿ytkownika o potwierdzenie usuniêcia danych
    if (modelIndex.row () >= 0 && QMessageBox::question (this,"Usuwanie ksi¹¿ki","Czy chcesz usun¹æ bie¿¹c¹ ksi¹¿kê?",QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    { 
        // ustalenie numeru identyfikatora usuwanego rekordu
        QSqlQuery query (db);
        query.exec ("SELECT ID_KSIAZKI, IMIE, NAZWISKO, TYTUL FROM AUTORZY, KSIAZKI WHERE KSIAZKI.ID_AUTORA = AUTORZY.ID_AUTORA");
        query.seek (modelIndex.row ());
        QString ID_KSIAZKI = query.value (0).toString ();
            
        // usuniêcie rekordu
        query.exec ("DELETE FROM KSIAZKI WHERE ID_KSIAZKI = " + ID_KSIAZKI);

        // ponowne wykonanie zapytania
        static_cast <QSqlQueryModel*> (sqlTableModel) -> setQuery ("SELECT IMIE, NAZWISKO, TYTUL FROM AUTORZY, KSIAZKI WHERE KSIAZKI.ID_AUTORA = AUTORZY.ID_AUTORA",db);

        // testy b³êdów
        if (query.lastError().type() != QSqlError::NoError)
            DBError (query.lastError());
        if (db.lastError().type() != QSqlError::NoError)
            DBError (db.lastError ());
    }
}

// obs³uga b³êdu bazy danych

void MyWindow::DBError (QSqlError error)
{
    QMessageBox::critical (this,"B³¹d",error.driverText () + "\n" + error.databaseText ());
}
