#include "circle.h"
#include "ui_circle.h"
#include <mainwindow.h>

#include <QPen>
#include <QPainter>

Circle::Circle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Circle)
{
    ui->setupUi(this);

    this->setStyleSheet(QString("QWidget {background-color:yellow;}"));
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);hide();
    setGeometry(0, 250, 700, 550);
}

Circle::~Circle()
{
    delete ui;
}

void Circle::paintEvent(QPaintEvent *)
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

//假定圆心为(300,250)
void Circle:: Calculation(int r)
{
    count=0;
    for(int i=0; i<=600; i=i+5)
    {
        for(int j=0; j<=900; j=j+5)
        {
            if((i-300)*(i-300)+(j-250)*(j-250)<=r*r)
            {
                pointff[count].setX(i);
                pointff[count++].setY(j);
            }
        }
    }

}


void Circle::paint_1()
{
    current_num=count;
    update();
}

void Circle::paint_2()
{
    current_num=0;

    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Update()));
    timer->start(10);
}

void Circle::Update()
{
    current_num++;
    update();
}
