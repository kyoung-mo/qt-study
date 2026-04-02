#include "widget.h"
#include "./ui_widget.h"
#include <QBuffer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->readButton, &QPushButton::pressed,
            this, &Widget::readButton);

    QString key = QString("qt-dev.com");
    m_sharedMemory = new QSharedMemory(key);
}

void Widget::readButton()
{
    if (!m_sharedMemory->attach()) {
        ui->label->setText("Reading Failed from shared memory");
        return;
    }

    QBuffer buffer;
    QDataStream in(&buffer);
    QImage image;

    m_sharedMemory->lock();
    buffer.setData((char*)m_sharedMemory->constData(),
                   m_sharedMemory->size());

    buffer.open(QBuffer::ReadOnly);
    in >> image;
    m_sharedMemory->unlock();

    m_sharedMemory->detach();
    ui->label->setPixmap(QPixmap::fromImage(image));
}

Widget::~Widget()
{
    delete ui;
}
