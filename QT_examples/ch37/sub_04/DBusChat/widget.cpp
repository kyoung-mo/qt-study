#include "widget.h"
#include "./ui_widget.h"
#include <QInputDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    auto newNickname = QInputDialog::getText(this,
                                             tr("Set nickname"),
                                             tr("New nickname:"));
    if(newNickname.isEmpty())
    {
        deleteLater();
    }
    else
    {
        this->show();

        m_dbusChat = new DBusChat(this);
        m_dbusChat->newConnection(newNickname, "joins the chat.");

        connect(m_dbusChat, &DBusChat::uiDisplayMessage,
                this, [this](const QString &text) {

            m_msgList.append(text);

            auto history = m_msgList.join(QLatin1String("\n"));
            ui->textBrowser->setPlainText(history);
        });

        connect(ui->pbtSend, &QPushButton::clicked, this, [this]() {
            m_dbusChat->newMessage(ui->lineEdit->text().trimmed());
        });
    }
}

Widget::~Widget()
{
    delete ui;
}

