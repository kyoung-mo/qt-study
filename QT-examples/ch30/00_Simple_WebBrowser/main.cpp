#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow w;
//    w.show();

    QUrl url = QUrl("http://www.qt-dev.com");
    MainWindow *browser = new MainWindow(url);
    browser->resize(1024, 768);
    browser->show();

    return a.exec();
}
