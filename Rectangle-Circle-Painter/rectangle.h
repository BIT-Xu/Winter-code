#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QDialog>
#include <QPointF>
#include <QTimer>

namespace Ui {
class Rectangle;
}

class Rectangle : public QDialog
{
    Q_OBJECT

public:
    explicit Rectangle(QWidget *parent = 0);
    ~Rectangle();

private:
    Ui::Rectangle *ui;

private slots:
    void paint_1();
    void paint_2();
    void Update();

private:  
    void paintEvent(QPaintEvent *);

public:
    QPointF pointff[60000];
    int count;
    int w, h;
    int current_num;
    QTimer* timer;
    void Calculation(int h, int w);
};

#endif // RECTANGLE_H
