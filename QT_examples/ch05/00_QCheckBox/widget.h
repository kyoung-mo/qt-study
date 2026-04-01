#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCheckBox>
#include <QButtonGroup>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QButtonGroup    *m_chk_group[2];
    QCheckBox       *m_exclusive[3];
    QCheckBox       *m_non_exclusive[3];

private slots:
    void slot_chkChanged();


};
#endif // WIDGET_H
