#ifndef QHTTPSOCKET_H
#define QHTTPSOCKET_H

#include <QObject>
#include <QTcpSocket>

class QHttpSocket : public QObject
{
    Q_OBJECT
public:
    explicit QHttpSocket(QObject *parent = nullptr);
    ~QHttpSocket();
    void httpConnect();

signals:

public slots:
    void httpDisconnected();

private:
    QTcpSocket *socket;

};

#endif // QHTTPSOCKET_H
