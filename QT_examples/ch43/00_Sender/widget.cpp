#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

#include "employee.qpb.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pbtSend, &QPushButton::clicked, this, &Widget::slot_pbtSend);
}

void Widget::send(const QByteArray &data)
{
    if (m_socket.writeDatagram(data, QHostAddress::LocalHost, 61122) == -1) {
        qWarning() << "Unable to send data of size: "
                   << data.size()
                   << "to UDP port 61122";
    }
}

void Widget::slot_pbtSend()
{
    my::employee::EmployeeInfo eInfo;

    QtProtobuf::int32 tNum    = ui->leNum->text().toInt();
    QString           tName   = ui->leName->text();
    QString           tDepart = ui->lePart->text();

    eInfo.setNum(tNum);
    eInfo.setName(tName);
    eInfo.setDepartment(tDepart);

    QByteArray sendData = eInfo.serialize(&m_serializer);
    send(sendData);
}

Widget::~Widget()
{
    delete ui;
}

