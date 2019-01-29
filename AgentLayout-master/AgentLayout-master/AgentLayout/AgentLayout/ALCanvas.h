#pragma once
#include <qwidget.h>
#include <qvector.h>
#include <QPixmap>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QMessageBox>
#include <QPainter>
#include <QPaintEvent>
#include <QVector>


//�������������ݺϷ��Խ����жϣ��������߽���޷�����
class ALCanvas :
	public QWidget
{
	Q_OBJECT
public:
	ALCanvas(QWidget *parent = Q_NULLPTR);
	~ALCanvas();

	void Draw(const QVector<QPoint>& pos);

	void paintEvent(QPaintEvent*) override;

private:
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void keyPressEvent(QKeyEvent  *event);
	//void paintEvent(QPaintEvent *event);

private:
	QVector<QPoint> m_agentPos;

private:
	QPoint start;
	QPoint end;
	bool sign = false;
	int delete_flag = 0;
};

