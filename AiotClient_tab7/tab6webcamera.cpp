#include "tab6webcamera.h"
#include "ui_tab6webcamera.h"

Tab6WebCamera::Tab6WebCamera(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab6WebCamera)
{
    ui->setupUi(this);
    webcamUrl=QUrl("heep://10.10.16.35:8080/?action=stream");
    webcamUrl.setUserName("user");
    webcamUrl.setPassword("1234");
    pQProcess = new QProcess(this);
    pQWebEngineView = new QWebEngineView(this);

    QPixmap pixMap(":/Images/Images/background.jpg");
    QGraphicsScene* scene = new QGraphicsScene(ui->pGPView);
    scene->addPixmap(pixMap);
    ui->
}

Tab6WebCamera::~Tab6WebCamera()
{
    delete ui;
}
