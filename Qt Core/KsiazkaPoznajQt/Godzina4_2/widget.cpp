#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    button1 = new QPushButton("Zaznacz tekst",this);
    button1->setGeometry(10,10,280,40);
    button1->setFont(QFont ("Times", 18, QFont::Bold));

    button3 = new QPushButton("Usun tekst",this);
    button3->setGeometry(10,110,280,40);
    button3->setFont(QFont ("Times", 18, QFont::Bold));


    lineEdit = new QLineEdit ("To jest linia tekstu", this);
    lineEdit->setGeometry(10,160,280,30);

    QObject::connect(button1, SIGNAL(clicked()), lineEdit, SLOT(selectAll()));
    QObject::connect(button3, SIGNAL(clicked()), lineEdit, SLOT(clear()));

}

Widget::~Widget()
{
    delete ui;
}

