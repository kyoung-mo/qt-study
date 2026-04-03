#ifndef TAB1DEVICECONTROL_H
#define TAB1DEVICECONTROL_H

#include <QWidget>
#include <QTimer>
#include <QDial>
#include <QComboBox>
#include <QLCDNumber>
#include <QProgressBar>
#include <QCheckBox>
#include <QButtonGroup>
#include <QDebug>

namespace Ui {
class Tab1DeviceControl;
}

class Tab1DeviceControl : public QWidget
{
    Q_OBJECT

public:
    explicit Tab1DeviceControl(QWidget *parent = nullptr);
    ~Tab1DeviceControl();

private slots:
    void on_pPBquit_clicked();
    void timerStartSlot(bool);
    void updateDialValueSlot();
    void updateComboSlot(QString);
    void updateCheckBoxSlot(int);
    void on_pDialLed_valueChanged(int value);

public slots:
    void tab1RecvDataSlot(QStringList&);

private:
    Ui::Tab1DeviceControl *ui;
    QTimer *pQTimer;
    QCheckBox *pQCheckBox[8];
    QButtonGroup *pQButtonGroup;
    unsigned char lcdDataKey;

signals:
    void socketSendDataSig(QString);
};

#endif // TAB1DEVICECONTROL_H
