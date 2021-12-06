#include <QtGui>        
#include "ui_window.h"

class MyWindow: public QMainWindow, private Ui::Window
{
public:
    MyWindow ();
    ~MyWindow () {}
};        

MyWindow::MyWindow ():
    QMainWindow (0,Qt::Window)
{
    setupUi (this);
    connect (button,SIGNAL (clicked()),qApp,SLOT (quit()));
}

int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("Windows-1250"));
    MyWindow window;
    window.show ();
    return app.exec();
}

