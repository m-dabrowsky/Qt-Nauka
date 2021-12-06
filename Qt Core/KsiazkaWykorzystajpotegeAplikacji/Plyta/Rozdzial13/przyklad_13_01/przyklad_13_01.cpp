#include <QtGui>        
#include "mywindow.h"

int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("Windows-1250"));
    MyWindow window;
    window.show ();
    return app.exec();
}

