#ifndef MYUTIL_H
#define MYUTIL_H

#include <QObject>
#include "MyUtil_global.h"

class MYUTIL_EXPORT MyUtil : public QObject
{
    Q_OBJECT
public:
    explicit MyUtil(QObject *parent = nullptr);
    int getSumValue(int a, int b);

};

#endif // MYUTIL_H
