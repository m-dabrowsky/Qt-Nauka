#include "mywindow.h"

MyWindow::MyWindow ()
{
    setupUi (this);
    
    // powi�zania sygna�-gniazdo
    connect (pushButton_1,SIGNAL (clicked()),this,SLOT(QInputDialogGetDouble()));
    connect (pushButton_2,SIGNAL (clicked()),this,SLOT(QInputDialogGetInteger()));
    connect (pushButton_3,SIGNAL (clicked()),this,SLOT(QInputDialogGetItem()));
    connect (pushButton_4,SIGNAL (clicked()),this,SLOT(QInputDialogGetText()));
}

// QInputDialog::getDouble

void MyWindow::QInputDialogGetDouble ()
{
     bool ok;
     double d = QInputDialog::getDouble (this,"Pobieranie liczby zmiennoprzecinkowej","Podaj warto��",0,-100,100,2,&ok);
     label_1 -> setText ("QInputDialog::getDouble");
     if (ok)
         label_2 -> setNum (d);
     else
         label_2 -> setText ("");
}

// QInputDialog::getInteger

void MyWindow::QInputDialogGetInteger ()
{
     bool ok;
     int i = QInputDialog::getInteger (this,"Pobieranie liczby ca�kowitej","Podaj warto��",0,-100,100,1,&ok);
     label_1 -> setText ("QInputDialog::getInteger");
     if (ok)
         label_2 -> setNum (i);
     else
         label_2 -> setText ("");
}

// QInputDialog::getItem

void MyWindow::QInputDialogGetItem ()
{
     bool ok;
     QStringList items;
     items << "Poniedzia�ek" << "Wtorek" << "�roda" << "Czwartek" << "Pi�tek" << "Sobota" << "Niedziela";
     QString str = QInputDialog::getItem (this,"Wyb�r elementu z listy","Wybierz element",items,0,false,&ok);
     label_1 -> setText ("QInputDialog::getItem");
     if (ok)
         label_2 -> setText (str);
     else
         label_2 -> setText ("");
}

// QInputDialog::getText

void MyWindow::QInputDialogGetText ()
{
     bool ok;
     QString str = QInputDialog::getText (this,"Pobieranie tekstu","Wprowad� tekst",QLineEdit::Normal,"",&ok);
     label_1 -> setText ("QInputDialog::getText");
     if (ok)
         label_2 -> setText (str);
     else
         label_2 -> setText ("");
}
