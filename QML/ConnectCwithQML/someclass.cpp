#include "someclass.h"
#include <QDebug>

SomeClass::SomeClass(QObject *parent) : QObject(parent), m_someVar("123")
{
    qDebug() << "I'm being created";
}

void SomeClass::anotherFunction()
{
    qDebug() << "Another Function";
}

// getter
QString SomeClass::getsomeVar()
{
    return m_someVar;
}

void SomeClass::callMe()
{
   qDebug() << "I'm super" ;
}


const QString &SomeClass::someVar() const
{
    return m_someVar;
}

// setter
void SomeClass::setSomeVar(const QString &newSomeVar)
{
    if (m_someVar == newSomeVar)
        return;
    m_someVar = newSomeVar;
    emit someVarChanged();
}
