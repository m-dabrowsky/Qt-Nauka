#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication EditorApp(argc, argv); // zarządza zasobami aplikacji i jest niezbędne do uruchomienia programu
    MainWindow Editor;                  // Utworzony obiekt Editor klasy stworzonego UI (MainWindow)
    Editor.show();                      // pokazuje UI w nowym oknie
    return EditorApp.exec();            // QApplication wchodzi w swoją pętle zdarzeń. Gdy aplikacja jest uruchomiona, zdarzenai są generowane o wysyłane do
                                        // widgetów aplikacji (naciśnięcie myszky, klawiszy itd.)
}
