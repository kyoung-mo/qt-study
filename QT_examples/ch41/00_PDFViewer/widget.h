#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPdfView>
#include <QPdfDocument>
#include <QFileDialog>
#include <QPdfPageNavigator>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QFileDialog *m_fileDialog = nullptr;

    QPdfView     *m_pdfView;
    QPdfDocument *m_document;

    void slot_pbtChoosePDF();
};
#endif // WIDGET_H
