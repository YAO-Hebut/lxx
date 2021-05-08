#include <iostream>
using namespace std;

void Merge(int r[], int r1[], int s, int m, int t)
{
    int i = s, j = m + 1, k = s;
    while (i <= m && j <= t)
    {
        if (r[i] < r[j])
            r1[k++] = r[i];
        else
            r1[k++] = r[j];
    }
    while (i <= m)
    {
        r1[k++] = r[i++];
    }
    while (j <= t)
    {
        r1[k++] = r[j++];
    }
}

void Mergesort(int r[], int s, int t)
{
    int m, r1[1000];
    if (s == t)
    {
        return;
    }
    else
    {
        m = (s + t) / 2;
        Mergesort(r, s, m - 1);
        Mergesort(r, m + 1, t);
        Merge(r, r1, s, m, t);
        for (int i = s; i <= t; i++)
            r[i] = r1[i]; //将有序序列传回数组r中
    }
}

int main()
{
    int a[100];
    cout << "请输入数组的大小：";
    int n;
    cin >> n;
    cout << "请输入数组的数：";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Mergesort(a, 0, n);
    cout << "归并排序后的数组为:";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}