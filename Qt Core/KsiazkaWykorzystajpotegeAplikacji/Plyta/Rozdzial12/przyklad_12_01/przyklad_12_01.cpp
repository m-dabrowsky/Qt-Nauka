#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    QPushButton button ("Hello world!");
    button.resize (100, 30);
    button.show();
    return app.exec();
}

