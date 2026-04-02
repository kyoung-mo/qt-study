#ifndef TAB2SOCKETCLIENT_H
#define TAB2SOCKETCLIENT_H

#include <QWidget>
#include <QTime>
#include <QString>
#include "socketclient.h"

namespace Ui {
class Tab2SocketClient;
}

class Tab2SocketClient : public QWidget
{
    Q_OBJECT

public:
    explicit Tab2SocketClient(QWidget *parent = nullptr);
    ~Tab2SocketClient();

private slots: //
    void on_pPBserverConnect_clicked(bool checked);
    void updateRecvDataSlot(QString strRecvData);
    void on_pPBsend_clicked();

public slots:
    void socketWriteDataSlot(QString);
    void socketWriteKeyDataSig(QString);

private:
    Ui::Tab2SocketClient *ui;
    SocketClient *pSocketClient;

signals:
    void tab3RecvDataSig(QStringList&);
    void tab1SendKeyData(QStringList&);
};


#endif // TAB2SOCKETCLIENT_H
