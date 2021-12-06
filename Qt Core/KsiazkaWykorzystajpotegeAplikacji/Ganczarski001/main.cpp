#include "mainwindow.h"
#include "mywindow.h"

#include <QApplication>
#include <QPushButton>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyWindow window;
    window.show();

    return a.exec();            // rozpoczęcie działania programu gdzie obiekt a, przechodziw stan nieskończonej pętli
                                // obłusgi zdarzeń pochodzących zarówno z systemu jak i od użytkownika
}
