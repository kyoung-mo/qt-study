#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_myUtil = new MyUtil();

    connect(ui->pbtResult, &QPushButton::clicked,
            this,          &Widget::slot_pbtResult);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_pbtResult()
{
    qDebug() << Q_FUNC_INFO;

    qint32 arg1 = ui->leArg1->text().toInt();
    qint32 arg2 = ui->leArg2->text().toInt();

    //qint32 sumValue = 0;
    qint32 sumValue = m_myUtil->getSumValue(arg1, arg2);

    ui->leSum->setText(QString("%1").arg(sumValue));

}


