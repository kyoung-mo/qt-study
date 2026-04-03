/********************************************************************************
** Form generated from reading UI file 'tab3controlpannel.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB3CONTROLPANNEL_H
#define UI_TAB3CONTROLPANNEL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab3ControlPannel
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pPBplug;
    QPushButton *pPBlamp;
    QFormLayout *formLayout;
    QLabel *label;

    void setupUi(QWidget *Tab3ControlPannel)
    {
        if (Tab3ControlPannel->objectName().isEmpty())
            Tab3ControlPannel->setObjectName("Tab3ControlPannel");
        Tab3ControlPannel->resize(400, 300);
        verticalLayout = new QVBoxLayout(Tab3ControlPannel);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(Tab3ControlPannel);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 547, 344));
        pPBplug = new QPushButton(scrollAreaWidgetContents);
        pPBplug->setObjectName("pPBplug");
        pPBplug->setGeometry(QRect(200, 130, 71, 71));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/Images/plug_off.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon.addFile(QString::fromUtf8(":/Images/Images/plug_on.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pPBplug->setIcon(icon);
        pPBplug->setIconSize(QSize(70, 70));
        pPBplug->setCheckable(true);
        pPBlamp = new QPushButton(scrollAreaWidgetContents);
        pPBlamp->setObjectName("pPBlamp");
        pPBlamp->setGeometry(QRect(40, 50, 71, 71));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/Images/light_off.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon1.addFile(QString::fromUtf8(":/Images/Images/light_on.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pPBlamp->setIcon(icon1);
        pPBlamp->setIconSize(QSize(70, 70));
        pPBlamp->setCheckable(true);
        formLayout = new QFormLayout(scrollAreaWidgetContents);
        formLayout->setObjectName("formLayout");
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName("label");
        label->setPixmap(QPixmap(QString::fromUtf8(":/Images/Images/room1.png")));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        scrollArea->setWidget(scrollAreaWidgetContents);
        label->raise();
        pPBlamp->raise();
        pPBplug->raise();

        verticalLayout->addWidget(scrollArea);


        retranslateUi(Tab3ControlPannel);

        QMetaObject::connectSlotsByName(Tab3ControlPannel);
    } // setupUi

    void retranslateUi(QWidget *Tab3ControlPannel)
    {
        Tab3ControlPannel->setWindowTitle(QCoreApplication::translate("Tab3ControlPannel", "Form", nullptr));
        pPBplug->setText(QString());
        pPBlamp->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Tab3ControlPannel: public Ui_Tab3ControlPannel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB3CONTROLPANNEL_H
