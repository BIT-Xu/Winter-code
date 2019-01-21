#include "rectangle.h"
#include "ui_rectangle.h"
#include <mainwindow.h>

#include <QPen>
#include <QPainter>

Rectangle::Rectangle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rectangle)
{
    ui->setupUi(this);

    this->setStyleSheet(QString("QWidget {background-color:green;}"));
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);hide();
    setGeometry(0, 250, 700, 550);
}

Rectangle::~Rectangle()
{
    delete ui;
}

void Rectangle::paintEvent(QPaintEvent *)
{
    QPen pen;
    QPainter painter(this);


    pen.setWidth(2);
    painter.setPen(pen); // 设置画笔

    for (int i=0;i<current_num;i++){
       painter.drawPoint(pointff[i].x(),pointff[i].y());
    }


    return ;
}

void Rectangle::Calculation(int h, int w)
{
    int x=150;
    int y=100;
    count=0;


    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=w; j++)
        {
            pointff[count].setX(x);
            pointff[count++].setY(y);
            x=x+5;
        }
        x=150;
        y=y+5;
    }
}

void Rectangle::paint_1()
{
    current_num=count;
    update();

}

void Rectangle::paint_2()
{
    current_num=0;

    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Update()));
    timer->start(10);
}

void Rectangle::Update()
{
    current_num++;
    update();
}

