#include "widget.h"
#include "./ui_widget.h"
Widget::Widget(QWidget *parent)
 : QWidget(parent)
 , ui(new Ui::Widget)
{
 ui->setupUi(this);
 connect(ui->pbtHello, SIGNAL(pressed()), this, SLOT(slot_helloBtn()));
 connect(ui->pbtClear, SIGNAL(pressed()), this, SLOT(slot_clearBtn()));
}
Widget::~Widget()
{
 delete ui;
}
void Widget::slot_helloBtn()
{
 ui->label->setText("Hello world. !! ^^;");
}
void Widget::slot_clearBtn()
{
 ui->label->setText("");
}
