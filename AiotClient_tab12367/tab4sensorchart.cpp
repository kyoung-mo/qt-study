#include "tab4sensorchart.h"
#include "ui_tab4sensorchart.h"

Tab4SensorChart::Tab4SensorChart(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab4SensorChart)
{
    ui->setupUi(this);
    illuLine=new QLineSeries(this);
    illuLine->setName("조도");

    QPen pen_r,pen_g,pen_b;
    pen_r.setWidth(2);
    pen_r.setBrush(Qt::red);
    pen_r.setCapStyle(Qt::FlatCap);
    pen_r.setJoinStyle(Qt::MiterJoin);
    illuLine->setPen(pen_r);

    pQChart = new QChart();
    pQChart ->addSeries(illuLine);


    tempLine=new QLineSeries(this);
    tempLine->setName("온도");

    pen_b.setBrush(Qt::blue);
    pen_b.setCapStyle(Qt::FlatCap);
    pen_b.setJoinStyle(Qt::MiterJoin);
    humiLine->setPen(pen_b);

    pQChart = new QChart();
    pQChart ->addSeries(humiLine);


    humiLine=new QLineSeries(this);
    humiLine->setName("습도");

    pen_g.setBrush(Qt::green);
    pen_g.setCapStyle(Qt::FlatCap);
    pen_g.setJoinStyle(Qt::MiterJoin);
    tempLine->setPen(pen_g);

    pQChart = new QChart();
    pQChart ->addSeries(tempLine);


    pQChart->createDefaultAxes();
    pQChart->axes(Qt::Vertical).constFirst()->setRange(0,100);

    pQChartView = new QChartView(pQChart);
    pQDateTimeAxis = new QDateTimeAxis;
    pQDateTimeAxis->setFormat("hh:mm");

    updateLastDateTime(false);

    ui->pChartViewLayout->layout()->addWidget(pQChartView);
    pQChartView->chart()->setAxisX(pQDateTimeAxis, illuLine);
    pQChartView->chart()->setAxisX(pQDateTimeAxis, humiLine);
    pQChartView->chart()->setAxisX(pQDateTimeAxis, tempLine);

//    illuLine->append(0.25, 50);
//    illuLine->append(0.5, 75);
//    illuLine->append(0.7, 40);

}

Tab4SensorChart::~Tab4SensorChart()
{
    delete ui;
}

void Tab4SensorChart::updateLastDateTime(bool bFlag)
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    firstDateTime.setDate(date);
    firstDateTime.setTime(time);
    lastDateTime.setDate(date);
    lastDateTime.setTime(time.addSecs(60*1));
    pQDateTimeAxis->setRange(firstDateTime, lastDateTime);

}

void Tab4SensorChart::tab4RecvDataSlot(QStringList& strList)
{
    qDebug() << strList[2];
    qDebug() << strList[3];

    QDateTime dateTime = QDateTime::currentDateTime();

    QString strIllu = strList[3];

    illuLine->append(dateTime.toMSecsSinceEpoch(), strIllu.toInt());
}