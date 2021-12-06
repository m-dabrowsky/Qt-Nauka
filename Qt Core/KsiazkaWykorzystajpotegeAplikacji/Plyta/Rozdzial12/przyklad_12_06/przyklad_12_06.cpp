#include <QtGui>        
#include "ui_window.h"

class MyWindow: public QMainWindow
{
public:
    MyWindow ();
    ~MyWindow () {}
private:
    Ui::Window window;
};        

MyWindow::MyWindow ():
    QMainWindow (0,Qt::Window)
{
    window.setupUi (this);
    connect (window.button,SIGNAL (clicked()),qApp,SLOT (quit()));
}

int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("Windows-1250"));
    MyWindow window;
    window.show ();
    return app.exec();
}

