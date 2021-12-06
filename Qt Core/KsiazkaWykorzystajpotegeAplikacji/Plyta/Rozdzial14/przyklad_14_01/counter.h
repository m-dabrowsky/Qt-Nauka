#ifndef __COUNTER_H__
#define __COUNTER_H__

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
public:
    Counter();
    int getValue();
public slots:
    void setValue (int newValue);
signals:
    void valueChanged (int newValue);
private:
    int value;
};
 
#endif // __COUNTER_H__
