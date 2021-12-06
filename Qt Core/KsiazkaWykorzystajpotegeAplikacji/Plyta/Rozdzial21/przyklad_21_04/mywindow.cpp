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
    // sprawdzenie dostêpnoœci zasobów
    if (Prime::semaphore.tryAcquire (max_thread))
    {
        // usuniêcie poprzednich wyników
        listWidget -> clear ();
        listWidget -> update ();
        
        // komunikat o iloœci w¹tków
        label -> setText ("Pozosta³o w¹tków " + QString::number (max_thread - Prime::semaphore.available ()));
        
        // generowanie poszczególnych w¹tków     
        for (int i = 0; i < max_thread; i++)
        {
            Prime *prime = new Prime (this,i*step,i*step+step,listWidget);
            connect (prime,SIGNAL (finished ()),this,SLOT(Info()));
            prime -> start();
        }
    }
}

// wyszukiwanie liczb pierwszych bez u¿ycia w¹tków

void MyWindow::ExecStd ()
{
    // sprawdzenie, czy nie jest wykonywana wersja wielow¹tkowa
    if (max_thread != Prime::semaphore.available ())
        return;
        
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
    // komunikat
    label -> setText ("Pozosta³o w¹tków " + QString::number (max_thread - Prime::semaphore.available ()));
    
    // aktualizacja danych 
    if (max_thread == Prime::semaphore.available ())
    {
        listWidget -> sortItems (Qt::AscendingOrder);
        listWidget -> update ();
    }
}
