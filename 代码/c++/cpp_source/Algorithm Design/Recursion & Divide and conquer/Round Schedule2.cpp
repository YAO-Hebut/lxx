#include <iostream>
using namespace std;
int a[1024][1024];

void schedule_2(int x)
{
    int y = x / 2;
    if (y > 1)
    {
        schedule_2(y);

        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < y; j++)
            {
                a[i + y][j + y] = a[i][j]; //左上赋给右下
            }
            for (int j = 0; j < y; j++)
            {
                a[i + y][j] = a[i][j] + y; //从左侧头部向下赋值
            }
            for (int j = 0; j < y; j++)
            {
                a[i][j + y] = a[i + y][j]; //左下赋给右上
            }
        }
    }
    else //给初始的左上块赋值
    {
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 2;
        a[1][1] = 1;
    }
}

int main()
{
    cout << "请输入要比赛的人数: ";
    int n;
    cin >> n;
    schedule_2(n);
    cout << "  ";
    for (int i = 1; i < n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}