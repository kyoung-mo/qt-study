#include <QCoreApplication>
#include "WebServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    WebServer webServer;

    return a.exec();
}
