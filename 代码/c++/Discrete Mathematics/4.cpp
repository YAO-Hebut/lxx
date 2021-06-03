#include <iostream>
using namespace std;

int const n = 5;

struct road //用结构体封装起一个路径
{
    int num;    //路径权值
    int point1; //路径端点1
    int point2; //路径端点2
};

// road Sort(int t[n][n]) //对路径进行升序排序
// {
//     int m[n * n][2];   //用于记载路径的两端点
//     int x = 0;         //用于控制对右上半矩阵按列排序
//     int k = 0;         //用于记载排序路径个数
//     road route[n * n]; //用于记载排序后的路径
//     int min = 100;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = x; j < n; j++)
//         {
//             route[k].num = t[i][j]; //二维变一维
//             route[k].point1 = i;
//             route[k].point2 = j;
//             k++;
//         }
//     }
//     road temp;
//     for (int i = 0; i < k; i++) //冒泡排序
//     {
//         for (int j = 0; j < k - i; j++)
//         {
//             if (route[j].num > route[j + 1].num)
//             {
//                 temp = route[j];
//                 route[j] = route[j + 1];
//                 route[j + 1] = temp;
//             }
//         }
//     }
// }

int main()
{
    int t[n][n];
    int m[n * n][2];   //用于记载路径的两端点
    int x = 0;         //用于控制对右上半矩阵按列排序
    int k = 0;         //用于记载排序路径个数
    road route[n * n]; //用于记载排序后的路径
    int min = 100;

    int S[n];          //记录已在树中节点
    int edgeCount = 0; //记录边长个数
    int PointNum = 0;
    int Flag_P1 = 0;
    int Flag_P2 = 0;

    cout << "请输入一个 " << n << "X" << n << " 的图权矩阵(横纵坐标相等时不用输入,默认为100):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                t[i][j] = 100;
            }
            else
            {
                cin >> t[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = x; j < n; j++)
        {
            route[k].num = t[i][j]; //二维变一维
            route[k].point1 = i;
            route[k].point2 = j;
            k++;
        }
    }
    road temp;
    for (int i = 0; i < k; i++) //冒泡排序
    {
        for (int j = 0; j < k - i; j++)
        {
            if (route[j].num > route[j + 1].num)
            {
                temp = route[j];
                route[j] = route[j + 1];
                route[j + 1] = temp;
            }
        }
    }

    while (edgeCount != n - 1)
    {
        int i = 0;
        for (int j = 0; j < PointNum; j++)
        {
            if (route[i].point1 == S[j])
            {
                Flag_P1 = 1;
            }
            if (route[i].point2 == S[j])
            {
                Flag_P2 = 1;
            }
        }
        if (Flag_P1 == 1 && Flag_P2 == 1)
        {
            i++;
            continue;
        }

        else if (Flag_P1 == 1 && Flag_P2 == 0)
        {
            S[PointNum++] = route[i].point2;
            edgeCount++;
            cout << route[i].point1 << "--" << route[i].point2 << endl;
        }
        else if (Flag_P1 == 0 && Flag_P2 == 1)
        {
            S[PointNum++] = route[i].point1;
            edgeCount++;
            cout << route[i].point1 << "--" << route[i].point2 << endl;
        }
        else //Flag_P1 == 0 && Flag_P2 == 0
        {
            S[PointNum++] = route[i].point1;
            S[PointNum++] = route[i].point2;
            edgeCount++;
            cout << route[i].point1 << "--" << route[i].point2 << endl;
        }
        i++;
    }
    return 0;
}

// 6 1 5 100
// 6 5 100 3
// 1 5 5 6
// 5 100 5 100
// 100 3 6 100