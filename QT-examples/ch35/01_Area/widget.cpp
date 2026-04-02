#include "widget.h"
#include <QtCharts>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    window()->setMinimumSize(600, 400);

    QLineSeries *series1 = new QLineSeries();

    *series1 << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6)
             << QPointF(9, 7) << QPointF(12, 6) << QPointF(16, 7)
             << QPointF(18, 5);

    QLineSeries *series2 = new QLineSeries();

    *series2 << QPointF(1, 3) << QPointF(3, 4) << QPointF(7, 3)
             << QPointF(12, 3) << QPointF(16, 4);

    QAreaSeries *series = new QAreaSeries(series1, series2);
    series->setName("Area Data");

    QPen pen(Qt::blue); // Applying a outline
    pen.setWidth(3);
    series->setPen(pen);
    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
    gradient.setColorAt(0.0, 0x3cc63c);
    gradient.setColorAt(1.0, 0x26f626);
    series->setBrush(gradient); // Applying a gradient

    QChart *chart = new QChart();
    chart->legend()->hide();  // Hiding legend
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Area chart");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QHBoxLayout *hLay = new QHBoxLayout();
    hLay->addWidget(chartView);
    setLayout(hLay);
}

Widget::~Widget()
{
}

