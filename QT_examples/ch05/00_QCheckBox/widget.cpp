#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QString str1[3] = {"Game", "Office", "Develop"};
    QString str2[3] = {"Programming", "Qt", "OS"};

    int xpos = 30;
    int ypos = 30;

    m_chk_group[0] = new QButtonGroup(this);
    m_chk_group[1] = new QButtonGroup(this);

    for(int i = 0 ; i < 3 ; i++)
    {
        m_exclusive[i] = new QCheckBox(str1[i], this);
        m_exclusive[i]->setGeometry(xpos, ypos, 120, 30);
        m_chk_group[0]->addButton(m_exclusive[i]);

        m_non_exclusive[i] = new QCheckBox(str2[i], this);
        m_non_exclusive[i]->setGeometry(xpos + 120, ypos, 120, 30);
        m_chk_group[1]->addButton(m_non_exclusive[i]);

        connect(m_exclusive[i], SIGNAL(clicked()), this, SLOT(slot_chkChanged()));

        ypos += 40;
    }

    m_chk_group[0]->setExclusive(false);
    m_chk_group[1]->setExclusive(true);

    m_exclusive[0]->setIcon(QIcon(":resources/browser.png"));
    m_exclusive[1]->setIcon(QIcon(":resources/calendar.png"));
    m_exclusive[2]->setIcon(QIcon(":resources/chat.png"));

    m_non_exclusive[0]->setIcon(QIcon(":resources/editor.png"));
    m_non_exclusive[1]->setIcon(QIcon(":resources/mail.png"));
    m_non_exclusive[2]->setIcon(QIcon(":resources/users.png"));
}

void Widget::slot_chkChanged()
{
    for(int i = 0 ; i < 3 ; i++)
    {
        if(m_exclusive[i]->checkState())
        {
            qDebug("checkbox %d selected ", i+1);
        }
    }
}

Widget::~Widget()
{
}

