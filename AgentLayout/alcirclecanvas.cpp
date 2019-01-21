#include "alcirclecanvas.h"

ALCircleCanvas::ALCircleCanvas(QWidget *parent) :
    ALCanvas(parent)
{
    //背景色设置
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(250,255,240)));
}

bool ALCircleCanvas::StartDraw(int width, int height, int gap, int mode)
{
    int m_width = this->width(), m_height = this->height();
    if (m_width - width < 0 || m_height - height < 0)
        return false;

    int startX = (m_width - width) / 2;
    int startY = (m_height - height) / 2;
    int endX = (m_width + width) / 2;
    int endY = (m_height + height) / 2;

    m_agentPos.clear();

    int centerX = 399, centerY = 274;
    for (int j = startY; j < endY; j += gap){
        for (int i = startX; i < endX; i += gap){
            //判断是否在椭圆内
            if ((i - centerX)* 1.f * (i - centerX) / width / width * 4
                    + (j - centerY) * 1.f * (j - centerY) / height / height * 4 <= 1)
                m_agentPos.push_back(QPoint(i, j));
        }
    }

   Start(mode);

   return true;
}
