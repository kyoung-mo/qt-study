#include "widget.h"
#include "./ui_widget.h"

#include <QDateTime>
#include <QGeoCoordinate>
#include <QGeoPositionInfo>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pbtCalc, &QPushButton::clicked,
            this,        &Widget::slotCalculation);
}

void Widget::slotCalculation()
{
    double lat1    = ui->leLat1->text().toDouble();
    double long1   = ui->leLong1->text().toDouble();

    double lat2    = ui->leLat2->text().toDouble();
    double long2   = ui->leLong2->text().toDouble();

    QGeoCoordinate coord1(lat1, long1);
    QGeoCoordinate coord2(lat2, long2);

    int distance_meter = coord1.distanceTo(coord2);
    QString distanceStr = QString("%L1").arg(distance_meter);

    ui->leResult->setText(distanceStr);
}

Widget::~Widget()
{
    delete ui;
}

