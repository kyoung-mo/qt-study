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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab3ControlPannel
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pPBlamp;
    QPushButton *pPBplug;
    QFormLayout *formLayout;
    QLabel *Qlabel;

    void setupUi(QWidget *Tab3ControlPannel)
    {
        if (Tab3ControlPannel->objectName().isEmpty())
            Tab3ControlPannel->setObjectName("Tab3ControlPannel");
        Tab3ControlPannel->resize(400, 300);
        scrollArea = new QScrollArea(Tab3ControlPannel);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 0, 375, 245));
        scrollArea->setBaseSize(QSize(0, 0));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 547, 344));
        scrollAreaWidgetContents->setAutoFillBackground(true);
        pPBlamp = new QPushButton(scrollAreaWidgetContents);
        pPBlamp->setObjectName("pPBlamp");
        pPBlamp->setGeometry(QRect(190, 40, 71, 71));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/light_off.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon.addFile(QString::fromUtf8(":/Images/light_on.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pPBlamp->setIcon(icon);
        pPBlamp->setIconSize(QSize(70, 70));
        pPBlamp->setCheckable(true);
        pPBplug = new QPushButton(scrollAreaWidgetContents);
        pPBplug->setObjectName("pPBplug");
        pPBplug->setGeometry(QRect(30, 170, 71, 71));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/plug_off.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon1.addFile(QString::fromUtf8(":/Images/plug_on.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pPBplug->setIcon(icon1);
        pPBplug->setIconSize(QSize(70, 70));
        pPBplug->setCheckable(true);
        formLayout = new QFormLayout(scrollAreaWidgetContents);
        formLayout->setObjectName("formLayout");
        Qlabel = new QLabel(scrollAreaWidgetContents);
        Qlabel->setObjectName("Qlabel");
        Qlabel->setAutoFillBackground(true);
        Qlabel->setPixmap(QPixmap(QString::fromUtf8(":/Images/room1.png")));

        formLayout->setWidget(0, QFormLayout::LabelRole, Qlabel);

        scrollArea->setWidget(scrollAreaWidgetContents);
        Qlabel->raise();
        pPBlamp->raise();
        pPBplug->raise();

        retranslateUi(Tab3ControlPannel);

        QMetaObject::connectSlotsByName(Tab3ControlPannel);
    } // setupUi

    void retranslateUi(QWidget *Tab3ControlPannel)
    {
        Tab3ControlPannel->setWindowTitle(QCoreApplication::translate("Tab3ControlPannel", "Form", nullptr));
        pPBlamp->setText(QString());
        pPBplug->setText(QString());
        Qlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Tab3ControlPannel: public Ui_Tab3ControlPannel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB3CONTROLPANNEL_H
