#pragma once
#include <qwidget.h>
#include <qslider.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

//界面输入交互部分
class InputCtrl :
	public QWidget
{
	Q_OBJECT
public:
	InputCtrl(QWidget *parent = Q_NULLPTR);
	~InputCtrl();

	void SetAgtNum(int agtNum);

	void SetGap(float gap);

signals:
	//触发画布开始打点的信号
	//scale 缩放比例
	//mode  模式，0为固定间距，1为固定人数
	//param 参数，固定间距模式下为间距值，固定人数模式下为人数
	void ShowLayout(float scale, int mode, float param);

	//出发将打点结果写入文件的信号
	void WriteFile();

private slots:
	void ShowLayoutClicked();

	void ModeSwitch();

	void ChangeScale(int val);

private:
	//调节点阵显示缩放比例
	QLabel* m_imgScaleLabel;
	QSlider* m_imgScale;

	//固定间距值
	QLabel *m_gapLabel;
	QLineEdit *m_gapEdit;

	//人数
	QLabel *m_agCntLabel;
	QLineEdit *m_agCntEdit;

	//切换模式，输入人数锁定间距，输入间距锁定人数
	QPushButton* m_modeSwitch;

	//开始打点
	QPushButton* m_showLayout;

	//输出文件
	QPushButton* m_WriteFile;

	//0为固定间距，1为固定人数
	int m_mode;
};

