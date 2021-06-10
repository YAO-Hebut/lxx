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

    friend ostream &operator<<(ostream &ofs, book b)
    {
        ofs << b.name << "     " << b.writer << "     " << b.ID << "     ";
        if (b.status)
        {
            ofs << "可借"
                << "     ";
        }
        else
        {
            ofs << "已借出"
                << "     ";
        }
        ofs << b.data << endl;

        return ofs;
    }

    void Delete(vector<book> &b, book c, int i);
};

#endif