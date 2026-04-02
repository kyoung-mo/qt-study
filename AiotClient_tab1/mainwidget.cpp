#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    pTab1DeviceControl = new Tab1DeviceControl(ui->pTab1);
    ui->pTab1->setLayout(pTab1DeviceControl->layout());

    ui->tabWidget->setCurrentIndex(0);

    pTab2SocketClient = new Tab2SocketClient(ui->pTab2);
    ui->pTab2->setLayout(pTab2SocketClient->layout());

    ui->tabWidget->setCurrentIndex(1);

    pTab3ControlPannel = new Tab3ControlPannel(ui->pTab3);
    ui->pTab3->setLayout(pTab3ControlPannel->layout());

    ui->tabWidget->setCurrentIndex(2);

    connect(pTab3ControlPannel, SIGNAL(socketSendDataSig(QString)),pTab2SocketClient,SLOT(socketWriteDataSlot(QString)));
    connect(pTab2SocketClient, SIGNAL(tab3RecvDataSig(QStringList&)), pTab3ControlPannel, SLOT(tab3RecvDataSlot(QStringList&)));

}

MainWidget::~MainWidget()
{
    delete ui;
}
