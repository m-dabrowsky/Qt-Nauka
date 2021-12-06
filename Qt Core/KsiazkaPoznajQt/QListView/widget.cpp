#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    list = new QListWidget(this);
    widoklisty = new QListView(this);

    list->addItem("Ksiazka");

    kat1 = new QListWidgetItem(list, 1);
}

Widget::~Widget()
{
    delete ui;
}

