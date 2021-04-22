#include <iostream>
using namespace std;

class polygon

{
protected:
    int number; //边数，最多不超过100条边
private:
    int side_length[100]; //边长数组
public:
    polygon();       //构造函数根据需要重载
    int perimeter(); //计算多边形边长
    void display();  //输出多边形边数和周长
    void set_len(int num, int *);
};

polygon::polygon() : number(0)
{
    *side_length = 0;
}
void polygon::set_len(int num, int len[])
{
    number = num;
    for (int i = 0; i < number; i++)
    {
        side_length[i] = len[i];
    }
}
int polygon::perimeter()
{
    int sum = 0;
    for (int i = 0; i < number; i++)
    {
        sum += side_length[i];
    }
    return sum;
}
void polygon::display()
{
    cout << number << " " << perimeter() << endl;
}

class rectangle : public polygon
{
    int height;
    int width;

public:
    rectangle(int, int);
    int perimeter(); //计算多边形边长
    void display();  //输出多边形边数和周长
};
rectangle::rectangle(int h, int w)
{
    width = w;
    height = h;
}
int rectangle::perimeter()
{
    int sum = 0;
    sum += (height + width) * 2;
    return sum;
}
void rectangle::display()
{
    cout << 4 << " " << perimeter() << endl;
}

class equal_polygon : public polygon
{
    int side_len;

public:
    equal_polygon(int num, int len);
    int perimeter(); //计算等边多边形边长
    void display();  //输出多边形边数和周长
};
equal_polygon::equal_polygon(int num, int len) : side_len(len)
{
    number = num;
}
int equal_polygon::perimeter()
{
    int sum = 0;
    sum = side_len * number;
}
void equal_polygon::display()
{
    cout << number << " " << perimeter() << endl;
}

int main()
{
    int n;
    cin >> n;
    int number[100] = {0}, pol[100], side_lenth[1000], bianshu;
    for (int i = 0; i < n; i++)
    {
        cin >> pol[i];
        if (pol[i] == 0)
        {
            for (int j = 0;; j++)
            {
                cin >> side_lenth[j];
                if (side_lenth[j] != -1)
                {
                    number[i]++;
                }
                else
                    break;
            }
            polygon p;
            p.set_len(number[i], side_lenth);
            p.display();
        }
        else if (pol[i] == 1)
        {
            cin >> side_lenth[0] >> side_lenth[1];
            rectangle r(side_lenth[0], side_lenth[1]);
            r.display();
        }
        else if (pol[i] == 2)
        {
            cin >> bianshu;
            cin >> side_lenth[0];
            equal_polygon e(bianshu, side_lenth[0]);
            e.display();
        }
        else
            cout << "Error: Please enter again" << endl;
    }
    return 0;
}