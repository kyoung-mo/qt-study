#ifndef MYCLASSPRIVATE_H
#define MYCLASSPRIVATE_H

#include "myclass.h"
#include <QDebug>

class MyClassPrivate
{
    Q_DECLARE_PUBLIC(MyClass)

public:
    MyClassPrivate(MyClass *q);
    ~MyClassPrivate();

    void setValue(int);
    void printValue();

private:
    int      m_value;
    MyClass *q_ptr;
};

#endif // MYCLASSPRIVATE_H
