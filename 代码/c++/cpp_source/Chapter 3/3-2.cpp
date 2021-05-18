#include <iostream>
using namespace std;

class Complex
{
private:
    double real, image;

public:
    Complex(double, double);
    void qufan();
    void Print();
    double getReal();
    double getImage();
};

Complex::Complex(double r, double i)
{
    real = r;
    image = i;
}

void Complex::qufan()
{
    real = -real;
    image = -image;
}

void Complex::Print()
{
    cout << "(" << real << ","
         << " " << image << ")" << endl;
}

double Complex::getReal()
{
    return real;
}

double Complex::getImage()
{
    return image;
}

void add(double, double, double, double);

int main()
{
    double r1, r2, i1, i2;
    double r, i;
    cin >> r1 >> i1 >> r2 >> i2;
    Complex a(r1, i1), b(r2, i2);
    add(r1, i1, r2, i2);
    b.qufan();
    r2 = b.getReal();
    i2 = b.getImage();
    add(r1, i1, r2, i2);
    b.qufan();
    b.Print();
    return 0;
}

void add(double r1, double i1, double r2, double i2)
{
    double r;
    double i;
    r = r1 + r2;
    i = i1 + i2;
    cout << "(" << r << ","
         << " " << i << ")" << endl;
}