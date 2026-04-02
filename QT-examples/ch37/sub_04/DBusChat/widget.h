#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "dbuschat.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void message(const QString &nickname, const QString &text);
    void action(const QString &nickname, const QString &text);

private:
    Ui::Widget *ui;
    DBusChat *m_dbusChat;

    QStringList m_msgList;
};
#endif // WIDGET_H
