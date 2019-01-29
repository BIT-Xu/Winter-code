#include "ALCanvas.h"

#include <qpainter.h>
#include <qpen.h>


ALCanvas::ALCanvas(QWidget *parent) :
	QWidget(parent),
	m_agentPos(0)
{
	setAutoFillBackground(true);
	setPalette(QPalette(QColor(240, 255, 240)));
	setFocusPolicy(Qt::StrongFocus);
}


ALCanvas::~ALCanvas()
{
}

void ALCanvas::Draw(const QVector<QPoint>& pos)
{
	m_agentPos = pos;
	update();
}

void ALCanvas::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	QPen pen, other_pen; //画笔
	pen.setColor(QColor(255, 0, 0));
	pen.setWidth(4);
	other_pen.setColor(QColor(0, 0, 0));
	other_pen.setWidth(4);
	//painter.setPen(pen);

	for (const auto& i : m_agentPos) {
		if (delete_flag)//删除选框内的点
		{
			if (i.x() >= start.x() && i.y() >= start.y() && i.x() <= end.x() && i.y() <= end.y()){}
			else
			{
				painter.setPen(pen);
				painter.drawPoint(i);
			}

		}
		else//选框内的点变色
		{
			if (i.x() >= start.x() && i.y() >= start.y() && i.x() <= end.x() && i.y() <= end.y())
			{
				painter.setPen(other_pen);
				painter.drawPoint(i);
			}
			else
			{
				painter.setPen(pen);
				painter.drawPoint(i);
			}
		}	
	}
}

/*矩形选框*/
void ALCanvas::mouseMoveEvent(QMouseEvent *event)
{
	if (sign)
	{
		//保存鼠标移动的时候的尾坐标.
		end = event->pos();
		//用来重绘更新.可以理解为调用paintEvent函数，但不一定是立即调用的.在此程序中可以理解为:马上更新窗口上显示的图像.
		update();
	}
}
//void ALCanvas::paintEvent(QPaintEvent *event)
//{
//	//画一个矩形.
//	QPainter painter(this);
//	painter.setPen(QColor(240, 255, 255));
//
//	QRect temp(start, end);
//	painter.setBrush(QColor(240, 255, 255));
//	painter.drawRect(temp);
//}

void ALCanvas::mouseReleaseEvent(QMouseEvent *event)
{
	//当左键释放后，保存尾坐标.
	if (event->button() == Qt::LeftButton)
	{
		this->end = event->pos();
		update();
		sign = false;
	}
	delete_flag = 0;
}

void ALCanvas::mousePressEvent(QMouseEvent *event)
{
	//当左键被按下时，保存首坐标.并更新重绘.
	delete_flag = 0;
	if (event->button() == Qt::LeftButton)
	{
		//点击的时候定下初始位置.
		this->start = event->pos();
		sign = true;
	}
}

void ALCanvas::keyPressEvent(QKeyEvent  *event)
{

	if (event->key() == Qt::Key_D)
	{
		delete_flag = 1;
		update();
	}
	
}