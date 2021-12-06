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
    // sprawdzenie dost�pno�ci zasob�w
    if (Prime::semaphore.tryAcquire (max_thread))
    {
        // usuni�cie poprzednich wynik�w
        listWidget -> clear ();
        listWidget -> update ();
        
        // komunikat o ilo�ci w�tk�w
        label -> setText ("Pozosta�o w�tk�w " + QString::number (max_thread - Prime::semaphore.available ()));
        
        // generowanie poszczeg�lnych w�tk�w     
        for (int i = 0; i < max_thread; i++)
        {
            Prime *prime = new Prime (this,i*step,i*step+step,listWidget);
            connect (prime,SIGNAL (finished ()),this,SLOT(Info()));
            prime -> start();
        }
    }
}

// wyszukiwanie liczb pierwszych bez u�ycia w�tk�w

void MyWindow::ExecStd ()
{
    // sprawdzenie, czy nie jest wykonywana wersja wielow�tkowa
    if (max_thread != Prime::semaphore.available ())
        return;
        
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
    // komunikat
    label -> setText ("Pozosta�o w�tk�w " + QString::number (max_thread - Prime::semaphore.available ()));
    
    // aktualizacja danych 
    if (max_thread == Prime::semaphore.available ())
    {
        listWidget -> sortItems (Qt::AscendingOrder);
        listWidget -> update ();
    }
}
