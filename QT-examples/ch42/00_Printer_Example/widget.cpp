#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>
#include <QFileDialog>
#include <QPrintDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pbtPrint, &QPushButton::clicked,
            this,         &Widget::slot_pbtPrint);
}

void Widget::slot_pbtPrint()
{
    QPrinter printer(QPrinter::HighResolution);

    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle(tr("Print Document"));

    if (dialog.exec() == QDialog::Accepted) {
        ui->textEdit->print(&printer);
    }
}

Widget::~Widget()
{
    delete ui;
}

