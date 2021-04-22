#include<iostream>
#include<iomanip>
using namespace std;
class student {
private:
    string id;
    double score;
public:
    friend double average(student* p, int count);
    void set(string, double);
    student() :score(0) {}
};

void student::set(string a, double s)
{
    id = a;
    score = s;
}

double average(student* p, int count)
{
    double s(0);
    for (int i = 0; i < count; i++, p++)
    {
        s += p->score;
    }
    return s / count;
}

int main()
{
    int n(0);
    string id;
    double score;
    student a[100];
    int i = 0;
    for (;;)
    {
        cin >> id;
        if (id == "0") break;
        cin >> score;
        a[i].set(id, score);
        i++;
        n++;
    }
    double av = average(a, n);
    cout << av << endl;
    return 0;
}
