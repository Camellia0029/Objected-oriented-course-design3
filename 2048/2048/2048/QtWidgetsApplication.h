#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication.h"
#include <qpushbutton.h>
#include <qpainter.h>
#include <QTime>
#include <qevent.h>
#include <qmessagebox.h>
#include <qpixmap.h>
#include <deque>
#include <vector>
#include <iostream>
#include <math.h>


using namespace std;

class CGame
{
public:
    CGame();
    void move(int);//方块移动
    void replay();//重新开始
    bool Is_OK();//判断游戏是否结束
    bool Is_2048(int);//判断游戏是否胜利
protected:
    int matrix[4][4];
    int score = 0;
    vector<int> add;
    void Reduce(deque<int>& q, deque<int>& p);
    void ReduceLeft();
    void ReduceRight();
    void ReduceUp();
    void ReduceDown();
    void myRand();//随机生成2/4
};

class QtWidgetsApplication : public QMainWindow,public CGame
{
    Q_OBJECT

public:
    QtWidgetsApplication(QWidget *parent = nullptr);
    ~QtWidgetsApplication();

    void paintEvent(QPaintEvent*);

    //wasd事件
    void keyPressEvent(QKeyEvent* event);

    QPushButton* button;
public slots:
    void slotStart();

private:
    Ui::QtWidgetsApplicationClass ui;
};
