#include <iostream>

using namespace std;

//比较两个数的大小，返回较大的数
int max(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}
//01背包动态规划算法
int KnapSack(int C, int n, int w[], int v[])
{
    int V[n + 1][C + 1];

    for (int i = 0; i <= n; i++)
    {
        V[i][0] = 0;
    }
    for (int j = 0; j <= C; j++)
    {
        V[0][j] = 0;
    }
    //计算第i行，进行第i次迭代
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (j < w[i])
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
        }
    }
    //装入的物品
    int x[n];
    int j = C;
    cout << "装入的物品(从后向前):";
    for (int i = n; i >= 1; i--) //反推
    {
        if (V[i][j] > V[i - 1][j])
        {
            x[i] = 1;
            j = j - w[i];
        }
        else
            x[i] = 0;
        cout << x[i] << ' ';
    }
    cout << endl;
    return V[n][C];
}

int main()
{
    int n;
    int C;
    cout << "输入物品的个数：";
    cin >> n;
    cout << "输入背包的容量：";
    cin >> C;
    int v[n];
    int w[n];
    for (int i = 1; i <= n; i++)
    {
        cout << "输入第" << i << "个物品的质量：";
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "输入第" << i << "个物品的价值：";
        cin >> v[i];
    }
    cout << "背包装入最大物品价值为：" << KnapSack(C, n, w, v) << endl;
}