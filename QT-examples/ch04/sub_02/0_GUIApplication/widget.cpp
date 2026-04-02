#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(slot_clicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_clicked()
{
    qDebug() << "Hello world";
}


