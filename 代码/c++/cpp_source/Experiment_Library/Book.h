
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
// #include "User.h"

using namespace std;

class Resources
{
public:
    string name;
    string writer;
    string ID;
    bool status = 1; //默认为未借出状态
    // int quantity;
    // int remindance;
    string data;

    void set_name(string);
    void set_writer(string);
    void set_ID(string);
    void set_status(bool);
    // void set_quantity(int);
    // void set_remidance(int);
    void set_data(string);

    string get_name();
    string get_writer();
    string get_ID();
    bool get_status();
    // int get_quantity();
    // int get_remindance();      //2021.5.16发现这两个数据成员是不需要的，因为一个ID只能对应一本书
    string get_data();

    void showBook()
    {
        cout << "《" << get_name() << "》"
             << "\t";
        cout << "作者：" << get_writer() << "\t";
        cout << "ID:" << get_ID() << "\t";
    }

    // void add_resources(vector<Resources> b);    //图书管理员对Resources进行“增”的操作
    // void delete_resources(vector<Resources> b); //图书管理员对Resources进行“删”的操作

    // Resources find_Resources(vector<Resources> b);              //Resources查找功能
    // void find_name(vector<Resources> b, vector<Resources> c);   //通过name查找书
    // void find_writer(vector<Resources> b, vector<Resources> c); //通过writer查找书
    // void find_id(vector<Resources> b, vector<Resources> c);     //通过id查找书

    // void change_resources(vector<Resources> b); //图书管理员对Resources进行“改”的操作
    // void change_name(vector<Resources> b);      //更改name
    // void change_writer(vector<Resources> b);    //更改writer
    // void change_id(vector<Resources> b);        //更改ID
    // // void change_quantity(vector<Resources> b);  //更改quantity

    // void borrow(vector<Resources> b);  //学生借书
    // void payback(vector<Resources> b); //学生还书

    // void User_student(vector<Resources> b);       //学生界面
    // void User_administrator(vector<Resources> b); //管理员界面

    // void fetch_Resources(vector<Resources> b)
    // {
    //     ifstream ifs;
    //     ifs.open("Resources.txt", ios::in);
    //     if (!ifs.is_open())
    //     {
    //         cout << "文件打开失败！" << endl;
    //         ifs.close();
    //         return;
    //     }
    //     Resources r;
    //     while (ifs >> r.name && ifs >> r.writer && ifs >> r.ID && ifs >> r.status)
    //     {
    //         b.push_back(r);
    //     }
    //     ifs.close();
    // }

    // void showMenu_Chazhao()
    // {
    //     cout << "******************************" << endl;
    //     cout << "********* 1.按书名查找 ********" << endl;
    //     cout << "********* 2.按作者查找 ********" << endl;
    //     cout << "********* 3.按ID查找   ********" << endl;
    //     cout << "**********其他键退出***********" << endl;
    //     cout << "******************************" << endl;
    // }

    // void showMenu_Xiugai()
    // {
    //     cout << "******************************" << endl;
    //     cout << "********* 1.删除书籍 ********" << endl;
    //     cout << "********* 2.修改书名 ********" << endl;
    //     cout << "********* 3.修改作者   *******" << endl;
    //     cout << "********* 4.修改书ID  ********" << endl;
    //     cout << "***********其他键退出*********" << endl;
    //     cout << "******************************" << endl;
    // }

    // void showStudent()
    // {
    //     cout << "**************************************************" << endl;
    //     cout << "***************1.借书*****************************" << endl;
    //     cout << "***************2.还书*****************************" << endl;
    //     cout << "***************3.找书*****************************" << endl;
    //     cout << "**************其他键退出***************************" << endl;
    //     cout << "**************************************************" << endl;
    // }

    // void showAdministrator()
    // {
    //     cout << "**************************************************" << endl;
    //     cout << "***************1.找书*****************************" << endl;
    //     cout << "***************2.增*****************************" << endl;
    //     cout << "***************3.删*****************************" << endl;
    //     cout << "***************4.改*****************************" << endl;
    //     cout << "**************其他键退出***************************" << endl;
    //     cout << "**************************************************" << endl;
    // }
};

#endif