#include "prime.h"

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
