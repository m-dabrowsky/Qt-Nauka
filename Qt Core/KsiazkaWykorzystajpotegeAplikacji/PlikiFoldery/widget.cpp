#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    layout = new QVBoxLayout();
    this->setLayout(layout);

    pushButton_1 = new QPushButton("getExistingDirectory", this);
    layout->addWidget(pushButton_1);
    pushButton_2 = new QPushButton("getOpenFileName", this);
    layout->addWidget(pushButton_2);
    pushButton_3 = new QPushButton("getOpenFileNames", this);
    layout->addWidget(pushButton_3);
    pushButton_4 = new QPushButton("getSaveFileName", this);
    layout->addWidget(pushButton_4);

    checkBox = new QCheckBox("Uzyj okien systemowych", this);
    layout->addWidget(checkBox);

    label_1 = new QLabel();
    layout->addWidget(label_1);
    label_2 = new QLabel();
    layout->addWidget(label_2);

    QObject::connect(pushButton_1, SIGNAL(clicked()), this, SLOT(getExistingDirectory()));
    QObject::connect(pushButton_2, SIGNAL(clicked()), this, SLOT(getOpenFileName()));
    QObject::connect(pushButton_3, SIGNAL(clicked()), this, SLOT(getOpenFileNames()));
    QObject::connect(pushButton_4, SIGNAL(clicked()), this, SLOT(getSaveFileName()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::getExistingDirectory()
{
    QString dir;
    if(checkBox -> isChecked())
        dir = QFileDialog::getExistingDirectory(this, "Wybierz folder", ".", QFileDialog::ShowDirsOnly);
    else
        dir = QFileDialog::getExistingDirectory(this, "Wybierz folder", ".", QFileDialog::ShowDirsOnly | QFileDialog::DontUseNativeDialog);
}

void Widget::getOpenFileName()
{

}

void Widget::getOpenFileNames()
{
    QStringList files;
    QString filter("pliki tekstowe (*.txt)::wszystkie pliki (*.*)");
    if(checkBox -> isChecked())
        files = QFileDialog::getOpenFileNames(this, "Otwieranie", ".", filter);
    else
        files = QFileDialog::getOpenFileNames(this, "Otwieranie", ".", filter, 0, QFileDialog::DontUseNativeDialog);
    label_1 -> setText("getOpenFileNames");
    label_2 -> setText("");
    for (int i=0; i<files.count(); i++)
        label_2 -> setText(label_2 -> text() + files[i] + " ");

}

void Widget::getSaveFileName()
{

}

