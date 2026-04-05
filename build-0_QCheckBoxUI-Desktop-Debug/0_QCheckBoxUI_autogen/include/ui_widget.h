/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(515, 162);
        verticalLayout_10 = new QVBoxLayout(Widget);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBox_1 = new QCheckBox(groupBox);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));
        checkBox_1->setAutoExclusive(true);
        checkBox_1->setTristate(true);

        verticalLayout->addWidget(checkBox_1);

        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setAutoExclusive(true);
        checkBox_2->setTristate(true);

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setAutoExclusive(true);
        checkBox_3->setTristate(true);

        verticalLayout->addWidget(checkBox_3);


        horizontalLayout_5->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(horizontalLayout_5);


        horizontalLayout_8->addWidget(groupBox);

        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setChecked(true);
        checkBox_4->setTristate(false);

        verticalLayout_2->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setTristate(false);

        verticalLayout_2->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(groupBox_2);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setTristate(true);

        verticalLayout_2->addWidget(checkBox_6);


        horizontalLayout_7->addLayout(verticalLayout_2);


        horizontalLayout_8->addWidget(groupBox_2);


        horizontalLayout_6->addLayout(horizontalLayout_8);


        verticalLayout_10->addWidget(groupBox_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox_3->setTitle(QString());
        groupBox->setTitle(QString());
        checkBox_1->setText(QCoreApplication::translate("Widget", "Game", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Widget", "Office", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Widget", "Develop", nullptr));
        groupBox_2->setTitle(QString());
        checkBox_4->setText(QCoreApplication::translate("Widget", "Programming", nullptr));
        checkBox_5->setText(QCoreApplication::translate("Widget", "&Q&t", nullptr));
        checkBox_6->setText(QCoreApplication::translate("Widget", "O&&S", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
