#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->checkBox_3,SIGNAL(clicked()), this, SLOT(checkBox_3_clicked())); // signal clicked -> this object call
    connect(ui->checkBox_5,SIGNAL(clicked()), this, SLOT(checkBox_5_clicked(Q))); // signal clicked -> this object call
    connect(ui->checkBox_3,SIGNAL(clicked(bool)), this, SLOT(checkBox_3_clicked(bool flag))); // signal clicked -> this object call
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_checkBox_2_clicked()
{
    qDebug() << "on_checkBox_2_clicked()";

}

void Widget::checkBox_3_clicked()
{
    qDebug() << "on_checkBox_3_clicked()";

}

void Widget::checkBox_5_clicked()
{
    qDebug() << "on_checkBox_5_clicked()";

}


void Widget::checkBox_3_clicked(bool flag)
{
    qDebug() << "on_checkBox_3_clicked()";
    if(ui->checkBox_3->isChecked()){

    }
    if(flag)
    qDebug() << "ON";
    else
        qDebug() << "OFF"
}
