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

private:
    Ui::Widget *ui;

    QUdpSocket m_socket;
    QProtobufSerializer m_serializer;

    void send(const QByteArray &data);

private slots:
    void slot_pbtSend();
};
#endif // WIDGET_H
