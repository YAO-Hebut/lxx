#include <iostream>
using namespace std;

class Area
{
public:
    double height;
    double width;

public:
    Area(double h, double w)
    {
        height = h;
        width = w;
    }
    virtual double getArea() = 0;
};

class Rectangle : public Area
{

public:
    Rectangle(double h, double w) : Area(h, w) {}
    double getArea()
    {
        return height * width;
    }
};

class Isosceles : public Area
{

public:
    Isosceles(double h, double w) : Area(h, w) {}
    double getArea()
    {
        return height * width / 2.0;
    }
};

int main()
{
    double h1, w1, h2, w2;
    cin >> h1 >> w1 >> h2 >> w2;
    Rectangle jv(h1, w1);
    Isosceles san(h2, w2);
    cout << "the Area of Rectangle is " << jv.getArea() << endl;
    cout << "the Area of Isosceles is " << san.getArea() << endl;
    return 0;
}