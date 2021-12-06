#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setGeometry(100,100,200,100);

    group = new QButtonGroup(this);

    button = new QPushButton("Przycisk",this);
    button->move(20,20);
    radioButton = new QRadioButton("radiobutton", this);
    radioButton->move(20,50);
    group->addButton(button);
    group->addButton(radioButton);


}

Widget::~Widget()
{
    delete ui;
}

