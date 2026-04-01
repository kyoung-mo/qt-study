#include "widget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
QString str1[3] = {"Game", "Office", "Develop"};
QString str2[3] = {"P&rogramming", "Q&t", "O&S"};
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
    connect(m_exclusive[i], SIGNAL(clicked()),
            this,
            SLOT(slot_chkChanged ()));
    ypos += 40;
}
m_chk_group[0]->setExclusive(false);
m_chk_group[1]->setExclusive(true);
}
void Widget::slot_chkChanged()
{
    for(int i = 0 ; i < 3 ; i++) {
        if(m_exclusive[i]->checkState())
        {
            qDebug("checkbox %d selected ", i+1);
        }
    }
}
Widget::~Widget()
{
}