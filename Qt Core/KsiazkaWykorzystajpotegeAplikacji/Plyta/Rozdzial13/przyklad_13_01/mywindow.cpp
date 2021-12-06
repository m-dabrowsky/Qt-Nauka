#include "mywindow.h"

MyWindow::MyWindow (): 
    QMainWindow (0,Qt::Window)
{
    fileName = "dokument1.txt";
    setGeometry (300,300,600,400);
    setWindowTitle ("Edytor - czêœæ 1 - " + fileName);
    textEdit = new QTextEdit;
    setCentralWidget (textEdit);
}

MyWindow::~MyWindow ()
{
}
