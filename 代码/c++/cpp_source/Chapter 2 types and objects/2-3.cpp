#include <iostream>
#include <math.h>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point();
    Point(int, int);
};

Point::Point() : x(0), y(0) {}
Point::Point(int xx, int yy) : x(xx), y(yy) {}

double Distance(int, int, int, int);

int main()
{
    int x1, x2, y1, y2;
    double d;
    cin >> x1 >> y1 >> x2 >> y2;
    d = Distance(x1, y1, x2, y2);
    printf("%.2lf", d);
    return 0;
}

double Distance(int x1, int y1, int x2, int y2)
{
    double distance;
    distance = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
    return distance;
}
