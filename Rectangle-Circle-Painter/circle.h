#ifndef CIRCLE_H
#define CIRCLE_H

#include <QDialog>
#include <QPointF>
#include <QTimer>

namespace Ui {
class Circle;
}

class Circle : public QDialog
{
    Q_OBJECT

public:
    explicit Circle(QWidget *parent = 0);
    ~Circle();

private:
    Ui::Circle *ui;

private slots:
    void paint_1();
    void paint_2();
    void Update();

public:
    void paintEvent(QPaintEvent *);
    void Calculation(int r);
    QPointF pointff[60000];
    int count;
    int current_num=0;
    QTimer* timer;


};

#endif // CIRCLE_H
