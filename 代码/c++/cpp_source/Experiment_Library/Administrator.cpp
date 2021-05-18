#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "User.h"
#include "Book.h"
#include "Administrator.h"

using namespace std;

// void showBook()
// {
//     cout << "《" << get_name() << "》"
//          << "\t";
//     cout << "作者：" << get_writer() << "\t";
//     cout << "ID:" << get_ID() << "\t";
// }

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

void fetch_Resources(vector<Resources> b)
{
    ifstream ifs;
    ifs.open("Resources.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败！" << endl;
        ifs.close();
        return;
    }
    Resources r;
    while (ifs >> r.name && ifs >> r.writer && ifs >> r.ID && ifs >> r.status)
    {
        b.push_back(r);
    }
    ifs.close();
}

void showMenu_Chazhao()
{
    cout << "******************************" << endl;
    cout << "********* 1.按书名查找 ********" << endl;
    cout << "********* 2.按作者查找 ********" << endl;
    cout << "********* 3.按ID查找   ********" << endl;
    cout << "**********其他键退出***********" << endl;
    cout << "******************************" << endl;
}

void showMenu_Xiugai()
{
    cout << "******************************" << endl;
    cout << "********* 1.删除书籍 ********" << endl;
    cout << "********* 2.修改书名 ********" << endl;
    cout << "********* 3.修改作者   *******" << endl;
    cout << "********* 4.修改书ID  ********" << endl;
    cout << "***********其他键退出*********" << endl;
    cout << "******************************" << endl;
}

void showStudent()
{
    cout << "**************************************************" << endl;
    cout << "***************1.借书*****************************" << endl;
    cout << "***************2.还书*****************************" << endl;
    cout << "***************3.找书*****************************" << endl;
    cout << "**************其他键退出***************************" << endl;
    cout << "**************************************************" << endl;
}

void showAdministrator()
{
    cout << "**************************************************" << endl;
    cout << "***************1.找书*****************************" << endl;
    cout << "***************2.增*****************************" << endl;
    cout << "***************3.删*****************************" << endl;
    cout << "***************4.改*****************************" << endl;
    cout << "**************其他键退出***************************" << endl;
    cout << "**************************************************" << endl;
}

//****************************************查找图书*************************************************//

void find_name(vector<Resources> b, vector<Resources> c) //c存储所查找到的书籍(可能会有重复)
{
    cout << "请输入书名:" << endl;
    string find;
    cin >> find;
    for (auto &i : b)
    {
        if (i.name == find)
        {
            c.push_back(i);
        }
    }
}

void find_writer(vector<Resources> b, vector<Resources> c) //c存储所查找到的书籍(可能会有重复)
{
    cout << "请输入作者:" << endl;
    string find;
    cin >> find;
    for (auto &i : b)
    {
        if (i.writer == find)
        {
            c.push_back(i);
        }
    }
}
void find_id(vector<Resources> b, vector<Resources> c) //c存储所查找到的书籍(可能会有重复)
{
    cout << "请输入ID:" << endl;
    string find;
    cin >> find;
    for (auto &i : b)
    {
        if (i.ID == find)
        {
            c.push_back(i);
        }
    }
}

Resources find_Resources(vector<Resources> b) //查找的封装
{
    showMenu_Chazhao();
    int x;
    cin >> x;
    vector<Resources> c;
    switch (x)
    {
    case 1:
    {
        find_name(b, c);
        break;
    }
    case 2:
    {
        find_writer(b, c);
        break;
    }
    case 3:
    {
        find_id(b, c);
        break;
    }
    default:
    {
        cout << "输入错误！";
        break;
    }
    }
    if (c.empty()) //c为空时表示没有此书
    {
        cout << "查无此书！" << endl;
    }
    else if (c.size() == 1) //c=1时只查到一本书，无重复书籍
    {
        c[0].showBook();
        return c[0];
    }
    else //查到多本书时，依次显示出来
    {
        int i;
        for (i = 0; i < c.size(); i++)
        {
            cout << i + 1 << "、";
            c[i].showBook();
        }
        cout << "请确定您要找的书籍序号:" << endl;
        cin >> i;
        c[i].showBook();
        return c[i - 1];
    }
}

//****************************************查找图书*************************************************//

//****************************************添加图书*************************************************//

void add_resources(vector<Resources> b)
{
    string n, w, id;
    int qua;
    // cout << "请输入您要增加的资源种类：" << endl;
    // cout << "1.书籍" << endl;
    // cout << "2.唱片" << endl;                      //由于做两种Resources类型太过复杂，先只做Book一种类型，以后有机会再补Album类的Resources(2021/5/9)

    cout << "请输入您想要添加的书籍的名称：";
    cin >> n;
    cout << "请输入您想要添加的书籍的ID：";
    cin >> id;
    cout << "请输入您想要添加的书籍的作者：";
    cin >> w;
    // cout << "请输入您想要添加的书籍的数量：";
    // cin >> qua;
    Resources r;
    r.name = n;
    r.ID = id;
    r.writer = w;
    // r.quantity = qua;
    b.push_back(r);
    ofstream ofs;
    ofs.open("Resources.txt", ios::out);
    for (auto &i : b)
    {
        ofs << i.name << " " << i.ID << " " << i.writer << endl;
    }
    cout << "添加成功！" << endl;
    ofs.close();
}
//****************************************添加图书*************************************************//

//************************************修改图书(修改和删除)******************************************//

void delete_resources(vector<Resources> b) //删除
{
    Resources c;
    c = find_Resources(b);
    int i;
    for (i = 0; i < b.size(); i++)
    {
        if (b[i].ID == c.ID) //ID是唯一的，通过ID来确认唯一书籍
            b.erase(b.begin() + i);
    }
    cout << "删除成功！" << endl;
}

void change_name(vector<Resources> b)
{
    cout << "请输入新的书名：" << endl;
    string new_name;
    cin >> new_name;
    Resources c;
    c = find_Resources(b);
    int i;
    for (i = 0; i < b.size(); i++)
    {
        if (b[i].ID == c.ID) //ID是唯一的，通过ID来确认唯一书籍
            b[i].name = new_name;
    }
    cout << "修改成功！" << endl;
    b[i].showBook();
}

void change_writer(vector<Resources> b)
{
    cout << "请输入新的作者名：" << endl;
    string new_writer;
    cin >> new_writer;
    Resources c;
    c = find_Resources(b);
    int i;
    for (i = 0; i < b.size(); i++)
    {
        if (b[i].ID == c.ID) //ID是唯一的，通过ID来确认唯一书籍
            b[i].writer = new_writer;
    }
    cout << "修改成功！" << endl;
    b[i].showBook();
}
void change_id(vector<Resources> b)
{
    int i, flag = 1;
    cout << "请输入新的ID：" << endl;
    string new_id;
    cin >> new_id;
    for (i = 0; i < b.size(); i++)
    {
        if (b[i].ID == new_id) //ID是唯一的，通过ID来确认唯一书籍
        {
            cout << "该ID已存在，修改失败" << endl;
            flag = 0;
        }
    }
    if (flag)
    {
        Resources c;
        c = find_Resources(b);

        for (i = 0; i < b.size(); i++)
        {
            if (b[i].ID == c.ID) //ID是唯一的，通过ID来确认唯一书籍
                b[i].ID = new_id;
        }
        cout << "修改成功！" << endl;
        b[i].showBook();
    }
}

// void change_quantity(vector<Resources> b)
// {
//     cout << "请输入现在书的数量：" << endl;
//     int new_quantity;
//     cin >> new_quantity;
//     if (new_quantity < 0)
//     {
//         cout << "输入错误！" << endl;
//     }
//     else
//     {
//         Resources c;
//         c = find_Resources(b);
//         int i, lent;
//         for (i = 0; i < b.size(); i++)
//         {
//             if (b[i].ID == c.ID) //ID是唯一的，通过ID来确认唯一书籍
//             {
//                 lent = b[i].quantity - b[i].remindance;
//                 b[i].quantity = new_quantity;
//             }
//             if ((b[i].quantity - b[i].remindance) < 0)
//             {
//                 b[i].remindance = 0;
//             }
//             else
//             {
//                 b[i].remindance = b[i].quantity - lent;
//             }
//         }
//         cout << "修改成功！" << endl;
//         b[i].showBook();
//     }
// }

void change_resources(vector<Resources> b) //修改和删除的封装
{
    showMenu_Xiugai();
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
    {
        delete_resources(b);
        break;
    }
    case 2:
    {
        change_name(b);
        break;
    }
    case 3:
    {
        change_writer(b);
        break;
    }
    case 4:
    {
        change_id(b);
        break;
    }
    default:
    {
        cout << "输入错误！";
        break;
    }
    }
}

//************************************修改图书(修改和删除)******************************************//

//***************************************借书******************************************************//
void borrow(vector<Resources> b)
{
    Resources c;
    c = find_Resources(b);
    int i;
    for (i = 0; i < b.size(); i++)
    {
        if (b[i].ID == c.ID)
        {
            b[i].showBook();
            if (b[i].get_status())
            {
                cout << "是否确定借阅此书？(Y/N)" << endl;
                string question;
                cin >> question;
                if (question == "Y")
                {
                    b[i].set_status(0);
                    cout << "借阅成功" << endl;
                }
                else
                {
                    cout << "退出" << endl;
                }
            }
        }
    }
}

//***************************************借书******************************************************//

//***************************************还书******************************************************//
void payback(vector<Resources> b)
{
    Resources c;
    c = find_Resources(b);
    int i;
    for (i = 0; i < b.size(); i++)
    {
        if (b[i].ID == c.ID)
        {
            b[i].showBook();
            if (!b[i].get_status())
            {
                cout << "是否归还此书？(Y/N)" << endl;
                string question;
                cin >> question;
                if (question == "Y")
                {
                    b[i].set_status(1);
                    cout << "归还成功" << endl;
                }
                else
                {
                    cout << "退出" << endl;
                }
            }
        }
    }
}

//***************************************还书******************************************************//

// 学生登陆界面(借、还、找封装起来)
void User_student(vector<Resources> b)
{
    showStudent();
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        borrow(b);
    case 2:
        payback(b);
    case 3:
        find_Resources(b);
    default:
        cout << "退出" << endl;
    }
}

// 管理员登陆界面(增、删、改、查封装起来)
void User_administrator(vector<Resources> b)
{
    showAdministrator();
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        find_Resources(b);
    case 2:
        add_resources(b);
    case 3:
        delete_resources(b);
    case 4:
        change_resources(b);
    default:
        cout << "退出" << endl;
    }
}

/**************************************user***********************************/
// void set_name(string n) { name == n; }
// void set_gender(string g) { gender == g; }
// void set_ID(string id) { ID == id; }
// void set_password(string pass) { password == pass; }
// void set_bool(bool s) { is_Student = s; }

// string get_name() { return name; }
// string get_gender() { return gender; }
// string get_ID() { return ID; }
// string get_password() { return password; }
// bool get_bool() { return is_Student; }

bool isExistID(string id, vector<User> u)
{
    for (int i = 0; i < u.size(); i++)
    {
        if (id == u[i].ID)
            return i;
    }
    return 0;
}

void login(vector<User> u)
{
    // ofstream fout("D:\Codefield\Code\c++\cpp_source\Experiment_Library\Reader.txt");
    string n;
    string g;
    string id;
    string pass;
    User a;
    cout << "请输入您的姓名:";
    cin >> n;
    cout << "请输入您的性别:";
    cin >> g;
    cout << "请输入您想要创建的的账号ID:";
    cin >> id;
    cout << "请输入您要创建的密码:";
    cin >> pass;
    if (isExistID(id, u))
    {
        cout << "该用户ID已存在" << endl; //通过判断ID是否存在来决定是否可以用此ID注册
    }
    else
    {
        a.name = n;
        a.gender = g;
        a.ID = id;
        a.password = pass;
        u.push_back(a);
        ofstream ofs;
        ofs.open("user.txt", ios::out);
        for (auto &i : u)
        {
            ofs << i.name << " " << i.gender << " " << i.ID << " " << i.password << " " << i.is_Student << endl; //存入文件中
        }
        cout << "注册成功！" << endl;
        ofs.close();
    }
}

bool address(vector<User> u)
{
    string id, pass;
    int flag;
    cout << "请输入您的ID:";
    cin >> id;
    flag = isExistID(id, u);
    if (flag) //id存在时
    {
        cout << "请输入您的密码:";
        cin >> pass;
        if (u[flag].password == pass)
        {
            cout << "登陆成功！" << endl;
            return true;
        }
    }
    else
    {
        cout << "密码错误！" << endl;
        return false;
    }
}

void dlt(vector<User> u)
{
    string id, pass;
    int flag;
    cout << "请输入您的ID:";
    cin >> id;
    flag = isExistID(id, u);
    if (flag) //id存在时
    {
        cout << "请输入您的密码:";
        cin >> pass;
        if (u[flag].password == pass)
        {
            cout << "登陆成功！" << endl;
            cout << "是否确定删除此账户？(Y/N)" << endl;
            string x;
            cin >> x;
            if (x == "Y")
            {
                u.erase(u.begin() + flag);
                cout << "删除成功！" << endl;
            }
        }
    }
    else
    {
        cout << "密码错误！" << endl;
    }
}

void User_student(vector<Resources> b);       //学生界面
void User_administrator(vector<Resources> b); //管理员界面
void begin(vector<User> u, vector<Resources> b)
{
    showMenu_begin();
    int x;
    cin >> x;
    int flag = 0;
    switch (x)
    {
    case 1:
        flag = address(u);
    case 2:
        login(u);
    case 3:
        dlt(u);
    }
    if (flag)
    {
        cout << "您是否为管理员？(Y/N)" << endl;
        string YN, pass;
        cin >> YN;
        if (YN == "Y")
        {
            cout << "请输入权限码:" << endl;
            cin >> pass;
            if (pass == administrator_key)
            {
                User_administrator(b);
            }
            else
            {
                cout << "密码错误" << endl;
            }
        }
        else if (YN == "N")
        {
            User_student(b);
        }
        else
        {
            cout << "输入错误！" << endl;
        }
    }
}

void fetch_User(vector<User> u)
{
    ifstream ifs;
    ifs.open("User.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败！" << endl;
        ifs.close();
        return;
    }
    User user;
    while (ifs >> user.name && ifs >> user.gender && ifs >> user.ID && ifs >> user.password && ifs >> user.is_Student)
    {
        u.push_back(user);
    }
    ifs.close();
}

/**************************************user***********************************/
