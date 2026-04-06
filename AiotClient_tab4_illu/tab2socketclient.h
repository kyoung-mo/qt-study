#ifndef TAB2SOCKETCLIENT_H
#define TAB2SOCKETCLIENT_H

#include <QWidget>
#include <QTime>
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

private slots:
    void on_pPBserverConnect_clicked(bool checked);
    void updateRecvDataSlot(QString);
    void on_pPBsend_clicked();

public slots:
    void socketWriteDataSlot(QString);

private:
    Ui::Tab2SocketClient *ui;
    SocketClient *pSocketClient;

signals:
    void tab1RecvDataSig(QStringList&);
    void tab3RecvDataSig(QStringList&);
    void tab4RecvDataSig(QStringList&);
    void tab6RecvDataSig(QStringList&);
};

#endif // TAB2SOCKETCLIENT_H
