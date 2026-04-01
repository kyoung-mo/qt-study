
#include "widget.h"
#include <QDate>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QDate dt1 = QDate(2023, 1, 1);
    QDate dt2 = QDate::currentDate();

    dateEdit[0] = new QDateEdit(dt1.addYears(2), this);
    dateEdit[0]->setGeometry(10, 10, 140, 40);

    dateEdit[1] = new QDateEdit(dt1.addMonths(3), this);
    dateEdit[1]->setGeometry(160, 10, 140, 40);

    dateEdit[2] = new QDateEdit(dt1.addDays(10), this);
    dateEdit[2]->setGeometry(310, 10, 140, 40);

    dateEdit[3] = new QDateEdit(dt2, this);
    dateEdit[3]->setGeometry(10, 60, 140, 40);

    // 1:mon, 2:tue, 3:wed, 4:thur, 5:fri, 6:sat, 7:sun
    qDebug("Day of year : %d", dt1.dayOfYear());
    qDebug("End Day : %d", dt1.daysInMonth());
    qDebug("End Day : %d", dt1.daysInYear());

    QDate dt3 = QDate::fromString("2002.06.26", "yyyy.MM.dd");
    QDate dt4 = QDate::fromString("06.26", "MM.dd");

    lbl[0] = new QLabel(dt3.toString(), this);
    lbl[0]->setGeometry(10,110, 150, 30);
    lbl[1] = new QLabel(dt4.toString(), this);
    lbl[1]->setGeometry(10,150, 150, 30);

    if(QDate::isValid(2011, 6, 27))
    {
        qDebug("2013.6.27 true");
    }
    else
    {
        qDebug("2013.6.27 false");
    }
}

Widget::~Widget()
{

}















