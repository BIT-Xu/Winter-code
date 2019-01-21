#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    this->setStyleSheet(QString("QWidget {background-color:blue;}"));

    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);hide();
    setGeometry(0, 200, 700, 550);
}

Form::~Form()
{
    delete ui;
}
