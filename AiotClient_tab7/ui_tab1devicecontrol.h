/********************************************************************************
** Form generated from reading UI file 'tab1devicecontrol.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB1DEVICECONTROL_H
#define UI_TAB1DEVICECONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab1DeviceControl
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pPBtimerStart;
    QComboBox *pCBtimerValue;
    QPushButton *pPBquit;
    QHBoxLayout *horizontalLayout_2;
    QDial *pDialLed;
    QLCDNumber *pLcdNumberLed;
    QHBoxLayout *horizontalLayout_3;
    QProgressBar *pProgressBarLed;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout;
    QCheckBox *pCBkey3;
    QCheckBox *pCBkey2;
    QCheckBox *pCBkey5;
    QCheckBox *pCBkey4;
    QCheckBox *pCBkey7;
    QCheckBox *pCBkey1;
    QCheckBox *pCBkey8;
    QCheckBox *pCBkey6;
    QLCDNumber *pLcdNumberKey;

    void setupUi(QWidget *Tab1DeviceControl)
    {
        if (Tab1DeviceControl->objectName().isEmpty())
            Tab1DeviceControl->setObjectName("Tab1DeviceControl");
        Tab1DeviceControl->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(Tab1DeviceControl);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pPBtimerStart = new QPushButton(Tab1DeviceControl);
        pPBtimerStart->setObjectName("pPBtimerStart");
        pPBtimerStart->setCheckable(true);

        horizontalLayout->addWidget(pPBtimerStart);

        pCBtimerValue = new QComboBox(Tab1DeviceControl);
        pCBtimerValue->addItem(QString());
        pCBtimerValue->addItem(QString());
        pCBtimerValue->addItem(QString());
        pCBtimerValue->addItem(QString());
        pCBtimerValue->addItem(QString());
        pCBtimerValue->setObjectName("pCBtimerValue");

        horizontalLayout->addWidget(pCBtimerValue);

        pPBquit = new QPushButton(Tab1DeviceControl);
        pPBquit->setObjectName("pPBquit");

        horizontalLayout->addWidget(pPBquit);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pDialLed = new QDial(Tab1DeviceControl);
        pDialLed->setObjectName("pDialLed");
        pDialLed->setMaximum(255);
        pDialLed->setValue(0);
        pDialLed->setWrapping(true);
        pDialLed->setNotchesVisible(true);

        horizontalLayout_2->addWidget(pDialLed);

        pLcdNumberLed = new QLCDNumber(Tab1DeviceControl);
        pLcdNumberLed->setObjectName("pLcdNumberLed");
        pLcdNumberLed->setSmallDecimalPoint(false);
        pLcdNumberLed->setDigitCount(2);
        pLcdNumberLed->setMode(QLCDNumber::Mode::Hex);
        pLcdNumberLed->setSegmentStyle(QLCDNumber::SegmentStyle::Filled);

        horizontalLayout_2->addWidget(pLcdNumberLed);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pProgressBarLed = new QProgressBar(Tab1DeviceControl);
        pProgressBarLed->setObjectName("pProgressBarLed");
        pProgressBarLed->setMaximum(255);
        pProgressBarLed->setValue(0);
        pProgressBarLed->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pProgressBarLed->setTextVisible(true);
        pProgressBarLed->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_3->addWidget(pProgressBarLed);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pCBkey3 = new QCheckBox(Tab1DeviceControl);
        pCBkey3->setObjectName("pCBkey3");

        gridLayout->addWidget(pCBkey3, 1, 1, 1, 1);

        pCBkey2 = new QCheckBox(Tab1DeviceControl);
        pCBkey2->setObjectName("pCBkey2");

        gridLayout->addWidget(pCBkey2, 1, 2, 1, 1);

        pCBkey5 = new QCheckBox(Tab1DeviceControl);
        pCBkey5->setObjectName("pCBkey5");

        gridLayout->addWidget(pCBkey5, 0, 3, 1, 1);

        pCBkey4 = new QCheckBox(Tab1DeviceControl);
        pCBkey4->setObjectName("pCBkey4");

        gridLayout->addWidget(pCBkey4, 1, 0, 1, 1);

        pCBkey7 = new QCheckBox(Tab1DeviceControl);
        pCBkey7->setObjectName("pCBkey7");

        gridLayout->addWidget(pCBkey7, 0, 1, 1, 1);

        pCBkey1 = new QCheckBox(Tab1DeviceControl);
        pCBkey1->setObjectName("pCBkey1");

        gridLayout->addWidget(pCBkey1, 1, 3, 1, 1);

        pCBkey8 = new QCheckBox(Tab1DeviceControl);
        pCBkey8->setObjectName("pCBkey8");

        gridLayout->addWidget(pCBkey8, 0, 0, 1, 1);

        pCBkey6 = new QCheckBox(Tab1DeviceControl);
        pCBkey6->setObjectName("pCBkey6");

        gridLayout->addWidget(pCBkey6, 0, 2, 1, 1);


        horizontalLayout_5->addLayout(gridLayout);

        pLcdNumberKey = new QLCDNumber(Tab1DeviceControl);
        pLcdNumberKey->setObjectName("pLcdNumberKey");
        pLcdNumberKey->setSmallDecimalPoint(false);
        pLcdNumberKey->setDigitCount(2);
        pLcdNumberKey->setMode(QLCDNumber::Mode::Hex);
        pLcdNumberKey->setSegmentStyle(QLCDNumber::SegmentStyle::Filled);

        horizontalLayout_5->addWidget(pLcdNumberKey);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 4);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 4);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Tab1DeviceControl);
        QObject::connect(pDialLed, &QDial::valueChanged, pLcdNumberLed, qOverload<int>(&QLCDNumber::display));
        QObject::connect(pDialLed, &QDial::valueChanged, pProgressBarLed, &QProgressBar::setValue);

        QMetaObject::connectSlotsByName(Tab1DeviceControl);
    } // setupUi

    void retranslateUi(QWidget *Tab1DeviceControl)
    {
        Tab1DeviceControl->setWindowTitle(QCoreApplication::translate("Tab1DeviceControl", "Form", nullptr));
        pPBtimerStart->setText(QCoreApplication::translate("Tab1DeviceControl", "TimerStart", nullptr));
        pCBtimerValue->setItemText(0, QCoreApplication::translate("Tab1DeviceControl", "50", nullptr));
        pCBtimerValue->setItemText(1, QCoreApplication::translate("Tab1DeviceControl", "100", nullptr));
        pCBtimerValue->setItemText(2, QCoreApplication::translate("Tab1DeviceControl", "500", nullptr));
        pCBtimerValue->setItemText(3, QCoreApplication::translate("Tab1DeviceControl", "1000", nullptr));
        pCBtimerValue->setItemText(4, QCoreApplication::translate("Tab1DeviceControl", "2000", nullptr));

        pPBquit->setText(QCoreApplication::translate("Tab1DeviceControl", "Quit", nullptr));
        pCBkey3->setText(QCoreApplication::translate("Tab1DeviceControl", "3", nullptr));
        pCBkey2->setText(QCoreApplication::translate("Tab1DeviceControl", "2", nullptr));
        pCBkey5->setText(QCoreApplication::translate("Tab1DeviceControl", "5", nullptr));
        pCBkey4->setText(QCoreApplication::translate("Tab1DeviceControl", "4", nullptr));
        pCBkey7->setText(QCoreApplication::translate("Tab1DeviceControl", "7", nullptr));
        pCBkey1->setText(QCoreApplication::translate("Tab1DeviceControl", "1", nullptr));
        pCBkey8->setText(QCoreApplication::translate("Tab1DeviceControl", "8", nullptr));
        pCBkey6->setText(QCoreApplication::translate("Tab1DeviceControl", "6", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab1DeviceControl: public Ui_Tab1DeviceControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB1DEVICECONTROL_H
