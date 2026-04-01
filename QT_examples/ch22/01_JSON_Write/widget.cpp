#include "widget.h"
#include "ui_widget.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pbtWirteFile, &QPushButton::clicked,
            this, &Widget::slot_pbtWriteFile);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::writeJSON()
{
    qDebug() << Q_FUNC_INFO;

    QFile file("d:/write_sample.json");

    if(!file.open(QIODevice::ReadWrite)) {
        qDebug() << "File open error";
        return;
    }

    file.resize(0);

    tMember member1;
    member1.firstName    = QString("Dae Jin");
    member1.lastName     = QString("Kim");
    member1.addr_nation  = QString("South Korea");
    member1.addr_city    = QString("Yongin");
    member1.school_grade = 3;
    member1.school_major = QString("Computer science");

    tMember member2;
    member2.firstName    = QString("Gil Dong");
    member2.lastName     = QString("Hong");
    member2.addr_nation  = QString("South Korea");
    member2.addr_city    = QString("Suwon");
    member2.school_grade = 2;
    member2.school_major = QString("Math");

    m_memList.append(member1);
    m_memList.append(member2);


    QJsonArray jsonArray;

    for(qsizetype i = 0 ; i < m_memList.size() ; i++)
    {
        QJsonObject jsonObject;

        jsonObject.insert("FirstName", m_memList.at(i).firstName);
        jsonObject.insert("LastName",  m_memList.at(i).lastName);

        QJsonObject jsonAddrObject;
        jsonAddrObject.insert("Nation", m_memList.at(i).addr_nation);
        jsonAddrObject.insert("City",   m_memList.at(i).addr_city);

        QJsonObject jsonSchoolObject;
        jsonSchoolObject.insert("Grade", m_memList.at(i).school_grade);
        jsonSchoolObject.insert("Major", m_memList.at(i).school_major);

        jsonObject.insert("School", jsonSchoolObject);
        jsonObject.insert("Address", jsonAddrObject);

        jsonArray.append(jsonObject);
    }

    QJsonDocument jsonDocment;

    jsonDocment.setArray(jsonArray);
    file.write(jsonDocment.toJson());
    file.close();

}

void Widget::slot_pbtWriteFile()
{
    writeJSON();
}





