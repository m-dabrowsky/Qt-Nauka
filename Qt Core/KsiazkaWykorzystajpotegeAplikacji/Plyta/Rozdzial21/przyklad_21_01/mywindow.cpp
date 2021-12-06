#include "mywindow.h"

// klasa ze zmienna statyczn¹, na której wykonywane s¹ operacje

class A : public QThread
{
public:
    static signed long int a;
};

// definicja zmiennej statycznej a

signed long int A::a;

// klasa zwiêkszaj¹ca wartoœæ a

class Aplus : public A
{
public:
    void run () 
    {    
        for (int i = 0; i < 1000000; i++)
            a++;
    }
};

// klasa zmniejszaj¹ca wartoœæ a

class Aminus : public A
{
public:
    void run ()
    {
        for (int i = 0; i < 1000000; i++)
            a--;
    }
};

// konstruktor

MyWindow::MyWindow ()
{
    setupUi (this);

    // po³¹czenia sygna³-gniazdo
    connect (pushButton,SIGNAL (clicked()),this,SLOT (Exec()));
}

// test pary w¹tków nie u¿ywaj¹cych synchronizacji

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

