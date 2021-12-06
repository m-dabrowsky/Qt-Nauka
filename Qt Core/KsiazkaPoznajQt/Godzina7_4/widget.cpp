#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    splitter = new QSplitter(this);
    splitter ->setGeometry(10,10,200,10);

    b1 = new QPushButton("Przycisk 1", splitter);
    b2 = new QPushButton("Przycisk 2", splitter);
}

Widget::~Widget()
{
    delete ui;
}

