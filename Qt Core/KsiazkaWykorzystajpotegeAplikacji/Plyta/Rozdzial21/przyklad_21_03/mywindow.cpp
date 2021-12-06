#include "mywindow.h"
#include "prime.h"

// 1/100 ilo�ci sprawdzanych liczb 

const int step = 2000; 

// konstruktor

MyWindow::MyWindow ()
{
    setupUi (this);
    
    // po��czenia sygna�-gniazdo
    connect (pushButtonThread,SIGNAL (clicked()),this,SLOT (ExecThread()));
    connect (pushButtonStd,SIGNAL (clicked()),this,SLOT (ExecStd()));
}

// wyszukiwanie liczb pierwszych w trybie wielow�tkowym

void MyWindow::ExecThread ()
{
}

// wyszukiwanie liczb pierwszych bez u�ycia w�tk�w

void MyWindow::ExecStd ()
{
    // usuni�cie poprzednich wynik�w
    listWidget -> clear ();
    listWidget -> update ();
        
    // komunikat 
    label -> setText ("Pocz�tek oblicze�");

    // obliczenia    
    for (int i = 0; i < max_thread * step; i++)
        if (IsPrime (i))
            listWidget -> addItem (QString::number (i).rightJustified (6));

    // komunikat 
    label -> setText ("Koniec oblicze�");
}

// informacja o stanie pracy w�tk�w

void MyWindow::Info ()
{
}
