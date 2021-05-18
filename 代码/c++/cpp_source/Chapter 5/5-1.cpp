#include <iostream>
using namespace std;
class Time
{
private:
    int hour, minute, second;

public:
    Time(int, int, int);
    void print();
    Time operator+(int);
};
Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

void Time::print()
{
    cout << "Time:" << hour << ":" << minute << ":" << second << endl;
}
Time Time::operator+(int sec)
{
    int h, m, s;
    h = sec / 3600;
    m = (sec - (h * 3600)) / 60;
    s = sec - h * 3600 - m * 60;
    hour += h;
    minute += m;
    second += s;
    if (second >= 60)
    {
        second -= 60;
        minute += 1;
    }
    if (minute >= 60)
    {
        minute -= 60;
        hour += 1;
    }
    if (hour >= 24)
    {
        hour -= 24;
    }
    return *this;
}

int main()
{
    int h, m, s, sec;
    cin >> h >> m >> s >> sec;
    while (!(h == 0 && m == 0 && s == 0 && sec == 0))
    {
        if (h >= 24 || m > 60 || s > 60 || h < 0 || m < 0 || s < 0 )

        {
            cout << "Time Error!" << endl;
        }
        else if (sec < 0)
        {
            cout << "Input n Error!" << endl;
        }
        else
        {
            Time t(h, m, s);
            t = t + sec;
            t.print();
        }
        cin >> h >> m >> s >> sec;
    }
    return 0;
}