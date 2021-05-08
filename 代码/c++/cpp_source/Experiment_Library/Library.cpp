#include <iostream>
#include <fstream>
using namespace std;

int user_count = 0;
User user[];
struct shujuku //用此结构体将User的成员数据封装到一起，便于登录和删除等工作
{
    string name;
    string gender;
    string ID;
    string password;
} sql[10000];

//****************************************用户类***************************************************//
class User //User为用户类，包括Reader和Librarian
{
private:
    string name;
    string gender;
    string ID;
    string password;
    bool is_Student = 1; //默认为学生

public:
    void set_name(string);
    void set_gender(string);
    void set_ID(string);
    void set_password(string);
    void set_bool(bool);
    string get_name();
    string get_gender();
    string get_ID();
    string get_password();
    void login();   //用户注册
    void dlt();     //用户删除
    void address(); //用户登录
};
void User::set_name(string n) { name == n; }
void User::set_gender(string g) { gender == g; }
void User::set_ID(string id) { ID == id; }
void User::set_password(string pass) { password == pass; }
void User::set_bool(bool s) { is_Student = s; }

string User::get_name() { return name; }
string User::get_gender() { return gender; }
string User::get_ID() { return ID; }
string User::get_password() { return password; }

void User::login()
{
    ofstream fout("D:\Codefield\Code\c++\cpp_source\Experiment_Library\Reader.txt");
    string n;
    string g;
    string id;
    string pass;
    cout << "请输入您的姓名:";
    cin >> n;
    cout << "请输入您的性别:";
    cin >> g;
    cout << "请输入您想要创建的的账号ID:";
    cin >> id;
    cout << "请输入您要创建的密码:";
    cin >> pass;
    if (user[user_count] == id)
    {
        cout << "该用户ID已存在" << endl; //通过判断ID是否存在来决定是否可以用此ID注册
        return;
    }
    else
    {
        sql[user_count].name = n;
        sql[user_count].gender = g;
        sql[user_count].ID = id;
        sql[user_count].password = pass;
        // user[user_count++](n, g, id, pass);
        // fout << n << " " << g << " " << id << " " << pass << endl; //将注册信息写入.txt(相当于简易数据库)文件中
        // fout.close();
        cout << "注册成功！" << endl;
    }
}

void User::dlt()
{
    string id, pass;
    cout << "请输入您要删除的ID:";
    cin >> id;
    cout << "请输入您的密码:";
    cin >> pass;
    for (int i = 0; i < user_count; i++)
    {
        if ((sql[i].ID == id) && (sql[i].password == pass)) //如果输入的ID存在且密码对应正确，则删除sql[i]，利用的是线性表的删除操作(此方法时间复杂度为O(n),效果不好，换成链表则为O(1)，待更正...)
        {
            for (int j = i; j < user_count - 1; j++)
            {
                sql[j] = sql[j + 1];
            }
            cout << "删除成功！" << endl;
            return; //此模块执行完毕，退出此模块
        }
        else if ((sql[i].ID == id) && (sql[i].password != pass))
        {
            cout << "密码错误！" << endl;
            return; //此模块执行完毕，退出此模块
        }
        else
        {
            cout << "ID不存在！" << endl;
            return;
        }
    }
}

void User::address()
{
    string id, pass;
    cout << "请输入您的ID:";
    cin >> id;
    cout << "请输入您的密码:";
    cin >> pass;
    for (int i = 0; i < user_count; i++)
    {
        if ((sql[i].ID == id) && (sql[i].password == pass))
        {
            cout << "登陆成功！" << endl;
            return;
        }
        else if ((sql[i].ID == id) && (sql[i].password != pass))
        {
            cout << "密码错误！" << endl;
            return;
        }
        else
        {
            cout << "ID不存在！" << endl;
            return;
        }
    }
}

class Student : public User
{
private:
    struct priority
    {
        int lend_days = 30;
        int lend_books = 5;
    };

public:
};

class Teacher : public User
{
private:
    struct priority
    {
        int lend_days = 90;
        int lend_books = 15;
    };
};
//****************************************用户类***************************************************//

//****************************************资源类***************************************************//
class Resources
{
private:
    string name;
    string writer;
    string ID;
    bool status;
    int quantity;
    int remindance;
    string data;

public:
    Resources(string, string, string, bool, int, int, string);
};

Resources::Resources(string n, string w, string id, bool sta, int qua, int rem, string d) : name(n), writer(w), ID(id), status(sta), quantity(qua), remindance(rem), data(d) {}

class Book : public Resources //书籍类
{
private:
    string press;

public:
    Book(string, string, string, bool, int, int, string, string);
};
Book::Book(string n, string w, string id, bool sta, int qua, int rem, string d, string p) : Resources(n, w, id, sta, qua, rem, d), press(p) {}

class Album : public Resources //唱片类
{
private:
    int duration;

public:
    Album(string, string, string, bool, int, int, string, int);
};

Album::Album(string n, string w, string id, bool sta, int qua, int rem, string d, int dur) : Resources(n, w, id, sta, qua, rem, d), duration(dur) {}

//****************************************资源类***************************************************//
