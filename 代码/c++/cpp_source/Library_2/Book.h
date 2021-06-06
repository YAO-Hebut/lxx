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