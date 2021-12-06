#include "mywindow.h"

MyWindow::MyWindow ():
    QMainWindow (0,Qt::Window)
{
    // utworzenie interfejsu okna
    setupUi (this);

    // grupowanie menu antyaliasingu
    QActionGroup *actionGroup = new QActionGroup (this);
    actionGroup -> addAction (aaMenuOn);
    actionGroup -> addAction (aaMenuOff);

    // sygna³y i gniazda
    connect (fileMenuOpen,SIGNAL (triggered()),this,SLOT (Open()));
    connect (aaMenuOn,SIGNAL(toggled(bool)),SVGwidget,SLOT(setAntialiased(bool)));
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

