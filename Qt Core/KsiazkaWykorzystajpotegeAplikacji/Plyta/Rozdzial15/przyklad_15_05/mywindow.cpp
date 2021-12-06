#include "mywindow.h"

MyWindow::MyWindow ():
    QMainWindow (0,Qt::Window)
{
    resize (300,200);
    setWindowTitle ("W³aœciwoœci elementów menu");
    
    // menu 1
    menu1 = menuBar() -> addMenu ("Menu1");
    
    // menu 11
    action11 = new QAction ("Menu11",this);
    action11 -> setCheckable (true);
    action11 -> setChecked (false);
    menu1 -> addAction (action11);

    // menu 12
    action12 = new QAction ("Menu12",this);
    action12 -> setDisabled (true);
    menu1 -> addAction (action12);
    
    // menu 13
    action13 = new QAction ("Menu13",this);
    action13 -> setVisible (false);
    menu1 -> addAction (action13);
    
    // po³¹czenia sygna³-gniazdo
    QObject::connect (action11,SIGNAL(toggled(bool)),action13,SLOT(setVisible(bool)));
    QObject::connect (action13,SIGNAL(triggered()),action11,SLOT(toggle()));
}
