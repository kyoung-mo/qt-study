#include "widget.h"
#include "./ui_widget.h"
#include <QFileDialog>
#include <QBuffer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->writeButton, &QPushButton::pressed,
            this, &Widget::writeButton);

    QString key = QString("qt-dev.com");
    m_sharedMemory = new QSharedMemory(key);
}

void Widget::writeButton()
{
    if (m_sharedMemory->isAttached()) {
        if (!m_sharedMemory->detach())
            ui->label->setText(tr("Shared memory detach failed."));
    }


    QString fileName;
    fileName = QFileDialog::getOpenFileName(
        0, QString(), QString(),
        tr("Images (*.png *.xpm *.jpg)"));
    QImage image;
    if (!image.load(fileName)) {
        ui->label->setText(tr("Could you select a image file?"));
        return;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));

    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDataStream out(&buffer);
    out << image;
    int size = buffer.size();

    if (!m_sharedMemory->create(size)) {
        ui->label->setText(tr("Shared memory Segment create failed."));
        return;
    }
    m_sharedMemory->lock();
    char *to = (char*)m_sharedMemory->data();
    const char *from = buffer.data().data();
    memcpy(to, from, qMin(m_sharedMemory->size(), size));
    m_sharedMemory->unlock();
}

Widget::~Widget()
{
    delete ui;
}
