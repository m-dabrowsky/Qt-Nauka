#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    layout = new QVBoxLayout();
    this->setLayout(layout);


    pushButton_1 = new QPushButton("QInputDialog::getDouble", this);
    layout->addWidget(pushButton_1);
    pushButton_2 = new QPushButton("QInputDialog::getInteger", this);
    layout->addWidget(pushButton_2);
    pushButton_3 = new QPushButton("QInputDialog::getItem", this);
    layout->addWidget(pushButton_3);
    pushButton_4 = new QPushButton("QInputDialog::getText", this);
    layout->addWidget(pushButton_4);

    label_1 = new QLabel();
    layout->addWidget(label_1);
    label_2 = new QLabel();
    layout->addWidget(label_2);


    QObject::connect(pushButton_1, SIGNAL(clicked()), this, SLOT(QInputDialogGetDouble()));
    QObject::connect(pushButton_2, SIGNAL(clicked()), this, SLOT(QInputDialogGetInteger()));
    QObject::connect(pushButton_3, SIGNAL(clicked()), this, SLOT(QInputDialogGetItem()));
    QObject::connect(pushButton_4, SIGNAL(clicked()), this, SLOT(QInputDialogGetText()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::QInputDialogGetDouble()
{
    bool ok;
    double d = QInputDialog::getDouble(this, "Pobieranie liczby zmiennoprzecinkowej", "Podaj wartość", 0, -100, 100, 2, &ok);
    label_1 -> setText("QInputDialog::getDouble");
    if(ok)
        label_2 -> setNum(d);
    else
        label_2 -> setText(" ");

}

void Widget::QInputDialogGetInteger()
{
    bool ok;
    int i = QInputDialog::getInt(this, "Pobieranie liczby całkowitej", "Podaj wartość", 0, -100,100, 1, &ok);
    label_1 -> setText("QInputDialog::getInt");
    if(ok)
        label_2 -> setNum(i);
    else
        label_2 -> setText(" ");
}

void Widget::QInputDialogGetItem()
{
    bool ok;
    QStringList items;
    items << "Poniedziałek" << "Wtorek" << "Środa";
    QString str = QInputDialog::getItem(this, "Wybór elementu z listy", "Wybierz element", items, 0, false, &ok);
    label_1 -> setText("QInputDialog::getItem");
    if(ok)
        label_2 -> setText(str);
    else
        label_2 -> setText(" ");
}

void Widget::QInputDialogGetText()
{
    bool ok;
    QString str = QInputDialog::getText(this, "Pobieranie tekstu", "Wprowadź tekst", QLineEdit::Normal, "", &ok);
    label_1 -> setText("QInputDialog::getText");
    if(ok)
        label_2 -> setText(str);
    else
        label_2 -> setText(" ");
}



