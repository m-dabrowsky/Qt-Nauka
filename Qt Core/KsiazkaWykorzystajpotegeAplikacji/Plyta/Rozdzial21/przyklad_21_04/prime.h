#ifndef __PRIME_H__
#define __PRIME_H__

#include <QtGui>

// iloœæ generowanych w¹tków

const int max_thread = 100;

// funkcja obliczaj¹ca, czy dana liczba jest liczb¹ pierwsz¹

bool IsPrime (int number);

// klasa w¹tku

class Prime : public QThread
{
public:
    Prime (QObject * parent, int from, int to, QListWidget *listWidget);
    void run ();
private:
    int from, to;
    QListWidget *listWidget;
    static QMutex mutex;
public:
    static QSemaphore semaphore;
};

#endif // __PRIME_H__
