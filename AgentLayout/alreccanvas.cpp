#include "alreccanvas.h"

ALRecCanvas::ALRecCanvas(QWidget *parent):
    ALCanvas(parent)
{
    //背景色设置
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(189,252,201)));
}

bool ALRecCanvas::StartDraw(int width, int height, int gap, int mode)
{
    int m_width = this->width(), m_height = this->height();
    if (m_width - width < 0 || m_height - height < 0)
        return false;

    int startX = (m_width - width) / 2;
    int startY = (m_height - height) / 2;
    int endX = (m_width + width) / 2;
    int endY = (m_height + height) / 2;

    m_agentPos.clear();

    for (int j = startY; j < endY; j += gap){
        for (int i = startX; i < endX; i += gap){
            m_agentPos.push_back(QPoint(i, j));
        }
    }

   Start(mode);

   return true;
}
