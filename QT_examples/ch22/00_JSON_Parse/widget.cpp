#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pbtJSONParser, SIGNAL(pressed()),
            this, SLOT(slotPbtJSONParser()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotPbtJSONParser()
{
    qDebug() << Q_FUNC_INFO;

    QString inputFilePath =
        QFileDialog::getOpenFileName(this, tr("Open File"),
                                     QDir::currentPath(),
                                     tr("JSON Files (*.json)"));

    QFile file(inputFilePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file.";
        return;
    }

    QString data = file.readAll();
    file.close();

    ui->plainTextEdit->clear();
    parseJSON(data);
}

void Widget::parseJSON(const QString &data)
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(data.toLocal8Bit());
    QJsonObject jsonObj = jsonResponse.object();

    addText(jsonObj["time"].toString().append("\n"));
    addText(jsonObj["date"].toString().append("\n"));

    if(jsonObj["success"].toBool() == true)
        addText(QString("success : true \n"));
    else
        addText(QString("success : false \n"));

    foreach ( const QString& key, jsonObj.keys() )
    {
        if(key == "properties")
        {
            QJsonArray jsonArray = jsonObj["properties"].toArray();
            for( int i = 0 ; i < jsonArray.size() ; i++ )
            {
                QJsonObject sObj = jsonArray.at(i).toObject();

                qint32  subId       = sObj.value("Num").toInt();
                QString subProperty = sObj.value("PropertyName").toString();
                QString subKey      = sObj.value("Key").toString();

                QString arrayData;
                arrayData = QString("[Num: %1] [Property: %2] [Key: %3]")
                                .arg(subId)
                                .arg(subProperty, subKey);

                addText(arrayData + "\n");
            }
        }
    }
}

void Widget::addText(const QString &addLine)
{
    ui->plainTextEdit->insertPlainText(addLine);
}


