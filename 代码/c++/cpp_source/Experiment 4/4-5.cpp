#include <iostream>
using namespace std;

enum COLOR
{
    WHITE,
    RED,
    BROWN,
    BLACK,
    KHAKI
};

class Mammal
{
public:
    //constructors
    Mammal();
    Mammal(int age);
    ~Mammal();

    //accessors
    int GetAge() const;
    void SetAge(int);
    int GetWeight() const;
    void SetWeight(int);

    //Other methods
    void Speak() const;
    void Sleep() const;

protected:
    int itsAge;
    int itsWeight;
};
Mammal::Mammal()
{
    itsWeight = 0;
    itsAge = 0;
};
Mammal::Mammal(int age) : itsAge(age) {}
int Mammal::GetAge() const
{
    return itsAge;
}
void Mammal::SetAge(int a)
{
    itsAge = a;
}
int Mammal::GetWeight() const
{
    return itsWeight;
}
void Mammal::SetWeight(int w)
{
    itsWeight = w;
}

void Mammal::Speak() const
{
    cout << "Mammal is speaking..." << endl;
}
void Mammal::Sleep() const
{
    cout << "Mammal is sleeping" << endl;
}
Mammal::~Mammal() {}

class Dog : public Mammal
{
    COLOR itsColor;

public:
    //constructors
    Dog();
    Dog(int age);
    Dog(int age, int weight);
    Dog(int age, COLOR color);
    Dog(int age, int weight, COLOR color);
    ~Dog();
    //accessors
    COLOR GetColor();
    void SetColor(COLOR);
    //Other Methods
    void WagTail();
    void BegForFood();
};

Dog::Dog() : itsColor(WHITE) {}
Dog::Dog(int age) : Mammal(age) {}
Dog::Dog(int age, int weight) : Mammal(age)
{
    itsWeight = weight;
}
Dog::Dog(int age, COLOR color) : Mammal(age), itsColor(color) {}

Dog::Dog(int age, int weight, COLOR color) : Mammal(age), itsColor(color)
{
    itsWeight = weight;
}
COLOR Dog::GetColor()
{
    return itsColor;
}

void Dog::SetColor(COLOR color)
{
    itsColor = color;
}

void Dog::WagTail()
{
    cout << "The dog is wagging its tail..." << endl;
}
void Dog::BegForFood()
{
    cout << "The dog is begging for food" << endl;
}
Dog::~Dog()
{
}
int main()
{
    Dog Fido;
    Dog Rover(5);
    Dog Buster(6, 8);
    Dog Yorkie(3, RED);
    Dog Dobbie(4, 20, KHAKI);
    Fido.Speak();
    Rover.WagTail();
    cout << "Yorkie is " << Yorkie.GetAge() << " years old." << endl;
    cout << "Dobbie weighs " << Dobbie.GetWeight() << " pounds." << endl;
    return 0;
}
