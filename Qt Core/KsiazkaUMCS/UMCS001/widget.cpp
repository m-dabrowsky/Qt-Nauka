#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    x = 0;
    name = "Nazwa testowa";
    setWindowTitle(name);
    button = new QPushButton("Exit", this); // button.show() dla parent = NULL
    slider = new QSlider(Qt::Horizontal, this);
    slider->setRange(0,100);
    spin = new QSpinBox(this);
    layout = new QHBoxLayout(this);
    layout->addWidget(button);
    //button->show();
    layout->addWidget(slider);
    layout->addWidget(spin);


    QObject::connect(button, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(slider, SIGNAL(valueChanged(int)), spin, SLOT(setValue(int)));
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


