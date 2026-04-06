#include "tab2socketclient.h"
#include "ui_tab2socketclient.h"

Tab2SocketClient::Tab2SocketClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab2SocketClient)
{
    ui->setupUi(this);
    pSocketClient = new SocketClient(this);
    ui->pPBsend->setEnabled(false);

    connect(pSocketClient, SIGNAL(socketRecvDataSig(QString)), this, SLOT(updateRecvDataSlot(QString)));

}

Tab2SocketClient::~Tab2SocketClient()
{
    delete ui;
}

void Tab2SocketClient::on_pPBserverConnect_clicked(bool checked)
{
    bool bFlag;
    if(checked)
    {
        pSocketClient->connectToServerSlot(bFlag);
        if(bFlag)
        {
            ui->pPBserverConnect->setText("서버해제");
            ui->pPBsend->setEnabled(true);
        }
        else
            ui->pPBserverConnect->setChecked(false);
    }
    else
    {
        pSocketClient->socketClosedServerSlot();
        ui->pPBserverConnect->setText("서버연결");
        ui->pPBsend->setEnabled(false);
    }
}
void Tab2SocketClient::updateRecvDataSlot(QString strRecvData)
{
    strRecvData.chop(1);    //'\n' remove
    QTime time = QTime::currentTime();
    QString strTime = time.toString();
    strTime = strTime + " " + strRecvData;
    ui->pTErecvData->append(strTime);

    //[KSH_LIN]LAMPON@ARG1@ARG@
    strRecvData.replace("[","@");
    strRecvData.replace("]","@");
    QStringList strList = strRecvData.split("@");
    //strList[0] ="",
    //strList[1] = "KSH_LIN",
    //strList[2] = "LAMPON"

    if(strList[2] == "KEY")
        emit tab1RecvDataSig(strList);
    else if((strList[2].indexOf("LAMP") == 0) || (strList[2].indexOf("GAS") == 0))
        emit tab3RecvDataSig(strList);
    else if(strList[2] == "SNAPSHOT")
        emit tab6RecvDataSig(strList);
}

void Tab2SocketClient::on_pPBsend_clicked()
{
    QString strRecvId = ui->pLErecvId->text();
    QString strSendData = ui->pLEsendData->text();
    if(strSendData.isEmpty())
        return;
    if(strRecvId.isEmpty())
        strSendData = "[ALLMSG]" + strSendData;
    else
        strSendData = "["+strRecvId+"]" + strSendData;

    pSocketClient->socketWriteDataSlot(strSendData);
    ui->pLEsendData->clear();

}
void Tab2SocketClient::socketWriteDataSlot(QString strSendData)
{
    pSocketClient->socketWriteDataSlot(strSendData);
}
