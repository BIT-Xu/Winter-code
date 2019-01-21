#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QPainter>
#include <QPen>

#define SPACE_w 8;
#define SPACE_h 10;
#define ORIGIN_x 100;
#define ORIGIN_y 200;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGeometry(400, 100, 700, 800);

    textEdit_1=new QTextEdit(this);
    textEdit_1->setGeometry(100,30,300,50);//set the position and size(int x,int y,int w,int h)

    button_1=new QPushButton(this);
    button_1->setGeometry(500, 30, 150, 50);
    button_1->setText("连续打点");

    button_2=new QPushButton(this);
    button_2->setGeometry(500, 100, 150, 50);
    button_2->setText("存在时间间隔打点");

    label_1=new QLabel(this);
    label_1->setText("半径");
    label_1->setGeometry(50,30,50,50);

    connect(button_1, SIGNAL(clicked(bool)), this, SLOT(paint_1()));
    connect(button_2, SIGNAL(clicked(bool)), this, SLOT(paint_2()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//假定圆心为(300,400)
void MainWindow:: Calculation()
{
    count=0;
    r = textEdit_1->toPlainText().toInt() ;
    for(int i=0; i<=600; i=i+5)
    {
        for(int j=0; j<=900; j=j+5)
        {
            if((i-300)*(i-300)+(j-400)*(j-400)<=r*r)
            {
                pointff[count].setX(i);
                pointff[count++].setY(j);
            }
        }
    }

}


void MainWindow::paintEvent(QPaintEvent *)
{
    QPen pen;
    QPainter painter(this);

    pen.setWidth(2);
    painter.setPen(pen); // 设置画笔

    for (int i = 0;i<current_num;i++){
        painter.drawPoint(pointff[i].x(),pointff[i].y());
    }

    return ;
}

void MainWindow::paint_1()
{
    Calculation();
    current_num=count;
    update();
}

void MainWindow::paint_2()
{
    Calculation();
    current_num=0;

    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(UpDate()));
    timer->start(50);

}



void MainWindow::UpDate()
{
  current_num++;
  update();
}

/*
void MainWindow::UpDate()
{
   current_num=0;
   for(int i=1; i<=count; i++)
   {
       current_num=i;
       update();
   }
}
*/










