#include "mywindow.h"

MyWindow::MyWindow ()
{
    setupUi (this);
    
    // utworzenie obiektu komunikuj¹cego b³¹d
    errorMessage = new QErrorMessage (this);
    errorMessage -> setWindowTitle ("B³¹d");

    // powi¹zania sygna³-gniazdo
    connect (pushButton_1,SIGNAL (clicked()),this,SLOT(MessageBoxAbout()));
    connect (pushButton_2,SIGNAL (clicked()),this,SLOT(MessageBoxCritical()));
    connect (pushButton_3,SIGNAL (clicked()),this,SLOT(MessageBoxInformation()));
    connect (pushButton_4,SIGNAL (clicked()),this,SLOT(MessageBoxQuestion()));
    connect (pushButton_5,SIGNAL (clicked()),this,SLOT(MessageBoxWarning()));
    connect (pushButton_6,SIGNAL (clicked()),this,SLOT(MessageBoxAboutQt()));
    connect (pushButton_7,SIGNAL (clicked()),this,SLOT(ErrorMessage()));
}

// MyWindow::MessageBoxAbout

void MyWindow::MessageBoxAbout ()
{
     QMessageBox::about (this,"O programie","<I></I>Informacja o &reg;programie i &copy;autorze");
     label_1 -> setText ("QMessageBox::about");
     label_2 -> setText ("");
}

// QMessageBox::critical

void MyWindow::MessageBoxCritical ()
{
     QMessageBox::critical (this,"B³¹d","Treœæ informacji o <B>b³êdzie</B>");
     label_1 -> setText ("QMessageBox::critical");
     label_2 -> setText ("");
}

// QMessageBox::information

void MyWindow::MessageBoxInformation ()
{
     QMessageBox::information (this,"Informacja","<CENTER>Treœæ informacji.</CENTER><BR><U>Drugi wiersz informacji</U>");
     label_1 -> setText ("QMessageBox::information");
     label_2 -> setText ("");
}

// QMessageBox::qestion

void MyWindow::MessageBoxQuestion ()
{
     unsigned int ret = QMessageBox::question (this,"Zapytanie","Treœæ zapytania",QMessageBox::Yes | QMessageBox::No);
     label_1 -> setText ("QMessageBox::question");
     label_2 -> setText ("");
     if (ret & QMessageBox::Yes)
        label_2 -> setText ("QMessageBox::Yes");
     if (ret & QMessageBox::No)
        label_2 -> setText ("QMessageBox::No");
}

// QMessageBox::warning

void MyWindow::MessageBoxWarning ()
{
     unsigned int ret = QMessageBox::warning (this,"Ostrze¿enie","Treœæ <BIG>ostrze¿enia</BIG>",QMessageBox::Ok | QMessageBox::Cancel);
     label_1 -> setText ("QMessageBox::warning");
     label_2 -> setText ("");
     if (ret & QMessageBox::Ok)
        label_2 -> setText ("QMessageBox::Ok");
     if (ret & QMessageBox::Cancel)
        label_2 -> setText ("QMessageBox::Cancel");
}

// QMessageBox::aboutQt

void MyWindow::MessageBoxAboutQt ()
{
     QMessageBox::aboutQt (this);
     label_1 -> setText ("QMessageBox::aboutQt");
     label_2 -> setText ("");
}

// QErrorMessage

void MyWindow::ErrorMessage ()
{
     errorMessage -> showMessage ("Treœæ komunikatu b³êdu");
     label_1 -> setText ("QErrorMessage");
     label_2 -> setText ("");
}
