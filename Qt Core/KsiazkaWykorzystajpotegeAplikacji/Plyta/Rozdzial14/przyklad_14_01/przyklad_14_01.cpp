#include <QObject>
#include <iostream>
#include "counter.h"

int main(int argc, char *argv[])
{
    Counter a,b;
    QObject::connect (&a,SIGNAL(valueChanged(int)),&b, SLOT(setValue(int)));
    a.setValue (12);     
    
    // a = 12, b = 12
    std::cout << "a = " << a.getValue() << std::endl;
    std::cout << "b = " << b.getValue() << std::endl;
     
    // a = 12, b = 48
    b.setValue (48);     
    std::cout << "a = " << a.getValue() << std::endl;
    std::cout << "b = " << b.getValue() << std::endl;
    
    // a = 36, b = 48
    QObject::disconnect (&a,SIGNAL(valueChanged(int)),&b, SLOT(setValue(int)));
    a.setValue (36);     
    std::cout << "a = " << a.getValue() << std::endl;
    std::cout << "b = " << b.getValue() << std::endl;
}

