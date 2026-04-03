/********************************************************************************
** Form generated from reading UI file 'tab7camopencv.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB7CAMOPENCV_H
#define UI_TAB7CAMOPENCV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab7CamOpencv
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *plabelCamView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pPBcamStart;
    QCheckBox *pCBrgb;
    QPushButton *pPBsnapShot;

    void setupUi(QWidget *Tab7CamOpencv)
    {
        if (Tab7CamOpencv->objectName().isEmpty())
            Tab7CamOpencv->setObjectName("Tab7CamOpencv");
        Tab7CamOpencv->resize(400, 300);
        verticalLayout_3 = new QVBoxLayout(Tab7CamOpencv);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        plabelCamView = new QLabel(Tab7CamOpencv);
        plabelCamView->setObjectName("plabelCamView");
        plabelCamView->setPixmap(QPixmap(QString::fromUtf8(":/Images/Images/initDisplay_1.png")));
        plabelCamView->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(plabelCamView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pPBcamStart = new QPushButton(Tab7CamOpencv);
        pPBcamStart->setObjectName("pPBcamStart");
        pPBcamStart->setCheckable(true);
        pPBcamStart->setChecked(false);

        horizontalLayout->addWidget(pPBcamStart);

        pCBrgb = new QCheckBox(Tab7CamOpencv);
        pCBrgb->setObjectName("pCBrgb");

        horizontalLayout->addWidget(pCBrgb);

        pPBsnapShot = new QPushButton(Tab7CamOpencv);
        pPBsnapShot->setObjectName("pPBsnapShot");

        horizontalLayout->addWidget(pPBsnapShot);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 9);
        verticalLayout->setStretch(1, 1);

        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(Tab7CamOpencv);

        QMetaObject::connectSlotsByName(Tab7CamOpencv);
    } // setupUi

    void retranslateUi(QWidget *Tab7CamOpencv)
    {
        Tab7CamOpencv->setWindowTitle(QCoreApplication::translate("Tab7CamOpencv", "Form", nullptr));
        plabelCamView->setText(QString());
        pPBcamStart->setText(QCoreApplication::translate("Tab7CamOpencv", "CamStart", nullptr));
        pCBrgb->setText(QCoreApplication::translate("Tab7CamOpencv", "RGB Classify", nullptr));
        pPBsnapShot->setText(QCoreApplication::translate("Tab7CamOpencv", "Snapshot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab7CamOpencv: public Ui_Tab7CamOpencv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB7CAMOPENCV_H
