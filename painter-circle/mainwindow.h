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
#include <dialog_1.h>
#include <form.h>
#include <dialog2.h>


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

    Dialog* dialog_1;
    Form* form_1;
    Dialog2* dialog_2;


    QTimer* timer;
private:
    int count=0;
    int current_num;
    int r;
    QPointF pointff[60000];

};

#endif // MAINWINDOW_H
