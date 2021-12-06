#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setGeometry(100,100,200,100);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    paint = new QPainter();
    paint->begin(this); // zapoczątkowanie rysowania
    // Pióro do rysowania
    QPen pen(Qt::green,3,Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    paint->setPen(pen);
    // Pędzel do wypełeniania wzoru
    QBrush brush(Qt::red, Qt::Dense1Pattern);
    paint->setBrush(brush);

    paint->drawRect(20,20,160,160); //rysowanie kwadratu

    // Ustawienie wielkości czcionki i styl
    QFont font("Arial", 12, QFont::Bold, false);
    paint->setFont(font);
    paint->drawText(20,20,260,60,Qt::AlignCenter,"tekst");
    paint->end();
}

