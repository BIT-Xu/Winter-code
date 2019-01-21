#ifndef ALCANVAS_H
#define ALCANVAS_H

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QTimer>

class ALCanvas : public QWidget
{
    Q_OBJECT

public:
    explicit ALCanvas(QWidget *parent=0);

    //画出m_agentPos中的所有点
    void paintEvent(QPaintEvent*);

public slots:
    void UpdateOutput();

protected:
    void Start(int mode);
protected:
    //agent排布相关数据
    QVector<QPoint> m_agentPos;         //所有agent位置
    int m_gap;                          //agent之间的间距
    QTimer* m_timer;                    //控制按序输出agent的定时器
    int m_showNum;                      //控制按序输出agent的计数器，显示前m_showNum个agent
};

#endif // ALCANVAS_H
