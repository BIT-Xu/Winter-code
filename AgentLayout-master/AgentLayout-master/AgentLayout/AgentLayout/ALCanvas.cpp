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
	QPen pen, other_pen; //����
	pen.setColor(QColor(255, 0, 0));
	pen.setWidth(4);
	other_pen.setColor(QColor(0, 0, 0));
	other_pen.setWidth(4);
	//painter.setPen(pen);

	for (const auto& i : m_agentPos) {
		if (delete_flag)//ɾ��ѡ���ڵĵ�
		{
			if (i.x() >= start.x() && i.y() >= start.y() && i.x() <= end.x() && i.y() <= end.y()){}
			else
			{
				painter.setPen(pen);
				painter.drawPoint(i);
			}

		}
		else//ѡ���ڵĵ��ɫ
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

/*����ѡ��*/
void ALCanvas::mouseMoveEvent(QMouseEvent *event)
{
	if (sign)
	{
		//��������ƶ���ʱ���β����.
		end = event->pos();
		//�����ػ����.�������Ϊ����paintEvent����������һ�����������õ�.�ڴ˳����п������Ϊ:���ϸ��´�������ʾ��ͼ��.
		update();
	}
}
//void ALCanvas::paintEvent(QPaintEvent *event)
//{
//	//��һ������.
//	QPainter painter(this);
//	painter.setPen(QColor(240, 255, 255));
//
//	QRect temp(start, end);
//	painter.setBrush(QColor(240, 255, 255));
//	painter.drawRect(temp);
//}

void ALCanvas::mouseReleaseEvent(QMouseEvent *event)
{
	//������ͷź󣬱���β����.
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
	//�����������ʱ������������.�������ػ�.
	delete_flag = 0;
	if (event->button() == Qt::LeftButton)
	{
		//�����ʱ���³�ʼλ��.
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