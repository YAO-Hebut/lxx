#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "User.h"
#include "Book.h"

using namespace std;

// void showBook()
// {
//     cout << "《" << get_name() << "》"
//          << "\t";
//     cout << "作者：" << get_writer() << "\t";
//     cout << "ID:" << get_ID() << "\t";
// }

void add_resources(vector<Resources> b);    //图书管理员对Resources进行“增”的操作
void delete_resources(vector<Resources> b); //图书管理员对Resources进行“删”的操作

Resources find_Resources(vector<Resources> b);              //Resources查找功能
void find_name(vector<Resources> b, vector<Resources> c);   //通过name查找书
void find_writer(vector<Resources> b, vector<Resources> c); //通过writer查找书
void find_id(vector<Resources> b, vector<Resources> c);     //通过id查找书

void change_resources(vector<Resources> b); //图书管理员对Resources进行“改”的操作
void change_name(vector<Resources> b);      //更改name
void change_writer(vector<Resources> b);    //更改writer
void change_id(vector<Resources> b);        //更改ID
// void change_quantity(vector<Resources> b);  //更改quantity

void borrow(vector<Resources> b);  //学生借书
void payback(vector<Resources> b); //学生还书

void User_student(vector<Resources> b);       //学生界面
void User_administrator(vector<Resources> b); //管理员界面

void set_name(string);                     //设置name
void set_gender(string);                   //设置gender
void set_ID(string);                       //设置ID
void set_password(string);                 //设置password
void set_bool(bool);                       //设置is_Student
string get_name();                         //获取name
string get_gender();                       //获取gender
string get_ID();                           //获取ID
string get_password();                     //获取password
bool get_bool();                           //获取is_Student
bool isExistID(string id, vector<User> u); //用来时判断此ID是否已经存在,登陆时也用于寻找到该ID的下标值i
void login(vector<User> u);                //用户注册
void dlt(vector<User> u);                  //用户删除
bool address(vector<User> u);              //用户登录

void begin(vector<User> u, vector<Resources> b); //开始界面

void fetch_Resources(vector<Resources> b);
void fetch_User(vector<User> u);

void showMenu_begin()
{
    cout << "**************************************************" << endl;
    cout << "***************1.登录*****************************" << endl;
    cout << "***************2.注册*****************************" << endl;
    cout << "***************3.删除用户**************************" << endl;
    cout << "**************************************************" << endl;
}

string administrator_key = "20010626";

#endif