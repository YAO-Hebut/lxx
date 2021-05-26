#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
    int a, b;

public:
    Complex(int, int);
    double operator-(Complex);
};

Complex::Complex(int x, int y) : a(x), b(y) {}
double Complex::operator-(Complex z)
{
    double dis;
    dis = sqrt((a - z.a) * (a - z.a) + (b - z.b) * (b - z.b));
    return dis;
}

template <typename T>
T dist(T a, T b)
{
    T distance;
    distance = sqrt((a - b) * (a - b));
    return distance;
}

int main()
{
    int x;
    for (int i = 0;; i++)
    {
        cin >> x;
        if (x == 0)
            break;
        else if (x == 1)
        {
            int a, b, distance;
            cin >> a >> b;
            distance = dist(a, b);
            cout << distance << endl;
        }
        else if (x == 2)
        {
            float a, b, distance;
            cin >> a >> b;
            distance = dist(a, b);
            cout << distance << endl;
        }
        else if (x == 3)
        {
            int a, b, c, d;
            double distance;
            cin >> a >> b >> c >> d;
            Complex x(a, b), y(c, d);
            distance = x - y;
            cout << distance << endl;
        }
        else
            break;
    }
    return 0;
}