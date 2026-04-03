#include "tab6camviewer.h"
#include "ui_tab6camviewer.h"

Tab6CamViewer::Tab6CamViewer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tab6CamViewer)
{
    ui->setupUi(this);
}

Tab6CamViewer::~Tab6CamViewer()
{
    delete ui;
}
