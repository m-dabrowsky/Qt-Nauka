#include "mywindow.h"

MyWindow::MyWindow (): 
    QMainWindow (0,Qt::Window)
{
    // domyœlna nazwa pliku
    fileName = "dokument1.txt";
    
    // okno
    setGeometry (300,300,600,400);
    setWindowTitle ("Edytor - czêœæ 5 - " + fileName);
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

    // menu Plik/Otwórz
    fileMenuOpen = new QAction (QIcon (":/images/open.png"),"Otwórz",this);
    fileMenuOpen -> setShortcut (Qt::Key_O | Qt::ControlModifier);
    fileMenuOpen -> setStatusTip ("Odczytuje plik");
    fileMenu -> addAction (fileMenuOpen);

    // menu Plik/Zapisz
    fileMenuSave = new QAction ("Zapisz",this);
    fileMenuSave -> setIcon (QIcon (":/images/save.png"));
    fileMenuSave -> setShortcut (QKeySequence::Save);
    fileMenuSave -> setStatusTip ("Zapisuje bie¿¹ce zmiany");
    fileMenu -> addAction (fileMenuSave);

    // menu Plik/Zapisz jako
    fileMenuSaveAs = new QAction ("Zapisz jako",this);
    fileMenuSaveAs -> setStatusTip ("Zapisuje jako nowy plik");
    fileMenu -> addAction (fileMenuSaveAs);
    fileMenu -> addSeparator ();  // separator

    // menu Plik/Wyjœcie
    fileMenuQuit = new QAction ("Wyjœcie",this);
    fileMenuQuit -> setStatusTip ("Zakoñczenie dzia³ania programu");
    fileMenuQuit -> setShortcut (Qt::Key_F4 | Qt::AltModifier);
    fileMenu -> addAction (fileMenuQuit);
    
    // pasek statusu
    statusBar() -> showMessage ("Gotowy");
    
    // pasek narzêdzi
    fileToolBar = new QToolBar (this);
    fileToolBar -> addAction (fileMenuNew);
    fileToolBar -> addAction (fileMenuOpen);
    fileToolBar -> addAction (fileMenuSave);
    addToolBar (fileToolBar);
    
    // sygna³y i gniazda
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
             setWindowTitle ("Edytor - czêœæ 5 - " + fileName);
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

// zapis pliku pod now¹ nazw¹

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
            setWindowTitle ("Edytor - czêœæ 5 - " + fileName);
            statusBar() -> showMessage ("Plik zapisany",2000);
        }
    }
}
