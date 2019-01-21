#include "alcanvas.h"

#include <QPainter>
#include <QPen>

ALCanvas::ALCanvas(QWidget *parent) :
    QWidget(parent),
    m_agentPos(0)
{
    m_timer = new QTimer(this);
    m_timer->setInterval(10);

    connect(m_timer,SIGNAL(timeout()),this,SLOT(UpdateOutput()));
}

void ALCanvas::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPen pen; //画笔
    pen.setColor(QColor(255, 0, 0));
    pen.setWidth(4);
    painter.setPen(pen);

    //安全检查
    int size = m_agentPos.size();
    if (m_showNum > size)
        m_showNum = size;

    for (int i = 0; i < m_showNum; i++){
        painter.drawPoint(m_agentPos[i].x(),m_agentPos[i].y());
    }
}

void ALCanvas::Start(int mode)
{
    //直接输出
    if (mode == 0){
        m_showNum = m_agentPos.size();
        update();
    }
    //timer控制输出
    else{
        m_showNum = 1;
        m_timer->start();
    }
}

void ALCanvas::UpdateOutput()
{
    int size = m_agentPos.size();
    if (m_showNum < size)
        m_showNum++;
    else
        m_showNum = size;
    update();
}
