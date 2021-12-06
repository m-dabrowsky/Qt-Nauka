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

    // zamkniêcie bazy
    db.close ();
}

