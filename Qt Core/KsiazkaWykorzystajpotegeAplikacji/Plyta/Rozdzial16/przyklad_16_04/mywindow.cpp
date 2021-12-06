#include "mywindow.h"

MyWindow::MyWindow ()
{
    setupUi (this);
    
    // powi¹zania sygna³-gniazdo
    connect (pushButton_1,SIGNAL (clicked()),this,SLOT(GetExistingDirectory()));
    connect (pushButton_2,SIGNAL (clicked()),this,SLOT(GetOpenFileName()));
    connect (pushButton_3,SIGNAL (clicked()),this,SLOT(GetOpenFileNames()));
    connect (pushButton_4,SIGNAL (clicked()),this,SLOT(GetSaveFileName()));
}

// QFileDialog::getExistingDirectory

void MyWindow::GetExistingDirectory ()
{
    QString dir;
    if (checkBox -> isChecked ())
        dir = QFileDialog::getExistingDirectory (this,"Wybierz folder",".",QFileDialog::ShowDirsOnly);
    else
        dir = QFileDialog::getExistingDirectory (this,"Wybierz folder",".",QFileDialog::ShowDirsOnly | QFileDialog::DontUseNativeDialog);
    label_1 -> setText ("getExistingDirectory");
    label_2 -> setText (dir);
}

// QFileDialog::getOpenFileName

void MyWindow::GetOpenFileName ()
{
    QString file;
    QString filter ("pliki tekstowe (*.txt);;wszystkie pliki (*.*)");
    if (checkBox -> isChecked ())
        file = QFileDialog::getOpenFileName (this,"Otwieranie",".",filter);
    else
        file = QFileDialog::getOpenFileName (this,"Otwieranie",".",filter,0,QFileDialog::DontUseNativeDialog);
    label_1 -> setText ("getOpenFileName");
    label_2 -> setText (file);
}

// QFileDialog::getOpenFileNames
                
void MyWindow::GetOpenFileNames ()
{
    QStringList files;
    QString filter ("pliki tekstowe (*.txt);;wszystkie pliki (*.*)");
    if (checkBox -> isChecked ())
        files = QFileDialog::getOpenFileNames (this,"Otwieranie",".",filter);
    else
        files = QFileDialog::getOpenFileNames (this,"Otwieranie",".",filter,0,QFileDialog::DontUseNativeDialog);
    label_1 -> setText ("getOpenFileNames");
    label_2 -> setText ("");
    for (int i = 0; i < files.count(); i++)
        label_2 -> setText (label_2 -> text() + files [i] + " ");
}

// QFileDialog::getSaveFileName

void MyWindow::GetSaveFileName ()
{
    QString file;
    QString filter ("pliki tekstowe (*.txt);;wszystkie pliki (*.*)");
    if (checkBox -> isChecked ())
        file = QFileDialog::getSaveFileName (this,"Zapisywanie jako",".",filter);
    else
        file = QFileDialog::getSaveFileName (this,"Zapisywanie jako",".",filter,0,QFileDialog::DontUseNativeDialog);
    label_1 -> setText ("getSaveFileName");
    label_2 -> setText (file);
}

