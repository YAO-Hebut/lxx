#include <iostream>
using namespace std;
bool leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)
        return true;
    else
        return false;
}
int Examine(int x, int y, int z)
{
    int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (y <= 0 || z <= 0)
        return 0;
    else if (z > mon[y])
        return 0;
    else
        return 1;
}

int main()
{
    int x, y, z, flag;
    cin >> x, y, z;
    flag = Examine(x, y, z);
    cout << flag;
    return 0;
}