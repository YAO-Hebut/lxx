#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Book.h"
#include "User.h"
#include "Administrator.h"

using namespace std;

void Begin(vector<book> &b, vector<User> &u)
{
    show_Menu_Begin();
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
    {
        int y;
        y = Address(u);
        if (y)
        {
            ArrangeBook(b);
        }
        else
        {
            cout << "退出..." << endl;
            break;
        }
        break;
    }
    case 2:
    {
        Login(u);
        break;
    }
    default:
    {
        cout << "退出..." << endl;
        break;
    }
    }
}

void ArrangeBook(vector<book> &b) //将对书的增删改查都封装到这里面
{
    string quanxian = "190665"; //管理员特权码
    show_Menu_Arrange();
    int x;
    cin >> x;
    string key; //增改删需要用特权码
    switch (x)
    {
    case 1:
    {
        cout << "请输入您的权限码：";
        cin >> key;
        if (key == quanxian)
        {
            book newbook;
            string id, name, writer;
            int x = 0; //判断id是否已经存在
            cout << "请输入新书的ID：";
            cin >> id;
            for (auto &i : b)
            {
                if (i.ID == id)
                    x = -1;
            }
            if (x == -1)
            {
                cout << "该ID已经存在" << endl;
            }
            else if (x == 0)
            {
                cout << "请输入新书的书名：";
                cin >> name;
                cout << "请输入新书的作者：";
                cin >> writer;
                newbook.ID = id;
                newbook.name = name;
                newbook.writer = writer;
                b.push_back(newbook);
                saveinBook(b);
            }
            cout << "添加完毕" << endl;
        }
        break;
    }
    case 2:
    {
        book find_book;
        find_book = FindBook(b);
        if (find_book.ID == "-1")
        {
            cout << "未找到此书籍..." << endl;
        }
        else
            find_book.show();
    }
    break;
    case 3:
    {
        cout << "请输入您的权限码：";
        cin >> key;
        if (key == quanxian)
        {
            ChangeBook(b);
        }
        break;
    }
    case 4:
    {
        cout << "请输入您的权限码：";
        cin >> key;
        if (key == quanxian)
        {
            DeleteBook(b);
        }
        break;
    }
    case 5:
    {
        BorrowBook(b);
        break;
    }
    case 6:
    {
        PaybackBook(b);
        break;
    }
    default:
    {
        cout << "退出..." << endl;
        break;
    }
    }
}

//***********************************对书的增加***********************************//

void AddBook(vector<book> &b)
{
    book newbook;
    string id, name, writer;
    int x = 0; //判断id是否已经存在
    cout << "请输入新书的ID：";
    cin >> id;
    for (auto &i : b)
    {
        if (i.ID == id)
            x = -1;
    }
    if (x == -1)
    {
        cout << "该ID已经存在" << endl;
    }
    else if (x == 0)
    {
        cout << "请输入新书的书名：";
        cin >> name;
        cout << "请输入新书的作者：";
        cin >> writer;
        newbook.ID = id;
        newbook.name = name;
        newbook.writer = writer;
        b.push_back(newbook);
    }
    cout << "添加完毕" << endl;
}
void AddName(vector<book> &b, book &c)
{
    cout << "请输入新书的书名：";
    string new_name;
    cin >> new_name;
    c.name = new_name;
}
void AddWriter(vector<book> &b, book &c)
{
    cout << "请输入新书的作者：";
    string new_writer;
    cin >> new_writer;
    c.writer = new_writer;
}
void AddID(vector<book> &b, book &c)
{
    cout << "请输入新书的ID：";
    string new_id;
    cin >> new_id;
    c.ID = new_id;
}

//***********************************对书的增加***********************************//

//***********************************对书的删除***********************************//

void DeleteBook(vector<book> &b)
{
    book c;
    c = FindBook(b);
    cout << "请先选择您要删除的书籍" << endl;
    if (c.ID == "-1")
    {
        cout << "未找到书籍..." << endl;
    }
    else
    {
        int i;
        for (i = 0; i < b.size(); i++)
        {
            if (b[i].ID == c.ID)
            {
                cout << "是否删除该书？(Y/N)" << endl;
                b[i].show();
                string YN;
                cin >> YN;
                if (YN == "Y")
                {
                    b.erase(b.begin() + i);
                    cout << "删除成功" << endl;
                }
                else if (YN == "N")
                {
                    cout << "退出..." << endl;
                    break;
                }
                else
                {
                    cout << "输入错误..." << endl;
                    break;
                }
            }
        }
    }
}

//***********************************对书的删除***********************************//

//***********************************对书的查找***********************************//

book FindBook(vector<book> &b) //找书的汇总,返回为book类可应用于删改等后续操作
{
    book temp;
    vector<book> c;
    temp.ID = "0";
    int x;
    cout << "请选择您要查找的方式：" << endl;
    show_Menu_Find();
    cin >> x;
    switch (x)
    {
    case 1:
    {
        FindName(b, c);
        break;
    }
    case 2:
    {
        FindWriter(b, c);
        break;
    }
    case 3:
    {
        FindID(b, c);
        break;
    }
    default:
    {
        temp.ID = "-1";
        break;
    }
    }
    if (temp.ID != "-1")
    {
        if (c.empty())
        {

            temp.ID = "-1";
        }
        else if (c.size() == 1)
        {
            return c[0];
        }
        else
        {
            for (int i = 0; i < c.size(); i++)
            {
                for (i = 0; i < c.size(); i++)
                {
                    cout << i + 1 << ".";
                    c[i].show();
                }
                cout << "请选择您想要的书籍：";
                int y;
                cin >> y;
                if (y - 1 >= 0 && y - 1 < c.size())
                    return c[y - 1];
                else
                {
                    cout << "选择错误!" << endl;
                    temp.ID = -1;
                    break;
                }
            }
        }
    }
    return temp;
}
void FindName(vector<book> &b, vector<book> &c) //通过书名找书  vector<book> &c用来存储所找到的书籍，最后返回到findbook里面封装起来
{
    cout << "请输入你要查找的书名：";
    string find_name;
    cin >> find_name;
    for (auto &i : b)
    {
        if (i.name == find_name)
        {
            c.push_back(i);
        }
    }
}
void FindWriter(vector<book> &b, vector<book> &c) //通过作者找书
{
    {
        cout << "请输入你要查找的作者名：";
        string find_writer;
        cin >> find_writer;
        for (auto &i : b)
        {
            if (i.writer == find_writer)
            {
                c.push_back(i);
            }
        }
    }
}
void FindID(vector<book> &b, vector<book> &c) //通过ID找书
{
    {
        cout << "请输入你要查找的ID：";
        string find_id;
        cin >> find_id;
        for (auto &i : b)
        {
            if (i.ID == find_id)
            {
                c.push_back(i);
            }
        }
    }
}

//***********************************对书的查找***********************************//

//***********************************对书的改***********************************//

void ChangeBook(vector<book> &b) //改书的汇总
{
    show_Menu_Change();
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
    {
        ChangeName(b);
        break;
    }
    case 2:
    {
        ChangeWriter(b);
        break;
    }
    case 3:
    {
        ChangeID(b);
        break;
    }
    default:
    {
        cout << "退出..." << endl;
        break;
    }
    }
}
void ChangeName(vector<book> &b) //改书名
{
    cout << "请输入新的书名：";
    string new_name;
    cin >> new_name;
    book c;
    c = FindBook(b);
    if (c.ID == "-1")
    {
        cout << "未找到书籍..." << endl;
    }
    else
    {
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i].ID == c.ID)
            {
                b[i].name = new_name;
                cout << "修改成功..." << endl;
                break;
            }
        }
    }
}
void ChangeWriter(vector<book> &b) //改作者
{
    cout << "请输入新的作者：";
    string new_writer;
    cin >> new_writer;
    book c;
    c = FindBook(b);
    if (c.ID == "-1")
    {
        cout << "未找到书籍..." << endl;
    }
    else
    {
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i].ID == c.ID)
            {
                b[i].writer = new_writer;
                cout << "修改成功..." << endl;
                break;
            }
        }
    }
}
void ChangeID(vector<book> &b) //改书ID
{
    cout << "请输入新的书名：";
    string new_id;
    cin >> new_id;
    book c;
    c = FindBook(b);
    if (c.ID == "-1")
    {
        cout << "未找到书籍..." << endl;
    }
    else
    {
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i].ID == c.ID)
            {
                b[i].ID = new_id;
                cout << "修改成功..." << endl;
                break;
            }
        }
    }
}

//***********************************对书的改***********************************//

//

//

void BorrowBook(vector<book> &b) //借助FindBook进行，改变标志位并记录下借书时间data即可
{
}

void PaybackBook(vector<book> &b) //借助FindBook进行，改变标志位即可
{
}

void Login(vector<User> &u) //注册
{
    string id, name, password, gender;
    User temp;
    cout << "请输入您要注册的ID";
    cin >> id;
    int x = 0; //判断id是否已经存在
    for (auto &i : u)
    {
        if (i.ID == id)
            x = -1;
    }
    if (x == -1)
    {
        cout << "该ID已经存在" << endl;
    }
    else if (x == 0)
    {
        cout << "请输入您的姓名";
        cin >> name;
        cout << "请输入您的密码";
        cin >> password;
        cout << "请输入您的性别";
        cin >> gender;
        temp.ID = id;
        temp.name = name;
        temp.password = password;
        temp.gender = gender;
        u.push_back(temp);
        saveinUser(u);
    }
}

int Address(vector<User> &u) //登录
{
    string id, password;
    int s = 0;
    cout << "请输入您的ID" << endl;
    cin >> id;
    int x = 0; //判断ID是否存在
    for (int i = 0; i < u.size(); i++)
    {
        if (u[i].ID == id)
        {
            x = 1;
            s = i;
        }
    }
    if (x)
    {
        cout << "请输入您的密码：";
        cin >> password;
        if (u[s].password == password)
        {
            cout << "登录成功..." << endl;
            return 1;
        }
        else
        {
            cout << "密码错误..." << endl;
            return 0;
        }
    }
    else
    {
        cout << "该ID不存在..." << endl;
        return 0;
    }
}

//*************************************信息存入.txt文件的操作***************************************//
void saveinBook(vector<book> &b) //Book信息存入
{
    ofstream ofs;
    ofs.open("D:\\Codefield\\Code\\c++\\cpp_source\\Library_2\\Book.txt", ios::out);
    for (auto &i : b)
    {
        ofs << i.name << " " << i.writer << " " << i.ID << " " << i.data << " " << i.status << endl;
    }
    cout << "存入完毕..." << endl;
    ofs.close();
}
void fetchBook(vector<book> &b) //Book信息读出，main()函数一开始时就进行读出操作，即信息的初始化
{
    ifstream ifs;
    ifs.open("D:\\Codefield\\Code\\c++\\cpp_source\\Library_2\\Book.txt", ios::in);
    book temp;
    while (ifs >> temp.name && ifs >> temp.writer && ifs >> temp.ID && ifs >> temp.data && ifs >> temp.status)
    {
        b.push_back(temp);
    }
    cout << "书籍初始化完毕..." << endl;
    ifs.close();
}

void saveinUser(vector<User> &u) //User信息存入
{
    ofstream ofs;
    ofs.open("D:\\Codefield\\Code\\c++\\cpp_source\\Library_2\\User.txt", ios::app);
    for (auto &i : u)
    {
        ofs << i.ID << " " << i.name << " " << i.password << " " << i.gender << " " << i.is_Student << endl;
    }
    cout << "存入完毕..." << endl;
    ofs.close();
}
void fetchUser(vector<User> &u) //Book信息读出，main()函数一开始时就进行读出操作，即信息的初始化
{
    ifstream ifs;
    ifs.open("D:\\Codefield\\Code\\c++\\cpp_source\\Library_2\\User.txt", ios::in);
    User temp;
    while (ifs >> temp.ID && ifs >> temp.name && ifs >> temp.password && ifs >> temp.gender && ifs >> temp.is_Student)
    {
        u.push_back(temp);
    }
    cout << "读者初始化完毕..." << endl;
    ifs.close();
}

//*************************************信息存入.txt文件的操作***************************************//

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