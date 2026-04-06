#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <QWidget>
#include <QTcpSocket> // tcp socket connection's main class?
#include <QHostAddress> // handling IP Address
#include <QInputDialog>
#include <QDebug>
#include <QMessageBox>

#define BLOCK_SIZE 1024
class SocketClient : public QWidget
{
    Q_OBJECT
    QTcpSocket *pQTcpSocket;
    QString SERVERIP = "10.10.16.60";
    int SERVERPORT = 5000;
    QString LOGID = "5";
    QString LOGPW = "PASSWD";

public:
    explicit SocketClient(QWidget *parent = nullptr);
    ~SocketClient();

signals:
    void socketRecvDataSig(QString strRecvData);

private slots:
    void socketReadDataSlot();
    void socketErrorSlot();
    void socketConnectServerSlot();

public slots:
    void connectToServerSlot(bool &);
    void socketClosedServerSlot();
    void socketWriteDataSlot(QString);

};

#endif // SOCKETCLIENT_H
