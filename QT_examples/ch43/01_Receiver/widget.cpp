#include "widget.h"
#include "ui_widget.h"

#include <QNetworkDatagram>
#include <QDebug>

#include "employee.qpb.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Q_ASSERT_X(m_client.bind(QHostAddress::LocalHost, 61122),
               "Receiver",
               "Unable to bind to port 61122");

    QObject::connect(&m_client, &QUdpSocket::readyRead,
                     this,      &Widget::receive);
}

void Widget::receive()
{
    while (m_client.hasPendingDatagrams())
    {
        const auto datagram = m_client.receiveDatagram();

        my::employee::EmployeeInfo eInfo;
        eInfo.deserialize(&m_serializer, datagram.data());

        if(m_serializer.deserializationError()
                     == QAbstractProtobufSerializer::NoError)
        {
            QtProtobuf::int32 tNum    = eInfo.num();
            QString           tName   = eInfo.name();
            QString           tDepart = eInfo.department();

            display(tNum, tName, tDepart);
        }
    }
}

void Widget::display(const QtProtobuf::int32 vNum,
                     const QString &vName,
                     const QString &vDepartment)
{
    QString strNum          = QString("%1").arg(vNum);
    QString strName         = QString("%1").arg(vName);
    QString strDepartment   = QString("%1").arg(vDepartment);

    ui->leNum->setText(strNum);
    ui->leName->setText(strName);
    ui->lePart->setText(strDepartment);
}

Widget::~Widget()
{
    delete ui;
}

