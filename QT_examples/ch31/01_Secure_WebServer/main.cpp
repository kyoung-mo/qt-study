#include <QCoreApplication>
#include "SecureWebServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SecureWebServer secureWebServer;

    return a.exec();
}
