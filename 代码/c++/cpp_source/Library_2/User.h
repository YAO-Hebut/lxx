#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

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
    int book_days = 30;

    friend ostream &operator<<(ostream &ofs, User u)
    {
        ofs << left << setw(13) << u.name;
        ofs << left << setw(13) << u.gender;
        ofs << left << setw(13) << u.ID;
        ofs << left << setw(13) << u.password;
        if (u.is_Student)
        {
            ofs << left << setw(13) << "学生";
        }
        else
        {
            ofs << left << setw(13) << "管理员  " << endl;
        }
        ofs << left << setw(13) << u.book_num << endl;

        return ofs;
    }
};

class Adm : public User
{
public:
    bool is_Student = 0; //默认为管理员
    int book_days = 90;
};

#endif