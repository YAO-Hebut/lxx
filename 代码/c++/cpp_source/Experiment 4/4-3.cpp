#include <iostream>
#include <string>
using namespace std;

#include <iostream>
using namespace std;

class Animal
{
private:
    int m_nWeightBase;

protected:
    int m_nAgeBase;

public:
    void set_base(double);
    double get_weight();
    void set_age(int);
};

void Animal::set_base(double base)
{
    m_nAgeBase = base;
}

double Animal::get_weight()
{
    return m_nWeightBase;
}
void Animal::set_age(int a)
{
    m_nAgeBase = a;
}

class Cat : Animal
{
    string m_strName;

public:
    Cat(string);
    void set_print_age();
    void set_print_weight();
};

Cat::Cat(string name) : m_strName(name) {}
void Cat::set_print_age()
{
    Animal::set_age(5);
    cout << m_strName << ", age = " << m_nAgeBase << endl;
}
void Cat::set_print_weight()
{
    Animal::set_base(6);
    cout << m_strName << ", weight = " << m_nAgeBase << endl;
}

int main()
{
    Cat cat("Persion"); //定义派生类对象cat
    cat.set_print_age();
    cat.set_print_weight(); //派生类对象调用自己的公有函数
    return 0;
}
