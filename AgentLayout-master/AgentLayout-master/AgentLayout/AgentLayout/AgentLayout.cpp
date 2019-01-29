#include "AgentLayout.h"

#include <qgridlayout.h>
#include <qmessagebox.h>
#include <opencv2\opencv.hpp>

//TODO：把各个控件设置一下状态并排布一下,在不知道自己尺寸的前提下使用相对位置，适配控件尺寸
//TODO：通过信号绑定将各个控件的逻辑有机结合起来
AgentLayout::AgentLayout(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
	setFixedSize(1200, 600);

	m_shower = new ImgShower(this);
	m_inputCtrl = new InputCtrl(this);
	m_canvas = new ALCanvas(this);

	QWidget* m_centralWidget = new QWidget();
	this->setCentralWidget(m_centralWidget);

	//布局管理
	QGridLayout* layout = new QGridLayout(this);
	layout->addWidget(m_shower, 0, 7, 3, 5);
	layout->addWidget(m_inputCtrl, 3, 7, 3, 5);
	layout->addWidget(m_canvas, 0, 0, 6, 7);
	m_centralWidget->setLayout(layout);

	
	

	connect(m_inputCtrl, SIGNAL(ShowLayout(float, int, float)), this, SLOT(CalcuLayout(float, int, float)));
	connect(m_inputCtrl, SIGNAL(WriteFile()), this, SLOT(OutputCSV()));
}

void AgentLayout::CalcuLayout(float scale, int mode, float param)
{
	/*int width = 0, height = 0;
	QVector<unsigned char> mat;
	if (!m_shower->GetData(width, height, mat)) {
		QMessageBox::warning(this, tr("警告！"), tr("请先打开图片进行阈值化获取图案"), QMessageBox::Yes);
		return;
	}*/
	cv::Mat mat;
	if (!m_shower->GetData(mat)) {
		QMessageBox::warning(this, tr("警告！"), tr("请先打开图片进行阈值化获取图案"), QMessageBox::Yes);
		return;
	}

	QVector<QPointF> agtPos;
	//固定间距
	if (mode == 0) {
		agtPos = ConstGapFunc(mat, param);
	}
	//固定人数
	else {
		agtPos = ConstNumFunc(mat, param);
	}

	//坐标居中
	if (fabs(1.f * M_AREAWIDTH / M_AREAHEIGHT - 1.f * mat.cols / mat.rows) > 0.001f) {
		float wRate = 1.f * M_AREAWIDTH / mat.cols, hRate = 1.f * M_AREAHEIGHT / mat.rows;
		float rate = (hRate < wRate ? hRate : wRate);
		float width = mat.cols * rate, height = mat.rows * rate;

		for (auto& i : agtPos) {
			i = i - QPointF(width / 2, height / 2) + QPointF(M_AREAWIDTH / 2, M_AREAHEIGHT / 2);
		}
	}

	m_agtPos = agtPos;

	//乘缩放比例
	for (auto& i : agtPos) {
		i = i * scale;
	}

	//中心点坐标统一
	QPoint oriCen(M_AREAWIDTH * scale / 2, M_AREAHEIGHT * scale / 2);
	QPoint CanvasCen(m_canvas->width() / 2, m_canvas->height() / 2);
	
	for (auto& i : agtPos) {
		i = CanvasCen + (i - oriCen) * (oriCen.x() * 1.f / CanvasCen.x());
	}

	QVector<QPoint> drawData;
	for (auto& i : agtPos) {
		drawData.push_back(QPoint(i.x(),i.y()));
	}
	m_canvas->Draw(drawData);
}

void AgentLayout::OutputCSV()
{
	if (m_agtPos.size() < 1) {
		QMessageBox::warning(this, tr("警告！"), tr("请先点击“开始打点”查看排布结果"), QMessageBox::Yes);
		return;
	}

	bool ret = CSVWriter::GetInstance()->Write("Output.csv", m_agtPos);
	if (ret) {
		QMessageBox::information(this, tr("提示"), tr("CSV文件写入成功！"), QMessageBox::Yes);
	}
}

QVector<QPointF> AgentLayout::ConstGapFunc(cv::Mat& mat, float gap)
{
	const float scaleRate = 10.f;
	QVector<QPointF> ret;
	cv::Mat tMat;
	float wRate = 1.f * M_AREAWIDTH / mat.cols, hRate = 1.f * M_AREAHEIGHT / mat.rows;
	float rate = (hRate < wRate ? hRate : wRate);
	cv::resize(mat, tMat, cv::Size(mat.cols * rate * scaleRate, mat.rows * rate * scaleRate));	//1位小数

	int tGap = gap * 10;
	int count = 0;
	for (int i = 0; i < tMat.rows; i += tGap) {
		uchar*pdata = tMat.ptr<uchar>(i);
		for (int j = 0; j < tMat.cols; j += tGap) {
			if (m_shower->back_flag)
			{
				if (pdata[j] != 0) {
					count++;
					ret.push_back(QPoint(j, i));
				}
			}
			else
			{
				if (pdata[j] == 0) {
					count++;
					ret.push_back(QPoint(j, i));
				}
			}

			
		}
	}
	m_inputCtrl->SetAgtNum(count);

	//坐标系回归
	for (auto& i : ret) {
		i.setX(i.x() / scaleRate);
		i.setY(i.y() / scaleRate);
	}
	
	return ret;
}

QVector<QPointF> AgentLayout::ConstNumFunc(cv::Mat& mat, int agtNum)
{
	const float scaleRate = 10.f;
	QVector<QPointF> ret;
	cv::Mat tMat;
	float wRate = 1.f * M_AREAWIDTH / mat.cols, hRate = 1.f * M_AREAHEIGHT / mat.rows;
	float rate = (hRate < wRate ? hRate : wRate);
	cv::resize(mat, tMat, cv::Size(mat.cols * rate * scaleRate, mat.rows * rate * scaleRate));	//1位小数

	//统计所有点
	int count = 0;
	for (int i = 0; i < tMat.rows; i++) {
		uchar*pdata = tMat.ptr<uchar>(i);
		for (int j = 0; j < tMat.cols; j++) {
			if (m_shower->back_flag)
			{
				if (pdata[j] != 0) {
					count++;
					
				}
			}
			else
			{
				if (pdata[j] == 0) {
					count++;
					
				}
			}
		}
	}

	int gap = sqrt(1.f * count / agtNum);
	bool done = false;

	//迭代直到刚好能把人放进去
	while (!done) {
		count = 0;
		for (int i = 0; i < tMat.rows; i += gap) {
			uchar*pdata = tMat.ptr<uchar>(i);
			for (int j = 0; j < tMat.cols; j += gap) {
				if (m_shower->back_flag)
				{
					if (pdata[j] != 0) { 
						count++;
						ret.push_back(QPoint(j, i));
					}
				}
				else
				{
					if (pdata[j] == 0) {
						count++;
						ret.push_back(QPoint(j, i));
					}
				}
			}
		}

		if (count < agtNum) {
			gap--;
			continue;
		}
		else
			done = true;
	}

	m_inputCtrl->SetGap(gap / scaleRate);

	//剪切人数并将坐标系回归
	count = 0;
	for (auto i = ret.begin(); i != ret.end();) {
		count++;
		if (count > agtNum) {
			i = ret.erase(i);
		}
		else {
			i->setX(i->x() / scaleRate);
			i->setY(i->y() / scaleRate);
			i++;
		}
	}

	return ret;
}

