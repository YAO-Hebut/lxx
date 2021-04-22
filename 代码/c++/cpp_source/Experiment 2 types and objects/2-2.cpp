#include <iostream>
using namespace std;

class Birthday
{
private:
    int year, month, day;

public:
    Birthday();
    Birthday(int, int, int);
    void getAge();
};
Birthday::Birthday() : year(0), month(0), day(0) {}
Birthday::Birthday(int y, int m, int d) : year(y), month(m), day(d) {}
void Birthday::getAge()
{
    int age;
    age = 2017 - year;
    if (month == 12 && day >= 25)
        age = age - 1;
    cout << age << endl;
}

int main()
{
    int y, m, d;
    cin >> y >> m >> d;
    Birthday a(y, m, d);
    a.getAge();
    return 0;
}