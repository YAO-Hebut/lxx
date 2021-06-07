# 2021.6.6
目前已经完成了图书管理系统的 **“增 删 改 查 借 还”** 功能，其中，增、删、改、查都已经可以正常使用，而借和还功能还没有加入借出和归还日期功能，此外还没有对用户的借书数目进行限制，也没有区分学生与老师的不同权限功能。


需要改进的地方：
* 1. ~~对借还书籍加入时间统计~~
* 2. ~~对用户加入借书数目限制(学生：5，教师：10)，当数目达到上限时出现 **异常警告**。~~
* 3. 让程序不再是 **“一次性的”**





# 实验报告的书写
* 1 实验设计：
    一、User类的设计
```cpp
#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class User
{
public:
    string name;
    string gender;
    string ID;
    string password;
    bool is_Student = 1; //默认为学生
    int book_num;        //可借书的数目(学生5，教师10)
};

#endif
```
包括了：姓名，性别(没有限制输入，可输入“男、女、boy、girl...”等)，ID(唯一的)，密码，身份状态(是否为学生)和可借书的数目(学生为5，教师为10)。
**User类没有cpp文件，只设置了User类供Administrator.cpp使用**


二、Book类的设计
```cpp
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class book
{
public:
    string name;
    string writer;
    string ID;
    bool status = 1;       //默认为未借出状态
    string data = "0/0/0"; //记录借还日期

    void show()
    {
        cout << name << " " << writer << " " << ID << " ";
        if (status)
        {
            cout << "可借"
                 << " ";
        }
        else
        {
            cout << "已借出"
                 << " ";
        }
        cout << "借出日期" << data << endl;
    }

    void Delete(vector<book> &b, book c, int i);
};

#endif
```

book类里面包含了书名，作者名，ID(唯一的)，是否借出状态位，借出日期(初始化为0/0/0)。

有一个```cppshow()```函数，用来展示书籍信息

**同User类一样Book类也没有cpp文件，只设置了User类供Administrator.cpp使用**

三、Administrator的设置
大部分操作的函数都在这个文件里

有用户的注册、登录等
```cpp
void Login(vector<User> &u); //注册

int Address(vector<User> &u); //登录
```
其中登录返回值类型为 int 返回的是用户在```cppvector<User> &u```在用户数据库(.txt文件)中的位置