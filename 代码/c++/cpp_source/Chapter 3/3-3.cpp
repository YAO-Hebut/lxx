#include <iostream>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point();
    Point(double, double);
    void Shift(double, double);
};

Point::Point() : x(0), y(0) {}

Point::Point(double xx, double yy) : x(xx), y(yy) {}

void Point::Shift(double x1, double y1)
{
    double x0, y0;
    x0 = x1 + x;
    y0 = y1 + y;
    cout << x0 << " " << y0 << endl;
}

int main()
{
    double x, y, x1, y1, x0, y0;
    cin >> x >> y;
    Point a(x, y);
    cin >> x1 >> y1;
    a.Shift(x1, y1);
    return 0;
}