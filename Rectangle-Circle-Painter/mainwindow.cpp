#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <circle.h>
#include <rectangle.h>
#include <QPainter>
#include <QPen>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->setupUi(this);
    setGeometry(400, 100, 700, 800);

    textEdit_1=new QTextEdit(this);
    textEdit_1->setGeometry(100,30,300,50);//set the position and size(int x,int y,int w,int h)

    textEdit_2=new QTextEdit(this);
    textEdit_2->setGeometry(100,100,300,50);//set the position and size(int x,int y,int w,int h)

    textEdit_3=new QTextEdit(this);
    textEdit_3->setGeometry(100,170,300,50);//set the position and size(int x,int y,int w,int h)

    button_1=new QPushButton(this);
    button_1->setGeometry(500, 30, 150, 50);
    button_1->setText("连续打点");

    button_2=new QPushButton(this);
    button_2->setGeometry(500, 100, 150, 50);
    button_2->setText("存在时间间隔打点");

    button_3=new QPushButton(this);
    button_3->setGeometry(500, 170, 60, 50);
    button_3->setText("圆形");

    button_4=new QPushButton(this);
    button_4->setGeometry(600, 170, 60, 50);
    button_4->setText("矩形");

    label_1=new QLabel(this);
    label_1->setText("高度");
    label_1->setGeometry(50,30,50,50);

    label_2=new QLabel(this);
    label_2->setText("宽度");
    label_2->setGeometry(50,100,50,50);

    label_3=new QLabel(this);
    label_3->setText("半径");
    label_3->setGeometry(50,170,50,50);

    connect(button_3, SIGNAL(clicked(bool)), this, SLOT(Circle_Paint()));
    connect(button_4, SIGNAL(clicked(bool)), this, SLOT(Rectangle_Paint()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Circle_Paint()
{
    circle=new Circle(this);
    circle->show();
    circle->Calculation(textEdit_3->toPlainText().toInt()) ;
    connect(MainWindow::button_1, SIGNAL(clicked(bool)), circle, SLOT(paint_1()));
    connect(MainWindow::button_2, SIGNAL(clicked(bool)), circle, SLOT(paint_2()));

}


void MainWindow::Rectangle_Paint()
{
    rectangle=new Rectangle(this);
    rectangle->show();

    rectangle->Calculation(textEdit_1->toPlainText().toInt(), textEdit_2->toPlainText().toInt());

    connect(MainWindow::button_1, SIGNAL(clicked(bool)), rectangle, SLOT(paint_1()));
    connect(MainWindow::button_2, SIGNAL(clicked(bool)), rectangle, SLOT(paint_2()));

}
