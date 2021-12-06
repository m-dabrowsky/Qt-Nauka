#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    layout = new QVBoxLayout();
    this->setLayout(layout);

    textEdit = new QTextEdit(this);
    layout->addWidget(textEdit);
    pushButton_1 = new QPushButton("QInputDialog::getDouble", this);
    layout->addWidget(pushButton_1);
    pushButton_2 = new QPushButton("QInputDialog::getInteger", this);
    layout->addWidget(pushButton_2);


    QObject::connect(pushButton_1, SIGNAL(clicked()), this, SLOT(QColorDialogGetColor()));
    QObject::connect(pushButton_2, SIGNAL(clicked()), this, SLOT(QFontDialogGetFont()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::QColorDialogGetColor()
{
    QColor color = QColorDialog::getColor(textEdit->textColor(), this);
    if(color.isValid())
        textEdit -> setTextColor(color);
}

void Widget::QFontDialogGetFont()
{
    bool ok;
    QFont font = QFontDialog::getFont (&ok,textEdit->currentFont(), this);
    if(ok)
        textEdit -> setCurrentFont(font);
}

