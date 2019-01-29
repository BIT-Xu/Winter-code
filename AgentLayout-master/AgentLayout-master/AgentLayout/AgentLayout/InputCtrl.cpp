#include "InputCtrl.h"
#include <qgridlayout.h>
#include <qmessagebox.h>

//TODO���Ѹ����ؼ�����һ��״̬���Ų�һ��,�ڲ�֪���Լ��ߴ��ǰ����ʹ�����λ�ã�����ؼ��ߴ�
InputCtrl::InputCtrl(QWidget *parent) :
	QWidget(parent),
	m_mode(0)
{
	setAutoFillBackground(true);
	setPalette(QPalette(QColor(255, 248, 220)));

	//ͳһ����
	QFont font = QFont("Timers", 14);

	//���ڵ�����ʾ���ű���
	m_imgScaleLabel = new QLabel(this);
	m_imgScaleLabel->setText(tr("���ű�����0"));
	m_imgScaleLabel->setAlignment(Qt::AlignLeft);
	m_imgScaleLabel->setFont(font);

	m_imgScale = new QSlider(this);
	m_imgScale->setOrientation(Qt::Horizontal);  // ˮƽ����
	m_imgScale->setMinimum(-3);
	m_imgScale->setMaximum(3);
	m_imgScale->setValue(0);

	//�̶����ֵ
	m_gapLabel = new QLabel(this);
	m_gapLabel->setText(tr("���"));
	m_gapLabel->setFont(font);
	m_gapLabel->setAlignment(Qt::AlignLeft);
	m_gapEdit = new QLineEdit(this);
	m_gapEdit->setPlaceholderText(tr("��������ֵ"));
	m_gapEdit->setFont(font);

	//����
	m_agCntLabel = new QLabel(this);
	m_agCntLabel->setText(tr("����"));
	m_agCntLabel->setAlignment(Qt::AlignLeft);
	m_agCntLabel->setFont(font);
	m_agCntEdit = new QLineEdit(this);
	m_agCntEdit->setPlaceholderText(tr("����������"));
	m_agCntEdit->setFont(font);

	//�л�ģʽ����������������࣬��������������
	m_modeSwitch = new QPushButton(this);
	m_modeSwitch->setText(tr("�̶�����ģʽ"));
	m_modeSwitch->setFont(font);
	//��ʼ���
	m_showLayout = new QPushButton(this);
	m_showLayout->setText(tr("��ʼ���"));
	m_showLayout->setFont(font);
	//����ļ�
	m_WriteFile = new QPushButton(this);
	m_WriteFile->setText(tr("��������ļ�"));
	m_WriteFile->setFont(font);

	//�趨����
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

	//������ź����
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
	if (m_mode == 0) {//�̶����
		float gap = m_gapEdit->text().trimmed().toFloat();
		if (gap <= 0) {
			QMessageBox::warning(this, tr("���棡"), tr("������������0��"), QMessageBox::Yes);
		}
		else if (gap > 70) {
			QMessageBox::warning(this, tr("���棡"), tr("���볬�������ᣡ"), QMessageBox::Yes);
		}
		else
			emit ShowLayout(scale, 0, gap);
	}
	if (m_mode == 1) {//�̶�����
		int AgtNum = m_agCntEdit->text().trimmed().toInt();
		if (AgtNum <= 0) {
			QMessageBox::warning(this, tr("���棡"), tr("������������Ϊ����0��������"), QMessageBox::Yes);
		}
		/*else if (AgtNum > 50000) {
			QMessageBox::warning(this, tr("���棡"), tr("������������"), QMessageBox::Yes);
		}*/
		else
			emit ShowLayout(scale, 1, AgtNum);
	}

}

void InputCtrl::ChangeScale(int val)
{
	m_imgScaleLabel->setText(tr("���ű�����") + QString("%1").arg(val));
}

void InputCtrl::ModeSwitch()
{
	m_mode = 1 - m_mode;
	if (m_mode == 0) {
		m_modeSwitch->setText(tr("�̶����ģʽ"));
		m_agCntLabel->setEnabled(false);
		m_agCntEdit->setEnabled(false);
		m_gapLabel->setEnabled(true);
		m_gapEdit->setEnabled(true);
	}
	else {
		m_modeSwitch->setText(tr("�̶�����ģʽ"));
		m_gapLabel->setEnabled(false);
		m_gapEdit->setEnabled(false);
		m_agCntLabel->setEnabled(true);
		m_agCntEdit->setEnabled(true);
	}
}