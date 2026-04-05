/********************************************************************************
** Form generated from reading UI file 'tab2socketclient.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB2SOCKETCLIENT_H
#define UI_TAB2SOCKETCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab2SocketClient
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pPBrecvClear;
    QPushButton *pPBserverConnect;
    QHBoxLayout *horizontalLayout;
    QTextEdit *pTErecvData;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *pLErecvid;
    QLineEdit *pLEsendData;
    QPushButton *pPBsend;

    void setupUi(QWidget *Tab2SocketClient)
    {
        if (Tab2SocketClient->objectName().isEmpty())
            Tab2SocketClient->setObjectName("Tab2SocketClient");
        Tab2SocketClient->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(Tab2SocketClient);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(Tab2SocketClient);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pPBrecvClear = new QPushButton(Tab2SocketClient);
        pPBrecvClear->setObjectName("pPBrecvClear");

        horizontalLayout_2->addWidget(pPBrecvClear);

        pPBserverConnect = new QPushButton(Tab2SocketClient);
        pPBserverConnect->setObjectName("pPBserverConnect");
        pPBserverConnect->setCheckable(true);

        horizontalLayout_2->addWidget(pPBserverConnect);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 7);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pTErecvData = new QTextEdit(Tab2SocketClient);
        pTErecvData->setObjectName("pTErecvData");

        horizontalLayout->addWidget(pTErecvData);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pLErecvid = new QLineEdit(Tab2SocketClient);
        pLErecvid->setObjectName("pLErecvid");

        horizontalLayout_3->addWidget(pLErecvid);

        pLEsendData = new QLineEdit(Tab2SocketClient);
        pLEsendData->setObjectName("pLEsendData");

        horizontalLayout_3->addWidget(pLEsendData);

        pPBsend = new QPushButton(Tab2SocketClient);
        pPBsend->setObjectName("pPBsend");

        horizontalLayout_3->addWidget(pPBsend);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 6);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 8);
        verticalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Tab2SocketClient);
        QObject::connect(pPBrecvClear, &QPushButton::clicked, pTErecvData, qOverload<>(&QTextEdit::clear));
        QObject::connect(pLEsendData, &QLineEdit::returnPressed, pPBsend, qOverload<>(&QPushButton::click));

        QMetaObject::connectSlotsByName(Tab2SocketClient);
    } // setupUi

    void retranslateUi(QWidget *Tab2SocketClient)
    {
        Tab2SocketClient->setWindowTitle(QCoreApplication::translate("Tab2SocketClient", "Form", nullptr));
        label->setText(QCoreApplication::translate("Tab2SocketClient", "\354\210\230\354\213\240 \353\215\260\354\235\264\355\204\260", nullptr));
        pPBrecvClear->setText(QCoreApplication::translate("Tab2SocketClient", "\354\210\230\354\213\240 \354\202\255\354\240\234", nullptr));
        pPBserverConnect->setText(QCoreApplication::translate("Tab2SocketClient", "\354\204\234\353\262\204 \354\227\260\352\262\260", nullptr));
        pPBsend->setText(QCoreApplication::translate("Tab2SocketClient", "\354\206\241\354\213\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab2SocketClient: public Ui_Tab2SocketClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB2SOCKETCLIENT_H
