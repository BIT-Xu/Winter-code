#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AgentLayout.h"
#include "ImgShower.h"
#include "InputCtrl.h"
#include "ALCanvas.h"
#include "CSVWriter.h"
#include <opencv2\opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>


class AgentLayout : public QMainWindow
{
	Q_OBJECT

public:
	AgentLayout(QWidget *parent = Q_NULLPTR);

private slots:
	void CalcuLayout(float scale, int mode, float param);

	void OutputCSV();


private:
	QVector<QPointF> ConstGapFunc(cv::Mat& mat, float gap);

	QVector<QPointF> ConstNumFunc(cv::Mat& mat, int agtNum);

	Ui::AgentLayoutClass ui;

	ImgShower* m_shower;
	InputCtrl* m_inputCtrl;
	ALCanvas* m_canvas;

	QVector<QPointF> m_agtPos;

	//输出文件坐标范围，TODO：可用配置文件设置
	static const int M_AREAWIDTH = 690;
	static const int M_AREAHEIGHT = 690;



};
