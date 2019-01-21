#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPen>
#include <QTimer>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QPointF>

#include <circle.h>
#include <rectangle.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void Circle_Paint();
    void Rectangle_Paint();

private:
    QPushButton* button_1;
    QPushButton* button_2;
    QPushButton* button_3;
    QPushButton* button_4;
    QLabel* label_1;
    QLabel* label_2;
    QLabel* label_3;

    Circle* circle;
    Rectangle* rectangle;

    QTimer* timer;
public:
    QTextEdit* textEdit_1;
    QTextEdit* textEdit_2;
    QTextEdit* textEdit_3;
    int count=0;
    int w, h;
    int x, y;
    QPointF pointff[6000];
};

#endif // MAINWINDOW_H
