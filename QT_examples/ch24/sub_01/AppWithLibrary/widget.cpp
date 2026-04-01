#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pbtResult, &QPushButton::clicked,
            this,          &Widget::slot_pbtResult);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_pbtResult()
{
    qint32 arg1 = ui->leArg1->text().toInt();
    qint32 arg2 = ui->leArg2->text().toInt();

    qint32 sumValue = m_myUtil->getSumValue(arg1, arg2);
    ui->leSum->setText(QString("%1").arg(sumValue));
}

