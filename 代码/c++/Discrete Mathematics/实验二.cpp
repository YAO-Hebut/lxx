#include <iostream>
using namespace std;

//只需要写出各种闭包即可，判断是否具有相对性质则可以通过判断闭包与原式是否相同即可

int main()
{
    int n;
    int zf_flag, dc_flag, cd_flag, fzf_flag, fdc_flag;
    cout << "请输入矩阵的行列数:";
    cin >> n;
    cout << "请输入关系矩阵:";
    int a[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0 || a[i][j] != 1)
            {
                cout << "输入的关系矩阵错误！" << endl;
                break;
            }
        }
    }
    int zf[100][100], dc[100][100], cd[100][100];
    for (int i = 0; i < n; i++) //初始化各个关系矩阵，在同一个关系矩阵上产生闭包即可
    {
        for (int j = 0; j < n; j++)
        {
            zf[i][j] = a[i][j];
            dc[i][j] = a[i][j];
            cd[i][j] = a[i][j];
        }
    }
    //自反闭包
    for (int i = 0; i < n; i++)
    {
        zf[i][i] = 1;
    }

    //对称闭包
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dc[i][j] == 1)
            {
                dc[j][i] = 1;
            }
        }
    }

    //Warshall算法求传递闭包
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (cd[i][j] == 1)
            {
                for (int k = 0; k < n; k++)
                {
                    cd[i][j] = cd[i][k] + cd[j][k];
                    if (cd[i][j] > 1)
                    {
                        cd[i][j] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == zf[i][j])
                zf_flag = 1;
            else
            {
                zf_flag = 0;
                break;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == dc[i][j])
                dc_flag = 1;
            else
            {
                dc_flag = 0;
                break;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == cd[i][j])
                cd_flag = 1;
            else
            {
                cd_flag = 0;
                break;
            }
        }
    }
    //判断是否为反自反，反对称的
    for (int i = 0; i < n; i++)
    {
        if (a[i][i] == 0)
            fzf_flag = 1;
        else
        {
            fzf_flag = 0;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != a[j][i])
                fdc_flag = 1;
            else
            {
                fdc_flag = 0;
                break;
            }
        }
    }

    //输出结论
    cout << "该关系是:";
    if (zf_flag == 1)
        cout << "自反的   ";
    else
        cout << "非自反的   ";
    if (dc_flag == 1)
        cout << "对称的   ";
    else
        cout << "非对称的   ";
    if (cd_flag == 1)
        cout << "传递的   ";
    else
        cout << "非传递的   ";
    if (fzf_flag == 1)
        cout << "反自反的   ";
    else
        cout << "非反自反的   ";
    if (fdc_flag == 1)
        cout << "反对称的" << endl;
    else
        cout << "非反对称的" << endl;

    
    cout << "自反闭包为:";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != n - 1)
                cout << zf[i][j] << " ";
            else
                cout << zf[i][j] << endl;
        }
    }

    cout << "对称闭包为:";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != n - 1)
                cout << dc[i][j] << " ";
            else
                cout << dc[i][j] << endl;
        }
    }

    cout << "传递闭包为:";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != n - 1)
                cout << cd[i][j] << " ";
            else
                cout << cd[i][j] << endl;
        }
    }
    return 0;
}
