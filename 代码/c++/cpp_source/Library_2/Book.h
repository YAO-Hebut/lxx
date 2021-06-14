#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

class book
{
public:
    string name;
    string writer;
    string ID;
    bool status = 1;           //默认为未借出状态
    string data = "none";      //记录借出日期
    string data_back = "none"; //记录应该归还日期
    string borrow_ID = "none"; //记录借书人ID

    friend ostream &operator<<(ostream &ofs, book b)
    {
        ofs << left << setw(13) << b.name;
        ofs << left << setw(13) << b.writer;
        ofs << left << setw(13) << b.ID;

        if (b.status)
        {
            ofs << left << setw(13) << "可借";
            ofs << left << setw(13) << b.data << endl;
        }

        else
        {
            ofs << left << setw(13) << "已借出";
            ofs << left << setw(13) << b.data;
            ofs << left << setw(13) << b.data_back;
            ofs << left << setw(13) << b.borrow_ID << endl;
        }

        return ofs;
    }

    void Delete(vector<book> &b, book c, int i);
};

#endif