#include "mywindow.h"

MyWindow::MyWindow ()
{
    setupUi (this);
    
    // powi¹zania sygna³-gniazdo
    connect (pushButton_1,SIGNAL (clicked()),this,SLOT(QColorDialogGetColor()));
    connect (pushButton_2,SIGNAL (clicked()),this,SLOT(QFontDialogGetFont()));
}

// QColorDialog::getColor

void MyWindow::QColorDialogGetColor ()
{
     QColor color = QColorDialog::getColor (textEdit -> textColor (),this);
     if (color.isValid ())
         textEdit -> setTextColor (color);
}

// QFontDialog::getFont

void MyWindow::QFontDialogGetFont ()
{
     bool ok;
     QFont font = QFontDialog::getFont (&ok,textEdit -> currentFont (),this);
     if (ok)
         textEdit -> setCurrentFont (font);
}
