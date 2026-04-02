#include <QApplication>
#include <QDebug>

#include "dbuschat.h"
#include "dbuschat_adaptor.h"
#include "dbuschat_interface.h"

DBusChat::DBusChat(QObject *parent)
    : QObject{parent}
{
    qDebug() << Q_FUNC_INFO;

    new DBusChatAdaptor(this);

    auto connection = QDBusConnection::sessionBus();
    connection.registerObject("/", this);

    using local::DBusChat;

    auto *iface = new DBusChat({}, {}, connection, this);

    connect(iface, &DBusChat::message, this, [this](const QString &nickname, const QString &text) {
        displayMessage(tr("<%1> %2").arg(nickname, text));
    });

    connect(iface, &DBusChat::action, this, [this](const QString &nickname, const QString &text) {
        displayMessage(tr("* %1 %2").arg(nickname, text));
    });
}

void DBusChat::displayMessage(const QString &message)
{
    emit uiDisplayMessage(message);
}

void DBusChat::newConnection(const QString &nickname, const QString &text)
{
    m_nickname = nickname;

    emit action(nickname, text);
}

void DBusChat::newMessage(const QString &text)
{
    emit message(m_nickname, text);
}



















