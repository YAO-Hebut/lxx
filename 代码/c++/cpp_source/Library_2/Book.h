#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class book
{
public:
    string name;
    string writer;
    string ID;
    bool status = 1; //默认为未借出状态
    string data;     //记录借还日期

    book();
    ostream &operator<<(const book b) //对“<<”进行重载，使得可以直接输出book类
    {
        cout << b.name << " " << b.writer << " " << b.ID << " ";
        if (b.status)
        {
            cout << "可借"
                 << " ";
        }
        else
        {
            cout << "已借出"
                 << " ";
        }
        cout << "借出日期" << b.data << endl;
    }
};

#endif