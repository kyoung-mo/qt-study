#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QWebEngineView>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget() override;

private:
    Ui::MainWidget *ui;
    QWebEngineView *pQWebEngineView_1;
    QWebEngineView *pQWebEngineView_2;
    QWebEngineView *pQWebEngineView_3;
    QWebEngineView *pQWebEngineView_4;
};
#endif // MAINWIDGET_H
