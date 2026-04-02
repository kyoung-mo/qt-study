#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    pQWebEngineView_1 = new QWebEngineView(this);
    pQWebEngineView_1 ->load(QUrl("http://10.10.16.65:8080/?action=stream"));
    ui->verticalLayout_1->addWidget(pQWebEngineView_1);

    pQWebEngineView_2 = new QWebEngineView(this);
    pQWebEngineView_2 ->load(QUrl("http://10.10.16.65:8080/?action=stream"));
    ui->verticalLayout_2->addWidget(pQWebEngineView_2);

    pQWebEngineView_3 = new QWebEngineView(this);
    pQWebEngineView_3 ->load(QUrl("http://10.10.16.65:8080/?action=stream"));
    ui->verticalLayout_3->addWidget(pQWebEngineView_3);

    pQWebEngineView_4 = new QWebEngineView(this);
    pQWebEngineView_4 ->load(QUrl("http://10.10.16.65:8080/?action=stream"));
    ui->verticalLayout_4->addWidget(pQWebEngineView_4);

}

MainWidget::~MainWidget()
{
    delete ui;
}
