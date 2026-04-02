#include "widget.h"
#include <QtDataVisualization>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    window()->setMinimumSize(600, 400);

    Q3DSurface *surface = new Q3DSurface();
    QSurfaceDataArray *data = new QSurfaceDataArray;

    QSurfaceDataRow *dataRow1 = new QSurfaceDataRow;

    *dataRow1 << QVector3D(0.0f, 0.1f, 0.5f)
              << QVector3D(1.0f, 0.5f, 0.5f);

    QSurfaceDataRow *dataRow2 = new QSurfaceDataRow;

    *dataRow2 << QVector3D(0.0f, 1.8f, 1.0f)
              << QVector3D(1.0f, 1.2f, 1.0f);

    *data << dataRow1 << dataRow2;

    QSurface3DSeries *series = new QSurface3DSeries;
    series->dataProxy()->resetArray(data);
    surface->addSeries(series);

    QHBoxLayout *hLay = new QHBoxLayout();
    hLay->addWidget(QWidget::createWindowContainer(surface));
    setLayout(hLay);
}

Widget::~Widget()
{
}
