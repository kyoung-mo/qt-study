#include "tab3controlpannel.h"
#include "ui_tab3controlpannel.h"

Tab3ControlPannel::Tab3ControlPannel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab3ControlPannel)
{
    ui->setupUi(this);
    paletteOn.setColor(ui->pPBlamp->backgroundRole(),QColor(255,0,0));
    paletteOff.setColor(ui->pPBlamp->backgroundRole(),QColor(0,0,255));
    ui->pPBlamp->setPalette(paletteOff);
    ui->pPBplug->setPalette(paletteOff);
}

Tab3ControlPannel::~Tab3ControlPannel()
{
    delete ui;
}

void Tab3ControlPannel::on_pPBlamp_clicked(bool checked)
{
    if(checked)
    {
        ui->pPBlamp->setChecked(true);
        emit socketSendDataSig("[KYM_LIN]LAMPON");
        ui->pPBlamp->setPalette(paletteOn);
    }
    else
    {
        ui->pPBlamp->setChecked(false);
        emit socketSendDataSig("[KYM_LIN]LAMPOFF");
        ui->pPBlamp->setPalette(paletteOff);
    }

}

void Tab3ControlPannel::on_pPBplug_clicked(bool checked)
{
    if(checked)
    {
        ui->pPBplug->setChecked(true);
        emit socketSendDataSig("[HM_CON]GASON");

        ui->pPBplug->setPalette(paletteOn);
    }
    else
    {
        ui->pPBplug->setChecked(false);
        emit socketSendDataSig("[HM_CON]GASOFF");
        ui->pPBplug->setPalette(paletteOff);
    }
}

void Tab3ControlPannel::tab3RecvDataSlot(QStringList& recvData)
{
    if(recvData[2] == "LAMPON")
    {
        ui->pPBlamp->setChecked(true);
        ui->pPBlamp->setPalette(paletteOn);
    }
    else if(recvData[2] == "LAMPOFF")
    {
        ui->pPBlamp->setChecked(false);
        ui->pPBlamp->setPalette(paletteOff);
    }
    else if(recvData[2] == "GASON")
    {
        ui->pPBplug->setChecked(true);
        ui->pPBplug->setPalette(paletteOn);
    }
    else if(recvData[2] == "GASOFF")
    {
        ui->pPBplug->setChecked(false);
        ui->pPBplug->setPalette(paletteOff);
    }
}
