#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Book.h"
#include "User.h"

using namespace std;

//**************************************对书的操作*************************************************//

void ArrangeBook(vector<book> &b); //将对书的增删改查都封装到这里面

//***********************************对书的增加***********************************//

void AddBook(vector<book> &b);
void AddName(vector<book> &b, book c);
void AddWriter(vector<book> &b, book c);
void AddID(vector<book> &b, book c);

//***********************************对书的增加***********************************//

//***********************************对书的删除***********************************//

void DeleteBook(vector<book> &b);

//***********************************对书的删除***********************************//

//***********************************对书的查找***********************************//

book FindBook(vector<book> &b);                    //找书的汇总,返回为book类可应用于删改等后续操作
void FindName(vector<book> &b, vector<book> &c);   //通过书名找书  vector<book> &c用来存储所找到的书籍，最后返回到findbook里面封装起来
void FindWriter(vector<book> &b, vector<book> &c); //通过作者找书
void FindID(vector<book> &b, vector<book> &c);     //通过ID找书

//***********************************对书的查找***********************************//

//***********************************对书的改***********************************//

void ChangeBook(vector<book> &b);   //改书的汇总
void ChangeName(vector<book> &b);   //改书名
void ChangeWriter(vector<book> &b); //改作者
void ChangeID(vector<book> &b);     //改书ID

//***********************************对书的改***********************************//

//**************************************对书的操作*************************************************//

//

//

//**************************************User的操作*************************************************//

void BorrowBook(vector<book> &b); //借助FindBook进行，改变标志位并记录下借书时间data即可

void PaybackBook(vector<book> &b); //借助FindBook进行，改变标志位即可

void Login(vector<User> &u); //注册

int Address(vector<User> &u); //登录

//**************************************User的操作*************************************************//

//*************************************信息存入.txt文件的操作***************************************//
void saveinBook(vector<book> &b); //Book信息存入
void fetchBook(vector<book> &b);  //Book信息读出，main()函数一开始时就进行读出操作，即信息的初始化

void saveinUser(vector<User> &u); //User信息存入
void fetchUser(vector<User> &u);  //Book信息读出，main()函数一开始时就进行读出操作，即信息的初始化

//*************************************信息存入.txt文件的操作***************************************//

void Begin(vector<book> &b, vector<User> &u); //开始界面

void show_Menu_Arrange()
{
    cout << "******************************" << endl;
    cout << "********* 1.添加书籍 ********" << endl;
    cout << "********* 2.查找书籍 ********" << endl;
    cout << "********* 3.更改书籍信息********" << endl;
    cout << "********* 4.删除书籍********" << endl;
    cout << "********* 5.借书********" << endl;
    cout << "********* 6.还书********" << endl;
    cout << "**********其他键退出***********" << endl;
    cout << "******************************" << endl;
}

void show_Menu_Find()
{
    cout << "******************************" << endl;
    cout << "********* 1.按书名查找 ********" << endl;
    cout << "********* 2.按作者查找 ********" << endl;
    cout << "********* 3.按ID查找   ********" << endl;
    cout << "**********其他键退出***********" << endl;
    cout << "******************************" << endl;
}

void show_Menu_Change()
{
    cout << "******************************" << endl;
    cout << "********* 1.修改书名 ********" << endl;
    cout << "********* 2.修改作者 ********" << endl;
    cout << "********* 3.修改ID  ********" << endl;
    cout << "**********其他键退出***********" << endl;
    cout << "******************************" << endl;
}

void show_Menu_Begin()
{
    cout << "*************************" << endl;
    cout << "********* 1.登录 ********" << endl;
    cout << "********* 2.注册 ********" << endl;
    cout << "********其他键退出********" << endl;
    cout << "*************************" << endl;
}

#endif