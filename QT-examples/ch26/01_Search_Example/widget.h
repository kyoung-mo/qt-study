#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlTableModel>
#include "databasehandler.h"

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

    DatabaseHandler *m_dbHandler;
    QSqlTableModel  *m_model;

    void setupModel(const QString &tableName, const QStringList &headers);
    void createUserInterface();

private slots:
    void onPushButton();

};
#endif // WIDGET_H
