#include "mywindow.h"

MyWindow::MyWindow ():
    QMainWindow (0,Qt::Window)
{
    resize (300,200);
    setWindowTitle ("Menu podrêczne");
    
    // menu 1
    menu1 = menuBar() -> addMenu ("Menu1");
    
    // menu 11
    action11 = new QAction ("Menu11",this);
    menu1 -> addAction (action11);

    // separator
    menu1 -> addSeparator ();

    // grupowanie menu12 - menu14
    actionGroup = new QActionGroup (this);

    // menu 12
    action12 = new QAction ("Menu12",actionGroup);
    action12 -> setCheckable (true);
    action12 -> setChecked (true);
    menu1 -> addAction (action12);

    // menu 13
    action13 = new QAction ("Menu13",actionGroup);
    action13 -> setCheckable (true);
    menu1 -> addAction (action13);
    
    // menu 14
    action14 = new QAction ("Menu14",actionGroup);
    action14 -> setCheckable(true);
    menu1 -> addAction (action14);

    // separator
    menu1 -> addSeparator ();

    // menu 15
    action15 = new QAction ("Menu15",this);
    menu1 -> addAction (action15);
}

// wywo³ywanie menu podrêcznego

void MyWindow::contextMenuEvent (QContextMenuEvent *event)
{
    //menu1 -> popup (event -> globalPos ());
    menu1 -> exec (event -> globalPos ());
}
