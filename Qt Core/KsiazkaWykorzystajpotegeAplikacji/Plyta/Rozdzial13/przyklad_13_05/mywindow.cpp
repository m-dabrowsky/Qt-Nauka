#include "mywindow.h"

MyWindow::MyWindow (): 
    QMainWindow (0,Qt::Window)
{
    // domy�lna nazwa pliku
    fileName = "dokument1.txt";
    
    // okno
    setGeometry (300,300,600,400);
    setWindowTitle ("Edytor - cz�� 5 - " + fileName);
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
    
    // pasek statusu
    statusBar() -> showMessage ("Gotowy");
    
    // pasek narz�dzi
    fileToolBar = new QToolBar (this);
    fileToolBar -> addAction (fileMenuNew);
    fileToolBar -> addAction (fileMenuOpen);
    fileToolBar -> addAction (fileMenuSave);
    addToolBar (fileToolBar);
    
    // sygna�y i gniazda
    connect (fileMenuNew,SIGNAL (triggered()),this,SLOT (New()));
    connect (fileMenuOpen,SIGNAL (triggered()),this,SLOT (Open()));
    connect (fileMenuSave,SIGNAL (triggered()),this,SLOT (Save()));
    connect (fileMenuSaveAs,SIGNAL (triggered()),this,SLOT (SaveAs()));
    connect (fileMenuQuit,SIGNAL (triggered()),qApp,SLOT (quit()));
}

MyWindow::~MyWindow ()
{
}

// nowy plik

void MyWindow::New ()
{
     textEdit -> clear ();
}

// odczyt pliku

void MyWindow::Open ()
{
     QString newFileName = QFileDialog::getOpenFileName (this);
     if (!newFileName.isEmpty ())
     {
         QFile file (newFileName);
         if (file.open (QFile::ReadOnly | QFile::Text))
         {
             QTextStream in (&file);
             textEdit -> setPlainText (in.readAll ());
             fileName = newFileName;
             setWindowTitle ("Edytor - cz�� 5 - " + fileName);
             statusBar() -> showMessage ("Plik odczytany",2000);
         }
     }
}

// zapis pliku

void MyWindow::Save ()
{
    QFile file (fileName);
    if (file.open (QFile::WriteOnly | QFile::Text))
    {
        QTextStream out (&file);
        out << textEdit -> toPlainText ();
        statusBar() -> showMessage ("Plik zapisany",2000);
    }
}

// zapis pliku pod now� nazw�

void MyWindow::SaveAs ()
{
    QString newFileName = QFileDialog::getSaveFileName (this);
    if (!newFileName.isEmpty ())
    {
        QFile file (newFileName);
        if (file.open (QFile::WriteOnly | QFile::Text))
        {
            QTextStream out (&file);
            out << textEdit -> toPlainText ();
            fileName = newFileName;
            setWindowTitle ("Edytor - cz�� 5 - " + fileName);
            statusBar() -> showMessage ("Plik zapisany",2000);
        }
    }
}
