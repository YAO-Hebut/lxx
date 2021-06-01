#include <iostream>
using namespace std;

int const N = 5;

// void chengfa(int a[N][N], int b[N][N])
// {
//     int c[N][N]; //用来存储“乘”完之后的矩阵
//     int i, j, k, sum = 0;
//     for (i = 0; i < N; i++)
//     {
//         for (j = 0; j < N; j++)
//         {
//             for (k = 0; k < N; k++)
//             {
//                 sum += a[i][k] * b[k][j];
//             }
//             c[i][j] = sum;
//             sum = 0;
//         }
//     }
//     a = c;
// }

//***************函数无法直接返回 二维数组 或者太麻烦 因此不用函数计算矩阵乘法而直接在主函数中进行

int isDirect(int a[N][N]) //判断是否为有向图
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[i][j] != a[j][i])
                return 1;
        }
    }
    return 0;
}

int main()
{
    int a[N][N], b[N][N], c[N][N], m;
    int road_num = 0;
    int sum = 0;
    cout << "请输入一个" << N << "行" << N << "列的邻接矩阵:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }
    cout << "请输入链路长度:" << endl;
    cin >> m;
    for (int mx = 1; mx < m; mx++) //从1开始是因为 原邻接矩阵就是A的一次方
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    sum += (b[i][k] * a[k][j]);
                }
                c[i][j] = sum;
                sum = 0;
            }
        }
        for (int l = 0; l < N; l++)
        {
            for (int m = 0; m < N; m++)
            {
                b[l][m] = c[l][m];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << c[i][j] << " ";
            if (c[i][j] == m)
            {
                road_num++;
            }
        }
        cout << endl;
    }
    if (!isDirect(b))
    {
        cout << "为无向图" << endl;
        road_num /= 2;
    }
    else
    {
        cout << "为有向图" << endl;
    }
    cout << "链路数目为：" << road_num << endl;
    return 0;
}