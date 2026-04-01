#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtGlobal>

#define MYCLASS_EXPORT Q_DECL_EXPORT

class MyClassPrivate;
class MYCLASS_EXPORT MyClass
{
    Q_DECLARE_PRIVATE(MyClass)

public:
    MyClass();
    ~MyClass();

    int getValue();
    void printValue();

private:
    int m_value;
    MyClassPrivate *d_ptr;
};

#endif // MYCLASS_H
