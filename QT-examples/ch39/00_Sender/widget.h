#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>


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

    struct SerialSettings {
        QString portName;
        qint32 baudRate;
        QSerialPort::DataBits dataBits;
        QSerialPort::Parity parity;
        QSerialPort::StopBits stopBits;
        QSerialPort::FlowControl flowControl;
    };

    SerialSettings m_serialSettings;
    QSerialPort *m_serial = nullptr;

private slots:
    void connectButton();
    void sendButton();
};
#endif // WIDGET_H
