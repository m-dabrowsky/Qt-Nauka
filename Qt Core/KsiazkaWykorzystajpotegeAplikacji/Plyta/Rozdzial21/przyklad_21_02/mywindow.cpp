#include "mywindow.h"

// klasa ze zmienna statyczn¹, na której wykonywane s¹ operacje

class A : public QThread
{
public:
    static signed long int a;
};

// definicja zmiennej statycznej a

signed long int A::a;

// klasa ze zmienn¹ statyczn¹ - muteksem

class Amutex: public A
{
public:
    static QMutex mutex;
};

// definicja zmiennej statycznej mutex

QMutex Amutex::mutex;

// klasa zwiêkszaj¹ca wartoœæ a u¿ywaj¹ca muteksu

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

// klasa zmniejszaj¹ca wartoœæ a u¿ywaj¹ca muteksu

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
    
    // po³¹czenia sygna³-gniazdo
    connect (pushButton,SIGNAL (clicked()),this,SLOT (Exec()));
}


// test pary w¹tków synchronizowanych przy u¿yciu muteksu

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

