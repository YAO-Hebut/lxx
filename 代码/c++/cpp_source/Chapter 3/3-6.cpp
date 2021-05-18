#include <iostream>
using namespace std;

class box
{
private:
    int length, weight, height;

public:
    box();
    box(int, int, int);
    int getArea();
};

box::box() : length(0), weight(0), height(0) {}
box::box(int l, int w, int h) : length(l), weight(w), height(h) {}

int box::getArea()
{
    int area;
    area = length * height * weight;
    cout << area << endl;
    return area;
}

int main()
{
    int l, w, h;
    cin >> l >> w >> h;
    box a(l, w, h);
    a.getArea();
    return 0;
}
