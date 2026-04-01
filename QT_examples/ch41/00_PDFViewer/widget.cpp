#include "widget.h"
#include "./ui_widget.h"
#include <QHBoxLayout>
#include <QStandardPaths>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_pdfView   = new QPdfView;
    m_document  = new QPdfDocument(this);

    m_pdfView->setDocument(m_document);

    QHBoxLayout *hLay = new QHBoxLayout();
    hLay->addWidget(m_pdfView);

    ui->frame->setLayout(hLay);

    connect(ui->pbtChoosePdf, &QPushButton::clicked,
            this,             &Widget::slot_pbtChoosePDF);
}

void Widget::slot_pbtChoosePDF()
{
    qDebug() << Q_FUNC_INFO;

    if (m_fileDialog == nullptr) {
        m_fileDialog = new QFileDialog(this, tr("Choose a PDF"),
                             QStandardPaths::writableLocation(
                                      QStandardPaths::DocumentsLocation));

        m_fileDialog->setAcceptMode(QFileDialog::AcceptOpen);
        m_fileDialog->setMimeTypeFilters({"application/pdf"});
    }

    if (m_fileDialog->exec() == QDialog::Accepted)
    {
        const QUrl toOpen = m_fileDialog->selectedUrls().constFirst();
        m_document->load(toOpen.toLocalFile());

        const auto docTitle =
                m_document->metaData(QPdfDocument::MetaDataField::Title)
                                      .toString();

        setWindowTitle(!docTitle.isEmpty() ? docTitle : "PDF Viewer");

        m_pdfView->setPageMode(QPdfView::PageMode::MultiPage);
    }
}

Widget::~Widget()
{
    delete ui;
}

