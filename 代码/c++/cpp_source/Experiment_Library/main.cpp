#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Book.h"
#include "User.h"
#include "Administrator.h"
using namespace std;

void showMenu_Welcome();
// void fetch_User(vector<User> u);
// void fetch_Resources(vector<Resources> b);
// void begin(vector<User> u, vector<Resources> b);

int main()
{
    showMenu_Welcome();
    vector<User> user;
    vector<Resources> resources;
    fetch_Resources(resources);
    fetch_User(user);
    begin(user, resources);
    return 0;
}

void showMenu_Welcome()
{
    cout << "**************************************************" << endl;
    cout << "************                          ************" << endl;
    cout << "********                                  ********" << endl;
    cout << "****       欢迎来到190665的图书管理系统       ****" << endl;
    cout << "********                                  ********" << endl;
    cout << "************                          ************" << endl;
    cout << "**************************************************" << endl;
}
