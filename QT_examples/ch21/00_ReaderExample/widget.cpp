#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QXmlStreamReader>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::pressed,
            this,           &Widget::readButtonClicked);

    mReadFile = new QFile();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readButtonClicked()
{
    QString fName = QFileDialog::getOpenFileName(this,
                                                 "Open XML File",
                                                 QDir::currentPath(),
                                                 "XML Files (*.xml)");
    mReadFile->setFileName(fName);

    if(!QFile::exists(fName)) {
        return;
    }

    if(!mReadFile->open(QIODevice::ReadOnly)) {
        ui->textEdit->setText("File open failed.");
        return;
    }

    QXmlStreamReader reader(mReadFile);

    QString inputData;
    while(!reader.atEnd())
    {
        reader.readNext();
        if(!reader.text().isEmpty()) {
            QString data = reader.text().toString();
            data.replace(" ", "");
            data.replace('\n', "");
            data.replace('\t', "");

            if(data.length() > 0) {
                inputData.append(data).append("<br>");
            }
        }
    }

    ui->textEdit->setText(inputData);
}













