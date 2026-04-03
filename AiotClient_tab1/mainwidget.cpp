#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    setWindowTitle("AiotClient");
    pTab1DeviceControl = new Tab1DeviceControl(ui->pTab1);
    ui->pTab1->setLayout(pTab1DeviceControl->layout());
    ui->tabWidget->setCurrentIndex(0);

    pTab2SocketClient = new Tab2SocketClient(ui->pTab2);
    ui->pTab2->setLayout(pTab2SocketClient->layout());
    ui->tabWidget->setCurrentIndex(1);

    pTab3ControlPannel = new Tab3ControlPannel(ui->pTab3);
    ui->pTab3->setLayout(pTab3ControlPannel->layout());
    ui->tabWidget->setCurrentIndex(2);

    pTab6CamViewer = new Tab6CamViewer(ui->pTab6);
    ui->pTab6->setLayout(pTab6CamViewer->layout());
    ui->tabWidget->setCurrentIndex(5);

    pTab7CamOpencv = new Tab7CamOpencv(ui->tabWidget);
    ui->tabWidget->setLayout(pTab7CamOpencv->layout());
    ui->tabWidget->setCurrentIndex(6);

    connect(pTab3ControlPannel, SIGNAL(socketSendDataSig(QString)),pTab2SocketClient,SLOT(socketWriteDataSlot(QString)));
    connect(pTab2SocketClient, SIGNAL(tab3RecvDataSig(QStringList&)), pTab3ControlPannel, SLOT(tab3RecvDataSlot(QStringList&)));

    connect(pTab7CamOpencv->getpWebCamThread(), SIGNAL(socketSendDataSig(QString)), pTab2SocketClient, SLOT(socketWriteDataSlot(QString)));

}

MainWidget::~MainWidget()
{
    delete ui;
}
