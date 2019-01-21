#include "dialog_1.h"
#include "ui_dialog.h"
#include <QStyleOption>

#include <QPainter>
#include <QPen>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setStyleSheet(QString("QWidget {background-color:yellow;}"));

    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);hide();
    setGeometry(0, 200, 700, 550);
}

Dialog::~Dialog()
{
    delete ui;

}

void Dialog::paintEvent(QPaintEvent *)
{
    QPen pen;
    QPainter painter(this);

    pen.setWidth(50);
    painter.setPen(pen); // 设置画


    for (int i = 0;i<100;i++){
       painter.drawPoint(300, 300);
    }

    return ;
}
