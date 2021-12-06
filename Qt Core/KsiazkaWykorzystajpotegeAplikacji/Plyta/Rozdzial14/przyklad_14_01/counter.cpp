#include "counter.h"

Counter::Counter() 
{ 
    value = 0; 
}

int Counter::getValue() 
{ 
    return value; 
}

void Counter::setValue(int newValue)
{
    if (value != newValue) 
    {
        value = newValue;
        emit valueChanged (newValue);
    }
}
