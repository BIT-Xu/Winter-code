#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);

    this->setStyleSheet(QString("QWidget {background-color:red;}"));

    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);hide();
    setGeometry(0, 200, 700, 550);
}

Dialog2::~Dialog2()
{
    delete ui;
}
