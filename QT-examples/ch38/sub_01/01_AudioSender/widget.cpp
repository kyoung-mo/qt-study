#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->volSlider,    &QSlider::valueChanged,
            this,             &Widget::volSliderChanged);
    connect(ui->pbtSendStart, &QPushButton::clicked,
            this,             &Widget::sendStartBtn);
    connect(ui->pbtSendStop,  &QPushButton::clicked,
            this,             &Widget::sendStopBtn);

    ui->volSlider->setEnabled(false);
    ui->pbtSendStop->setEnabled(false);

    audioInitialize();
}

void Widget::audioInitialize()
{
    m_devices = new QMediaDevices(this);

    devList = m_devices->audioInputs();
    for(int i = 0; i < devList.size(); ++i) {
        ui->comboDevList->addItem(devList.at(i).description());
    }

    mDevInfo = devList.at(ui->comboDevList->currentIndex());

    mFormat.setSampleRate(8000);
    mFormat.setChannelCount(1);

    mFormat.setSampleFormat(QAudioFormat::Int16);

    mAudioInput = new QAudioInput(mDevInfo, this);
    mInputVolume = ui->volSlider->value();
    ui->volLabel->setText(QString("%1 %").arg(mInputVolume));

    mBuffer = QByteArray(14096, 0);
}

void Widget::volSliderChanged(int val)
{
    mInputVolume = val;
    ui->volLabel->setText(QString("%1 %").arg(mInputVolume));
    mAudioInput->setVolume(qreal(mInputVolume) / 100);
}

void Widget::sendStartBtn()
{
    mDevInfo = devList.at(ui->comboDevList->currentIndex());
    mAudioInput = new QAudioInput(mDevInfo, this);

    mAudioInput->setVolume(qreal(mInputVolume) / 100);

    m_audioSource = new QAudioSource(mDevInfo, mFormat);
    m_audioSource->setBufferSize(200);

    connect(m_audioSource, SIGNAL(stateChanged(QAudio::State)),
            this,          SLOT(stateChanged(QAudio::State)));

    mInput = m_audioSource->start();
    connect(mInput, SIGNAL(readyRead()), this, SLOT(readMore()));
}

void Widget::sendStopBtn()
{
    if(mInput != nullptr) {
        disconnect(mInput, nullptr, this, nullptr);
        mInput = nullptr;
    }

    m_audioSource->stop();
}

void Widget::stateChanged(QAudio::State state)
{
    if( state == QAudio::IdleState || state == QAudio::ActiveState )
    {
        ui->volSlider->setEnabled(true);
        ui->pbtSendStart->setEnabled(false);
        ui->pbtSendStop->setEnabled(true);
    }
    else if(state == QAudio::StoppedState)
    {
        ui->volSlider->setEnabled(false);
        ui->pbtSendStart->setEnabled(true);
        ui->pbtSendStop->setEnabled(false);
    }
}

void Widget::readMore()
{
    if(!mAudioInput)
        return;

    qint64 len = m_audioSource->bytesAvailable();
    if(len > 4096) len = 4096;

    qint64 readLen = mInput->read(mBuffer.data(), len);
    if(readLen > 0) {
        mUdpSocket.writeDatagram(mBuffer.data(),
                                 len,
                                 QHostAddress::LocalHost,
                                 15000);
    }
}

Widget::~Widget()
{
    delete ui;
}

