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
    void move(int);//�����ƶ�
    void replay();//���¿�ʼ
    bool Is_OK();//�ж���Ϸ�Ƿ����
    bool Is_2048(int);//�ж���Ϸ�Ƿ�ʤ��
protected:
    int matrix[4][4];
    int score = 0;
    vector<int> add;
    void Reduce(deque<int>& q, deque<int>& p);
    void ReduceLeft();
    void ReduceRight();
    void ReduceUp();
    void ReduceDown();
    void myRand();//�������2/4
};

class QtWidgetsApplication : public QMainWindow,public CGame
{
    Q_OBJECT

public:
    QtWidgetsApplication(QWidget *parent = nullptr);
    ~QtWidgetsApplication();

    void paintEvent(QPaintEvent*);

    //wasd�¼�
    void keyPressEvent(QKeyEvent* event);

    QPushButton* button;
public slots:
    void slotStart();

private:
    Ui::QtWidgetsApplicationClass ui;
};
