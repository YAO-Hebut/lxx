#include <iostream>
using namespace std;

const double PI = 3.1415926;
class Container
{
public:
    virtual double surface_area() = 0; //纯虚函数surface_area，计算图形的表面积
    virtual double volume() = 0;       //纯虚函数volume，计算图形的体积
};

class Sphere : public Container
{
private:
    double radius;

public:
    Sphere(double);
    double surface_area();
    double volume();
};
Sphere::Sphere(double r) : radius(r) {}
double Sphere::surface_area()
{
    double area;
    area = 4 * PI * radius * radius;
    return area;
}
double Sphere::volume()
{
    double v;
    v = PI * radius * radius * radius * 4 / 3;
    return v;
}

class Cylinder : public Container
{
private:
    double radius, height;

public:
    Cylinder(double, double);
    double surface_area();
    double volume();
};
Cylinder::Cylinder(double r, double h) : radius(r), height(h) {}
double Cylinder::surface_area()
{
    double area;
    area = PI * radius * radius * 2 + 2 * PI * radius * height;
    return area;
}
double Cylinder::volume()
{
    double v;
    v = PI * radius * radius * height;
    return v;
}

class Cube : public Container
{
private:
    double length;

public:
    Cube(double);
    double surface_area();
    double volume();
};

Cube::Cube(double l) : length(l) {}
double Cube::surface_area()
{
    double area;
    area = length * length * 6;
    return area;
}
double Cube::volume()
{
    double v;
    v = length * length * length;
    return v;
}

int main()
{
    int n, x; //n为输入的立体个数，x为表示何种类型的立体
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == 1)
        {
            double r;
            cin >> r;
            Sphere s(r);
            cout << "球体表面积：" << s.surface_area() << "，球体体积：" << s.volume() << endl;
        }
        else if (x == 2)
        {
            double r, h;
            cin >> r >> h;
            Cylinder c(r, h);
            cout << "圆柱体表面积：" << c.surface_area() << "，圆柱体体积：" << c.volume() << endl;
        }
        else if (x == 3)
        {
            double l;
            cin >> l;
            Cube cub(l);
            cout << "正方体表面积：" << cub.surface_area() << "，正方体体积：" << cub.volume() << endl;
        }
        else
        {
            cout << "输入错误！" << endl;
        }
    }
    return 0;
}