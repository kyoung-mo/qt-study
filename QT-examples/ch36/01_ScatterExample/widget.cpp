#include "widget.h"
#include <QtDataVisualization>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    window()->setMinimumSize(600, 400);

    QScatter3DSeries *series = new QScatter3DSeries;
    QScatterDataArray data;
    data << QVector3D(0.5f, 0.5f, 0.5f)
         << QVector3D(-0.3f, -0.5f, -0.4f)
         << QVector3D(0.0f, -0.3f, 0.2f);

    Q3DScatter *scatter = new Q3DScatter;

    scatter->scene()->activeCamera()->setCameraPreset(
                                             Q3DCamera::CameraPresetFront);
    series->dataProxy()->addItems(data);
    scatter->addSeries(series);

    QHBoxLayout *hLay = new QHBoxLayout();
    hLay->addWidget(QWidget::createWindowContainer(scatter));
    setLayout(hLay);
}

Widget::~Widget()
{
}

