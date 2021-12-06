#include <QApplication>
#include <QDir>
#include <QStringList>
#include <QString>
#include <QTextStream>
#include <QFileInfo>
#include <QDateTime>
#include <iostream>

bool q_object( QString fichier );

int main(int argc, char *argv[])
{
    QDir dir;
    dir.setFilter(QDir::Files);
    QStringList liste = dir.entryList();
    for (int i = 0; i < liste.count(); ++i) {
        if( liste.at(i).right(2) == ".h" && q_object( liste.at(i) ) )
        {
            QString fichierMOC = "moc_"+liste.at(i).section(".",0,0)+".cpp";
            if( QFileInfo(liste.at(i)).lastModified() > QFileInfo(fichierMOC).lastModified() )
            {
                system(QString( "moc.exe " + liste.at(i) + " -o " + fichierMOC ).toLatin1() );
            }
        }
        if( liste.at(i).right(3) == ".ui" )
        {
            QString fichierUI = "ui_"+liste.at(i).section(".",0,0)+".h";
            if( QFileInfo(liste.at(i)).lastModified() > QFileInfo(fichierUI).lastModified() )
            {
                system(QString( "uic.exe " + liste.at(i) + " -o " + fichierUI ).toLatin1() );
            }
        }
        if( liste.at(i).right(4) == ".qrc" )
        {
            QString fichierRCC = "rcc_"+liste.at(i).section(".",0,0)+".cpp";
            if( QFileInfo(liste.at(i)).lastModified() > QFileInfo(fichierRCC).lastModified() )
            {
                system(QString( "rcc.exe -name " + liste.at(i).section(".",0,0) + " " + liste.at(i) + " -o " + fichierRCC).toLatin1() );
            }
        }
    }
    exit(0);
}

bool q_object( QString fichier )
{
     // Retourne true si le fichier contient la macro Q_OBJECT
     // Autrement retourne false
     QFile file( fichier );
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
     QTextStream in(&file);
     while (!in.atEnd()) {
		QString line = in.readLine();
           if ( line.contains("Q_OBJECT") )
        {
			file.close();
            return true;
        }
     }
     file.close();
     return false;
}
