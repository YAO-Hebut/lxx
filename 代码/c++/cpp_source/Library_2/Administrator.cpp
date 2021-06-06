#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdio>
#include <string>
#include "Book.h"
#include "User.h"
#include "Administrator.h"

using namespace std;

//时间显示
string getTime()
{
    time_t nowtime;
    //首先创建一个time_t 类型的变量nowtime
    struct tm *p;
    //然后创建一个新时间结构体指针 p
    time(&nowtime);
    //使用该函数就可得到当前系统时间，使用该函数需要将传入time_t类型变量nowtime的地址值。
    p = localtime(&nowtime);
    //由于此时变量nowtime中的系统时间值为日历时间，我们需要调用本地时间函数p=localtime（time_t* nowtime）将nowtime变量中的日历时间转化为本地时间，存入到指针为p的时间结构体中。不改的话，可以参照注意事项手动改。
    cout << "应还时间为：";
    printf("%04d/%02d/%02d\n", p->tm_year + 1900, p->tm_mon + 2, p->tm_mday);
    int year, mon, day;
    year = p->tm_year + 1900; //Unix默认时间戳为1900年
    mon = p->tm_mon + 1;      //默认为距离1月的月份数
    day = p->tm_mday;
    string time;
    time = std::to_string(year) + "/" + std::to_string(mon) + "/" + std::to_string(day);
    //控制格式输出

    return time;
}

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
        if (u[y].is_Student == 1) //学生界面
        {
            ArrangeBook_Stu(b, u, y);
        }
        else if (u[y].is_Student == 0) //管理员/教师界面
        {
            ArrangeBook_Adm(b, u, y);
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

void ArrangeBook_Adm(vector<book> &b, vector<User> &u, int y) //将对书的增删改查都封装到这里面
{
    string quanxian = "190665"; //管理员特权码
    show_Menu_Arrange_Adm();
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
        break;
    }
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
        BorrowBook(b, u, y);
        break;
    }
    case 6:
    {
        PaybackBook(b, u, y);
        break;
    }
    default:
    {
        cout << "退出..." << endl;
        break;
    }
    }
}

void ArrangeBook_Stu(vector<book> &b, vector<User> &u, int y) //将对书的增删改查都封装到这里面
{
    show_Menu_Arrange_Stu();
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
    {
        book find_book;
        find_book = FindBook(b);
        if (find_book.ID == "-1")
        {
            cout << "未找到此书籍..." << endl;
        }
        else
            find_book.show();
        break;
    }
    case 2:
    {
        BorrowBook(b, u, y);
        break;
    }
    case 3:
    {
        PaybackBook(b, u, y);
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
        newbook.data = "0/0/0";
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
                }
                else
                {
                    cout << "输入错误..." << endl;
                }
                saveinBook(b);
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
            c[0].show();
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
                    temp.ID = "-1";
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
    int i;
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
void FindID(vector<book> &b, vector<book> &c) //通过ID找书
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
                saveinBook(b);
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
                saveinBook(b);
                cout << "修改成功..." << endl;
                break;
            }
        }
    }
}
void ChangeID(vector<book> &b) //改书ID
{
    cout << "请输入新的ID：";
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
                saveinBook(b);
                cout << "修改成功..." << endl;
                break;
            }
        }
    }
}

//***********************************对书的改***********************************//

//

//

void BorrowBook(vector<book> &b, vector<User> &u, int y) //借助FindBook进行，改变标志位并记录下借书时间data即可
{
    if (u[y].book_num == 0)
    {
        cout << "您已超过借书上限，请先归还部分书籍..." << endl;
    }
    else
    {
        book borrow_book;
        borrow_book = FindBook(b);
        if (borrow_book.ID == "-1")
        {
            cout << "未找到此书..." << endl;
        }
        else
        {
            if (borrow_book.status == 0)
            {
                cout << "该书已被借出" << endl;
            }
            else
            {
                cout << "是否借出该书籍?(Y/N)" << endl;
                string YN;
                cin >> YN;
                if (YN == "Y")
                {
                    for (int i = 0; i < b.size(); i++)
                    {
                        if (borrow_book.ID == b[i].ID)
                        {
                            u[y].book_num--;
                            b[i].status = 0;
                            b[i].data = getTime();
                        }
                    }
                    saveinBook(b);
                    saveinUser(u);
                    cout << "借出完成!" << endl;
                }
            }
        }
    }
}

void PaybackBook(vector<book> &b, vector<User> &u, int y) //借助FindBook进行，改变标志位即可
{
    book pay_book;
    if (((u[y].book_num == 5) && (u[y].is_Student == 1)) || ((u[y].book_num == 10) && (u[y].is_Student == 0)))
    {
        cout << "您并未借阅书籍..." << endl;
    }
    else
    {
        pay_book = FindBook(b);
        if (pay_book.status == 1)
        {
            cout << "该书已被归还" << endl;
        }
        else
        {
            cout << "是否归还该书籍?(Y/N)" << endl;
            string YN;
            string payTime = getTime(); //归还时间
            cin >> YN;
            if (YN == "Y")
            {
                for (int i = 0; i < b.size(); i++)
                {
                    if (pay_book.ID == b[i].ID)
                    {

                        b[i].status = 1;
                        punish(payTime, pay_book.data);
                        b[i].data = "0/0/0";
                        u[y].book_num++;
                    }
                }
                saveinBook(b);
                saveinUser(u);
                cout << "归还完成!" << endl;
            }
        }
    }
}

void Login(vector<User> &u) //注册
{
    string id, name, password, gender;
    string key;
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
        cout << "您是否为管理员/教师？(Y/N)" << endl;
        cin >> key;
        if (key == "Y")
        {
            cout << "请输入权限码:";
            cin >> key;
            if (key == "190665")
            {
                cout << "权限码正确！" << endl;
                temp.ID = id;
                temp.name = name;
                temp.password = password;
                temp.gender = gender;
                temp.is_Student = 0;
                temp.book_num = 10;
                u.push_back(temp);
                saveinUser(u);
            }
            else
            {
                cout << "权限码错误!" << endl;
            }
        }
        else
        {
            temp.ID = id;
            temp.name = name;
            temp.password = password;
            temp.gender = gender;
            temp.book_num = 5;
            u.push_back(temp);
            saveinUser(u);
        }
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
            if (u[s].is_Student == 1)
            {
                cout << "欢迎同学 " << u[s].name << "  您还可以借 " << u[s].book_num << " 本书" << endl;
                return s;
            }
            else
            {
                cout << "欢迎老师 " << u[s].name << "  您还可以借 " << u[s].book_num << " 本书" << endl;
                return s;
            }
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
    ofs.open("D:\\Codefield\\Code\\c++\\cpp_source\\Library_2\\User.txt", ios::out);
    for (auto &i : u)
    {
        ofs << i.ID << " " << i.name << " " << i.password << " " << i.gender << " " << i.is_Student << " " << i.book_num << endl;
    }
    cout << "存入完毕..." << endl;
    ofs.close();
}
void fetchUser(vector<User> &u) //User信息读出，main()函数一开始时就进行读出操作，即信息的初始化
{
    ifstream ifs;
    ifs.open("D:\\Codefield\\Code\\c++\\cpp_source\\Library_2\\User.txt", ios::in);
    User temp;
    while (ifs >> temp.ID && ifs >> temp.name && ifs >> temp.password && ifs >> temp.gender && ifs >> temp.is_Student && ifs >> temp.book_num)
    {
        u.push_back(temp);
    }
    cout << "读者初始化完毕..." << endl;
    ifs.close();
}

void punish(string payback, string borrowtime) //还书逾期惩罚
{
    int pay_time;
    int borrow_time;
    pay_time = atoi(payback.c_str());
    borrow_time = atoi(borrowtime.c_str());
    int days;
    int punishment;
    days = pay_time - borrow_time;
    if (days > 30)
    {
        cout << "还书超过规定时间!" << endl;
        punishment = (days - 30) * 0.5;
        cout << "收取罚款: " << punishment << " 元(超过一天0.5元)" << endl;
    }
}

//*************************************信息存入.txt文件的操作***************************************//

void show_Menu_Arrange_Adm()
{
    cout << "*******************************" << endl;
    cout << "********* 1.添加书籍 **********" << endl;
    cout << "********* 2.查找书籍 **********" << endl;
    cout << "********* 3.更改书籍信息********" << endl;
    cout << "********* 4.删除书籍************" << endl;
    cout << "********* 5.借书***************" << endl;
    cout << "********* 6.还书***************" << endl;
    cout << "**********其他键退出***********" << endl;
    cout << "******************************" << endl;
}

void show_Menu_Arrange_Stu()
{
    cout << "*******************************" << endl;
    cout << "********* 1.查找书籍 **********" << endl;
    cout << "********* 2.借书***************" << endl;
    cout << "********* 3.还书***************" << endl;
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
    cout << "*******************************" << endl;
    cout << "********* 1.修改书名 **********" << endl;
    cout << "********* 2.修改作者 **********" << endl;
    cout << "********* 3.修改ID  ***********" << endl;
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