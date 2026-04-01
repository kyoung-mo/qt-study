#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <QObject>
#include <QtHttpServer/QHttpServer>

class WebServer : public QObject
{
    Q_OBJECT
public:
    explicit WebServer(QObject *parent = nullptr);
    ~WebServer();

private:
    QHttpServer m_server;
    QString hostName(const QHttpServerRequest &request);

};

#endif // WEBSERVER_H
