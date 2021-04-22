#include <iostream>
using namespace std;

class Data
{
private:
    int year, month, day;

public:
    Data(int, int, int);
    void isLeapyear();
};

Data::Data(int y, int m, int d) : year(y), month(m), day(d)
{
}

void Data::isLeapyear()
{
    if (year % 4 == 0 || year % 100 == 0)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}

int main()
{
    int y, m, d;
    cin >> y >> m >> d;
    Data a(y, m, d);
    a.isLeapyear();
    return 0;
}