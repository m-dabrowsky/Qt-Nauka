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
    
    // utworzenie po��czenia z baz� danych
    QSqlDatabase db = QSqlDatabase::addDatabase ("QIBASE");
    db.setDatabaseName ("TEST.FDB");
    db.setUserName ("SYSDBA");
    db.setPassword ("masterkey");
    
    // obs�uga b��du po��czenia
    if (!db.open())
    {
        QSqlError error = db.lastError ();
        std::cout << "B��d po��czenia" << std::endl;
        std::cout << error.driverText ().toStdString () << std::endl;
        std::cout << error.databaseText ().toStdString () << std::endl;
        return 0;
    }

    // dodanie danych w tabeli AUTORZY
    QSqlQuery query (db);
    query.exec ("INSERT INTO AUTORZY VALUES (1,'Henryk','Sienkiewicz')");
    query.exec ("INSERT INTO AUTORZY VALUES (2,'Boles�aw','Prus')");
    
    // dodanie danych w tabeli KSIAZKI
    query.exec ("INSERT INTO KSIAZKI VALUES (1,1,'Ogniem i mieczem')");
    query.exec ("INSERT INTO KSIAZKI VALUES (2,1,'Potop')");
    query.exec ("INSERT INTO KSIAZKI VALUES (3,1,'Pan Wo�odyjowski')");
    query.exec ("INSERT INTO KSIAZKI VALUES (4,1,'Quo vadis')");
    query.exec ("INSERT INTO KSIAZKI VALUES (5,1,'Krzy�acy')");
    query.exec ("INSERT INTO KSIAZKI VALUES (6,1,'W pustyni i w puszczy')");
    query.exec ("INSERT INTO KSIAZKI VALUES (7,2,'Plac�wka')");
    query.exec ("INSERT INTO KSIAZKI VALUES (8,2,'Lalka')");
    query.exec ("INSERT INTO KSIAZKI VALUES (9,2,'Faraon')");
    
    // zamkni�cie bazy
    db.close ();
}

