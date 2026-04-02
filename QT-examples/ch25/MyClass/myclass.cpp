#include "myclass.h"
#include "myclass_p.h"

MyClass::MyClass()
{
    d_ptr = new MyClassPrivate(this);
    Q_D(MyClass);

    m_value = 100;
    d->setValue(200);
}

MyClass::~MyClass()
{
}

int MyClass::getValue()
{
    return m_value;
}

void MyClass::printValue()
{
    Q_D(MyClass);
    d->printValue();
}
