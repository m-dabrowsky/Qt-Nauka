#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include <QLCDNumber>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;


    QLCDNumber *lcd = new QLCDNumber(&w);
    QSpinBox *spin = new QSpinBox();
    QVBoxLayout *layout = new QVBoxLayout();
    w.setLayout(layout);

    layout->addWidget(lcd);
    layout->addWidget(spin);

    QObject::connect(spin, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
    w.show();
    return a.exec();
}
