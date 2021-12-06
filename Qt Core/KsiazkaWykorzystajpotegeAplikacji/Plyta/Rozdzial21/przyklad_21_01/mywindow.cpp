#include "mywindow.h"

// klasa ze zmienna statyczn�, na kt�rej wykonywane s� operacje

class A : public QThread
{
public:
    static signed long int a;
};

// definicja zmiennej statycznej a

signed long int A::a;

// klasa zwi�kszaj�ca warto�� a

class Aplus : public A
{
public:
    void run () 
    {    
        for (int i = 0; i < 1000000; i++)
            a++;
    }
};

// klasa zmniejszaj�ca warto�� a

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

    // po��czenia sygna�-gniazdo
    connect (pushButton,SIGNAL (clicked()),this,SLOT (Exec()));
}

// test pary w�tk�w nie u�ywaj�cych synchronizacji

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

