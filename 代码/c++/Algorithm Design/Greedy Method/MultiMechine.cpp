#include <iostream>
using namespace std;

struct work //用一个结构体来解决换位置不换序号的问题
{
    int number;
    int hour;
};
void MultiMechine(int d[], work t[], int m, int n)
{
    int i, j, k;
    int max = 0;
    int S[m][n]; //以队列的形式进行存储机器M所执行的作业
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            S[i][j] = -1;
        }
    }
    int rear[m];                //队列下标
    for (int i = 0; i < m; i++) //分配前m个作业
    {
        S[i][0] = t[i].number;
        rear[i] = 0;
        d[i] = t[i].hour;
    }
    for (i = m; i < n; i++) //分配剩余作业
    {
        for (j = 0, k = 1; k < m; k++)
        {
            if (d[k] < d[j])
            {
                j = k;
            }
        }
        rear[j]++;
        S[j][rear[j]] = t[i].number;
        d[j] = d[j] + t[i].hour;
    }
    for (i = 0; i < m; i++)
    {
        cout << "机器" << i + 1 << ":";
        for (j = 0; S[i][j] >= 0; j++)
        {
            cout << "作业" << S[i][j] + 1 << " ";
        }
        cout << endl;
    }
    for (i = 0; i < 3; i++)
    {
        if (d[i] > max)
        {
            max = d[i];
        }
    }
    cout << "总共用时：" << max << endl;
}

int main()
{
    int d[100];
    work t[100], temp;
    int m, n;
    cout << "请输入机器的个数：";
    cin >> m;
    cout << "请输入需要处理的作业个数：";
    cin >> n;
    cout << "请输入作业处理时间：";
    for (int i = 0; i < n; i++)
    {
        cin >> t[i].hour;
        t[i].number = i;
    }
    for (int i = 0; i < 7; i++) //冒泡排序
    {
        for (int j = 0; j < 7 - i; j++)
        {
            if (t[j].hour < t[j + 1].hour)
            {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
    cout << "进行降序排序后的作业顺序为：";
    for (int i = 0; i < 7; i++)
    {
        if (i != 6)
            cout << t[i].number << " ";
        else
            cout << t[i].number << endl;
    }
    MultiMechine(d, t, m, n);
    return 0;
}