#include <iostream>
using namespace std;

class Complex
{
private:
    double real, imag;

public:
    Complex();
    Complex(double, double);
    friend Complex operator+(int, Complex);
    friend Complex operator-(int, Complex);
    friend Complex operator-(Complex, int);
    void print();
};
Complex::Complex() : real(0), imag(0) {}
Complex::Complex(double r, double i) : real(r), imag(i) {}
Complex operator+(int s, Complex x)
{
    x.real += s;
    return x;
}
Complex operator-(int s, Complex x)
{
    x.real = s - x.real;
    x.imag = -x.imag;
    return x;
}
Complex operator-(Complex x, int s)
{
    x.real = x.real-s;
    return x;
}

void Complex::print()
{
    cout << "(" << real << "," << imag << ")" << endl;
}
int main()
{
    double r, m;
    cin >> r >> m;
    Complex c(r, m);
    int n;
    cin >> n;
    Complex c1;
    c1 = n + c;
    Complex c2 = c - n;
    Complex c3 = n - c;
    c1.print();
    c2.print();
    c3.print();
    return 0;
}