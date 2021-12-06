#include "mywindow.h"

MyWindow::MyWindow ():
    QMainWindow (0,Qt::Window)
{
    // utworzenie interfejsu okna
    setupUi (this);

    // sygna³y i gniazda
    connect (fileMenuOpen,SIGNAL (triggered()),this,SLOT (Open()));
    connect (fileMenuQuit,SIGNAL (triggered()),qApp,SLOT (quit()));
}

// odczyt pliku

void MyWindow::Open ()
{
    QString filter ("pliki SVG (*.svg);;wszystkie pliki (*.*)");
    QString file = QFileDialog::getOpenFileName (this,"Otwieranie",".",filter);
    if (!file.isEmpty ())
    {
        SVGwidget -> load (file);
    }
}

