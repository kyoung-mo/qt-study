#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_dbHandler = new DatabaseHandler();
    m_dbHandler->connectToDataBase();

    for(int i = 0; i < 10; i++)
    {
        QVariantList data;


        QTime currTime = QTime::currentTime();
        currTime = currTime.addSecs(i*1000);

        int random = rand();

        data.append(currTime);
        data.append(random);
        data.append("Message : " + QString::number(random));

        m_dbHandler->insertIntoTable(data);
    }

    setupModel("RECEIVE_MAIL",
               QStringList() << "ID"
                             << "Time"
                             << "Number"
                             << "Message"
              );

    createUserInterface();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setupModel(const QString &tableName,
                        const QStringList &headers)
{
    m_model = new QSqlTableModel(this);
    m_model->setTable(tableName);

    for(int i = 0, j = 0; i < m_model->columnCount(); i++, j++) {
        m_model->setHeaderData(i, Qt::Horizontal, headers[j]);
    }

    m_model->setSort(0,Qt::AscendingOrder);
}

void Widget::createUserInterface()
{
    ui->tableView->setModel(m_model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    for(int i = 0 ; i < 4 ; i++)
        ui->tableView->setColumnWidth(i, 100);

    m_model->select(); // 테이블로부터 데이터를 Fetche
    ui->timeFROM->setTime(QTime::currentTime());
    ui->timeTO->setTime(QTime::currentTime());

    connect(ui->pbtSearch, SIGNAL(pressed()),
            this,          SLOT(onPushButton()));
}

void Widget::onPushButton()
{

    QString str = QString("TIME between '%3' and '%4'")
                      .arg(ui->timeFROM->time().toString("hh:mm:ss"));

    m_model->setFilter(QString( "TIME between '%3' and '%4'")
                             .arg(ui->timeFROM->time().toString("hh:mm:ss"),
                                  ui->timeTO->time().toString("hh:mm:ss")));

    m_model->select(); // 테이블로부터 데이터를 Fetche
}
