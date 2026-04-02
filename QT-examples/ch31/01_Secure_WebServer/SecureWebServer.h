#ifndef SECUREWEBSERVER_H
#define SECUREWEBSERVER_H

#include <QObject>
#include <QtHttpServer/QHttpServer>

class SecureWebServer : public QObject
{
    Q_OBJECT
public:
    explicit SecureWebServer(QObject *parent = nullptr);
    ~SecureWebServer();

private:
    QHttpServer m_server;

};

#endif // SECUREWEBSERVER_H
