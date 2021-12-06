#include <QApplication>
#include <QPushButton>
#include <QTextCodec>
#include <QMainWindow>

class MyWindow: public QMainWindow
{
public:
    MyWindow ();
    ~MyWindow ();
private:
    QPushButton *button;
};        

MyWindow::MyWindow (): QMainWindow ()
{
    setGeometry (400,300,300,200);
    setWindowTitle ("Przyk³ad 4");
    button = new QPushButton ("Wyjœcie",this);
    button -> setGeometry (100,120,100,40);
    connect (button,SIGNAL (clicked()),qApp,SLOT (quit()));
}

MyWindow::~MyWindow ()
{
}
        
int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("Windows-1250"));
    MyWindow window;
    window.show ();
    return app.exec();
}

