#include <QtGui>        
#include "mywindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(mywindow);
    QApplication app (argc, argv);
    QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("Windows-1250"));
    MyWindow window;
    window.show ();
    return app.exec();
}

