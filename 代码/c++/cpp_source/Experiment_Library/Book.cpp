#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Book.h>
#include <User.h>
using namespace std;
void Resources::set_name(string n) { name = n; }
void Resources::set_writer(string w) { writer = w; }
void Resources::set_ID(string id) { ID = id; }
void Resources::set_status(bool b) { status = b; }
// void Resources::set_quantity(int q) { quantity = q; }
// void Resources::set_remidance(int r) { remindance = r; }
void Resources::set_data(string d) { data = d; }

string Resources::get_name() { return name; }
string Resources::get_writer() { return writer; }
string Resources::get_ID() { return ID; }
bool Resources::get_status() { return status; }
// int Resources::get_quantity() { return quantity; }
// int Resources::get_remindance() { return remindance; }
string Resources::get_data() { return data; }

// //****************************************查找图书*************************************************//

// void Resources::find_name(vector<Resources> b, vector<Resources> c) //c存储所查找到的书籍(可能会有重复)
// {
//     cout << "请输入书名:" << endl;
//     string find;
//     cin >> find;
//     for (auto &i : b)
//     {
//         if (i.name == find)
//         {
//             c.push_back(i);
//         }
//     }
// }

// void Resources::find_writer(vector<Resources> b, vector<Resources> c) //c存储所查找到的书籍(可能会有重复)
// {
//     cout << "请输入作者:" << endl;
//     string find;
//     cin >> find;
//     for (auto &i : b)
//     {
//         if (i.writer == find)
//         {
//             c.push_back(i);
//         }
//     }
// }
// void Resources::find_id(vector<Resources> b, vector<Resources> c) //c存储所查找到的书籍(可能会有重复)
// {
//     cout << "请输入ID:" << endl;
//     string find;
//     cin >> find;
//     for (auto &i : b)
//     {
//         if (i.ID == find)
//         {
//             c.push_back(i);
//         }
//     }
// }

// Resources Resources::find_Resources(vector<Resources> b) //查找的封装
// {
//     showMenu_Chazhao();
//     int x;
//     cin >> x;
//     vector<Resources> c;
//     switch (x)
//     {
//     case 1:
//     {
//         find_name(b, c);
//         break;
//     }
//     case 2:
//     {
//         find_writer(b, c);
//         break;
//     }
//     case 3:
//     {
//         find_id(b, c);
//         break;
//     }
//     default:
//     {
//         cout << "输入错误！";
//         break;
//     }
//     }
//     if (c.empty()) //c为空时表示没有此书
//     {
//         cout << "查无此书！" << endl;
//     }
//     else if (c.size() == 1) //c=1时只查到一本书，无重复书籍
//     {
//         c[0].showBook();
//         return c[0];
//     }
//     else //查到多本书时，依次显示出来
//     {
//         int i;
//         for (i = 0; i < c.size(); i++)
//         {
//             cout << i + 1 << "、";
//             c[i].showBook();
//         }
//         cout << "请确定您要找的书籍序号:" << endl;
//         cin >> i;
//         c[i].showBook();
//         return c[i - 1];
//     }
// }

// //****************************************查找图书*************************************************//

// //****************************************添加图书*************************************************//

// void Resources::add_resources(vector<Resources> b)
// {
//     string n, w, id;
//     int qua;
//     // cout << "请输入您要增加的资源种类：" << endl;
//     // cout << "1.书籍" << endl;
//     // cout << "2.唱片" << endl;                      //由于做两种Resources类型太过复杂，先只做Book一种类型，以后有机会再补Album类的Resources(2021/5/9)

//     cout << "请输入您想要添加的书籍的名称：";
//     cin >> n;
//     cout << "请输入您想要添加的书籍的ID：";
//     cin >> id;
//     cout << "请输入您想要添加的书籍的作者：";
//     cin >> w;
//     // cout << "请输入您想要添加的书籍的数量：";
//     // cin >> qua;
//     Resources r;
//     r.name = n;
//     r.ID = id;
//     r.writer = w;
//     // r.quantity = qua;
//     b.push_back(r);
//     ofstream ofs;
//     ofs.open("Resources.txt", ios::out);
//     for (auto &i : b)
//     {
//         ofs << i.name << " " << i.ID << " " << i.writer << endl;
//     }
//     cout << "添加成功！" << endl;
//     ofs.close();
// }
// //****************************************添加图书*************************************************//

// //************************************修改图书(修改和删除)******************************************//

// void Resources::delete_resources(vector<Resources> b) //删除
// {
//     Resources c;
//     c = find_Resources(b);
//     int i;
//     for (i = 0; i < b.size(); i++)
//     {
//         if (b[i].ID == c.ID) //ID是唯一的，通过ID来确认唯一书籍
//             b.erase(b.begin() + i);
//     }
//     cout << "删除成功！" << endl;
// }

// void Resources::change_name(vector<Resources> b)
// {
//     cout << "请输入新的书名：" << endl;
//     string new_name;
//     cin >> new_name;
//     Resources c;
//     c = find_Resources(b);
//     int i;
//     for (i = 0; i < b.size(); i++)
//     {
//         if (b[i].ID == c.ID) //ID是唯一的，通过ID来确认唯一书籍
//             b[i].name = new_name;
//     }
//     cout << "修改成功！" << endl;
//     b[i].showBook();
// }

// void Resources::change_writer(vector<Resources> b)
// {
//     cout << "请输入新的作者名：" << endl;
//     string new_writer;
//     cin >> new_writer;
//     Resources c;
//     c = find_Resources(b);
//     int i;
//     for (i = 0; i < b.size(); i++)
//     {
//         if (b[i].ID == c.ID) //ID是唯一的，通过ID来确认唯一书籍
//             b[i].writer = new_writer;
//     }
//     cout << "修改成功！" << endl;
//     b[i].showBook();
// }
// void Resources::change_id(vector<Resources> b)
// {
//     int i, flag = 1;
//     cout << "请输入新的ID：" << endl;
//     string new_id;
//     cin >> new_id;
//     for (i = 0; i < b.size(); i++)
//     {
//         if (b[i].ID == new_id) //ID是唯一的，通过ID来确认唯一书籍
//         {
//             cout << "该ID已存在，修改失败" << endl;
//             flag = 0;
//         }
//     }
//     if (flag)
//     {
//         Resources c;
//         c = find_Resources(b);

//         for (i = 0; i < b.size(); i++)
//         {
//             if (b[i].ID == c.ID) //ID是唯一的，通过ID来确认唯一书籍
//                 b[i].ID = new_id;
//         }
//         cout << "修改成功！" << endl;
//         b[i].showBook();
//     }
// }

// // void Resources::change_quantity(vector<Resources> b)
// // {
// //     cout << "请输入现在书的数量：" << endl;
// //     int new_quantity;
// //     cin >> new_quantity;
// //     if (new_quantity < 0)
// //     {
// //         cout << "输入错误！" << endl;
// //     }
// //     else
// //     {
// //         Resources c;
// //         c = find_Resources(b);
// //         int i, lent;
// //         for (i = 0; i < b.size(); i++)
// //         {
// //             if (b[i].ID == c.ID) //ID是唯一的，通过ID来确认唯一书籍
// //             {
// //                 lent = b[i].quantity - b[i].remindance;
// //                 b[i].quantity = new_quantity;
// //             }
// //             if ((b[i].quantity - b[i].remindance) < 0)
// //             {
// //                 b[i].remindance = 0;
// //             }
// //             else
// //             {
// //                 b[i].remindance = b[i].quantity - lent;
// //             }
// //         }
// //         cout << "修改成功！" << endl;
// //         b[i].showBook();
// //     }
// // }

// void Resources::change_resources(vector<Resources> b) //修改和删除的封装
// {
//     showMenu_Xiugai();
//     int x;
//     cin >> x;
//     switch (x)
//     {
//     case 1:
//     {
//         delete_resources(b);
//         break;
//     }
//     case 2:
//     {
//         change_name(b);
//         break;
//     }
//     case 3:
//     {
//         change_writer(b);
//         break;
//     }
//     case 4:
//     {
//         change_id(b);
//         break;
//     }
//     default:
//     {
//         cout << "输入错误！";
//         break;
//     }
//     }
// }

// //************************************修改图书(修改和删除)******************************************//

// //***************************************借书******************************************************//
// void Resources::borrow(vector<Resources> b)
// {
//     Resources c;
//     c = find_Resources(b);
//     int i;
//     for (i = 0; i < b.size(); i++)
//     {
//         if (b[i].ID == c.ID)
//         {
//             b[i].showBook();
//             if (b[i].get_status())
//             {
//                 cout << "是否确定借阅此书？(Y/N)" << endl;
//                 string question;
//                 cin >> question;
//                 if (question == "Y")
//                 {
//                     b[i].set_status(0);
//                     cout << "借阅成功" << endl;
//                 }
//                 else
//                 {
//                     cout << "退出" << endl;
//                 }
//             }
//         }
//     }
// }

// //***************************************借书******************************************************//

// //***************************************还书******************************************************//
// void Resources::payback(vector<Resources> b)
// {
//     Resources c;
//     c = find_Resources(b);
//     int i;
//     for (i = 0; i < b.size(); i++)
//     {
//         if (b[i].ID == c.ID)
//         {
//             b[i].showBook();
//             if (!b[i].get_status())
//             {
//                 cout << "是否归还此书？(Y/N)" << endl;
//                 string question;
//                 cin >> question;
//                 if (question == "Y")
//                 {
//                     b[i].set_status(1);
//                     cout << "归还成功" << endl;
//                 }
//                 else
//                 {
//                     cout << "退出" << endl;
//                 }
//             }
//         }
//     }
// }

// //***************************************还书******************************************************//

// // 学生登陆界面(借、还、找封装起来)
// void Resources::User_student(vector<Resources> b)
// {
//     showStudent();
//     int x;
//     cin >> x;
//     switch (x)
//     {
//     case 1:
//         borrow(b);
//     case 2:
//         payback(b);
//     case 3:
//         find_Resources(b);
//     default:
//         cout << "退出" << endl;
//     }
// }

// // 管理员登陆界面(增、删、改、查封装起来)
// void Resources::User_administrator(vector<Resources> b)
// {
//     showAdministrator();
//     int x;
//     cin >> x;
//     switch (x)
//     {
//     case 1:
//         find_Resources(b);
//     case 2:
//         add_resources(b);
//     case 3:
//         delete_resources(b);
//     case 4:
//         change_resources(b);
//     default:
//         cout << "退出" << endl;
//     }
// }
