#include "paintarea.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PaintArea w;
    w.show();
    return a.exec();
}
