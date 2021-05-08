//递归分治法

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <fstream>
#define random(a, b) (rand() % (b - a) + a)
#define N 100
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
int Partition(point r[], int first, int end, int flag) //快排定轴函数,flag=0时对横坐标x进行快排，flag=1时对纵坐标y进行快排
{
    int i = first, j = end;
    point temp;
    if (flag == 0)
    {
        while (i < j)
        {
            while (i < j && r[i].x <= r[j].x)
                j--; //快排定轴右遍历
            if (i < j)
            {
                temp = r[i];
                r[i] = r[j];
                r[j] = temp;
                i++;
            }
            while (i < j && r[i].x <= r[j].x)
                i++; //继续开始左遍历
            if (i < j)
            {
                temp = r[i];
                r[i] = r[j];
                r[j] = temp;
                j--;
            }
        }
        return i; //最后i==j时返回i即得到中轴
    }
    else
    {
        while (i < j)
        {
            while (i < j && r[i].y <= r[j].y)
                j--;
            if (i < j)
            {
                temp = r[i];
                r[i] = r[j];
                r[j] = temp;
                i++;
            }
            while (i < j && r[i].y <= r[j].y)
                i++;
            if (i < j)
            {
                temp = r[i];
                r[i] = r[j];
                r[j] = temp;
                j--;
            }
        }
        return i;
    }
}
void Quicksort(point r[], int first, int end, int flag) //快排,flag=0时对横坐标x进行快排，flag=1时对纵坐标y进行快排
{
    int pivot;
    if (flag == 0)
    {
        if (first < end)
        {
            pivot = Partition(r, first, end, flag);
            Quicksort(r, first, pivot - 1, flag);
            Quicksort(r, pivot + 1, end, flag);
        }
    }
    else
    {
        if (first < end)
        {
            pivot = Partition(r, first, end, flag);
            Quicksort(r, first, pivot - 1, flag);
            Quicksort(r, pivot + 1, end, flag);
        }
    }
}
double Distance(point a, point b) //计算两点间距离
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
distance_index Closeset(point S[], int low, int high)
{
    int mid, i, j, index;
    point P[N];
    distance_index D1, D2, D3, D;
    if (high - low == 1) //如果只有两个点则直接计算点对距离
    {
        D.distance = Distance(S[low], S[high]);
        D.index1 = S[low];
        D.index2 = S[high];
        return D;
    }
    if (high - low == 2) //如果只有三个点则直接计算点对距离
    {
        D1.distance = Distance(S[low], S[low + 1]);
        D2.distance = Distance(S[low + 1], S[high]);
        D3.distance = Distance(S[low], S[high]);
        if ((D1.distance < D2.distance) && (D1.distance < D3.distance))
        {
            D1.index1 = S[low];
            D1.index2 = S[low + 1];
            return D1;
        }
        else if (D2.distance < D3.distance)
        {
            D2.index1 = S[low + 1];
            D2.index2 = S[high];
            return D2;
        }
        else
        {
            D3.index1 = S[low];
            D3.index2 = S[high];
            return D3;
        }
    }

    //当点的个数大于3个时
    mid = (low + high) / 2;          //根据横坐标计算中间点(主函数里数组已按横坐标排好序了)
    D1 = Closeset(S, low, mid);      //递归    求解子问题①
    D2 = Closeset(S, mid + 1, high); //递归    求解子问题②
    if (D1.distance <= D2.distance)  //取分属于S1、S2的最近点对
        D = D1;
    else
        D = D2;
    index = 0;
    for (i = mid; (i >= low) && (S[mid].x - S[i].x < D.distance); i--) //将中间点左边与中间点横坐标距离在d以内的点存到集合p中
        P[index++] = S[i];
    for (i = mid + 1; (i <= high) && (S[i].x - S[mid].x < D.distance); i++) //将中间点右边与中间点横坐标距离在d以内的点存到集合p中
        P[index++] = S[i];
    Quicksort(P, 0, index - 1, 1); //对集合p中的点按y坐标升序排列,0代表横坐标排序，1代表纵坐标排序
    for (i = 0; i < index; i++)    //从小到大依次处理集合p中的点
    {
        for (j = i + 1; j < index; j++)
        {
            if (P[j].y - P[i].y >= D.distance) //目的是找出与P[i]的纵坐标y在d范围内的点，所以一旦有一个点超出此范围，则其他点也会超出范围，因为已经升序排列
                break;
            else
            {
                D3.distance = Distance(P[i], P[j]);
                D3.index1 = P[i];
                D3.index2 = P[j];
                if (D3.distance < D.distance)
                {
                    D = D3; //此情况为P、Q分属S1、S2两个部分
                }
            }
        }
    }
    return D;
}

//蛮力法
distance_index manli(point S[], int n)
{
    distance_index D, D1;
    D.distance = Distance(S[0], S[1]);
    D.index1 = S[0];
    D.index2 = S[1];
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
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
    int i;
    point S[N];
    distance_index D;
    srand((int)time(0));                   //保证每次运行时产生的随机数都不同
    for (i = 0; i < N; i++)                //取100个随机横坐标
        S[i].x = random(100, 1000) * 0.01; //随机取一个[1,10)的浮点数（保留两位小数）
    for (i = 0; i < N; i++)                //取100个随机纵坐标
        S[i].y = random(100, 1000) * 0.01; //随机取一个[1,10)的浮点数（保留两位小数）
    Quicksort(S, 0, N - 1, 0);             //对集合s中的点按横坐标升序排列,0代表横坐标排序，1代表纵坐标排序
    cout << "按横坐标升序排列，100个坐标点分别为：" << endl;
    for (i = 0; i < N; i++)
        cout << "(" << S[i].x << "," << S[i].y << ")" << endl;
    D = Closeset(S, 0, N - 1);
    cout << "两个最近点对分别为"
         << "(" << D.index1.x << "," << D.index1.y << ")和(" << D.index2.x << "," << D.index2.y << ")" << endl;
    cout << "最近点对距离为：" << D.distance << endl;

    D = manli(S, N);
    cout << "蛮力法所得出的最近点对为："
         << "(" << D.index1.x << "," << D.index1.y << ")和(" << D.index2.x << "," << D.index2.y << ")" << endl;
    cout << "最近点对距离为：" << D.distance << endl;
    ofstream fout("D:\\Codefield\\Code\\c++\\Algorithm Design\\Recursion & Divide and conquer\\data.txt"); //将所有坐标写进文件
    if (!fout)
        cout << "文件不能打开" << endl;
    else
    {
        for (i = 0; i < N; i++)
            fout << S[i].x << ' ' << S[i].y << endl;
        fout << D.index1.x << ' ' << D.index1.y << endl; //最近点对记录在文件最后两行
        fout << D.index2.x << ' ' << D.index2.y << endl;
        cout << "文件能打开" << endl;
    }
    getchar();
    getchar();
    return 0;
}
