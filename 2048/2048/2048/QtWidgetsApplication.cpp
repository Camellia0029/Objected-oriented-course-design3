#include "QtWidgetsApplication.h"

CGame::CGame():score(0)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            matrix[i][j] = 0;

    //matrix[1][1] = matrix[2][2] = 1;
}

void CGame::move(int key)
{
    switch (key)
    {
    case  Qt::Key_W:
        ReduceUp();
        break;
    case Qt::Key_S:
        ReduceDown();;
        break;
    case  Qt::Key_A:
        ReduceLeft();
        break;
    case Qt::Key_D:
        ReduceRight();
        break;
    default:
        return;//����������ť
    }
}

void CGame::replay()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            matrix[i][j] = 0;
}

bool CGame::Is_OK()
{
    //������
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 0)
                return true;
            else
            {
                if (matrix[i][j] == matrix[i][j + 1])
                    return true;
            }
        }
    }
    //������
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (matrix[i][j] == 0)
                return true;
            else
            {
                if (matrix[i][j] == matrix[i + 1][j])
                    return true;
            }
        }
    }
    return false;
}

bool CGame::Is_2048(int i)
{
    static int flag = 0;
    if (i == 2048) flag++;
    if (flag == 1)
        return true;
    return false;
}

void CGame::Reduce(deque<int>& q, deque<int>& p)
{
    int temp1, temp2;
    while (!q.empty())
    {
        temp1 = q.front();
        q.pop_front();
        if (!q.empty())
        {
            temp2 = q.front();
            if (temp1 == temp2)
            {
                p.push_back(temp1 + 1);
                q.pop_front();
            }
            else
            {
                p.push_back(temp1);
            }
        }
        else
        {
            p.push_back(temp1);
        }
    }
    //ͳһ����
    /*if (!q.empty())
    {
        int a = q.front();
        q.pop_front();
        if (q.empty())
        {
            p.push_back(a);
        }
        else
        {
            int b = q.front();
            q.pop_front();
            if (a == b)
            {
                p.push_back(a + 1);
            }
            else
            {
                p.push_back(a);
                p.push_back(b);
            }
            if (!q.empty())
            {
                int a = q.front();
                q.pop_front();
                if (q.empty())
                {
                    p.push_back(a);
                }
                else
                {
                    int b = q.front();
                    q.pop_front();
                    if (a == b)
                    {
                        p.push_back(a + 1);
                    }
                    else
                    {
                        p.push_back(a);
                        p.push_back(b);
                    }
                }
            }
        }
    }*/
}

void CGame::ReduceLeft()
{
    deque<int> q;
    deque<int> p;
    for (int i = 0; i < 4; i++)
    {
        q.clear();
        p.clear();
        for (int j = 0; j < 4; j++)
        {
            if (matrix[i][j] > 0)
                q.push_back((matrix[i][j]));
        }
        Reduce(q, p);
        matrix[i][0] = matrix[i][1] = matrix[i][2] = matrix[i][3] = 0;
        for (int k = 0; k < p.size(); k++)
        {
            matrix[i][k] = p[k];
        }
    }
}

void CGame::ReduceRight()
{
    deque<int> q;
    deque<int> p;
    for (int i = 0; i < 4; i++)
    {
        q.clear();
        p.clear();
        for (int j = 3; j >= 0; j--)
        {
            if (matrix[i][j] > 0)
                q.push_back((matrix[i][j]));
        }
        Reduce(q, p);
        matrix[i][0] = matrix[i][1] = matrix[i][2] = matrix[i][3] = 0;
        for (int k = 0; k < p.size(); k++)
        {
            matrix[i][3 - k] = p[k];
        }
    }
}

void CGame::ReduceUp()
{
    deque<int> q;
    deque<int> p;
    for (int j = 0; j < 4; j++)
    {
        q.clear();
        p.clear();
        for (int i = 0; i < 4; i++)
        {
            if (matrix[i][j] > 0)
                q.push_back((matrix[i][j]));
        }
        Reduce(q, p);
        matrix[0][j] = matrix[1][j] = matrix[2][j] = matrix[3][j] = 0;
        for (int k = 0; k < p.size(); k++)
        {
            matrix[k][j] = p[k];
        }
    }
}

void CGame::ReduceDown()
{
    deque<int> q;
    deque<int> p;
    for (int j = 0; j < 4; j++)
    {
        q.clear();
        p.clear();
        for (int i = 3; i >= 0; i--)
        {
            if (matrix[i][j] > 0)
                q.push_back((matrix[i][j]));
        }
        Reduce(q, p);
        matrix[0][j] = matrix[1][j] = matrix[2][j] = matrix[3][j] = 0;
        for (int k = 0; k < p.size(); k++)
        {
            matrix[3 - k][j] = p[k];
        }
    }
}


QtWidgetsApplication::QtWidgetsApplication(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowTitle("2048");
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);    //ʧ�����
    setFixedSize(600, 600);                      //�̶����ڳߴ�

    //��ʼ������
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            matrix[i][j] = 0;

    button = new QPushButton("��ʼ��Ϸ", this);
    button->setGeometry(200, 525, 200, 50);

    //�������
    qsrand(uint(QTime(0, 0, 0).secsTo(QTime::currentTime())));

    //�ź����
    connect(button, SIGNAL(clicked()), this, SLOT(slotStart()));
}

QtWidgetsApplication::~QtWidgetsApplication()
{}

void QtWidgetsApplication::paintEvent(QPaintEvent*)
{
    //��ͼ
    QPixmap bmp;
    bmp.load("D:\\QQ�ļ�����\\2048.bmp");
    QPainter painter(this);
    score = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            painter.drawPixmap(100 + 100 * j, 100 + 100 * i, bmp, 90 * matrix[i][j], 0, 90, 90);
            if (matrix[i][j] != 0)
            {
                score += pow(2, matrix[i][j]);
            }
        }

    QPainter p(this);
    p.setFont(QFont("΢���ź�", 15, 700, false));
    p.drawText(QPoint(20, 60), "����:" + QString::number(score));
}

void QtWidgetsApplication::keyPressEvent(QKeyEvent* event)
{
    //�ж���Ϸ�Ƿ�ʤ��
    for (int i = 0; i < 16; i++)
    {
        if (Is_2048(matrix[i / 4][i % 4]))
            QMessageBox::about(this, "��Ϸʤ��", "��Ϸʤ��������Լ�����̸��߷�����");
    }
    //�ж���Ϸ�Ƿ����
    if (!Is_OK())
    {
        QMessageBox::about(this, "��Ϸ����", "  ����Ϊ��" + QString::number(score) + "    ");
        return;
    }
    CGame::move(event->key());

    myRand();
    
    update();//ǿ�ƽ���ˢ�¡�������
}

//��Ϸ�����£���ʼ
void QtWidgetsApplication::slotStart()
{
    QMessageBox::about(this, "��Ϸ����", "WSAD���Ʒ������������ƶ�");
    score = 0;
    button->setText("������Ϸ");
    replay();
    int randi = qrand() % 4;//0 1 2 3
    int randj = qrand() % 4;//0 1 2 3
    matrix[randi][randj] = 1;
    update();
}

void CGame::myRand()
{
    add.clear();
    //������ӵ����������n
    for (int i = 0; i < 16; i++)
    {
        if (matrix[i / 4][i % 4] == 0)
            add.push_back(i);
    }
    //������ĸ���������һ��2��4
    int rand = add[qrand() % add.size()];
    matrix[rand / 4][rand % 4] = (qrand()%2)+1;
}