#include "widget.h"
#include "ui_widget.h"
#include <QNetworkDatagram>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    groupAddress4 = QHostAddress(QStringLiteral("239.255.43.21"));
    groupAddress6 = QHostAddress(QStringLiteral("ff12::2115"));

    udpSocket4.bind(QHostAddress::AnyIPv4, 45000,
                    QUdpSocket::ShareAddress);
    udpSocket4.joinMulticastGroup(groupAddress4);

    if (!udpSocket6.bind(QHostAddress::AnyIPv6, 45000,
                         QUdpSocket::ShareAddress) ||
        !udpSocket6.joinMulticastGroup(groupAddress6))
        qDebug() << Q_FUNC_INFO << "IPv4 Multicast only.";

    connect(&udpSocket6, &QUdpSocket::readyRead,
            this,        &Widget::readDatagrams);
}

void Widget::readDatagrams()
{
    QByteArray datagram;

    while (udpSocket4.hasPendingDatagrams()) {
        datagram.resize(int(udpSocket4.pendingDatagramSize()));
        udpSocket4.readDatagram(datagram.data(), datagram.size());
        ui->recvMsg->setText(tr("IPv4 received datagram : \"%1\"")
                                 .arg(datagram.constData()));
    }

    while (udpSocket6.hasPendingDatagrams()) {
        QNetworkDatagram dgram = udpSocket6.receiveDatagram();
        ui->recvMsg->setText(ui->recvMsg->text() +
                             tr("\nIPv6 received datagram : \"%1\"")
                                 .arg(dgram.data().constData()));
    }
}

Widget::~Widget()
{
    delete ui;
}

