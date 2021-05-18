#include <iostream>
using namespace std;
class Car;
class Boat
{
private:
    int weight;

public:
    Boat(int);
    int friend getTotalWeight(Boat, Car);
};

Boat::Boat(int w) : weight(w) {}

class Car
{
private:
    int weight;

public:
    Car(int);
    int friend getTotalWeight(Boat, Car);
};
Car::Car(int w) : weight(w) {}

int getTotalWeight(Boat m, Car n)
{
    int total;
    total = m.weight + n.weight;
    return total;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Boat boat(n);
    Car car(m);
    cout << "船和汽车共重" << getTotalWeight(boat, car) << "吨" << endl;
}