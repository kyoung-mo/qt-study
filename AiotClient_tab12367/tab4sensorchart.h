#ifndef TAB4SENSORCHART_H
#define TAB4SENSORCHART_H

#include <QWidget>
#include <QChartView>
#include <QLineSeries>
#include <QDateTimeAxis>
#include <QDate>
#include <QTime>


namespace Ui {
class Tab4SensorChart;
}

class Tab4SensorChart : public QWidget
{
    Q_OBJECT

public:
    explicit Tab4SensorChart(QWidget *parent = nullptr);
    ~Tab4SensorChart();
    void updateLastDateTime(bool bFlag);


private slots:
    void tab4RecvDataSlot(QStringList&);

private:
    Ui::Tab4SensorChart *ui;
    QLineSeries * illuLine;
    QLineSeries * humiLine;
    QLineSeries * tempLine;
    QChart* pQChart;
    QChartView *pQChartView;
    QDateTimeAxis *pQDateTimeAxis;
    QDateTime firstDateTime;
    QDateTime lastDateTime;
};


#endif // TAB4SENSORCHART_H
