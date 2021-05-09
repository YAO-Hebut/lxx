#include <iostream>
#include <fstream>
using namespace std;

int user_count = 0;                             //记录用户的个数
int resources_count = 0;                        //记录资源的个数
string Teacher_special_password = "190665";     //教师的通行码
string Librarian_special_password = "20010626"; //图书管理员Librarian的特殊密码
// User user[];
struct shujuku_User //用此结构体将User的成员数据封装到一起，便于登录和删除等工作
{
    string name;
    string gender;
    string ID;
    string password;
} sql[10000];

struct shujuku_Resources //用此结构体将Resources的成员数据封装到一起，便于登录和删除等工作
{
    string name;
    string writer;
    string ID;
    int quantity;
    int remindance;
    string data;
} res[10000];

//****************************************用户类***************************************************//

//********************User类********************//
class User //User为用户类，包括Reader和Librarian
{
private:
    string name;
    string gender;
    string ID;
    string password;
    bool is_Student = 1; //默认为学生

public:
    void set_name(string);     //设置name
    void set_gender(string);   //设置gender
    void set_ID(string);       //设置ID
    void set_password(string); //设置password
    void set_bool(bool);       //设置is_Student
    string get_name();         //获取name
    string get_gender();       //获取gender
    string get_ID();           //获取ID
    string get_password();     //获取password
    bool get_bool();           //获取is_Student
    void login();              //用户注册
    void dlt();                //用户删除
    void address();            //用户登录

    int find_Resources(string); //User查找功能
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
bool User::get_bool() { return is_Student; }

void User::login()
{
    // ofstream fout("D:\Codefield\Code\c++\cpp_source\Experiment_Library\Reader.txt");
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
    if (sql[user_count].ID == id)
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

int User::find_Resources(string find)
{
    for (int i = 0; i < resources_count; i++)
    {
        if ((res[i].name == find) || (res[i].ID == find) || (res[i].writer == find))
        {
            return i; //返回查找到的该书籍在线性表中的存贮位置i
        }
    }
    cout << "未找到该书籍" << endl;
    return 0;
}
//********************User类********************//

//********************Student类(继承User类)********************//
class Student : public User
{
private:
    struct priority //新增了特权priority这一数据成员
    {
        int lend_days = 30;
        int lend_books = 5;
    };

public:
};
//********************Student类(继承User类)********************//

//********************Teacher类(继承User类)********************//
class Teacher : public User
{
private:
    struct priority //新增了特权priority这一数据成员
    {
        int lend_days = 90;
        int lend_books = 15;
    };
};
//********************Teacher类(继承User类)********************//

//********************Librarian类(继承User类)********************//
class Librarian : public User
{
private:
public:
    void add_resources();    //图书管理员对Resources进行“增”的操作
    void delete_resources(); //图书管理员对Resources进行“删”的操作
    void change_resources(); //图书管理员对Resources进行“改”的操作
};
void Librarian::add_resources()
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
    cout << "请输入您想要添加的书籍的数量：";
    cin >> qua;
    res[resources_count].name = n;
    res[resources_count].ID = id;
    res[resources_count].writer = w;
    res[resources_count].quantity = qua;
    res[resources_count].remindance = qua;
    resources_count++;
    cout << "书籍添加成功！" << endl;
}

void Librarian::delete_resources()
{
    int i;
    cout << "请输入您想要删除书籍的信息:" << endl;
    string find;
    for (i = 0; i < resources_count; i++)
    {
        if ((res[i].name == find) || (res[i].ID == find) || (res[i].writer == find))
        {
            break; //返回查找到的该书籍在线性表中的存贮位置i
        }
    }
    if (i < resources_count)
    {
        for (int j = i; j < user_count - 1; j++)
        {
            res[j] = res[j + 1]; //与删除用户的方法相同，但都存在算法不够优秀的问题
        }
        cout << "删除成功！" << endl;
        return; //此模块执行完毕，退出此模块
    }
    else
    {
        cout << "未找到该书籍" << endl;
        return;
    }
}

void Librarian::change_resources()
{
    int i;
    cout << "请输入您想要修改书籍的信息:" << endl;
    string find;
    for (i = 0; i < resources_count; i++)
    {
        if ((res[i].name == find) || (res[i].ID == find) || (res[i].writer == find))
        {
            break; //返回查找到的该书籍在线性表中的存贮位置i
        }
    }
    if (i < resources_count)
    {
        cout << "请输入您想要修改的信息类型：" << endl;
        cout << "1.书名" << endl;
        cout << "2.作者" << endl;
        cout << "3.ID" << endl;
        cout << "4.书的数量" << endl;
        int x;
        cin >> x;
        if (x == 1)
        {
            cout << "请输入新的书名：";
            string n;
            cin >> n;
            res[i].name = n;
            cout << "修改成功！" << endl;
        }
        else if (x == 2)
        {
            cout << "请输入新的作者：";
            string w;
            cin >> w;
            res[i].writer = w;
            cout << "修改成功！" << endl;
        }
        else if (x == 3)
        {
            cout << "请输入新的ID：";
            string id;
            cin >> id;
            res[i].ID = id;
            cout << "修改成功！" << endl;
        }
        else if (x == 3)
        {
            cout << "请输入新的数量：";
            int qua;
            cout << "现有总数量：" << res[i].quantity << endl;
            cout << "现书架上剩余数量：" << res[i].remindance << endl;
            cin >> qua;
            if (qua > res[i].quantity)
            {
                res[i].remindance = qua - (res[i].quantity - res[i].remindance);
                res[i].quantity = qua;
                cout << "修改成功！" << endl;
                cout << "现有总数量：" << res[i].quantity << endl;
                cout << "现书架上剩余数量：" << res[i].remindance << endl;
                return;
            }
            else if (qua > 0 && qua < res[i].quantity && qua <= res[i].quantity - res[i].remindance)
            {
                res[i].remindance = 0;
                res[i].quantity = res[i].remindance;
                cout << "由于有借出但仍未归还的书籍，书籍总数为未归还的书籍数" << endl;
                cout << "现有总数量：" << res[i].quantity << endl;
                cout << "现书架上剩余数量：" << res[i].remindance << endl;
                return;
            }
            else if (qua > 0 && qua < res[i].quantity && qua > res[i].quantity - res[i].remindance)
            {
                res[i].remindance = qua - (res[i].quantity - res[i].remindance);
                res[i].quantity = qua;
                cout << "修改成功！" << endl;
                cout << "现有总数量：" << res[i].quantity << endl;
                cout << "现书架上剩余数量：" << res[i].remindance << endl;
                return;
            }
            else
            {
                cout << "输出错误！" << endl;
                return;
            }
        }
        return; //此模块执行完毕，退出此模块
    }
    else
    {
        cout << "未找到该书籍" << endl;
        return;
    }
}

//********************Librarian类(继承User类)********************//

//****************************************用户类***************************************************//

//****************************************资源类***************************************************//

//********************Resources类********************//
class Resources
{
private:
    string name;
    string writer;
    string ID;
    bool status = 1; //默认为未借出状态
    int quantity;
    int remindance;
    string data;

public:
    void set_name(string);
    void set_writer(string);
    void set_ID(string);
    void set_status(bool);
    void set_quantity(int);
    void set_remidance(int);
    void set_data(string);

    string get_name();
    string get_writer();
    string get_ID();
    bool get_status();
    int get_quantity();
    int get_remindance();
    string get_data();
};

void Resources::set_name(string n) { name = n; }
void Resources::set_writer(string w) { writer = w; }
void Resources::set_ID(string id) { ID = id; }
void Resources::set_status(bool b) { status = b; }
void Resources::set_quantity(int q) { quantity = q; }
void Resources::set_remidance(int r) { remindance = r; }
void Resources::set_data(string d) { data = d; }

string Resources::get_name() { return name; }
string Resources::get_writer() { return writer; }
string Resources::get_ID() { return ID; }
bool Resources::get_status() { return status; }
int Resources::get_quantity() { return quantity; }
int Resources::get_remindance() { return remindance; }
string Resources::get_data() { return data; }

//********************Resources类********************//

//********************Book类(继承Resources类)********************//

// class Book : public Resources
// {
// private:
//     string press; //新增了出版商press这一数据成员

// public:
//     void set_press(string);
//     string get_press();
// };

// void Book::set_press(string pre) { press = pre; }
// string Book::get_press() { return press; }

//********************Book类(继承Resources类)********************//

//********************Album类(继承Resources类)********************//
// class Album : public Resources
// {
// private:
//     int duration; //新增了时长duration这一数据成员

// public:
//     void set_duration(int);
//     int get_duration();
// };
// void Album::set_duration(int d) { duration = d; }
// int Album::get_duration() { return duration; }

//********************Album类(继承Resources类)********************//

//****************************************资源类***************************************************//

//****************************************主函数调试区**********************************************//
int main()
{
    int x; //控制决定一级界面(Reader or Librarian or Esc)
    cout << "**************************************************" << endl;
    cout << "************                          ************" << endl;
    cout << "********                                  ********" << endl;
    cout << "****       欢迎来到190665的图书管理系统       ****" << endl;
    cout << "********                                  ********" << endl;
    cout << "************                          ************" << endl;
    cout << "**************************************************" << endl;
    cout << "请选择您是读者还是图书管理员：" << endl;
    cout << "1.读者" << endl;
    cout << "2.管理员" << endl;
    cout << "3.退出" << endl;
    cin >> x;
    if (x == 1) //进入读者Reader的二级界面
    {
        int a;
        User user;
        string n, g, id, password;
        cout << "欢迎！亲爱的读者" << endl;
        cout << "请选择您要进行的操作：" << endl;
        cout << "1.注册" << endl;
        cout << "2.登录" << endl;
        cout << "3.删除" << endl;
        cin >> a;
        if (a == 1) //注册时进入的三级界面
        {
            string is_Teacher;
            cout << "您是否为教师？(Y/N)" << endl;
            cin >> is_Teacher;
            if (is_Teacher == "Y")
            {
                string code;
                cout << "请输入教师通行码：";
                cin >> code;
                if (code == Teacher_special_password)
                {
                    cout << "密码正确！" << endl;
                    cout << "欢迎老师！" << endl;
                    Teacher tcr;
                    tcr.login();
                    tcr.set_bool(0);
                }
                else
                {
                    cout << "密码错误！" << endl;
                    return 0;
                }
            }
            else if (is_Teacher == "N")
            {
                cout << "欢迎同学！" << endl;
                Student stu;
                stu.login();
            }
            else
            {
                cout << "输入错误！" << endl;
                return 0;
            }
        }
        else if (a == 2) //登陆时的三级界面
        {
            int i;
            string id, pass;
            cout << "请输入您的ID：";
            cin >> id;
            for (i = 0; i < user_count; i++)
            {
                if (sql[i].ID == id)
                    break;
            }
            if (i == user_count) //ID不存在于数据库中时
            {
                cout << "ID不存在！" << endl;
            }
            else
            {
                cout << "请输入您的密码：";
                cin >> pass;
                if (sql[i].password == pass) //密码正确成功登录时，进入Reader的借、还书的四级界面(老师和学生界面略有不同)
                {
                    cout << "登录成功！" << endl;
                    if (user.get_bool() == 0) //教师界面
                    {
                        cout << "欢迎老师" << endl;
                        cout << "剩余可借书数量：";
                    }
                }
                else //密码错误时
                {
                    cout << "密码错误！" << endl;
                }
            }
        }
    }
    if (x == 2) //进入管理员Librarian的二级界面
    {
    }
    if (x == 3) //ESC退出程序
    {
        return 0;
    }
    return 0;
}
//****************************************主函数调试区**********************************************//
