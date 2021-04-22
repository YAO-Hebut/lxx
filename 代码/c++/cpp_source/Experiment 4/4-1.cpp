#include <iostream>
using namespace std;

class Time
{
public:
    Time(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }
    void display()
    {
        cout << hours << ":" << minutes << ":" << seconds;
    }

protected:
    int hours, minutes, seconds;
};

class Date
{
public:
    Date(int m, int d, int y)
    {
        month = m;
        day = d;
        year = y;
    }
    virtual void display()
    {
        cout << year << "-" << month << "-" << day;
    }

protected:
    int month, day, year;
};

class Birthtime : public Time, Date
{
private:
    string childname;

public:
    Birthtime(string, int, int, int, int, int, int);
    void display()
    {
        cout << childname << ": ";
        Date::display();
        cout << "  ";
        Time::display();
        cout << endl;
    }
};
Birthtime::Birthtime(string name, int y, int m, int d, int h, int min, int sec) : Date(m, d, y), Time(h, min, sec), childname(name)
{
}

int main()
{
    string name[2];
    int year[2], month[2], day[2], hours[2], minutes[2], seconds[2];
    cin >> name[0] >> year[0] >> month[0] >> day[0] >> hours[0] >> minutes[0] >> seconds[0];
    cin >> name[1] >> year[1] >> month[1] >> day[1] >> hours[1] >> minutes[1] >> seconds[1];
    Birthtime
        baby1(name[0], year[0], month[0], day[0], hours[0], minutes[0], seconds[0]),

        baby2(name[1], year[1], month[1], day[1], hours[1], minutes[1], seconds[1]);
    baby1.display();
    baby2.display();
    return 0;
}