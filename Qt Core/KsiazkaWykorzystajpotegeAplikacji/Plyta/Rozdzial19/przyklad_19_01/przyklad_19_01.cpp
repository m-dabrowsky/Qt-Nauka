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

    // zamkni�cie bazy
    db.close ();
}

