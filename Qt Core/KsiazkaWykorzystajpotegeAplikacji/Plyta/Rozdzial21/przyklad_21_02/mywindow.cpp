#include "mywindow.h"

// klasa ze zmienna statyczn�, na kt�rej wykonywane s� operacje

class A : public QThread
{
public:
    static signed long int a;
};

// definicja zmiennej statycznej a

signed long int A::a;

// klasa ze zmienn� statyczn� - muteksem

class Amutex: public A
{
public:
    static QMutex mutex;
};

// definicja zmiennej statycznej mutex

QMutex Amutex::mutex;

// klasa zwi�kszaj�ca warto�� a u�ywaj�ca muteksu

class Aplus : public Amutex
{
public:
    void run () 
    {    
        for (int i = 0; i < 1000000; i++)
        {
            mutex.lock();
            a++;
            mutex.unlock();
        }
    }
};

// klasa zmniejszaj�ca warto�� a u�ywaj�ca muteksu

class Aminus : public Amutex
{
public:
    void run ()
    {
        for (int i = 0; i < 1000000; i++)
        {
            mutex.lock();
            a--;
            mutex.unlock();
        }
    }
};

// konstruktor

MyWindow::MyWindow ()
{
    setupUi (this);
    
    // po��czenia sygna�-gniazdo
    connect (pushButton,SIGNAL (clicked()),this,SLOT (Exec()));
}


// test pary w�tk�w synchronizowanych przy u�yciu muteksu

void MyWindow::Exec ()
{
    // restart licznika
    A::a = 0;
    label -> setText ("a =");

    // obliczenia
    Aplus ap;
    Aminus am;
    ap.start();
    am.start();
    ap.wait();
    am.wait();
    
    // wynik
    label -> setText ("a = " + QString::number (A::a));
}

