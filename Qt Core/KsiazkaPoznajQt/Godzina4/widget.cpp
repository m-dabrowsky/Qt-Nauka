#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setGeometry(100, 100, 300, 300);

    button = new QPushButton("Wyjście",this);
    button->setGeometry(10,10,80,40);
    button->setFont(QFont ("Times", 18, QFont::Bold));

    lcd = new QLCDNumber(2, this);
    lcd->setGeometry(100,10,190,180);

    slider = new QSlider(Qt::Vertical, this);
    slider->setGeometry(10,60,80,130);

    QObject::connect(button, SIGNAL(clicked()), qApp, SLOT(quit()));

    QObject::connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

}

Widget::~Widget()
{
    delete ui;
}

