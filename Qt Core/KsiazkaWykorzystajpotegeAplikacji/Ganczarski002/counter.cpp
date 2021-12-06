#include "counter.h"
#include "ui_counter.h"

counter::counter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::counter)
{
    layout = new QVBoxLayout(this);
    setGeometry(300,300,300,200);
    setWindowTitle("Obsługa zdarzeń");
    label1 = new QLabel(this);
    label1->setGeometry(75,80,175,20);
    label2 = new QLabel(this);
    label2->setGeometry(75,110,175,20);
    setLayout(layout);
    layout->addWidget(label1);
    layout->addWidget(label2);

}

counter::~counter()
{
    delete ui;
}

bool counter::event(QEvent *event)
{
    event->accept();
    if(event->type() == QEvent::KeyPress){
        label1->setText("QEvent::KeyPress");
        label2->setText("Rzutowanie");
        return true;
    }
    if(event->type() == QEvent::KeyRelease){
        label1->setText("QEvent::KeyPress");
        label2->setText(" ");
        return true;
    }
    if(event->type() == QEvent::MouseButtonDblClick){
        label1->setText("QEvent::MouseButtonDblClick");
        QString x,y;
        x.setNum(static_cast<QMouseEvent*>(event)->x());
        y.setNum(static_cast<QMouseEvent*>(event)->y());
        label2->setText("X = " + x + " Y = " + y);
        return true;
    }
    return false;
}

