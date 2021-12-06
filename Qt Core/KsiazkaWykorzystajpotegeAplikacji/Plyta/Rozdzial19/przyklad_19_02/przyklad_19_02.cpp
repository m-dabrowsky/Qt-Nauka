#include <QtGui>
#include <QtSql>
#include <iostream>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(translations);
    QCoreApplication app (argc, argv);
    QTranslator qtTranslator;
    qtTranslator.load (":/translations/qt_pl.qm");
    app.installTranslator (&qtTranslator);
    QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("Windows-1250"));
    
    // utworzenie po³¹czenia z baz¹ danych
    QSqlDatabase db = QSqlDatabase::addDatabase ("QIBASE");
    db.setDatabaseName ("TEST.FDB");
    db.setUserName ("SYSDBA");
    db.setPassword ("masterkey");
    
    // obs³uga b³êdu po³¹czenia
    if (!db.open())
    {
        QSqlError error = db.lastError ();
        std::cout << "B³¹d po³¹czenia" << std::endl;
        std::cout << error.driverText ().toStdString () << std::endl;
        std::cout << error.databaseText ().toStdString () << std::endl;
        return 0;
    }

    // utworzenie tabeli AUTORZY
    QSqlQuery query (db);
    if (!query.exec ("CREATE TABLE AUTORZY (ID_AUTORA INTEGER PRIMARY KEY, IMIE VARCHAR(20) NOT NULL CHARACTER SET WIN1250 COLLATE PXW_PLK, NAZWISKO VARCHAR(30) NOT NULL CHARACTER SET WIN1250 COLLATE PXW_PLK)"))
    {
        QSqlError error = query.lastError ();
        std::cout << "B³¹d tworzenia tabeli AUTORZY" << std::endl;
        std::cout << error.driverText ().toStdString () << std::endl;
        std::cout << error.databaseText ().toStdString () << std::endl;
    }
        
    // utworzenie tabeli KSIAZKI
    if (!query.exec ("CREATE TABLE KSIAZKI (ID_KSIAZKI INTEGER PRIMARY KEY, ID_AUTORA INTEGER, TYTUL VARCHAR(100) NOT NULL CHARACTER SET WIN1250 COLLATE PXW_PLK)"))
    {
        QSqlError error = query.lastError ();
        std::cout << "B³¹d tworzenia tabeli KSIAZKI" << std::endl;
        std::cout << error.driverText ().toStdString () << std::endl;
        std::cout << error.databaseText ().toStdString () << std::endl;
    }
    
    // zamkniêcie bazy
    db.close ();
}

