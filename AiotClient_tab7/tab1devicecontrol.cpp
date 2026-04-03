#include "tab1devicecontrol.h"
#include "ui_tab1devicecontrol.h"

Tab1DeviceControl::Tab1DeviceControl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab1DeviceControl)
{
    ui->setupUi(this);
    int keyCount = ui->gridLayout->rowCount() * ui->gridLayout->columnCount();
    lcdDataKey = 0;
    pQTimer = new QTimer(this);
    pQButtonGroup = new QButtonGroup(this);
    for(int i=0;i<ui->gridLayout->rowCount();i++)
    {
        for(int j=0;j<ui->gridLayout->columnCount();j++)
        {
            pQCheckBox[--keyCount] = dynamic_cast<QCheckBox*>(ui->gridLayout->itemAtPosition(i,j)->widget());
        }
    }
    pQButtonGroup->setExclusive(false);
    keyCount = ui->gridLayout->rowCount() * ui->gridLayout->columnCount();
    for(int i=0;i<keyCount;i++)
        pQButtonGroup->addButton(pQCheckBox[i],i+1);

    connect(pQButtonGroup, SIGNAL(idClicked(int)) , this , SLOT(updateCheckBoxSlot(int)));
    connect(pQTimer, SIGNAL(timeout()), this, SLOT(updateDialValueSlot()));
    connect(ui->pCBtimerValue, SIGNAL(currentTextChanged(QString)), this, SLOT(updateComboSlot(QString)));
    connect(ui->pPBtimerStart, SIGNAL(clicked(bool)), this, SLOT(timerStartSlot(bool)));
}

Tab1DeviceControl::~Tab1DeviceControl()
{
    delete ui;
}

void Tab1DeviceControl::on_pPBquit_clicked()
{
    qApp->exit();
}

void Tab1DeviceControl::timerStartSlot(bool bFlag)
{
    // if(ui->pPBtimerStart->isChecked())
    //     ui->pPBtimerStart->setText("TmierStop");
    // else
    //     ui->pPBtimerStart->setText("TmierStart");
    if(bFlag)
    {
//        qDebug() << ui->pPBtimerStart->text();
        QString strValue = ui->pCBtimerValue->currentText();
        pQTimer->start(strValue.toInt());
        ui->pPBtimerStart->setText("TmierStop");
    }
    else
    {
//        qDebug() << ui->pPBtimerStart->text();
        pQTimer->stop();
        ui->pPBtimerStart->setText("TmierStart");
    }
}

void Tab1DeviceControl::updateDialValueSlot()
{
    int dialValue = ui->pDialLed->value();
    dialValue++;
    if(dialValue > ui->pDialLed->maximum())
        dialValue = 0;
    ui->pDialLed->setValue(dialValue);

}
void Tab1DeviceControl::updateComboSlot(QString strValue)
{
    if(pQTimer->isActive())
    {
        pQTimer->stop();
        pQTimer->start(strValue.toInt());
    }
}
void Tab1DeviceControl::updateCheckBoxSlot(int keyNum)
{
//    qDebug() << keyNum;
    lcdDataKey = lcdDataKey ^ (0x01 << (keyNum - 1));
    ui->pLcdNumberKey->display(lcdDataKey);
}
void Tab1DeviceControl::on_pDialLed_valueChanged(int value)
{
    //[KYM_LIN]DIAL@255
    QString strData = "[KYM_LIN]DIAL@" + QString::number(value);
    emit socketSendDataSig(strData);
}

void Tab1DeviceControl::tab1RecvDataSlot(QStringList& strList)
{
    bool keyFlag;
    int keyNumber = strList[3].toInt();

    if(keyNumber < 1 || 8 < keyNumber)
        return;
    else
        keyNumber--;
    if(strList[4] == "ON")
        keyFlag = true;
    else
        keyFlag = false;

//    qDebug() << keyNumber;
//    qDebug() << keyFlag;
    pQCheckBox[keyNumber]->setChecked(keyFlag);
    updateCheckBoxSlot(++keyNumber);
}
