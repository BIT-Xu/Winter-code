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

//�򿪲���ʾͼƬ�Լ���ֵ��Ч��
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
	//ͼƬ��ʾ����ԭͼ�Լ���ֵ�������
	QLabel* m_imgLabel;
	QLabel* m_imgThresLabel;

	//��ֵ��������
	QSlider* m_thresSlider;

	//��ͼƬ��ť
	QPushButton* m_openImg;

	//��ѡͼƬ��ť
	QPushButton* m_chose;

	//�洢��ȡ��ͼƬ
	cv::Mat m_img;
	cv::Mat m_imgThres;
	float m_scaleRate;

public:
	int back_flag = 1;
};

