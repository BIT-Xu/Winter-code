#include "ImgShower.h"
#include <qgridlayout.h>
#include <qfiledialog.h>
#include <qmessagebox.h>

ImgShower::ImgShower(QWidget *parent) :
	QWidget(parent)
{
	setAutoFillBackground(true);
	setPalette(QPalette(QColor(240, 255, 255)));

	//图片显示区域（原图以及二值化结果）
	m_imgLabel = new QLabel(this);
	m_imgThresLabel = new QLabel(this);
	QString borderStyle = "border:2px solid black;";
	m_imgLabel->setStyleSheet(borderStyle);
	m_imgThresLabel->setStyleSheet(borderStyle);

	//二值化滚动条
	m_thresSlider = new QSlider(this);
	m_thresSlider->setOrientation(Qt::Horizontal);  // 水平方向
	m_thresSlider->setMinimum(0);
	m_thresSlider->setMaximum(255);
	m_thresSlider->setValue(127);

	//打开图片按钮
	m_openImg = new QPushButton(this);
	m_openImg->setText(tr("打开图片"));
	m_openImg->setFont(QFont("Timers", 14));

	//反选按钮
	m_chose = new QPushButton(this);
	m_chose->setText(tr("反选"));
	m_chose->setFont(QFont("Timers", 14));

	//布局设置
	QGridLayout *layout = new QGridLayout(this);
	/*layout->addWidget(m_imgLabel, 1, 0, 3, 3);
	layout->addWidget(m_imgThresLabel, 1, 4, 3, 3);
	layout->addWidget(m_openImg, 4, 0, 1, 3);
	layout->addWidget(m_thresSlider, 4, 4, 1, 3);*/

	layout->addWidget(m_imgLabel,		1, 0, 3, 3);
	layout->addWidget(m_imgThresLabel,  1, 4, 3, 3);
	layout->addWidget(m_openImg,		4, 0, 1, 2);
	layout->addWidget(m_thresSlider,	4, 4, 1, 3);
	layout->addWidget(m_chose,			4, 2, 1, 1);

	connect(m_openImg, SIGNAL(clicked()), this, SLOT(OpenImg()));
	connect(m_chose, SIGNAL(clicked()), this, SLOT(ChoseImg()));
	connect(m_thresSlider, SIGNAL(valueChanged(int)), this, SLOT(ReThreshold(int)));
}


ImgShower::~ImgShower()
{
}

void ImgShower::OpenImg()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image File(*.png *.jpg *.jpeg *.bmp)"));
	if (fileName.isEmpty())
	{
		QMessageBox::warning(this, tr("警告！"), tr("读取图片失败！"), QMessageBox::Yes);
		return;
	}

	m_img = cv::imread(fileName.toLatin1().data());//读取图片数据
	cv::cvtColor(m_img, m_img, cv::COLOR_BGR2GRAY);//图像格式转换
	QImage img = QImage((const unsigned char*)(m_img.data), m_img.cols, m_img.rows, QImage::Format_Grayscale8);

	float wRate = 1.f * m_img.cols / m_imgLabel->width(), hRate = 1.f * m_img.rows / m_imgLabel->height();

	if (wRate > 1.f || hRate > 1.f) {
		m_scaleRate = 1 / (hRate > wRate ? hRate : wRate);
		img = img.scaled(QSize(img.width() * m_scaleRate, img.height() * m_scaleRate));
	}
	else
		m_scaleRate = -1.f;

	m_imgLabel->setPixmap(QPixmap::fromImage(img));//显示图像
	ReThreshold(m_thresSlider->value());
}

void ImgShower::ReThreshold(int val)
{
	cv::threshold(m_img, m_imgThres, val, 255, 0);

	QImage img = QImage((const unsigned char*)(m_imgThres.data), m_imgThres.cols, m_imgThres.rows, QImage::Format_Grayscale8);

	if (m_scaleRate > 0) {
		img = img.scaled(QSize(img.width() * m_scaleRate, img.height() * m_scaleRate));
	}
	m_imgThresLabel->setPixmap(QPixmap::fromImage(img));//显示图像
}

bool ImgShower::GetData(int& width, int& height, QVector<unsigned char>& mat)
{
	if (m_imgThres.empty())
		return false;

	width = m_imgThres.cols, height = m_imgThres.rows;
	mat.resize(width * height);

	//将cv::Mat转化为一位数组
	for (int i = 0; i < m_imgThres.rows; i++) {
		uchar*pdata = m_imgThres.ptr<uchar>(i);
		for (int j = 0; j < m_imgThres.cols; j++) {
			mat[i * m_imgThres.cols + j] = pdata[j];
		};
	}

	return true;
}

bool ImgShower::GetData(cv::Mat& mat)
{
	if (m_imgThres.empty())
		return false;

	mat = m_imgThres;
	return true;
}

void ImgShower::ChoseImg()
{
	back_flag = 1 - back_flag;
}