#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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

    typedef struct _tMember {
        QString firstName;
        QString lastName;

        QString addr_nation;
        QString addr_city;

        int     school_grade;
        QString school_major;

    } tMember;

    QList<tMember> m_memList;

    void writeJSON();

private slots:
    void slot_pbtWriteFile();

};
#endif // WIDGET_H
