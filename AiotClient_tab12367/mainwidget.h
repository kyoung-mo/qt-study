#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <tab1devicecontrol.h>
#include <tab2socketclient.h>
#include <tab3controlpannel.h>
#include <tab6webcamera.h>
#include <tab7camopencv.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget() override;

private:
    Ui::MainWidget *ui;
    Tab1DeviceControl *pTab1DeviceControl;
    Tab2SocketClient *pTab2SocketClient;
    Tab3ControlPannel *pTab3ControlPannel;
    Tab6WebCamera *pTab6WebCamera;
    Tab7CamOpencv *pTab7CamOpencv;
};
#endif // MAINWIDGET_H
