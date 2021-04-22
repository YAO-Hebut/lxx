#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;
typedef struct
{
    int ord; //序号
    int xpos;
    int ypos;
    //int di;   //24↑ 25↓ 27← 26→
} Selem;
Selem element;
char maze[100][101];

void initElem(int step, int x, int y)
{
    element.ord = step;
    element.xpos = x;
    element.ypos = y;
}

bool Status(char mz[][101], Selem elem)
{
    int x = elem.xpos, y = elem.ypos;
    if (mz[x][y + 1] == ' ')
        mz[x][y] = '>';
    else if (mz[x + 1][y] == ' ')
        mz[x][y] = '|';
    else if (mz[x][y - 1] == ' ')
        mz[x][y] = '<';
    else if (mz[x - 1][y] == ' ')
        mz[x][y] = '^';
    else
    {
        mz[x][y] = '$';
        return false;
    }
    return true;
}

int main()
{
    stack<Selem> path;
    int size[2], curpos[2], goal[2], curstep = 1;
    cout << "迷宫大小(m,n)：";
    cin >> size[0] >> size[1];
    cout << "输入迷宫图（#和0组成）：" << endl;
    for (int i = 0; i < size[0]; i++)
        for (int j = 0; j < size[1]; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == '0')
                maze[i][j] = ' ';
        }
    cout << "输入初始位置：";
    cin >> curpos[0] >> curpos[1];
    initElem(curstep, curpos[0] - 1, curpos[1] - 1);
    path.push(element);
    cout << "输入终点位置：";
    cin >> goal[0] >> goal[1];
    do
    {
        if (element.xpos == goal[0] - 1 && element.ypos == goal[1] - 1)
            break;
        if (!Status(maze, path.top())) //无通路
            path.pop();
        else
        {
            curstep++;
            int x = path.top().xpos, y = path.top().ypos;
            char c = maze[x][y];
            if (c == '>')
                initElem(curstep, x, y + 1);
            else if (c == '|')
                initElem(curstep, x + 1, y);
            else if (c == '<')
                initElem(curstep, x, y - 1);
            else if (c == '^')
                initElem(curstep, x - 1, y);
            path.push(element);
        }
    } while (path.size() != 0); //栈空
    maze[goal[0] - 1][goal[1] - 1] = '@';

    cout << "步数：" << curstep << endl;
    for (int i = 0; i < size[0]; i++)
    {
        for (int j = 0; j < size[1]; j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }

    return 0;
}