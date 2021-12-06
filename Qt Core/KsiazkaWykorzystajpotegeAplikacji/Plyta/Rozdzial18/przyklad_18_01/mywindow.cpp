#include "mywindow.h"

MyWindow::MyWindow ():
    QMainWindow (0,Qt::Window)
{
    // utworzenie interfejsu okna
    setupUi (this);
    
    // konfiguracja okna wewn�trznego
    scrollArea -> setBackgroundRole (QPalette::Dark);
    scrollArea -> setWidget (paint);

    // domy�lna nazwa pliku
    fileName = "obraz1.png";

    // tytu� okna
    setWindowTitle ("Rysownik Qt - " + fileName);

    // pasek statusu
    Ui::Window::statusBar -> showMessage ("Gotowy");

    // sygna�y i gniazda
    connect (fileMenuNew,SIGNAL (triggered()),this,SLOT (New()));
    connect (fileMenuOpen,SIGNAL (triggered()),this,SLOT (Open()));
    connect (fileMenuSave,SIGNAL (triggered()),this,SLOT (Save()));
    connect (fileMenuSaveAs,SIGNAL (triggered()),this,SLOT (SaveAs()));
    connect (fileMenuQuit,SIGNAL (triggered()),qApp,SLOT (quit()));
}

// nowy plik

void MyWindow::New ()
{
    paint -> clearImage ();
    Ui::Window::statusBar -> showMessage ("Obraz wyczyszczony",2000);
}

// odczyt pliku

void MyWindow::Open ()
{
    // wyb�r pliku
    QString filter ("Windows Bitmap (*.bmp);;Joint Photographic Experts Group (*.jpg *.jpeg);;Portable Network Graphics (*.png);;Portable Pixmap (*.ppm);;Tagged Image File Format (*.tif *.tiff);;X11 Bitmap (*.xbm);;X11 Pixmap (*.xpm);;wszystkie pliki (*.*)");
    QString fileName = QFileDialog::getOpenFileName (this,"Otwieranie",".",filter);
    
    // odczyt pliku
    if (!fileName.isEmpty())
    {
        paint -> openImage (fileName);
        setWindowTitle ("Rysownik Qt - " + fileName);
        Ui::Window::statusBar -> showMessage ("Plik odczytany",2000);
    }
}

// zapis pliku

void MyWindow::Save ()
{
     QFileInfo file (fileName);
     QString ext = file.suffix();
     paint -> saveImage (fileName,ext.toStdString().c_str());
     Ui::Window::statusBar -> showMessage ("Plik zapisany",2000);
}

// zapis pliku pod now� nazw�

void MyWindow::SaveAs ()
{
    // wyb�r nazwy pliku 
    QString filter ("Windows Bitmap (*.bmp);;Joint Photographic Experts Group (*.jpg *.jpeg);;Portable Network Graphics (*.png);;Portable Pixmap (*.ppm);;Tagged Image File Format (*.tif *.tiff);;X11 Bitmap (*.xbm);;X11 Pixmap (*.xpm);;wszystkie pliki (*.*)");
    QString newFileName = QFileDialog::getSaveFileName (this,"Zapisywanie jako",".",filter);
    
    // zapis pliku i zapami�tanie nowej nazwy
    if (!newFileName.isEmpty ())
    {
        QFileInfo file (fileName);
        QString ext = file.suffix();
        paint -> saveImage (fileName,ext.toStdString().c_str());
        fileName = newFileName;
        setWindowTitle ("Rysownik Qt - " + fileName);
        Ui::Window::statusBar -> showMessage ("Plik zapisany",2000);
    }
}

