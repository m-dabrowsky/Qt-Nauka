#include "mywindow.h"
#include "prime.h"

// 1/100 iloœci sprawdzanych liczb 

const int step = 2000; 

// konstruktor

MyWindow::MyWindow ()
{
    setupUi (this);
    
    // po³¹czenia sygna³-gniazdo
    connect (pushButtonThread,SIGNAL (clicked()),this,SLOT (ExecThread()));
    connect (pushButtonStd,SIGNAL (clicked()),this,SLOT (ExecStd()));
}

// wyszukiwanie liczb pierwszych w trybie wielow¹tkowym

void MyWindow::ExecThread ()
{
}

// wyszukiwanie liczb pierwszych bez u¿ycia w¹tków

void MyWindow::ExecStd ()
{
    // usuniêcie poprzednich wyników
    listWidget -> clear ();
    listWidget -> update ();
        
    // komunikat 
    label -> setText ("Pocz¹tek obliczeñ");

    // obliczenia    
    for (int i = 0; i < max_thread * step; i++)
        if (IsPrime (i))
            listWidget -> addItem (QString::number (i).rightJustified (6));

    // komunikat 
    label -> setText ("Koniec obliczeñ");
}

// informacja o stanie pracy w¹tków

void MyWindow::Info ()
{
}
