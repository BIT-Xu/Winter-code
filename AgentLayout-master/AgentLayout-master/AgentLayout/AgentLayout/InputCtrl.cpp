#include "InputCtrl.h"
#include <qgridlayout.h>
#include <qmessagebox.h>

//TODO：把各个控件设置一下状态并排布一下,在不知道自己尺寸的前提下使用相对位置，适配控件尺寸
InputCtrl::InputCtrl(QWidget *parent) :
	QWidget(parent),
	m_mode(0)
{
	setAutoFillBackground(true);
	setPalette(QPalette(QColor(255, 248, 220)));

	//统一字体
	QFont font = QFont("Timers", 14);

	//调节点阵显示缩放比例
	m_imgScaleLabel = new QLabel(this);
	m_imgScaleLabel->setText(tr("缩放比例：0"));
	m_imgScaleLabel->setAlignment(Qt::AlignLeft);
	m_imgScaleLabel->setFont(font);

	m_imgScale = new QSlider(this);
	m_imgScale->setOrientation(Qt::Horizontal);  // 水平方向
	m_imgScale->setMinimum(-3);
	m_imgScale->setMaximum(3);
	m_imgScale->setValue(0);

	//固定间距值
	m_gapLabel = new QLabel(this);
	m_gapLabel->setText(tr("间距"));
	m_gapLabel->setFont(font);
	m_gapLabel->setAlignment(Qt::AlignLeft);
	m_gapEdit = new QLineEdit(this);
	m_gapEdit->setPlaceholderText(tr("请输入间距值"));
	m_gapEdit->setFont(font);

	//人数
	m_agCntLabel = new QLabel(this);
	m_agCntLabel->setText(tr("人数"));
	m_agCntLabel->setAlignment(Qt::AlignLeft);
	m_agCntLabel->setFont(font);
	m_agCntEdit = new QLineEdit(this);
	m_agCntEdit->setPlaceholderText(tr("请输入人数"));
	m_agCntEdit->setFont(font);

	//切换模式，输入人数锁定间距，输入间距锁定人数
	m_modeSwitch = new QPushButton(this);
	m_modeSwitch->setText(tr("固定人数模式"));
	m_modeSwitch->setFont(font);
	//开始打点
	m_showLayout = new QPushButton(this);
	m_showLayout->setText(tr("开始打点"));
	m_showLayout->setFont(font);
	//输出文件
	m_WriteFile = new QPushButton(this);
	m_WriteFile->setText(tr("输出坐标文件"));
	m_WriteFile->setFont(font);

	//设定布局
	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(m_imgScaleLabel, 0, 0, 1, 1);
	layout->addWidget(m_imgScale, 0, 1, 1, 2);
	layout->addWidget(m_gapLabel, 2, 0, 1, 1);
	layout->addWidget(m_gapEdit, 2, 1, 1, 2);
	layout->addWidget(m_agCntLabel, 4, 0, 1, 1);
	layout->addWidget(m_agCntEdit, 4, 1, 1, 2);
	layout->addWidget(m_modeSwitch, 0, 4, 1, 1);
	layout->addWidget(m_showLayout, 2, 4, 1, 1);
	layout->addWidget(m_WriteFile, 4, 4, 1, 1);
	layout->setColumnStretch(3, 1);
	layout->setColumnStretch(5, 1);

	//绑定相关信号与槽
	connect(m_modeSwitch, SIGNAL(clicked()), this, SLOT(ModeSwitch()));
	connect(m_WriteFile, SIGNAL(clicked()), this, SIGNAL(WriteFile()));
	connect(m_showLayout, SIGNAL(clicked()), this, SLOT(ShowLayoutClicked()));
	connect(m_imgScale, SIGNAL(valueChanged(int)), this, SLOT(ChangeScale(int)));

	ModeSwitch();
}


InputCtrl::~InputCtrl()
{
}

void InputCtrl::SetAgtNum(int agtNum)
{
	m_agCntEdit->setText(QString("%1").arg(agtNum));
}

void InputCtrl::SetGap(float gap)
{
	m_gapEdit->setText(QString("%1").arg(gap));
}

void InputCtrl::ShowLayoutClicked()
{
	float scale = (m_imgScale->value()) * 0.1 + 1;
	if (m_mode == 0) {//固定间距
		float gap = m_gapEdit->text().trimmed().toFloat();
		if (gap <= 0) {
			QMessageBox::warning(this, tr("警告！"), tr("输入间距必须大于0！"), QMessageBox::Yes);
		}
		else if (gap > 70) {
			QMessageBox::warning(this, tr("警告！"), tr("距离超出坐标轴！"), QMessageBox::Yes);
		}
		else
			emit ShowLayout(scale, 0, gap);
	}
	if (m_mode == 1) {//固定人数
		int AgtNum = m_agCntEdit->text().trimmed().toInt();
		if (AgtNum <= 0) {
			QMessageBox::warning(this, tr("警告！"), tr("输入人数必须为大于0的整数！"), QMessageBox::Yes);
		}
		/*else if (AgtNum > 50000) {
			QMessageBox::warning(this, tr("警告！"), tr("输入人数过大！"), QMessageBox::Yes);
		}*/
		else
			emit ShowLayout(scale, 1, AgtNum);
	}

}

void InputCtrl::ChangeScale(int val)
{
	m_imgScaleLabel->setText(tr("缩放比例：") + QString("%1").arg(val));
}

void InputCtrl::ModeSwitch()
{
	m_mode = 1 - m_mode;
	if (m_mode == 0) {
		m_modeSwitch->setText(tr("固定间距模式"));
		m_agCntLabel->setEnabled(false);
		m_agCntEdit->setEnabled(false);
		m_gapLabel->setEnabled(true);
		m_gapEdit->setEnabled(true);
	}
	else {
		m_modeSwitch->setText(tr("固定人数模式"));
		m_gapLabel->setEnabled(false);
		m_gapEdit->setEnabled(false);
		m_agCntLabel->setEnabled(true);
		m_agCntEdit->setEnabled(true);
	}
}