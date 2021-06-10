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

    friend ostream &operator<<(ostream &ofs, User u)
    {
        ofs << u.name << "    " << u.gender << "    " << u.ID << "    " << u.password << "    ";
        if (u.is_Student)
        {
            ofs << "学生   ";
        }
        else
        {
            ofs << "老师/管理员  " << endl;
        }
        ofs << u.book_num << endl;

        return ofs;
    }
};

#endif