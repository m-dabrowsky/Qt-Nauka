#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    box = new QGroupBox(this);
    box->setGeometry(10,10,130,80);
    box->setTitle("Pole grupy");

    etykieta = new QLabel(this);
    etykieta->setGeometry(30,35,90,40);
    etykieta->setText("Tekst");
    etykieta->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}

Widget::~Widget()
{
    delete ui;
}

