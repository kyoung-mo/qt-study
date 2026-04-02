#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProtobufSerializer>
#include <QUdpSocket>

namespace  my::employee {
class EmployeeInfo;
}

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void receive();

private:
    Ui::Widget *ui;

    QUdpSocket m_client;
    QProtobufSerializer m_serializer;

    void display(const QtProtobuf::int32,
                 const QString &,
                 const QString &);
};
#endif // WIDGET_H
