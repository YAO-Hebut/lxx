#include <iostream>
using namespace std;
class Date
{
public:
    Date(int i, int j, int k) : year(i), month(j), day(k) {}

private:
    int year, month, day;

    friend int count_day(Date &da, int flag);
    friend bool leap(int year);
    friend int subs(Date &fir, Date &las);
};
bool leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)
        return true;
    else
        return false;
}
int count_day(Date &da, int flag)
{
    int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int judge = leap(da.year);
    int sum = 0;
    if (flag == 1)
    {
        for (int i = 0; i < da.month - 1; i++)
            sum += mon[i];
        sum += da.day + judge;
    }
    else
    {
        for (int i = 11; i >= da.month - 1; i--)
        {
            sum += mon[i];
            if (i == 1 && judge)
                sum += 1;
        }
        sum -= da.day;
    }
    return sum;
}
int subs(Date &fir, Date &las)
{
    int sum = 0;
    sum += count_day(fir, 0) + count_day(las, 1);
    if (fir.year == las.year)
    {
        int judge = leap(fir.year);
        sum -= (judge + 365);
    }
    if (las.year - fir.year > 1)
    {
        for (int i = fir.year + 1; i <= las.year - 1; i++)
        {
            if (leap(i))
                sum += 366;
            else
                sum += 365;
        }
    }
    return sum;
}

int Examine(int, int, int);
int main()
{
    int a, b, c, x, y, z;
    int n;
    cin >> n;
    int flag1, flag2;
    int e[1000] = {0}, j = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> x >> y >> z;
        flag1 = Examine(a, b, c);
        // cout << flag1 << endl; //texts
        // cout << flag2;         //text
        flag2 = Examine(x, y, z);

        Date d1(a, b, c),
            d2(x, y, z);
        if (b < 0 || c < 0 || y < 0 || z < 0 || b > 12 || y > 12 || c > 31 || z > 31 || flag1 == 0 || flag2 == 0)
            e[j++] = -1;
        else
        {
            if (a > x || (a == x && b > y) || (a == x && b == y && c > z))
                e[j++] = subs(d2, d1);
            else
                e[j++] = subs(d1, d2);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (e[i] == -1)
        {
            cout << "time error!" << endl;
        }
        else
            cout << "两个日期相差" << e[i] << "天" << endl;
    }
    return 0;
}

int Examine(int x, int y, int z)
{
    int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (y <= 0 || z <= 0)
        return 0;
    else if (z > mon[y - 1])
        return 0;
    else
        return 1;
}