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

    User();
    ~User();
};

#endif