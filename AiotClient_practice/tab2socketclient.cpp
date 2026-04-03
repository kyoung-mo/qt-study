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
    connect(pSocketClient, SIGNAL(socketRecvDataSig(QString)), this, SLOT(socketWriteKeyDataSig(QString)));
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
            ui->pPBserverConnect->setText("서버 종료");
            ui->pPBsend->setEnabled(true);
        }
        else
            ui->pPBserverConnect->setChecked(false);
    }
    else
    {
        pSocketClient->socketClosedServerSlot();
        ui->pPBserverConnect->setText("서버 연결");
        ui->pPBsend->setEnabled(false);
    }
}

void Tab2SocketClient::updateRecvDataSlot(QString strRecvData)
{
    strRecvData.chop(1);  // '\n' remove
    QTime time = QTime::currentTime();
    QString strTime = time.toString();
    strTime = strTime + " " + strRecvData;
    ui->pTErecvData->append(strTime);
    // parsing
    // [KYM_LIN]LAMPON@ARG1@ARG@
    // [-> @ && ]-> @
    strRecvData.replace("[","@");
    strRecvData.replace("]","@");
    QStringList strList = strRecvData.split("@");
    //strList[0]="" ,
    //strList[1]=KYM_NIN" ,
    //strList[2]="LAMP_ON"

    //index return
    if((strList[2].indexOf("LAMP")==0) || (strList[2].indexOf("PLUG")==0))// L > index 0 return
        emit tab3RecvDataSig(strList);
}

void Tab2SocketClient::on_pPBsend_clicked()
{
    QString strRecvId = ui->pLErecvid->text();
    QString strSendData = ui->pLEsendData->text();
    if(strSendData.isEmpty())
    {
        return;
    }
    if(strRecvId.isEmpty()) {
        strSendData = "[ALLMSG]" + strSendData;}
    else {
        strSendData = "["+strRecvId+"]"+strSendData;
    }

    pSocketClient->socketWriteDataSlot(strSendData);
    ui->pLEsendData->clear();
}


void Tab2SocketClient::socketWriteDataSlot(QString strSendData)
{
    pSocketClient->socketWriteDataSlot(strSendData);
}

void Tab2SocketClient::socketWriteKeyDataSig(QString strSendData)
{
    strSendData.chop(1);  // '\n' remove

    // parsing
    // [KYM_LIN]KEY@ARG1@ARG2
    // [-> @ && ]-> @

    strSendData.replace("[","@");
    strSendData.replace("]","@");
    QStringList strList = strSendData.split("@");



    //index return
    //if((strList[2].indexOf("1")==0) || (strList[2].indexOf("2")==0))// L > index 0 return
    if(strList.size()<5) return;
    qDebug() << strList[3];
    qDebug() << strList[4];

    if(((strList[3].indexOf("1")==0) || (strList[3].indexOf("2")==0))||((strList[3].indexOf("3")==0) || (strList[3].indexOf("4")==0))||((strList[3].indexOf("5")==0) || (strList[3].indexOf("6")==0))||((strList[3].indexOf("7")==0) || (strList[3].indexOf("8")==0)))
    {
        if((strList[4].indexOf("ON")==0)||(strList[4].indexOf("OFF")==0))
        {
            emit tab1SendKeyData(strList);
        }
    }

}