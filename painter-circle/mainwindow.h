#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPainter>
#include <QMainWindow>
#include <QPen>
#include <QTimer>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QPointF>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   void paintEvent(QPaintEvent*);
   void Calculation();

signals:
    void click_me();

private slots:
    void paint_1();
    void paint_2();
    void UpDate();

private:
    Ui::MainWindow *ui;

    QTextEdit* textEdit_1;
    QPushButton* button_1;
    QPushButton* button_2;
    QLabel* label_1;

    QTimer* timer;
public:
    int count=0;
    int current_num;
    int r;
    QPointF pointff[60000];

};

#endif // MAINWINDOW_H
