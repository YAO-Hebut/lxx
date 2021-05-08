#include <iostream>
using namespace std;
#define N 10

int data[N][N];

void Full(int number, int size, int begin) //number控制赋给矩阵的值，size控制旋转填充的长度，begin控制每次递归的起始位置
{
    if (size == 0)
        return;
    if (size == 1)
    {
        ::data[begin][begin] = number;
        return;
    }
    int i, j, k;
    i = begin;
    j = begin;
    for (k = 0; k < size - 1; k++)
    {
        ::data[i][j] = number++;
        i++;
    } //A部分的输入
    for (k = 0; k < size - 1; k++)
    {
        ::data[i][j] = number++;
        j++;
    } //B部分的输入
    for (k = 0; k < size - 1; k++)
    {
        ::data[i][j] = number++;
        i--;
    } //C部分的输入
    for (k = 0; k < size - 1; k++)
    {
        ::data[i][j] = number++;
        j--;
    }                                  //D部分的输入
    Full(number, size - 2, begin + 1); //找准可以进行递归的参数，以确保递归的正确运行
}

int main()
{
    cout << "请输入矩阵的行列数：";
    int n;
    cin >> n;
    cout << "请输入矩阵的从几开始：";
    int x;
    cin >> x;
    Full(x, n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != n - 1)
                cout << ::data[i][j] << " ";
            else
                cout << ::data[i][j];
        }
        cout << endl;
    }
    return 0;
}