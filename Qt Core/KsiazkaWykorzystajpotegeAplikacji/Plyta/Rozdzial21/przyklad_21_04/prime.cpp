#include "prime.h"

// definicja zmiennej statycznej mutex

QMutex Prime::mutex;

// definicja i inicjalizacja zmiennej statycznej semaphore

QSemaphore Prime::semaphore (max_thread);

// konstruktor

Prime::Prime (QObject * parent, int from_, int to_, QListWidget *list):
   QThread (parent),
   from (from_),
   to (to_),
   listWidget (list)
{
}

// funkcja obliczeniowa

void Prime::run ()
{
    // sprawdzanie liczb z okreœlonego zakresu
    for (int number = from; number < to; number++)
        if (IsPrime (number))   
        {
            // dodanie wyniku
            mutex.lock();
            listWidget -> addItem (QString::number (number).rightJustified (6));
            mutex.unlock();
        }
   
    // zwolnienie jednego zasobu semafora
    semaphore.release (1);
}

// sprawdzenie czy liczba jest pierwsza

bool IsPrime (int number)
{
    // przypadki elementarne
    if (number == 0 || number == 1)
        return false;

    // sprawdzenie, czy liczba jest pierwsza
    for (int i = 2; i <= number/2; i++)
        if (!(number % i))
            return false;
    return true;       
}
