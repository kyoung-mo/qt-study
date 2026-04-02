#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>
#include <QWidget>

#include <QtNetwork/QTcpServer>

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
    QTcpServer *tcpServer;

    void initialize();

private slots:
    void newConnection();

};
#endif // WIDGET_H
