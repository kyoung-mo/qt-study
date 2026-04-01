#ifndef DBUSCHAT_H
#define DBUSCHAT_H

#include <QObject>

class DBusChat : public QObject
{
    Q_OBJECT
public:
    explicit DBusChat(QObject *parent = nullptr);
    void newConnection(const QString &nickname, const QString &text);
    void newMessage(const QString &text);

signals:
    void message(const QString &nickname, const QString &text);
    void action(const QString &nickname, const QString &text);

    void uiDisplayMessage(const QString &text);

private:
    QString m_nickname;
    void displayMessage(const QString &message);
};

#endif // DBUSCHAT_H

