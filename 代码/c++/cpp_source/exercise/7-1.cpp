#include <iostream>
using namespace std;
int manzu(int);
int main()
{
    int a, n, max, min;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (manzu(a))
        {
            max = a / 2;
            min = a / 4 + (a % 4) / 2;
            cout << min << " " << max << endl;
        }
        else
        {
            cout << 0 << " " << 0 << endl;
        }
    }
    return 0;
}
int manzu(int n)
{
    int i, j;
    for (i = 0; 2 * i <= n; i++)
    {
        for (j = 0; 2 * i + 4 * j <= n; j++)
        {
            if (2 * i + 4 * j == n)
                return 1;
            else
                continue;
        }
    }
    return 0;
}