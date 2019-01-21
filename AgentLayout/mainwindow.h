#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "alreccanvas.h"
#include "alcirclecanvas.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void StartDirect();
    void StartStep();
    void jump();

private:
    void Start(int mode);

    Ui::MainWindow *ui;
    ALRecCanvas* m_recCanvas;
    ALCircleCanvas* m_circleCanvas;

    //宽度组，变量声明不要初始化，类内部可以以m_开头
    QLabel *WidthLabel;
    QLineEdit *WidthEdit;
    //高度组
    QLabel *HeighLabel;
    QLineEdit *HeightEdit;
    //间隔组
    QLabel *GapLabel;
    QLineEdit *GapEdit;
    //按钮组
    QPushButton *StartMode0;    //直接绘制
    QPushButton *StartMode1;    //顺序绘制
    //跳转组
    QPushButton *JumpButton;
    int m_status;
};

#endif // MAINWINDOW_H
