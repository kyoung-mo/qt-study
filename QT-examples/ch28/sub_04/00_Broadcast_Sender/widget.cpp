#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    udpSocket = new QUdpSocket(this);
    msgNumber = 1;

    connect(ui->startButton, SIGNAL(clicked()),
            this, SLOT(startButton()));

    connect(timer, SIGNAL(timeout()),
            this, SLOT(broadcastSend()));
}

void Widget::startButton()
{
    if(!timer->isActive())
        timer->start(1000);
}

void Widget::broadcastSend()
{
    ui->sendMsg->setText(QString("Send message %1").arg(msgNumber));

    QByteArray datagram = "Broadcast number "
                            + QByteArray::number(msgNumber);
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress::Broadcast, 35000);
    msgNumber++;
}

Widget::~Widget()
{
    delete ui;
}
