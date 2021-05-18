#include <iostream>
using namespace std;

class Rectangle
{
private:
    double width, height;

public:
    Rectangle();
    Rectangle(double, double);
    void getArea();
    void getPerimeter();
};

Rectangle::Rectangle() : width(1), height(1) {}

Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

void Rectangle::getArea()
{
    cout << width * height << endl;
}

void Rectangle::getPerimeter()
{
    cout << 2 * (width + height) << endl;
}

int main()
{
    double w, h;
    cin >> w >> h;
    Rectangle a(w, h);
    a.getArea();
    a.getPerimeter();
    return 0;
}
