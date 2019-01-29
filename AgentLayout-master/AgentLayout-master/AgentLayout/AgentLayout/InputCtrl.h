#pragma once
#include <qwidget.h>
#include <qslider.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

//�������뽻������
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
	//����������ʼ�����ź�
	//scale ���ű���
	//mode  ģʽ��0Ϊ�̶���࣬1Ϊ�̶�����
	//param �������̶����ģʽ��Ϊ���ֵ���̶�����ģʽ��Ϊ����
	void ShowLayout(float scale, int mode, float param);

	//�����������д���ļ����ź�
	void WriteFile();

private slots:
	void ShowLayoutClicked();

	void ModeSwitch();

	void ChangeScale(int val);

private:
	//���ڵ�����ʾ���ű���
	QLabel* m_imgScaleLabel;
	QSlider* m_imgScale;

	//�̶����ֵ
	QLabel *m_gapLabel;
	QLineEdit *m_gapEdit;

	//����
	QLabel *m_agCntLabel;
	QLineEdit *m_agCntEdit;

	//�л�ģʽ����������������࣬��������������
	QPushButton* m_modeSwitch;

	//��ʼ���
	QPushButton* m_showLayout;

	//����ļ�
	QPushButton* m_WriteFile;

	//0Ϊ�̶���࣬1Ϊ�̶�����
	int m_mode;
};

