#include <iostream>
using namespace std;

class Data
{
protected:
    int year, month, day;

public:
    Data();
    Data(int, int, int);
    void Data_show();
};
Data::Data() : year(0), month(0), day(0) {}
Data::Data(int y, int m, int d) : year(y), month(m), day(d) {}
void Data::Data_show()
{
    cout << " " << year << "/" << month << "/" << day;
}
class Time
{
protected:
    int hour, minute, second;

public:
    Time();
    Time(int, int, int, int, int, int);
    void Time_show();
};
Time::Time()
{
    hour = 0;
    minute = 0;
    second = 0;
}
Time::Time(int y, int m, int d, int h, int min, int sec) : hour(h), minute(m), second(sec) {}
void Time::Time_show()
{
    cout << " " << hour << ":" << minute << ":" << second;
}
class Schedule : public Data, public Time
{
    int ID;

public:
    bool operator<(const Schedule &s2);
    Schedule();
    void set_Schedule(int, int, int, int, int, int, int);
    void Schedule_show();
};
Schedule::Schedule()
{
    year = 0;
    day = 0;
    month = 0;
    hour = 0;
    minute = 0;
    second = 0;
    ID = 0;
}
void Schedule::Schedule_show()
{
    cout << ID;
}
void Schedule::set_Schedule(int id, int y, int m, int d, int h, int min, int sec)
{

    year = y;
    month = m;
    day = d;
    hour = h;
    minute = min;
    second = sec;
    ID = id;
}
bool Schedule::operator<(const Schedule &s2)
{
    if (year > s2.year)
        return 0;
    else if (month > s2.month)
        return 0;
    else if (day > s2.day)
        return 0;
    else if (hour > s2.hour)
        return 0;
    else if (minute > s2.minute)
        return 0;
    else if (second > s2.second)
        return 0;
    else
        return 1;
}

int main()
{
    int i = 0, min = 0;
    Schedule s[100];
    int y[100], m[100], d[100], h[100], mut[100], sec[100], id[100];
    cin >> id[0];
    while (id[i] != 0)
    {
        scanf("%d/%d/%d", &y[i], &m[i], &d[i]);     //用C语言进行输入
        scanf("%d:%d:%d", &h[i], &mut[i], &sec[i]); //用C语言进行输入
        s[i].set_Schedule(id[i], y[i], m[i], d[i], h[i], mut[i], sec[i]);
        if (i > 0)
            if (s[i] < (s[i - 1]))
                min = i;
        i++;
        cin >> id[i];
    }
    cout << "The urgent schedule is No.";
    if (id[min] != 0)
    {
        s[min].Schedule_show();
        cout << ":";
        s[min].Data_show();
        s[min].Time_show();
    }
    return 0;
}
