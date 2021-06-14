#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdio>
#include <iomanip>
#include <string>
#include "Book.h"
#include "User.h"
#include "Administrator.h"

using namespace std;

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
    int year, mon, day;
    year = p->tm_year + 1900; //Unix默认时间戳为1900年
    mon = p->tm_mon + 1;      //默认为距离1月的月份数
    day = p->tm_mday;
    string time;
    time = std::to_string(year) + "/" + std::to_string(mon) + "/" + std::to_string(day);
    //控制格式输出

    return time;
}

string getTime_payback(int x)
{
    time_t nowtime;
    //首先创建一个time_t 类型的变量nowtime
    struct tm *p;
    //然后创建一个新时间结构体指针 p
    time(&nowtime);
    //使用该函数就可得到当前系统时间，使用该函数需要将传入time_t类型变量nowtime的地址值。
    p = localtime(&nowtime);
    //由于此时变量nowtime中的系统时间值为日历时间，我们需要调用本地时间函数p=localtime（time_t* nowtime）将nowtime变量中的日历时间转化为本地时间，存入到指针为p的时间结构体中。不改的话，可以参照注意事项手动改。
    int year, mon, day;
    year = p->tm_year + 1900; //Unix默认时间戳为1900年
    if (x == 0)               //学生
    {
        mon = p->tm_mon + 2; //默认为距离1月的月份数
    }
    else if (x == 1) //老师
    {
        mon = p->tm_mon + 3;
    }
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
    std::cin >> x;
    switch (x)
    {
    case 1:
    {
        int y;
        y = Address(u);
        if (y == -1)
        {
            std::cout << "退出..." << endl;
            break;
        }
        else if (u[y].is_Student == 1) //学生界面
        {
            ArrangeBook_Stu(b, u, y);
            break;
        }
        else if (u[y].is_Student == 0) //管理员/教师界面
        {
            ArrangeBook_Adm(b, u, y);
            break;
        }
        else
        {
            std::cout << "退出..." << endl;
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
        std::cout << "退出..." << endl;
        break;
    }
    }
}

void ArrangeBook_Adm(vector<book> &b, vector<User> &u, int y) //将对书的增删改查都封装到这里面
{
    string quanxian = "190665"; //管理员特权码
    show_Menu_Arrange_Adm();
    int x;
    std::cin >> x;
    string key; //增改删需要用特权码
    switch (x)
    {
    case 1:
    {
        std::cout << "请输入您的权限码：";
        std::cin >> key;
        if (key == quanxian)
        {
            book newbook;
            string id, name, writer;
            int x = 0; //判断id是否已经存在
            std::cout << "请输入新资源的ID：";
            std::cin >> id;
            for (auto &i : b)
            {
                if (i.ID == id)
                    x = -1;
            }
            if (x == -1)
            {
                std::cout << "该ID已经存在" << endl;
            }
            else if (x == 0)
            {
                std::cout << "请输入新资源的名称：";
                std::cin >> name;
                std::cout << "请输入新资源的作者：";
                std::cin >> writer;
                newbook.ID = id;
                newbook.name = name;
                newbook.writer = writer;
                b.push_back(newbook);
                saveinBook(b);
            }
            std::cout << "添加完毕" << endl;
        }
        break;
    }
    case 2:
    {
        book find_book;
        find_book = FindBook(b);
        if (find_book.ID == "-1")
        {
            std::cout << "未找到此书籍..." << endl;
        }
        else
            std::cout << find_book;
        break;
    }
    case 3:
    {
        std::cout << "请输入您的权限码：";
        std::cin >> key;
        if (key == quanxian)
        {
            ChangeBook(b);
        }
        break;
    }
    case 4:
    {
        std::cout << "请输入您的权限码：";
        std::cin >> key;
        if (key == quanxian)
        {
            DeleteBook(b);
        }
        break;
    }
    case 5:
    {
        User user;
        user = FindUser(u);
        if (user.ID == "-1")
        {
            std::cout << "未找到该用户..." << endl;
        }
        else
        {
            std::cout << user;
        }
        break;
    }
    case 6:
    {
        std::cout << "   书名      作者        ID        在馆状态       借出日期     归还日期     借书人ID" << endl;
        for (auto &i : b)
        {
            std::cout << i;
        }
        break;
    }
    case 7:
    {
        std::cout << "   姓名      性别        ID        密码       身份      可借书数目" << endl;
        for (auto &i : u)
        {
            std::cout << i;
        }
        break;
    }
    case 8:
    {
        BorrowBook(b, u, y);
        break;
    }
    case 9:
    {
        PaybackBook(b, u, y);
        break;
    }
    case 10:
    {
        AllLog(b, u, y);
        break;
    }
    default:
    {
        std::cout << "退出..." << endl;
        break;
    }
    }
}

void ArrangeBook_Stu(vector<book> &b, vector<User> &u, int y) //将对书的增删改查都封装到这里面
{
    show_Menu_Arrange_Stu();
    int x;
    std::cin >> x;
    switch (x)
    {
    case 1:
    {
        book find_book;
        find_book = FindBook(b);
        if (find_book.ID == "-1")
        {
            std::cout << "未找到此书籍..." << endl;
        }
        else
            std::cout << find_book;
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
    case 4:
    {
        Log(b, u, y);
        break;
    }
    default:
    {
        std::cout << "退出..." << endl;
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
    std::cout << "请输入新资源的ID：";
    std::cin >> id;
    for (auto &i : b)
    {
        if (i.ID == id)
            x = -1;
    }
    if (x == -1)
    {
        std::cout << "该ID已经存在" << endl;
    }
    else if (x == 0)
    {
        std::cout << "请输入新资源的名称：";
        std::cin >> name;
        std::cout << "请输入新资源的作者：";
        std::cin >> writer;
        newbook.ID = id;
        newbook.name = name;
        newbook.writer = writer;
        newbook.data = "0/0/0";
        b.push_back(newbook);
    }
    std::cout << "添加完毕" << endl;
}
void AddName(vector<book> &b, book &c)
{
    std::cout << "请输入新资源的名称：";
    string new_name;
    std::cin >> new_name;
    c.name = new_name;
}
void AddWriter(vector<book> &b, book &c)
{
    std::cout << "请输入新资源的作者：";
    string new_writer;
    std::cin >> new_writer;
    c.writer = new_writer;
}
void AddID(vector<book> &b, book &c)
{
    std::cout << "请输入新资源的ID：";
    string new_id;
    std::cin >> new_id;
    c.ID = new_id;
}

//***********************************对书的增加***********************************//

//***********************************对书的删除***********************************//

void DeleteBook(vector<book> &b)
{
    book c;
    c = FindBook(b);
    std::cout << "请先选择您要删除的书籍" << endl;
    if (c.ID == "-1")
    {
        std::cout << "未找到书籍..." << endl;
    }
    else
    {
        int i;
        for (i = 0; i < b.size(); i++)
        {
            if (b[i].ID == c.ID)
            {
                std::cout << "是否删除该书？(Y/N)" << endl;
                std::cout << b[i];
                string YN;
                std::cin >> YN;
                if (YN == "Y")
                {
                    b.erase(b.begin() + i);
                    std::cout << "删除成功" << endl;
                }
                else if (YN == "N")
                {
                    std::cout << "退出..." << endl;
                }
                else
                {
                    std::cout << "输入错误..." << endl;
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
    std::cout << "请选择您要查找的方式：" << endl;
    show_Menu_Find();
    std::cin >> x;
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
            std::cout << c[0];
            return c[0];
        }
        else
        {
            for (int i = 0; i < c.size(); i++)
            {
                for (i = 0; i < c.size(); i++)
                {
                    std::cout << i + 1 << ".";
                    std::cout << c[i];
                }
                std::cout << "请选择您想要的书籍：";
                int y;
                std::cin >> y;
                if (y - 1 >= 0 && y - 1 < c.size())
                    return c[y - 1];
                else
                {
                    std::cout << "选择错误!" << endl;
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
    std::cout << "请输入你要查找的书名：";
    string find_name;
    std::cin >> find_name;
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
    std::cout << "请输入你要查找的作者名：";
    string find_writer;
    std::cin >> find_writer;
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
    std::cout << "请输入你要查找的ID：";
    string find_id;
    std::cin >> find_id;
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
    std::cin >> x;
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
        std::cout << "退出..." << endl;
        break;
    }
    }
}
void ChangeName(vector<book> &b) //改书名
{
    std::cout << "请输入新的书名：";
    string new_name;
    std::cin >> new_name;
    book c;
    c = FindBook(b);
    if (c.ID == "-1")
    {
        std::cout << "未找到书籍..." << endl;
    }
    else
    {
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i].ID == c.ID)
            {
                b[i].name = new_name;
                saveinBook(b);
                std::cout << "修改成功..." << endl;
                break;
            }
        }
    }
}
void ChangeWriter(vector<book> &b) //改作者
{
    std::cout << "请输入新的作者：";
    string new_writer;
    std::cin >> new_writer;
    book c;
    c = FindBook(b);
    if (c.ID == "-1")
    {
        std::cout << "未找到书籍..." << endl;
    }
    else
    {
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i].ID == c.ID)
            {
                b[i].writer = new_writer;
                saveinBook(b);
                std::cout << "修改成功..." << endl;
                break;
            }
        }
    }
}
void ChangeID(vector<book> &b) //改书ID
{
    std::cout << "请输入新的ID：";
    string new_id;
    std::cin >> new_id;
    book c;
    c = FindBook(b);
    if (c.ID == "-1")
    {
        std::cout << "未找到书籍..." << endl;
    }
    else
    {
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i].ID == c.ID)
            {
                b[i].ID = new_id;
                saveinBook(b);
                std::cout << "修改成功..." << endl;
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
    book borrow_book;
    try
    {
        if (u[y].book_num == 0)
            throw 0;
        else
            throw 1.0;
    }
    catch (int)
    {
        std::cout << "您已超过借书上限，请先归还部分书籍..." << endl;
    }
    catch (double)
    {

        borrow_book = FindBook(b);
        if (borrow_book.ID == "-1")
        {
            std::cout << "未找到此书..." << endl;
        }
        else
        {
            if (borrow_book.status == 0)
            {
                std::cout << "该书已被借出" << endl;
            }
            else
            {
                std::cout << "是否借出该书籍?(Y/N)" << endl;
                string YN;
                std::cin >> YN;
                if (YN == "Y")
                {
                    for (int i = 0; i < b.size(); i++)
                    {
                        if (borrow_book.ID == b[i].ID)
                        {
                            u[y].book_num--;
                            b[i].status = 0;
                            b[i].data = getTime();
                            b[i].borrow_ID = u[y].ID;
                            b[i].data_back = getTime_payback(u[y].is_Student);
                        }
                    }
                    saveinBook(b);
                    saveinUser(u);
                    std::cout << "借出完成!" << endl;
                }
            }
        }
    }
}

void PaybackBook(vector<book> &b, vector<User> &u, int y) //借助FindBook进行，改变标志位即可
{
    vector<book> pay_book;
    int j = 0;
    for (auto &i : b)
    {
        if (i.borrow_ID == u[y].ID)
        {
            pay_book.push_back(i);
            j++;
        }
    }
    if (j == 0)
    {
        std::cout << "您未借阅任何书籍..." << endl;
    }
    else
    {
        std::cout << "   书名     作者       ID       在馆状态      借出日期    归还日期    借书人ID" << endl;
        for (int i = 0; i < j; i++)
        {
            std::cout << i + 1 << "." << pay_book[i];
        }
        std::cout << "请选择您想要的书籍：";
        int x, z;
        std::cin >> z;
        if (z - 1 >= 0 && z - 1 < pay_book.size())
        {
            x = z - 1;
            std::cout << "是否归还该书籍?(Y/N)" << endl;
            string YN;
            string payTime = getTime(); //归还时间
            std::cin >> YN;
            if (YN == "Y")
            {
                for (int i = 0; i < b.size(); i++)
                {
                    if (pay_book[x].ID == b[i].ID)
                    {

                        b[i].status = 1;
                        punish(payTime, pay_book[i].data);
                        b[i].data = getTime();
                        b[i].data_back = getTime();
                        b[i].borrow_ID = "none";
                        u[y].book_num++;
                    }
                }
                saveinBook(b);
                saveinUser(u);
                std::cout << "归还完成!" << endl;
            }
            else
            {
                std::cout << "选择错误!" << endl;
            }
        }
    }
    // if (((u[y].book_num == 5) && (u[y].is_Student == 1)) || ((u[y].book_num == 10) && (u[y].is_Student == 0)))
    // {
    //     std::cout << "您并未借阅书籍..." << endl;
    // }
    // else
    // {
    //     pay_book = FindBook(b);
    //     if (pay_book.status == 1)
    //     {
    //         std::cout << "该书已被归还" << endl;
    //     }
    //     else
    //     {
    //         std::cout << "是否归还该书籍?(Y/N)" << endl;
    //         string YN;
    //         string payTime = getTime(); //归还时间
    //         std::cin >> YN;
    //         if (YN == "Y")
    //         {
    //             for (int i = 0; i < b.size(); i++)
    //             {
    //                 if (pay_book.ID == b[i].ID)
    //                 {

    //                     b[i].status = 1;
    //                     punish(payTime, pay_book.data);
    //                     b[i].data = "0/0/0";
    //                     u[y].book_num++;
    //                 }
    //             }
    //             saveinBook(b);
    //             saveinUser(u);
    //             std::cout << "归还完成!" << endl;
    //         }
    //     }
    // }
}

void Log(vector<book> &b, vector<User> &u, int y)
{
    vector<book> pay_book;
    int j = 0;
    for (auto &i : b)
    {
        if (i.borrow_ID == u[y].ID)
        {
            pay_book.push_back(i);
            j++;
        }
    }
    if (j == 0)
    {
        std::cout << "您未借阅任何书籍..." << endl;
    }
    else
    {
        std::cout << "   书名      作者        ID        在馆状态       借出日期     归还日期     借书人ID" << endl;
        for (int i = 0; i < j; i++)
        {
            std::cout << i + 1 << "." << pay_book[i];
        }
    }
}

void AllLog(vector<book> &b, vector<User> &u, int y)
{
    int j = 0;
    vector<book> borrow_book;
    for (auto &i : b)
    {
        if (i.status == 0)
        {
            borrow_book.push_back(i);
            j++;
        }
    }
    if (j == 0)
    {
        std::cout << "没有借出书籍..." << endl;
    }
    else
    {
        std::cout << "   书名      作者        ID        在馆状态       借出日期     归还日期     借书人ID" << endl;
        for (int i = 0; i < j; i++)
        {
            std::cout << i + 1 << "." << borrow_book[i];
        }
    }
}

void Login(vector<User> &u) //注册
{
    string id, name, password, gender;
    string key;
    User temp_u;
    Adm temp_adm;
    std::cout << "请输入您要注册的ID";
    std::cin >> id;
    int x = 0; //判断id是否已经存在
    for (auto &i : u)
    {
        if (i.ID == id)
            x = -1;
    }
    if (x == -1)
    {
        std::cout << "该ID已经存在" << endl;
    }
    else if (x == 0)
    {
        std::cout << "请输入您的姓名";
        std::cin >> name;
        std::cout << "请输入您的密码";
        std::cin >> password;
        std::cout << "请输入您的性别";
        std::cin >> gender;
        std::cout << "您是否为管理员/教师？(Y/N)" << endl;
        std::cin >> key;
        if (key == "Y")
        {
            std::cout << "请输入权限码:";
            std::cin >> key;
            if (key == "190665")
            {
                std::cout << "权限码正确！" << endl;
                temp_adm.ID = id;
                temp_adm.name = name;
                temp_adm.password = password;
                temp_adm.gender = gender;
                temp_adm.is_Student = 0;
                temp_adm.book_num = 10;
                u.push_back(temp_adm);
                saveinUser(u);
            }
            else
            {
                std::cout << "权限码错误!" << endl;
            }
        }
        else
        {
            temp_u.ID = id;
            temp_u.name = name;
            temp_u.password = password;
            temp_u.gender = gender;
            temp_u.book_num = 5;
            u.push_back(temp_u);
            saveinUser(u);
        }
    }
}

int Address(vector<User> &u) //登录
{
    string id, password;
    int s = 0;
    std::cout << "请输入您的ID" << endl;
    std::cin >> id;
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
        std::cout << "请输入您的密码：";
        std::cin >> password;
        if (u[s].password == password)
        {
            std::cout << "登录成功..." << endl;
            if (u[s].is_Student == 1)
            {
                std::cout << "欢迎同学 " << u[s].name << "  您还可以借 " << u[s].book_num << " 本书" << endl;
                return s;
            }
            else
            {
                std::cout << "欢迎老师 " << u[s].name << "  您还可以借 " << u[s].book_num << " 本书" << endl;
                return s;
            }
        }
        else
        {
            std::cout << "密码错误..." << endl;
            return -1;
        }
    }
    else
    {
        std::cout << "该ID不存在..." << endl;
        return -1;
    }
}

//*************************************信息存入.txt文件的操作***************************************//
void saveinBook(vector<book> &b) //Book信息存入
{
    ofstream ofs;
    ofs.open("D:\\Codefield\\Code\\c++\\cpp_source\\Library_2\\Book.txt", ios::out);
    for (auto &i : b)
    {
        ofs << i.name << " " << i.writer << " " << i.ID << " " << i.status << " " << i.data << " " << i.data_back << " " << i.borrow_ID << endl;
    }
    std::cout << "存入完毕..." << endl;
    ofs.close();
}
void fetchBook(vector<book> &b) //Book信息读出，main()函数一开始时就进行读出操作，即信息的初始化
{
    ifstream ifs;
    ifs.open("D:\\Codefield\\Code\\c++\\cpp_source\\Library_2\\Book.txt", ios::in);
    book temp;
    while (ifs >> temp.name && ifs >> temp.writer && ifs >> temp.ID && ifs >> temp.status && ifs >> temp.data && ifs >> temp.data_back && ifs >> temp.borrow_ID)
    {
        b.push_back(temp);
    }
    std::cout << "书籍初始化完毕..." << endl;
    ifs.close();
}

void saveinUser(vector<User> &u) //User信息存入
{
    ofstream ofs;
    ofs.open("D:\\Codefield\\Code\\c++\\cpp_source\\Library_2\\User.txt", ios::out);
    for (auto &i : u)
    {
        ofs << i.ID << " " << i.name << " " << i.password << " " << i.gender << " " << i.is_Student << " " << i.book_num << " " << i.book_days << endl;
    }
    std::cout << "存入完毕..." << endl;
    ofs.close();
}
void fetchUser(vector<User> &u) //User信息读出，main()函数一开始时就进行读出操作，即信息的初始化
{
    ifstream ifs;
    ifs.open("D:\\Codefield\\Code\\c++\\cpp_source\\Library_2\\User.txt", ios::in);
    User temp;
    while (ifs >> temp.ID && ifs >> temp.name && ifs >> temp.password && ifs >> temp.gender && ifs >> temp.is_Student && ifs >> temp.book_num && ifs >> temp.book_days)
    {
        u.push_back(temp);
    }
    std::cout << "读者初始化完毕..." << endl;
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
        std::cout << "还书超过规定时间!" << endl;
        punishment = (days - 30) * 0.5;
        std::cout << "收取罚款: " << punishment << " 元(超过一天0.5元)" << endl;
    }
}

User FindUser(vector<User> &u)
{
    {
        User temp;
        vector<User> user;
        temp.ID = "0";
        int x;
        std::cout << "请选择您要查找的方式：" << endl;
        show_Menu_Find_User();
        std::cin >> x;
        switch (x)
        {
        case 1:
        {
            FindName(u, user);
            break;
        }
        case 2:
        {
            FindID(u, user);
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
            if (user.empty())
            {
                temp.ID = "-1";
            }
            else if (user.size() == 1)
            {
                std::cout << user[0];
                return user[0];
            }
            else
            {
                for (int i = 0; i < user.size(); i++)
                {
                    for (i = 0; i < user.size(); i++)
                    {
                        std::cout << i + 1 << ".";
                        std::cout << user[i];
                    }
                    std::cout << "请选择您想要查找的用户：";
                    int y;
                    std::cin >> y;
                    if (y - 1 >= 0 && y - 1 < user.size())
                        return user[y - 1];
                    else
                    {
                        std::cout << "选择错误!" << endl;
                        temp.ID = "-1";
                        break;
                    }
                }
            }
        }
        return temp;
    }
}
void FindName(vector<User> &u, vector<User> &c)
{
    std::cout << "请输入你要查找的用户姓名：";
    string find_name;
    std::cin >> find_name;
    int i;
    for (auto &i : u)
    {
        if (i.name == find_name)
        {
            c.push_back(i);
        }
    }
}
void FindID(vector<User> &u, vector<User> &c)
{
    std::cout << "请输入你要查找用户ID：";
    string find_ID;
    std::cin >> find_ID;
    int i;
    for (auto &i : u)
    {
        if (i.ID == find_ID)
        {
            c.push_back(i);
        }
    }
}

//*************************************信息存入.txt文件的操作***************************************//

void show_Menu_Arrange_Adm()
{
    std::cout << "*******************************" << endl;
    std::cout << "********* 1.添加资源 **********" << endl;
    std::cout << "********* 2.查找资源 **********" << endl;
    std::cout << "********* 3.更改资源信息********" << endl;
    std::cout << "********* 4.删除资源************" << endl;
    std::cout << "********* 5.查找用户************" << endl;
    std::cout << "********* 6.显示全部资源********" << endl;
    std::cout << "********* 7.显示全部用户********" << endl;
    std::cout << "********* 8.借书***************" << endl;
    std::cout << "********* 9.还书***************" << endl;
    std::cout << "********* 10.查看全部借出书籍***" << endl;
    std::cout << "**********其他键退出***********" << endl;
    std::cout << "******************************" << endl;
}

void show_Menu_Arrange_Stu()
{
    std::cout << "*******************************" << endl;
    std::cout << "********* 1.查找资源 **********" << endl;
    std::cout << "********* 2.借书***************" << endl;
    std::cout << "********* 3.还书***************" << endl;
    std::cout << "********* 4.还书日志***********" << endl;
    std::cout << "**********其他键退出***********" << endl;
    std::cout << "******************************" << endl;
}

void show_Menu_Find()
{
    std::cout << "******************************" << endl;
    std::cout << "********* 1.按资源名查找 ******" << endl;
    std::cout << "********* 2.按作者查找 ********" << endl;
    std::cout << "********* 3.按ID查找   ********" << endl;
    std::cout << "**********其他键退出***********" << endl;
    std::cout << "******************************" << endl;
}

void show_Menu_Change()
{
    std::cout << "*******************************" << endl;
    std::cout << "********* 1.修改书名 **********" << endl;
    std::cout << "********* 2.修改作者 **********" << endl;
    std::cout << "********* 3.修改ID  ***********" << endl;
    std::cout << "**********其他键退出***********" << endl;
    std::cout << "******************************" << endl;
}

void show_Menu_Begin()
{
    std::cout << "*************************" << endl;
    std::cout << "********* 1.登录 ********" << endl;
    std::cout << "********* 2.注册 ********" << endl;
    std::cout << "********其他键退出********" << endl;
    std::cout << "*************************" << endl;
}

void show_Menu_Find_User()
{
    std::cout << "******************************" << endl;
    std::cout << "********* 1.按用户姓名查找 ****" << endl;
    std::cout << "********* 2.按用户ID查找 ******" << endl;
    std::cout << "**********其他键退出***********" << endl;
    std::cout << "******************************" << endl;
}