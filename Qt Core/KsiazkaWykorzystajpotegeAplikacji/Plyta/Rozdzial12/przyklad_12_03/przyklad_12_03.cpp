#include <QApplication>
#include <QPushButton>
#include <QTextCodec>
#include <QMainWindow>
        
int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("Windows-1250"));
    QMainWindow window;
    window.setGeometry (400,300,300,200);
    window.setWindowTitle ("Przyk³ad 3");
    QPushButton button ("Wyjœcie",&window);
    button.setGeometry (100,120,100,40);
    QObject::connect (&button,SIGNAL (clicked()),&app,SLOT (quit()));
    window.show ();
    return app.exec();
}

