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
            this,           &Widget::writeButtonClicked);

    mWriteFile = new QFile();

    mOriData.append("Qt developer community");
    mOriData.append("https://www.qt-dev.com");

    for(int i = 0 ; i < mOriData.count() ; i++)
        ui->textEdit->append(mOriData.at(i));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::writeButtonClicked()
{
    QFile file("d:/output.xml");
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("Qt");

    xmlWriter.writeStartElement("Info");

    xmlWriter.writeTextElement("Name", mOriData.at(0));
    xmlWriter.writeTextElement("URL",  mOriData.at(1));

    xmlWriter.writeEndElement(); // Info End tag
    xmlWriter.writeEndElement(); // Qt End tag

    file.close();
}














