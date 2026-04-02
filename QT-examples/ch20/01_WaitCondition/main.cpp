#include <QCoreApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer producer;
    producer.start();

    Consumer consumer;
    consumer.start();

    return a.exec();
}
