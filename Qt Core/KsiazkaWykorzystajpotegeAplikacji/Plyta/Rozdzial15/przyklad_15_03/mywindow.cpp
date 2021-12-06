#include "mywindow.h"

MyWindow::MyWindow ():
    QMainWindow (0,Qt::Window)
{
    resize (300,200);
    setWindowTitle ("Ró¿ne czcionki w menu");
    
    // menu 1
    menu1 = menuBar() -> addMenu ("Menu1");
    
    // menu 11
    action11 = new QAction ("Czcionka domyœlna",this);
    menu1 -> addAction (action11);

    // menu 12
    action12 = new QAction ("Helvetica Bold 12",this);
    action12 -> setFont (QFont ("Helvetica",12,QFont::Bold));
    menu1 -> addAction (action12);

    // menu 13
    action13 = new QAction ("Courier 6",this);
    action13 -> setFont (QFont ("Courier",6));
    menu1 -> addAction (action13);
    
    // menu 14
    action14 = new QAction ("Times Italic 18",this);
    QFont font ("Times",18);
    font.setItalic (true);
    action14 -> setFont (font);
    menu1 -> addAction (action14);

    // menu 15
    action15 = new QAction ("Arial Underline 14",this);
    font.setFamily ("Arial");
    font.setUnderline (true);
    font.setItalic (false);
    font.setPointSize (14);
    action15 -> setFont (font);
    menu1 -> addAction (action15);
    
    // menu 16
    action16 = new QAction ("Tahoma StrikeOut 10",this);
    font.setFamily ("Tahoma");
    font.setUnderline (false);
    font.setStrikeOut (true);
    font.setPointSize (10);
    action16 -> setFont (font);
    menu1 -> addAction (action16);
}
