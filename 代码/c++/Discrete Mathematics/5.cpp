//a[n]为集合A
//op[n][n]为计算表
//可结合性 op[op[a][b]][c]=op[a][op[b][c]]
//幺元 op[x][e]=op[e][x]=a[x]
//逆元 op[x][x^(-1)]=a[e];

#include <iostream>
using namespace std;

const int num = 4;

int isClose(int a[num], int op[num][num]) //封闭性
{
    int flag_all = 1;
    int flag;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            flag = 0;
            for (int k = 0; k < num; k++)
            {
                if (a[k] == op[i][j])
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag) //op[i][j]不在集合A里面
            {
                flag_all = 0;
                cout << "该集合不是封闭的" << endl;
                break;
            }
        }
    }
    return flag_all;
}

int isCombine(int a[num], int op[num][num]) //可结合性
{
    int flag_all = 1;
    int p, q;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            for (int k = 0; k < num; k++)
            {
                for (int l = 0; l < num; l++)
                {
                    if (op[i][j] == a[l])
                        p = l;
                    if (op[j][k] == a[l])
                        q = l;
                }
                if (op[i][q] != op[p][k])
                {
                    flag_all = 0;
                    break;
                }
            }
        }
    }
    if (flag_all == 0)
    {
        cout << "该集合不是可结合的" << endl;
    }
    return flag_all;
}

int identity(int a[num], int op[num][num]) //幺元
{
    int e;
    int flag = 0;
    int i, j;
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            if (op[i][j] != a[j] || op[j][i] != a[j])
            {
                break;
            }
        }
        e = a[j];
        if (j == num)
        {
            flag = 1;
        }
    }
    if (!flag)
    {
        cout << "不存在幺元e..." << endl;
        return -1;
    }
    else
    {
        cout << "该集合的幺元为:" << e << endl;
        return e;
    }
}

int inverseElement(int a[num], int op[num][num], int e) //逆元
{
    int flag_all = 1;
    int flag_inverse;
    for (int i = 0; i < num; i++)
    {
        flag_inverse = 0;
        for (int j = 0; j < num; j++)
        {

            if ((op[i][j] == op[j][i]) && (op[i][j] == a[e]) && (op[j][i] == a[e]))
            {
                flag_inverse = 1;
            }
        }
        if (!flag_inverse)
        {
            flag_all = 0; //此时不满足所有元素都存在逆元
            cout << "该集合不满足所有元素都存在逆元" << endl;
            break;
        }
    }
    return flag_all;
}
int main()
{
    int a[num];
    int op[num][num];

    int flag_Close;
    int flag_Combine;
    int flag_inverse;

    int e;

    cout << "请输入集合A(容量大小为4):" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> a[i];
    }

    cout << "请输入运算表OP:" << endl;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cin >> op[i][j];
        }
    }

    e = identity(a, op);

    if (e != -1)
    {
        flag_Close = isClose(a, op);
        flag_Combine = isCombine(a, op);
        flag_inverse = inverseElement(a, op, e);
        if ((flag_Close == 1) && (flag_Combine) == 1 && (flag_inverse == 1))
        {
            cout << "该集合满足封闭性" << endl;
            cout << "该集合满足可结合性" << endl;
            cout << "该集合满足所有元素都存在逆元" << endl;
            cout << "<A,*>是一个群" << endl;
        }
    }

    return 0;
}

// 1 2 3 4
// 2 3 4 1
// 3 4 1 2
// 4 1 2 3