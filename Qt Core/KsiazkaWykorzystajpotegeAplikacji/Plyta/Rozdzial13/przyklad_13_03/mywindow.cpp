#include "mywindow.h"

MyWindow::MyWindow (): 
    QMainWindow (0,Qt::Window)
{
    // domy�lna nazwa pliku
    fileName = "dokument1.txt";
    
    // okno
    setGeometry (300,300,600,400);
    setWindowTitle ("Edytor - cz�� 3 - " + fileName);
    setWindowIcon (QIcon (":/images/qt.png"));
    
    // edytor
    textEdit = new QTextEdit;
    setCentralWidget (textEdit);
    
    // menu Plik
    fileMenu = menuBar() -> addMenu ("&Plik");
    
    // menu Plik/Nowy
    fileMenuNew = new QAction (QIcon (":/images/new.png"),"&Nowy",this);
    fileMenuNew -> setShortcut (QString ("Ctrl+N"));
    fileMenuNew -> setStatusTip ("Tworzy nowy plik");
    fileMenu -> addAction (fileMenuNew);

    // menu Plik/Otw�rz
    fileMenuOpen = new QAction (QIcon (":/images/open.png"),"Otw�rz",this);
    fileMenuOpen -> setShortcut (Qt::Key_O | Qt::ControlModifier);
    fileMenuOpen -> setStatusTip ("Odczytuje plik");
    fileMenu -> addAction (fileMenuOpen);

    // menu Plik/Zapisz
    fileMenuSave = new QAction ("Zapisz",this);
    fileMenuSave -> setIcon (QIcon (":/images/save.png"));
    fileMenuSave -> setShortcut (QKeySequence::Save);
    fileMenuSave -> setStatusTip ("Zapisuje bie��ce zmiany");
    fileMenu -> addAction (fileMenuSave);

    // menu Plik/Zapisz jako
    fileMenuSaveAs = new QAction ("Zapisz jako",this);
    fileMenuSaveAs -> setStatusTip ("Zapisuje jako nowy plik");
    fileMenu -> addAction (fileMenuSaveAs);
    fileMenu -> addSeparator ();  // separator

    // menu Plik/Wyj�cie
    fileMenuQuit = new QAction ("Wyj�cie",this);
    fileMenuQuit -> setStatusTip ("Zako�czenie dzia�ania programu");
    fileMenuQuit -> setShortcut (Qt::Key_F4 | Qt::AltModifier);
    fileMenu -> addAction (fileMenuQuit);
}

MyWindow::~MyWindow ()
{
}
