#include <iostream>
#include <math.h>
using namespace std;

class Point_1D

{
protected:
    float x; //1D 点的x坐标

public:
    void set_Point1(float);
    float distance1(const Point_1D &p2);
};
void Point_1D::set_Point1(float a)
{
    x = a;
}
float Point_1D::distance1(const Point_1D &p2)
{
    float dis;
    dis = sqrt((x - p2.x) * (x - p2.x));
    return dis;
}

class Point_2D : public Point_1D
{
protected:
    float y;

public:
    void set_Point2(float, float);
    float distance2(const Point_2D &p2);
};
void Point_2D::set_Point2(float a, float b)
{
    x = a;
    y = b;
}

float Point_2D::distance2(const Point_2D &p2)
{
    float dis;
    dis = sqrt((x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y));
    return dis;
}

class Point_3D : public Point_2D
{
protected:
    float z;

public:
    void set_Point3(float, float, float);
    float distance3(const Point_3D &p2);
};
void Point_3D::set_Point3(float a, float b, float c)
{
    x = a;
    y = b;
    z = c;
}
float Point_3D::distance3(const Point_3D &p2)
{
    float dis;
    dis = sqrt((x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y) + (z - p2.z) * (z - p2.z));
    return dis;
}

int main()
{
    int n;
    float dis;
    float a[6]; //记录坐标
    cin >> n;
    while (n != 0)
    {
        if (n == 1)
        {
            cin >> a[0] >> a[1];
            Point_1D p1, p2;
            p1.set_Point1(a[0]);
            p2.set_Point1(a[1]);
            dis = p1.distance1(p2);
            cout << "Distance from Point " << a[0] << " to Point " << a[1] << " is " << dis << endl;
        }
        else if (n == 2)
        {
            cin >> a[0] >> a[1] >> a[2] >> a[3];
            Point_2D p1, p2;
            p1.set_Point2(a[0], a[1]);
            p2.set_Point2(a[2], a[3]);
            dis = p1.distance2(p2);
            cout << "Distance from Point(" << a[0] << "," << a[1] << ") to Point(" << a[2] << "," << a[3] << ") is " << dis << endl;
        }
        else if (n == 3)
        {
            cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
            Point_3D p1, p2;
            p1.set_Point3(a[0], a[1], a[2]);
            p2.set_Point3(a[3], a[4], a[5]);
            dis = p1.distance3(p2);
            cout << "Distance from Point(" << a[0] << "," << a[1] << "," << a[2] << ") to Point(" << a[3] << "," << a[4] << "," << a[5] << ") is " << dis << endl;
        }
        cin >> n;
    }
    return 0;
}
