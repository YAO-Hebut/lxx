#include <iostream>
using namespace std;

class student
{
private:
    string id;
    double score;

public:
    friend double average(student *p, int count);
    void set(string, double);
    student() : score(0) {}
};

void student::set(string i, double s)
{
    id = i;
    score = s;
}

double average(student *p, int count)
{
    double ave = 0;
    for (int i = 0; i < count; i++, p++)
    {
        ave += p->score;
    }
    ave /= count;
    return ave;
}

int main()
{
    student stu[100];
    string id;
    double s;
    int i = 0;
    int n = 0;
    for (;;)
    {
        cin >> id;
        if (id == "0")
            break;
        cin >> s;
        stu[i].set(id, s);
        i++;
        n++;
    }

    double ave;
    ave = average(stu, n);
    cout << ave << endl;
    return 0;
}