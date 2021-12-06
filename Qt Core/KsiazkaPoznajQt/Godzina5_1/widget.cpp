#include "widget.h"
#include "ui_widget.h"
#include

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setGeometry(100,100,200,100);

    button1 = new QPushButton("Przycisk",this);
    button1->setGeometry(10,10,210,120);
    button1->setFont(QFont ("Times", 18, QFont::Bold));
    scrollArea = new QScrollArea(this);
    scrollArea->setWidget(button1);
    button1->setDefault(true);


}

Widget::~Widget()
{
    delete ui;
}

