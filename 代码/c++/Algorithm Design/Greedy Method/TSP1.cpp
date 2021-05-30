#include <iostream>
using namespace std;

int const n = 5;

int TSP(int arc[n][n], int w)
{
    int edgeCount = 0;
    int TSPLength = 0;
    int u, v, min;
    int begin, end; //以便输出
    int flag[n] = {0};
    u = w;
    flag[w] = 1;
    cout << "TSP路径为：";
    while (edgeCount < n - 1)
    {
        min = 100;
        for (int i = 1; i <= n; i++)
        {
            if ((flag[i] == 0) && (arc[u][i] != 0) && arc[u][i] < min)
            {
                v = i;
                min = arc[u][i];
            }
        }
        TSPLength += min;
        flag[v] = 1;
        edgeCount++;
        begin = u + 1;
        end = v + 1;
        if (edgeCount == 1)
            cout << begin << "-->" << end;
        else
            cout << "-->" << end;
        u = v;
    }

    cout << "-->" << w + 1 << endl; //形成回路
    TSPLength += arc[v][w];

    return TSPLength;
}

int main()
{
    int arc[n][n], w;
    int Length;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                arc[i][j] = 0;
            }
            else
            {
                cout << "请输入城市" << i + 1 << "与城市" << j + 1 << "之间的距离：";
                cin >> arc[i][j];
            }
        }
    }
    cout << "请输入起始城市：";
    cin >> w;
    Length = TSP(arc, w - 1);
    cout << "最短路径为：" << Length;
    return 0;
}