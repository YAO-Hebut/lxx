#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
// #include "Book.h"

using namespace std;

class User //User为用户类
{
private:
public:
    string name;
    string gender;
    string ID;
    string password;
    bool is_Student = 1; //默认为学生
    
    
};
#endif