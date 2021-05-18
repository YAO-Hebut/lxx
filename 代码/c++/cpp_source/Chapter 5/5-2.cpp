#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex operator+(Complex);                 //重载双目运算符'+'
    Complex operator-=(Complex);                //重载双目运算符'-='
    friend Complex operator-(Complex, Complex); //重载双目运算符'-'
    void Display() const;

private:
    double real;
    double imag;
};

void Complex::Display() const
{
    cout << "(" << real << "," << imag << ")" << endl;
}

Complex Complex::operator+(Complex a)
{
    Complex b;
    b.real = real + a.real;
    b.imag = imag + a.imag;
    return b;
}
Complex Complex::operator-=(Complex a)
{
    real = real - a.real;
    imag = imag - a.imag;
    return *this;
}
Complex operator-(Complex a, Complex b)
{
    Complex c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}
int main()
{
    double r, m;
    cin >> r >> m;
    Complex c1(r, m);
    cin >> r >> m;
    Complex c2(r, m);
    Complex c3 = c1 + c2;
    c3.Display();
    c3 = c1 - c2;
    c3.Display();
    c3 -= c1;
    c3.Display();
    return 0;
}
