#include "mywindow.h"

MyWindow::MyWindow (): 
    QMainWindow (0,Qt::Window)
{
    // domy�lna nazwa pliku
    fileName = "dokument1.txt";
    
    // okno
    setGeometry (300,300,600,400);
    setWindowTitle ("Edytor - cz�� 2 - " + fileName);
    setWindowIcon (QIcon (":/images/qt.png"));
    
    // edytor
    textEdit = new QTextEdit;
    setCentralWidget (textEdit);
}

MyWindow::~MyWindow ()
{
}
