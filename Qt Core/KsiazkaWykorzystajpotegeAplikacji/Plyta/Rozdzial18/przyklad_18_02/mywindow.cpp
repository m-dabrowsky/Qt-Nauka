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

    // grupa menu stylu linii
    QActionGroup *penMenuStyleGroup = new QActionGroup (this);
    penMenuStyleGroup -> addAction (actionQt_SolidLine);
    penMenuStyleGroup -> addAction (actionQt_DashLine);
    penMenuStyleGroup -> addAction (actionQt_DotLine);
    penMenuStyleGroup -> addAction (actionQt_DashDotLine);
    penMenuStyleGroup -> addAction (actionQt_DashDotDotLine);

    // grupa menu sposobu zako�czenia linii
    QActionGroup *penMenuCapStyleGroup = new QActionGroup (this);
    penMenuCapStyleGroup -> addAction (actionQt_SquareCap);
    penMenuCapStyleGroup -> addAction (actionQt_FlatCap);
    penMenuCapStyleGroup -> addAction (actionQt_RoundCap);

    // grupa menu sposobu po��czenia linii
    QActionGroup *penMenuJoinStyleGroup = new QActionGroup (this);
    penMenuJoinStyleGroup -> addAction (actionQt_BevelJoin);
    penMenuJoinStyleGroup -> addAction (actionQt_MiterJoin);
    penMenuJoinStyleGroup -> addAction (actionQt_RoundJoin);

    // sygna�y i gniazda
    connect (fileMenuNew,SIGNAL (triggered()),this,SLOT (New()));
    connect (fileMenuOpen,SIGNAL (triggered()),this,SLOT (Open()));
    connect (fileMenuSave,SIGNAL (triggered()),this,SLOT (Save()));
    connect (fileMenuSaveAs,SIGNAL (triggered()),this,SLOT (SaveAs()));
    connect (fileMenuQuit,SIGNAL (triggered()),qApp,SLOT (quit()));
    connect (penMenuWidth,SIGNAL (triggered()),this,SLOT (PenWidth()));
    connect (penMenuColor,SIGNAL (triggered()),this,SLOT (PenColor()));
    connect (penMenuStyleGroup,SIGNAL (triggered(QAction *)),this,SLOT(PenStyle(QAction *)));
    connect (penMenuCapStyleGroup,SIGNAL (triggered(QAction *)),this,SLOT(PenCapStyle(QAction *)));
    connect (penMenuJoinStyleGroup,SIGNAL (triggered(QAction *)),this,SLOT(PenJoinStyle(QAction *)));
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

// zmiana grubo�ci pi�ra

void MyWindow::PenWidth ()
{
     QPen pen = paint -> getPen ();
     bool ok;
     int width = QInputDialog::getInteger (this,"Grubo�� pi�ra","Podaj warto��:",pen.width (),0,100,1,&ok);
     if (ok)
     {
         pen.setWidth (width);
         paint -> setPen (pen);
     }
}

// zmiana koloru pi�ra

void MyWindow::PenColor ()
{
     QPen pen = paint -> getPen ();
     QColor color = QColorDialog::getColor (pen.color (),this);
     if (color.isValid ())
     {
         pen.setColor (color);
         paint -> setPen (pen);
     }
}

// okre�lenie stylu linii

void MyWindow::PenStyle (QAction *action)
{
    QPen pen = paint -> getPen ();
    if (action == actionQt_SolidLine)
        pen.setStyle (Qt::SolidLine);
    if (action == actionQt_DashLine)
        pen.setStyle (Qt::DashLine);
    if (action == actionQt_DotLine)
        pen.setStyle (Qt::DotLine);
    if (action == actionQt_DashDotLine)
        pen.setStyle (Qt::DashDotLine);
    if (action == actionQt_DashDotDotLine)
        pen.setStyle (Qt::DashDotDotLine);
    paint -> setPen (pen);
}

// spos�b zako�czenia linii

void MyWindow::PenCapStyle (QAction *action)
{
    QPen pen = paint -> getPen (); 
    if (action == actionQt_SquareCap)
        pen.setCapStyle (Qt::SquareCap);
    if (action == actionQt_FlatCap)
        pen.setCapStyle (Qt::FlatCap);
    if (action == actionQt_RoundCap)
        pen.setCapStyle (Qt::RoundCap);
    paint -> setPen (pen);
}

// spos�b po��czenia linii

void MyWindow::PenJoinStyle (QAction *action)
{
    QPen pen = paint -> getPen ();
    if (action == actionQt_BevelJoin)
        pen.setJoinStyle (Qt::BevelJoin);
    if (action == actionQt_MiterJoin)
        pen.setJoinStyle (Qt::MiterJoin);
    if (action == actionQt_RoundJoin)
        pen.setJoinStyle (Qt::RoundJoin);
    paint -> setPen (pen);
}
