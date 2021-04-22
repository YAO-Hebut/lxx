#include <iostream>
using namespace std;

const double PI = 3.14159;

class Circle
{
private:
    double radius;

public:
    Circle(double);
    double getArea();
};

Circle::Circle(double r) : radius(r) {}

double Circle::getArea()
{
    double area;
    area = PI * radius * radius;
    return area;
}

class Rectangle
{
private:
    double length, width;

public:
    Rectangle(double, double);
    double getArea();
};

Rectangle::Rectangle(double l, double w) : length(l), width(w)
{
}

double Rectangle::getArea()
{
    double area;
    area = length * width;
    return area;
}

int main()
{
    double r, l, w;
    double areaCircle, areaRectangle;
    double fee;
    cin >> r >> l >> w;
    Circle c(r);
    Rectangle s(l, w);
    areaCircle = c.getArea();
    areaRectangle = s.getArea();
    fee = (areaRectangle - areaCircle) * 20;
    cout << fee << endl;
    return 0;
}