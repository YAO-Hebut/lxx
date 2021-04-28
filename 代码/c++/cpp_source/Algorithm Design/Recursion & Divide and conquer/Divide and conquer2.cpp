//蛮力法

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

struct point //点的横纵坐标（位置）用结构体来表示
{
    double x;
    double y;
};
struct distance_index //每次划分都记录下来两个最近点对的距离和位置
{
    double distance;
    point index1;
    point index2;
};
double Distance(point a, point b) //计算两点间距离
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
distance_index manli(point S[], int n)
{
    distance_index D, D1;
    D.distance = Distance(S[0], S[1]);
    D.index1 = S[0];
    D.index2 = S[1];
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            D1.distance = Distance(S[i], S[j]);
            D1.index1 = S[i];
            D1.index2 = S[j];
            if (D.distance > D1.distance)
            {
                D = D1;
            }
        }
    }
    return D;
}

int main()
{
    point S[100];
    int n;
    cout << "请输入点的个数：";
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        cin >> S[i].x >> S[i].y;
    }
    return 0;
}