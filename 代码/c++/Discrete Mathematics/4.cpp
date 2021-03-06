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
    int x = 0;         //用于控制对右上半矩阵按列排序
    int k = 0;         //用于记载排序路径个数
    road route[n * n]; //用于记载排序后的路径
    int min = 100;

    int put_in = 1;

    int r[n * n]; //记录加入树中的路径
    int m = 0;    //记录树种路径的个数

    int S[n];          //记录已在树中节点
    int edgeCount = 0; //记录边长个数
    int PointNum = 0;
    int Flag_P1 = 0;
    int Flag_P2 = 0;

    cout << "请输入一个 " << n << "X" << n << " 的图权矩阵(不可达时请输入0):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> t[i][j];
            if (t[i][j] == 0)
            {
                t[i][j] = 100;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                if (t[i][j] != 100)
                {
                    cout << "输入错误，对角线应全为0" << endl;
                    put_in = 0;
                }
            }
        }
    }

    if (put_in)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = x; j < n; j++)
            {
                route[k].num = t[i][j]; //二维变一维
                route[k].point1 = i;
                route[k].point2 = j;
                k++;
            }
            x++;
        }
        road temp;
        for (int i = 0; i < k - 1; i++) //冒泡排序
        {
            for (int j = 0; j < k - i - 1; j++)
            {
                if (route[j].num > route[j + 1].num)
                {
                    temp = route[j];
                    route[j] = route[j + 1];
                    route[j + 1] = temp;
                }
            }
        }

        for (int i = 0; edgeCount != n - 1; i++)
        {

            for (int j = 0; j < PointNum; j++) //判断两端点是否已经在树内
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
            if (Flag_P1 == 1 && Flag_P2 == 1) //两个端点已经都在树内了 判断是否会形成回路
            {
                int P1_child[n * n];
                int P2_child[n * n];
                int p1 = 0;
                int p2 = 0;
                int FLAG = 0; //标志位判断是否形成回路  默认为不形成
                for (int l = 0; l < m; l++)
                {
                    if (route[l].point1 == route[i].point1)
                    {
                        P1_child[p1] = route[l].point2;
                        p1++;
                    }
                    else if (route[l].point2 == route[i].point1)
                    {
                        P1_child[p1] = route[l].point1;
                        p1++;
                    }

                    if (route[l].point1 == route[i].point2)
                    {
                        P1_child[p2] = route[l].point2;
                        p2++;
                    }
                    else if (route[l].point2 == route[i].point2)
                    {
                        P1_child[p2] = route[l].point1;
                        p2++;
                    }
                }

                for (int g = 0; g < p1; g++)
                {
                    for (int h = 0; h < p2; h++)
                    {
                        if (P1_child[g] == P2_child[h]) //形成回路(算法不严谨，只是搜索了根节点的一个相邻边，但目前只能想到这些办法)
                        {
                            FLAG = 1; //形成了回路
                            break;
                        }
                    }
                }
                if (!FLAG)
                {
                    edgeCount++;
                    cout << route[i].point1 << "--" << route[i].point2 << endl;
                    r[m++] = i;
                }
            }

            else if (Flag_P1 == 1 && Flag_P2 == 0)
            {
                S[PointNum++] = route[i].point2;
                edgeCount++;
                cout << route[i].point1 << "--" << route[i].point2 << endl;
                r[m++] = i;
            }
            else if (Flag_P1 == 0 && Flag_P2 == 1)
            {
                S[PointNum++] = route[i].point1;
                edgeCount++;
                cout << route[i].point1 << "--" << route[i].point2 << endl;
                r[m++] = i;
            }
            else //Flag_P1 == 0 && Flag_P2 == 0
            {
                S[PointNum++] = route[i].point1;
                S[PointNum++] = route[i].point2;
                edgeCount++;
                cout << route[i].point1 << "--" << route[i].point2 << endl;
                r[m++] = i;
            }
        }
    }
    return 0;
}

// 0 6 1 5 0
// 6 0 5 0 3
// 1 5 0 5 6
// 5 0 5 0 0
// 0 3 6 0 0