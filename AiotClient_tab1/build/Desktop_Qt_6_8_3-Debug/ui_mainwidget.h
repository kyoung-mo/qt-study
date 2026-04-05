/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *pTab1;
    QWidget *pTab2;
    QWidget *pTab3;
    QWidget *pTab4;
    QWidget *pTab5;
    QWidget *pTab6;
    QWidget *pTab7;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName("MainWidget");
        MainWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(MainWidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(MainWidget);
        tabWidget->setObjectName("tabWidget");
        pTab1 = new QWidget();
        pTab1->setObjectName("pTab1");
        tabWidget->addTab(pTab1, QString());
        pTab2 = new QWidget();
        pTab2->setObjectName("pTab2");
        tabWidget->addTab(pTab2, QString());
        pTab3 = new QWidget();
        pTab3->setObjectName("pTab3");
        tabWidget->addTab(pTab3, QString());
        pTab4 = new QWidget();
        pTab4->setObjectName("pTab4");
        tabWidget->addTab(pTab4, QString());
        pTab5 = new QWidget();
        pTab5->setObjectName("pTab5");
        tabWidget->addTab(pTab5, QString());
        pTab6 = new QWidget();
        pTab6->setObjectName("pTab6");
        tabWidget->addTab(pTab6, QString());
        pTab7 = new QWidget();
        pTab7->setObjectName("pTab7");
        tabWidget->addTab(pTab7, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(MainWidget);

        tabWidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "MainWidget", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab1), QCoreApplication::translate("MainWidget", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab2), QCoreApplication::translate("MainWidget", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab3), QCoreApplication::translate("MainWidget", "Tab 3", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab4), QCoreApplication::translate("MainWidget", "Tab 4", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab5), QCoreApplication::translate("MainWidget", "Tab 5", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab6), QCoreApplication::translate("MainWidget", "Tab 6", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pTab7), QCoreApplication::translate("MainWidget", "Tab 7", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
