#include "mywindow.h"

MyWindow::MyWindow ():
    QMainWindow (0,Qt::Window)
{
    resize (300,200);
    setWindowTitle ("Menu wielopoziomowe");
    
    // menu 1
    menu1 = menuBar() -> addMenu ("Menu1");
    
    // menu 11
    action11 = new QAction ("Menu11",this);
    menu1 -> addAction (action11);

    // menu 12
    menu12 = new QMenu ("Menu12",menu1);
    menu1 -> addAction (menu12 -> menuAction());

    // menu 121
    action121 = new QAction ("Menu121",this);
    menu12 -> addAction (action121);
    
    // menu 122
    action122 = new QAction ("Menu122",this);
    menu12 -> addAction (action122);
    
    // menu 13
    action13 = new QAction ("Menu13",this);
    menu1 -> addAction (action13);
}
