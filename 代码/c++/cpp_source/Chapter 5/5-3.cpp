#include <iostream>
using namespace std;

class Time
{
public:
    Time(int h, int m, int s);     //构造函数
    Time operator+(const Time &t); //运算符重载函数，实现两个时间的相加
    void display();                //显示时间函数
private:
    int hours, minutes, seconds;
};
Time::Time(int h, int m, int s)
{
    hours = h;
    minutes = m;
    seconds = s;
}
Time Time::operator+(const Time &t)
{
    hours += t.hours;
    minutes += t.minutes;
    seconds += t.seconds;
    if (seconds >= 60)
    {
        seconds -= 60;
        minutes += 1;
    }
    if (minutes >= 60)
    {
        minutes -= 60;
        hours += 1;
    }
    if (hours >= 24)
    {
        hours -= 24;
    }
    return *this;
}

void Time::display()
{
    cout << hours << ":" << minutes << ":" << seconds << endl;
}

int main()
{
    int h1, m1, s1;
    int h2, m2, s2;
    cin >> h1 >> m1 >> s1;
    cin >> h2 >> m2 >> s2;
    if (h1 >= 24 || m1 > 60 || s1 > 60 || h1 < 0 || m1 < 0 || s1 < 0 || h2 >= 24 || m2 > 60 || s2 > 60 || h2 < 0 || m2 < 0 || s2 < 0)

    {
        cout << "Time Error!" << endl;
    }
    else
    {
        Time t1(h1, m1, s1), t2(h2, m2, s2);
        t1 + t2;
        t1.display();
    }

    return 0;
}