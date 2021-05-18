#include <iostream>
using namespace std;

class student
{
private:
    string name;
    int chinese, math, english, complex;

public:
    int sum = 0;
    student();
    void getStudent(string, int, int, int, int);
    friend student top(const student *p, int count);
};

student::student() : name("none"), chinese(0), math(0), english(0), complex(0) {}
void student::getStudent(string n, int ch, int m, int e, int clx)
{
    name = n;
    chinese = ch;
    math = m;
    english = e;
    complex = clx;
}
void getStudent(string, int, int, int, int);
student top(const student *p, int count)
{
    int sum = 0, max = 0;
    for (int i = 0; i < count; i++)
    {
        sum = p[i].chinese + p[i].complex + p[i].english + p[i].math;
        if (max < sum)
            max = sum;
    }
    cout << sum << endl;
    return *p;
}

int main()
{
    student a[100];
    string name;
    int ch, m, e, clx, count = 0;
    for (int i = 0;; i++)
    {
        cin >> name;
        if (name == "0")
            break;
        cin >> ch >> m >> e >> clx;
        count++;
        a[i].getStudent(name, ch, m, e, clx);
    }
    top(a, count);
    return 0;
}