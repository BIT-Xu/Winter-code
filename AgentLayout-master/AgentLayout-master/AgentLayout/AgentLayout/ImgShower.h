#pragma once
#include <qwidget.h>
#include <qlabel.h>
#include <qslider.h>
#include <qpushbutton.h>
#include <opencv2\opencv.hpp>
#include <qvector.h>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

//打开并显示图片以及二值化效果
class ImgShower :
	public QWidget
{
	Q_OBJECT
public:
	ImgShower(QWidget *parent = Q_NULLPTR);
	~ImgShower();

	bool GetData(int& width, int& height, QVector<unsigned char>& mat);

	bool GetData(cv::Mat& mat);

private slots:
	void OpenImg();

	void ReThreshold(int val);

	void ChoseImg();

private:
	//图片显示区域（原图以及二值化结果）
	QLabel* m_imgLabel;
	QLabel* m_imgThresLabel;

	//二值化滚动条
	QSlider* m_thresSlider;

	//打开图片按钮
	QPushButton* m_openImg;

	//反选图片按钮
	QPushButton* m_chose;

	//存储读取的图片
	cv::Mat m_img;
	cv::Mat m_imgThres;
	float m_scaleRate;

public:
	int back_flag = 1;
};

