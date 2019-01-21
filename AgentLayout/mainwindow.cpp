#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //窗体设置
    setWindowTitle("点阵模拟实践");
    //固定大小
    this->resize(QSize(800,800));
    //背景色设置
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(240,255,255)));
    //宽度组
    WidthLabel = new QLabel(this);
    WidthLabel->setGeometry(190,30,260,40);//set the position and size(int x,int y,int w,int h)
    WidthLabel->setFont(QFont("Timers" , 14));//字体编辑
    WidthLabel->setText(tr("图形宽度："));
    WidthEdit = new QLineEdit(this);
    WidthEdit->setGeometry(300,30,310,40);//位置、尺寸编辑
    WidthEdit->setFont(QFont("Timers" , 14 ));//字体编辑
    WidthEdit->setPlaceholderText(tr("请输入图形宽度"));
    //高度组
    HeighLabel = new QLabel(this);
    HeighLabel->setGeometry(190,80,260,40);//set the position and size(int x,int y,int w,int h)
    HeighLabel->setFont(QFont("Timers" , 14));//字体编辑
    HeighLabel->setText(tr("图形高度："));
    HeightEdit = new QLineEdit(this);
    HeightEdit->setGeometry(300,80,310,40);//位置、尺寸编辑
    HeightEdit->setFont(QFont("Timers" , 14 ));//字体编辑
    HeightEdit->setPlaceholderText(tr("请输入图形高度"));
    //间隔组
    GapLabel = new QLabel(this);
    GapLabel->setGeometry(190,130,260,40);//set the position and size(int x,int y,int w,int h)
    GapLabel->setFont(QFont("Timers" , 14));//字体编辑
    GapLabel->setText(tr("点阵间隔："));
    GapEdit = new QLineEdit(this);
    GapEdit->setGeometry(300,130,310,40);//位置、尺寸编辑
    GapEdit->setFont(QFont("Timers" , 14 ));//字体编辑
    GapEdit->setPlaceholderText(tr("请输入点阵间隔"));
    //按钮组
    StartMode0 = new QPushButton(this);
    StartMode0->setGeometry(220, 180, 150, 40);
    StartMode0->setFont(QFont("Timers" , 14 ));//字体编辑
    StartMode0->setText(tr("直接输出点阵"));
    StartMode1 = new QPushButton(this);
    StartMode1->setGeometry(430, 180, 150, 40);
    StartMode1->setFont(QFont("Timers" , 14 ));//字体编辑
    StartMode1->setText(tr("逐步输出点阵"));

    m_recCanvas = new ALRecCanvas(this);
    m_recCanvas->move(0, 250);
    m_recCanvas->resize(QSize(800,550));
    m_recCanvas->hide();

    m_circleCanvas = new ALCircleCanvas(this);
    m_circleCanvas->move(0, 250);
    m_circleCanvas->resize(QSize(800,550));

    //跳转按钮
    JumpButton=new QPushButton(this);
    JumpButton->setGeometry(0, 0, 150, 40);
    JumpButton->setFont(QFont("Timers" , 14 ));//字体编辑
    JumpButton->setText(tr("切换为矩形"));
    m_status = 0;

    //信号槽绑定
    connect(StartMode0,&QPushButton::clicked,this,&MainWindow::StartDirect);
    connect(StartMode1,&QPushButton::clicked,this,&MainWindow::StartStep);
    connect(JumpButton,&QPushButton::clicked,this,&MainWindow::jump);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StartDirect()
{
    Start(0);
}

void MainWindow::StartStep()
{
    Start(1);
}

void MainWindow::jump(){
    if(m_status==0){
        JumpButton->setText(tr("切换为圆形"));
        m_recCanvas->show();
        m_recCanvas->StartDraw(0,0,0,0);
        m_circleCanvas->hide();
        m_status=1;
    }
    else{
        JumpButton->setText(tr("切换为矩形"));
        m_circleCanvas->show();
        m_circleCanvas->StartDraw(0,0,0,0);
        m_recCanvas->hide();
        m_status=0;
    }
}


void MainWindow::Start(int mode)
{
    int width = 0;
    int height = 0;
    int gap = 0;
    if (WidthEdit->text().isEmpty()){
        QMessageBox::warning(this, tr("警告！"),tr("宽度不能为空！"),QMessageBox::Yes);
    }
    if (HeightEdit->text().isEmpty()){
        QMessageBox::warning(this, tr("警告！"),tr("高度不能为空！"),QMessageBox::Yes);
    }
    if (GapEdit->text().isEmpty()){
        gap = 5;
    }
    else{
        gap = GapEdit->text().trimmed().toInt();
    }
    width = WidthEdit->text().trimmed().toInt();
    height = HeightEdit->text().trimmed().toInt();

    if (!m_recCanvas->StartDraw(width, height, gap, mode))
        QMessageBox::warning(this, tr("警告！"), tr("超出边界！（尺寸应小于800*550）"), QMessageBox::Yes);
    if (!m_circleCanvas->StartDraw(width, height, gap, mode))
        QMessageBox::warning(this, tr("警告！"), tr("超出边界！（尺寸应小于800*550）"), QMessageBox::Yes);
}
