#include <iostream>
using namespace std;

class Student
{
public:
    int score;
    Student();
    Student(int);
};

Student::Student() : score(0) {}

Student::Student(int s) : score(s) {}

double getAverage(int, int);

int Sum(int s[1000], int n);

int main()
{
    int n, num, sum;
    int s[1000];
    double average;
    cin >> n;
    num = n;
    Student stu[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].score;
        if (stu[i].score < 0 || stu[i].score > 100)
        {
            stu[i].score = 0;
            num--;
        }
        s[i] = stu[i].score;
    }
    sum = Sum(s, n);
    average = getAverage(sum, num);
    cout << sum << "  " << average << endl;
    return 0;
}

int Sum(int s[1000], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + s[i];
    }
    return sum;
}

double getAverage(int sum, int n)
{
    double average;
    average = sum / n;
    return average;
}