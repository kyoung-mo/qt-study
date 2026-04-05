/********************************************************************************
** Form generated from reading UI file 'tab6camviewer.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB6CAMVIEWER_H
#define UI_TAB6CAMVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab6CamViewer
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *plabelCamView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pPBcamStart;
    QPushButton *pPBsnapShot;

    void setupUi(QWidget *Tab6CamViewer)
    {
        if (Tab6CamViewer->objectName().isEmpty())
            Tab6CamViewer->setObjectName("Tab6CamViewer");
        Tab6CamViewer->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(Tab6CamViewer);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        plabelCamView = new QLabel(Tab6CamViewer);
        plabelCamView->setObjectName("plabelCamView");
        plabelCamView->setFrameShape(QFrame::Shape::NoFrame);
        plabelCamView->setPixmap(QPixmap(QString::fromUtf8(":/Images/background_resize.png")));

        verticalLayout->addWidget(plabelCamView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pPBcamStart = new QPushButton(Tab6CamViewer);
        pPBcamStart->setObjectName("pPBcamStart");
        pPBcamStart->setCheckable(true);
        pPBcamStart->setChecked(false);

        horizontalLayout->addWidget(pPBcamStart);

        pPBsnapShot = new QPushButton(Tab6CamViewer);
        pPBsnapShot->setObjectName("pPBsnapShot");

        horizontalLayout->addWidget(pPBsnapShot);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 9);
        verticalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Tab6CamViewer);

        QMetaObject::connectSlotsByName(Tab6CamViewer);
    } // setupUi

    void retranslateUi(QWidget *Tab6CamViewer)
    {
        Tab6CamViewer->setWindowTitle(QCoreApplication::translate("Tab6CamViewer", "Form", nullptr));
        plabelCamView->setText(QString());
        pPBcamStart->setText(QCoreApplication::translate("Tab6CamViewer", "CamStart", nullptr));
        pPBsnapShot->setText(QCoreApplication::translate("Tab6CamViewer", "Snapshot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab6CamViewer: public Ui_Tab6CamViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB6CAMVIEWER_H
