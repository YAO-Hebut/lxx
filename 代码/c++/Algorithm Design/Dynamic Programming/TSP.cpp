#include <iostream>
#include <cmath>

using namespace std;

int arc[20][20];           //城市间距
int d[20][100];            //TSP最终结果
int col;                   //TSP最终结果表的列数
int sub[100];              //子集
void setDistance(int num); //创建城市间间距矩阵C
int subContain(int n);     //判断元素是否存在于子集
int subGather(int n, int num);
/*
	例:将5(二进制101),转化为子集形式
	{1,3}存放在集合sub[]中,
	并返回集合元素个数length;
*/
int deSub(int k, int j);
/*
	例:求集合{1,3}剔除元素3后的子集.
	{1,3}用二进制101表示,剔除元素3
	相当于将右数第三位置0.
	因此,可以将数字1(二进制001),左移2位为100
	再做差101-100=001
	得到子集{1};
*/
int doTSP(int num);
void show(int num); //输出结果

void setDistance(int num)
{
    int i, j;
    cout << "设置城市的矩阵:" << endl;
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            if (i == j)
                arc[i][j] = -1;
            else
            {
                cout << "请输入城市" << i << " 和城市" << j << "的距离:";
                cin >> arc[i][j];
            }
        }
    }
    cout << "设置成功!" << endl;
}

int subGather(int n, int num) //初始化sub[],并返回子集个数
{
    int length;
    length = 0;
    for (int i = 1; i < num; i++)
    {
        if (n & 1 == 1)
        {
            sub[length++] = i; //sub[]的初始化
        }
        n = n >> 1;
    }
    sub[length] = -1; //作为结束标志
    return length;
}

int subContain(int n)
{
    int i = 0;
    while (sub[i] != -1)
    {
        if (sub[i] == n)
        {
            return 1;
        }
        i++;
    }
    return 0;
}

int deSub(int k, int j)
{
    int temp = 1;
    temp = temp << (k - 1); //左移k-1位
    return j - temp;        //剔除k后的子集
}

int doTSP(int num)
{
    int i, j;
    col = pow(2, (num - 1));
    for (int i = 1; i < num; i++) //初始化d的第一列
    {
        d[i][0] = arc[i][0];
    }
    int length;
    int m = 1;          //m控制此时处于哪个集合阶段
    while (m < num - 1) //按列填入表格，从第2列开始到倒数第二列结束
    {
        for (j = 1; j < col; j++)
        {
            length = subGather(j, num); //子集个数
            if (m == length)
            {
                for (i = 1; i < num; i++) //填入每一行
                {
                    if (subContain(i) == 0) //该元素不存在于该子集
                    {
                        int min = 999;
                        int k;
                        int route;
                        for (k = 0; k < length; k++)
                        {
                            route = arc[i][sub[k]] + d[sub[k]][deSub(sub[k], j)];
                            if (route < min)
                            {
                                min = route;
                            }
                        }
                        d[i][j] = min;
                    }
                }
            }
        }
        m++;
    }

    int min = 999;
    int k;
    int route;
    length = subGather(col - 1, num);
    for (k = 0; k < length; k++) //填入最后一列
    {
        route = arc[0][sub[k]] + d[sub[k]][deSub(sub[k], col - 1)];
        if (route < min)
        {
            min = route;
        }
    }
    d[0][col - 1] = min;
    return d[0][col - 1];
}

void show(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int num;
    int path;
    cout << "请输入节点个数：";
    cin >> num;
    setDistance(num);
    path = doTSP(num);
    cout << "最短路径为：" << path << endl;
    cout << "图表为：" << endl;

    show(num);
    cout << "最短路径为：";
    cout << "1->";
    for (int i = 1; i < num - 1; i++)
    {
        cout << sub[i] << "->"; //填入最后一列时的sub[]就是最短路径点的集合
    }
    cout << "1" << endl;

    return 0;
}
