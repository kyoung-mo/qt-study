#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    audioInitialize();
    networkInitialize();

    connect(ui->comboDevList, SIGNAL(currentIndexChanged(int)),
            this,             SLOT(devListIndexChanged(int)));
    connect(ui->volSlider,    &QSlider::valueChanged,
            this,             &Widget::volSliderChanged);
}

void Widget::audioInitialize()
{
    m_devices = new QMediaDevices(this);
    mDevList = m_devices->audioOutputs();

    for(int i = 0; i < mDevList.size(); ++i)
        ui->comboDevList->addItem(mDevList.at(i).description());

    mDevInfo = mDevList.at(ui->comboDevList->currentIndex());

    mFormat.setSampleRate(8000);
    mFormat.setChannelCount(1);
    mFormat.setSampleFormat(QAudioFormat::Int16);

    mAudioOutput = new QAudioSink(mDevInfo, mFormat, this);

    mOutput = mAudioOutput->start();

    mOutputVolume = ui->volSlider->value() / 100.0;
    ui->volLabel->setText(QString("%1 %")
                              .arg(ui->volSlider->value()));

    mAudioOutput->setVolume(mOutputVolume);
}

void Widget::networkInitialize()
{
    mUdpSocket = new QUdpSocket(this);
    mUdpSocket->bind(QHostAddress::LocalHost, 15000);

    connect(mUdpSocket, SIGNAL(readyRead()),
            this,       SLOT(readUdpData()));
}

void Widget::devListIndexChanged(int index)
{
    mDevInfo = mDevList.at(index);

    if(mOutput != nullptr) {
        disconnect(mOutput, nullptr, this, nullptr);
        mOutput = nullptr;
    }

    mAudioOutput->stop();
    mAudioOutput->disconnect(this);
    delete mAudioOutput;

    mAudioOutput = new QAudioSink(mDevInfo, mFormat, this);
    mAudioOutput->setVolume(mOutputVolume);

    mOutput = mAudioOutput->start();

}

void Widget::volSliderChanged(int val)
{
    mOutputVolume = val / 100.0;
    mAudioOutput->setVolume(mOutputVolume);

    ui->volLabel->setText(QString("%1 %").arg(val));

}

void Widget::readUdpData()
{
    while (mUdpSocket->hasPendingDatagrams())
    {
        QNetworkDatagram datagram;
        datagram = mUdpSocket->receiveDatagram();

        QByteArray audioData = datagram.data();
        audioOutputProcess(audioData);
    }
}

void Widget::audioOutputProcess(const QByteArray &ba)
{
    qint64 len = ba.size();
    if(len > 0) {
        mOutput->write(ba.data(), ba.size());
    }
}

Widget::~Widget()
{
}

