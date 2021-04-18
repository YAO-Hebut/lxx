#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <cstdio>
using namespace std;
struct items
{
    int x, y;
};
int main()
{
    items pre, next;
    int g, h, Mark[100][100], flag = 0, d = 0, Len;
    int Move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //上下左右分开(Move[x][0]为左右移动)(Move[x][1]为上下移动)
    queue<items> Q;                                      //创建一个队列Q
    cin >> g >> h;
    while (g != -1)
    {
        for (int i = 0; i <= g + 1; i++)
        {
            Mark[i][0] = 1;     //最外层都设置为有障碍不同行(为1)
            Mark[i][h + 1] = 1; //最外层都设置为有障碍不同行(为1)
        }
        for (int j = 1; j <= h; j++)
        {
            Mark[0][j] = 1;     //最外层都设置为有障碍不同行(为1)
            Mark[g + 1][j] = 1; //最外层都设置为有障碍不同行(为1)
        }
        for (int i = 1; i <= g; i++)
        {
            for (int j = 1; j <= h; j++)
            {
                cin >> Mark[i][j];
            }
        }
        pre.x = g;
        pre.y = h; //终点为右下角
        Mark[g][h] = 2;
        do
        {
            for (d = 0; d < 4; d++) //d表示:上下左右4个方向
            {
                next.x = pre.x + Move[d][0];
                next.y = pre.y + Move[d][1];
                if (Mark[next.x][next.y] == 0) //表示可行
                {
                    Mark[next.x][next.y] = Mark[pre.x][pre.y] + 1;
                    if (next.x == 1 && next.y == 1)
                        break;    //回到原点
                    Q.push(next); //next入队
                }
            }
            if (next.x == 1 && next.y == 1)
            {
                break;
            }
            if (Q.empty() == true)
            {
                flag = 1;
                break;
            }
            pre = Q.front();
            Q.pop();
        } while (true);
        while (!Q.empty())
        {
            Q.pop();
        }
        /*        for(int i=0; i<=g+1; i++)
            {
                for(int j=0; j<=h+1; j++)
                {
                    cout<<Mark[i][j]<<" ";
                }
                cout<<endl;
            }*/
        Len = Mark[1][1] - 1;
        if (flag == 1)
            cout << "NO FOUND";
        else
        {
            pre.x = 1;
            pre.y = 1;
            cout << "1,1" << endl;
            for (int j = Len - 1; j > 0; j--)
            {
                for (d = 0; d < 4; d++)
                {
                    next.x = pre.x + Move[d][0];
                    next.y = pre.y + Move[d][1];
                    if (Mark[next.x][next.y] == j + 1)
                    {
                        cout << next.x << ',' << next.y << endl;
                        break;
                    }
                }
                pre = next;
            }
        }
        flag = 0;
        cin >> g >> h;
        cout << endl;
    }
    return 0;
}
