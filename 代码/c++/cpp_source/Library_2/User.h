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