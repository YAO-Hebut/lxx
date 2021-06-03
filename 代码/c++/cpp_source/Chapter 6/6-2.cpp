#include <iostream>
using namespace std;

class Student
{
public:
    int num;
    int score;
    int is_Pass;
    int set_score(int s);
    friend ostream &operator<<(ostream &os, Student stu);
};

ostream &operator<<(ostream &os, Student stu)
{
    cout << "[学号：" << stu.num << "，成绩" << stu.score << "]"; //让用户自己决定是否换行
    return os;
}

int Student::set_score(int s)
{
    int x = 0;
    try
    {
        if (s > 100)
        {
            x = 1;
            throw x;
        }
        else if (s < 0)
        {
            x = -1;
            throw x;
        }
        else if (s >= 60)
        {
            score = s;
            is_Pass = 1;
        }
        else
        {
            score = s;
            is_Pass = 0;
        }
    }

    catch (int x)
    {
        if (x == 1)
        {
            cout << s << " is invalid!" << endl;
        }
        else if (x == -1)
        {
            cout << s << " is invalid!" << endl;
        }
    }
    return x;
}

int main()
{
    int flag;
    int n;
    cin >> n;
    int num = 200001;
    int score;
    float ave = 0;
    int pass = 0;
    Student s[100];
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> score;
            s[i].num = num++;
            flag = s[i].set_score(score);
            if (!flag)
            {

                ave += s[i].score;
                if (s[i].is_Pass)
                {
                    pass++;
                }
            }
            else
            {
                i--;
                num--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << s[i] << endl;
        }
        ave = ave / n;

        cout << "Average is :" << ave << endl;
        cout << "Number of pass is :" << pass << endl;
        cout << "Number of No pass is :" << (n - pass) << endl;
    }
    return 0;
}