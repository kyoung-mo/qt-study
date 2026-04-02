#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtMultimedia>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    QMediaDevices       *m_devices = nullptr;
    QList<QAudioDevice>  devList;
    QAudioFormat         mFormat;
    QAudioDevice         mDevInfo;

    QAudioInput         *mAudioInput = nullptr;
    QAudioSource        *m_audioSource = nullptr;

    QIODevice           *mInput;
    QByteArray           mBuffer;
    int                  mInputVolume;

    QUdpSocket           mUdpSocket;
    void audioInitialize();

private slots:
    void volSliderChanged(int val);
    void sendStartBtn();
    void sendStopBtn();

    void stateChanged(QAudio::State state);
    void readMore();
};

#endif // WIDGET_H
