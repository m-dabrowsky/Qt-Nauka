#include <QApplication>
#include <QPushButton>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    QTextCodec::setCodecForCStrings (QTextCodec::codecForName ("Windows-1250"));
    QPushButton button ("Witaj Œwiecie!");
    button.resize (100, 30);
    button.show();
    return app.exec();
}

