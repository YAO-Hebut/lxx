// 7-2 多边形周长计算（继承） (50 分)
// 给出下面的多边形基类框架：

// class polygon

// { protected:

//    int number;//边数，最多不超过100条边
// private:

//    int side_length[100];//边长数组
// public:

//    polygon();//构造函数根据需要重载
//    int perimeter();//计算多边形边长
//    void display();//输出多边形边数和周长
// }

// 建立一个派生类rectangle(矩形)，增加以下数据成员：

//   int height;
//   int width;
// 增加以下成员函数：

//  rectangle类的无参和参数化构造函数
//  int perimeter();//计算矩形边长
//  void display();//输出多边形边数和周长
// 建立一个派生类equal_polygon(等边多边形)，增加以下数据成员：

//   int side_len;
// 增加以下成员函数：

//  equal_polygon类的无参和参数化构造函数
//  int perimeter();//计算等边多边形边长
//  void display();//输出多边形边数和周长
// 生成上述类并编写主函数，根据输入的多边形信息，相应建立一个多边形类对象或矩形类对象或等边多边形类对象，计算每一个多边形的周长并且输出其边数和周长。

// 输入格式： 测试输入包含一个测试用例，该测试用例的第一行输入多边形的个数n，接下来n行每一行给出一个多边形的基本信息，每行的第一个数字为当前多边形的类型，0为一般多边形，后面跟随m个数字为m条边的边长，-1为一般多边形边长输入结束标志，1为矩形，后面跟随两个数字，分别为height和width，2为等边多边形，后面跟随两个数字为等边多边形的边数和边长。

// 输入样例：

// 3

// 0 32 54 76 88 24 -1

// 1 32 54

// 2 3 32

// 输出样例：

// 5 274

// 4 172

// 3 96

#include <iostream>
using namespace std;

//多边形类
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

polygon::polygon() : number(0) //默认构造函数
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

//矩形类
class rectangle : public polygon
{
    int height;
    int width;

public:
    rectangle(); //默认构造函数
    void set_rectangle(int, int);
    int perimeter(); //计算多边形边长
    void display();  //输出多边形边数和周长
};
rectangle::rectangle() : width(0), height(0) {}
void rectangle::set_rectangle(int h, int w)
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

//等边多边形类
class equal_polygon : public polygon
{
    int side_len;

public:
    equal_polygon(); //默认构造函数
    void set_equal_polygon(int num, int len);
    int perimeter(); //计算等边多边形边长
    void display();  //输出多边形边数和周长
};
equal_polygon::equal_polygon() : side_len(0)
{
    number = 0;
}
void equal_polygon::set_equal_polygon(int num, int len)
{
    number = num;
    side_len = len;
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
    int a = 0, b = 0, c = 0; //分别记录普通多边形、矩形、等边多边形的个数
    cin >> n;
    int number[100] = {0}, pol[100], side_lenth[1000], bianshu; //分别记录边数、输入的指令指示的多边形类型、各个多边形的边长、等边多边形的边数
    polygon p[100];
    rectangle r[100];
    equal_polygon e[100];
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
            p[a].set_len(number[i], side_lenth);
            a++;
        }
        else if (pol[i] == 1)
        {
            cin >> side_lenth[0] >> side_lenth[1];
            r[b].set_rectangle(side_lenth[0], side_lenth[1]);
            b++;
        }
        else if (pol[i] == 2)
        {
            cin >> bianshu;
            cin >> side_lenth[0];
            e[c].set_equal_polygon(bianshu, side_lenth[0]);
            c++;
        }
        else
            cout << "Error: Please enter again" << endl;
    }

    for (int i = 0; i < a; i++)
    {
        p[i].display();
    }
    for (int i = 0; i < b; i++)
    {
        r[i].display();
    }
    for (int i = 0; i < c; i++)
    {
        e[i].display();
    }
    return 0;
}