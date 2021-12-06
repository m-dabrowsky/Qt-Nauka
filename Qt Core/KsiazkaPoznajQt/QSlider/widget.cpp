#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    suwak = new QSlider (Qt::Horizontal, this);
    suwak->setGeometry(10,15,130,20);
    suwak->setTickPosition(QSlider::TicksBelow);
}

Widget::~Widget()
{
    delete ui;
}

