#include <iostream>
using namespace std;
template <class T>
T Max(T x[], int len);
class Time
{
private:
    int hour, minute, second;

public:
    Time();
    friend Time Max(Time x[], int len);
    void set_hour(int);
    void set_minute(int);
    void set_second(int);
    void print();
};
Time::Time() : hour(0), minute(0), second(0) {}
void Time::set_hour(int h) { hour = h; }
void Time::set_minute(int m) { minute = m; }
void Time::set_second(int s) { second = s; }
void Time::print()
{
    cout << hour << ":" << minute << ":" << second << endl;
}
Time Max(Time x[], int len)
{
    Time max;
    max.set_hour(0);
    max.set_minute(0);
    max.set_second(0);
    for (int i = 0; i < len; i++)
    {
        if (x[i].hour > max.hour)
        {
            max = x[i];
            continue;
        }
        else if ((x[i].hour == max.hour) && (x[i].minute > max.minute))
        {
            max = x[i];
            continue;
        }
        else if ((x[i].hour == max.hour) && (x[i].minute == max.minute) && (x[i].second > max.second))
        {
            max = x[i];
            continue;
        }
        else
            continue;
    }
    return max;
}
class Data
{
private:
    int year, month, day;

public:
    Data();
    void set_year(double);
    void set_month(double);
    void set_day(double);
    void print();
    friend Data Max(Data x[], int len);
};
Data::Data() : year(0), month(1), day(1) {}
void Data::set_year(double y) { year = y; }
void Data::set_month(double m) { month = m; }
void Data::set_day(double d) { day = d; }
void Data::print() { cout << year << "/" << month << "/" << day << endl; }
Data Max(Data x[], int len)
{
    Data max;
    max.set_day(0);
    max.set_month(1);
    max.set_year(1);
    for (int i = 0; i < len; i++)
    {
        if (x[i].year > max.year)
        {
            max = x[i];
            continue;
        }
        else if ((x[i].year == max.year) && (x[i].month > max.month))
        {
            max = x[i];
            continue;
        }
        else if ((x[i].year == max.year) && (x[i].month == max.month) && (x[i].day > max.day))
        {
            max = x[i];
            continue;
        }
        else
            continue;
    }
    return max;
}

int Max(int x[], int len)
{
    int max = x[0];
    for (int i = 0; i < len; i++)
    {
        if (x[i] > max)
        {
            max = x[i];
        }
    }
    return max;
}
double Max(double x[], int len)
{
    double max = x[0];
    for (int i = 0; i < len; i++)
    {
        if (x[i] > max)
        {
            max = x[i];
        }
    }
    return max;
}

int main()
{
    int x; //x控制输入的数据类型，x=-1时退出

    cin >> x;
    while (x != -1)
    {

        if (x == 1)
        {
            int len = 0;
            int a[100000];
            cin >> a[0];
            int max = a[0];
            if (a[0] == 0)
            {
                cout << "0" << endl;
            }
            else
            {
                for (int i = 1;; i++)
                {
                    cin >> a[i];
                    if (a[i] == 0)
                        break;
                    else
                        len++;
                }
                cout << Max(a, len) << endl;
            }
        }
        else if (x == 2)
        {
            int len = 0;
            double b[100000];
            cin >> b[0];
            double max = b[0];
            if (b[0] == 0)
            {
                cout << "0" << endl;
            }
            else
            {
                for (int i = 1;; i++)
                {
                    cin >> b[i];
                    if (b[i] == 0)
                        break;
                    else
                        len++;
                }
                cout << Max(b, len) << endl;
            }
        }
        else if (x == 3)
        {
            int len = 0;
            int h, m, s;
            cin >> h;
            Time time[100000];
            Time max;

            if (h == 0)
            {
                max.print();
            }
            else
            {
                while (h != 0)
                {
                    cin >> m >> s;
                    time[len].set_hour(h);
                    time[len].set_minute(m);
                    time[len].set_second(s);
                    len++;
                    cin >> h;
                }
                max = Max(time, len);
                max.print();
            }
        }
        else if (x == 4)
        {
            int len = 0;
            int y, d, m;
            cin >> y;
            Data data[100000];
            Data max;

            if (y == 0)
            {
                max.print();
            }
            else
            {
                while (y != 0)
                {
                    cin >> m >> d;
                    data[len].set_year(y);
                    data[len].set_month(m);
                    data[len].set_day(d);
                    len++;
                    cin >> y;
                }
                max = Max(data, len);
                max.print();
            }
        }

        else
        {
            cout << "输入错误！" << endl;
        }
        cin >> x;
    }
    return 0;
}