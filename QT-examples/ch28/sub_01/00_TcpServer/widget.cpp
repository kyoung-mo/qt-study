#include "widget.h"
#include "./ui_widget.h"

#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QTcpSocket>
#include <QMessageBox>
#include <QTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    initialize();
}

void Widget::initialize()
{
    QHostAddress hostAddr;
    QList<QHostAddress> ipList = QNetworkInterface::allAddresses();

    // Use something other than localhost (127.0.0.1)
    for (int i = 0; i < ipList.size(); ++i) {
        if (ipList.at(i) != QHostAddress::LocalHost &&
            ipList.at(i).toIPv4Address()) {
            hostAddr = ipList.at(i);
            break;
        }
    }

    if (hostAddr.toString().isEmpty())
        hostAddr = QHostAddress(QHostAddress::LocalHost);

    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen(hostAddr, 25000)) {
        QMessageBox::critical(this, tr("TCP Server"),
                              tr("Cannot start the server, Error: %1.")
                              .arg(tcpServer->errorString()));
        close();
        return;
    }

    ui->labelStatus->setText(tr("Server running \n\n"
                                "IP : %1\n"
                                "PORT : %2\n")
                                 .arg(hostAddr.toString())
                                 .arg(tcpServer->serverPort()));

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));

    ui->connMsgEdit->clear();
}

void Widget::newConnection()
{
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, SIGNAL(disconnected()),
            clientConnection, SLOT(deleteLater()));

    QString currTime = QTime::currentTime().toString("hh:mm:ss");
    QString text = QString("Client Connection (%1)").arg(currTime);

                   ui->connMsgEdit->append(text);
    QByteArray message = QByteArray("Hello Client ~ ");
    clientConnection->write(message);
    clientConnection->disconnectFromHost();
}

Widget::~Widget()
{
    delete ui;
}

