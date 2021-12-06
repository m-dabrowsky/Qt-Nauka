#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // Utworzenie layoutu
    layout = new QVBoxLayout(this);
    // Ustawienie layoutu jako layout okna
    this->setLayout(layout);
    // Utworzenie przycisku
    push_button1 = new QPushButton("QMessageBox::MessageBoxAbout");
    layout -> addWidget(push_button1);
    push_button2 = new QPushButton("QMessageBox::MessageBoxCritical");
    layout -> addWidget(push_button2);
    push_button3 = new QPushButton("QMessageBox::MessageBoxInformation");
    layout -> addWidget(push_button3);
    push_button4 = new QPushButton("QMessageBox::MessageBoxQuestion");
    layout -> addWidget(push_button4);
    push_button5 = new QPushButton("QMessageBox::MessageBoxWarining");
    layout -> addWidget(push_button5);
    push_button6 = new QPushButton("QMessageBox::MessageBoxAboutQt");
    layout -> addWidget(push_button6);
    push_button7 = new QPushButton("QMessageBox::ErrorMessage");
    layout -> addWidget(push_button7);

    label_1 = new QLabel("Pusto");
    layout -> addWidget(label_1);
    label_2 = new QLabel("Nic");
    layout -> addWidget(label_2);

    // utworzenie obiektu komunikującego błąd
    errorMessage = new QErrorMessage(this);
    errorMessage -> setWindowTitle("Błąd");

    // powiązania sygnał-gniazdo
    QObject::connect (push_button1, SIGNAL(clicked()), this, SLOT(MessageBoxAbout()));
    QObject::connect (push_button2, SIGNAL(clicked()), this, SLOT(MessageBoxCritical()));
    QObject::connect (push_button3, SIGNAL(clicked()), this, SLOT(MessageBoxInformation()));
    QObject::connect (push_button4, SIGNAL(clicked()), this, SLOT(MessageBoxQuestion()));
    QObject::connect (push_button5, SIGNAL(clicked()), this, SLOT(MessageBoxWarning()));
    QObject::connect (push_button6, SIGNAL(clicked()), this, SLOT(MessageBoxAboutQt()));
    QObject::connect (push_button7, SIGNAL(clicked()), this, SLOT(ErrorMessage()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::MessageBoxAbout()
{
    QMessageBox::about(this, "O programie", "Informacja o programie i autorze");
    label_1->setText ("QMessageBox::about");
    label_2->setText(" ");
}

void Widget::MessageBoxCritical()
{
    QMessageBox::critical(this, "Błąd", "Treść informacji o <B>błędzie</B>");
    label_1->setText ("QMessageBox::critical");
    label_2->setText(" ");
}

void Widget::MessageBoxInformation()
{
    QMessageBox::information(this, "Informacja", "<CENTER>Treść informacji</CENTER><BR><U>Drugi wiersz</U>");
    label_1->setText ("QMessageBox::information");
    label_2->setText(" ");
}

void Widget::MessageBoxQuestion()
{
    QMessageBox::question(this, "Zapytanie", "Treść zapytania", QMessageBox::Yes | QMessageBox::No);
    label_1->setText ("QMessageBox::question");
    label_2->setText(" ");
}

void Widget::MessageBoxWarning()
{
    QMessageBox::warning(this, "Ostrzeżenie", "Treść <BIG>ostrzeżenia</BIG>", QMessageBox::Ok | QMessageBox::Cancel);
    label_1->setText ("QMessageBox::warning");
    label_2->setText(" ");
}

void Widget::MessageBoxAboutQt()
{
    QMessageBox::aboutQt(this);
    label_1->setText ("QMessageBox::aboutQt");
    label_2->setText(" ");
}

void Widget::ErrorMessage()
{
    errorMessage->showMessage("Treść komunikatu błędy");
    label_1->setText ("QErrorMessage");
    label_2->setText(" ");
}

