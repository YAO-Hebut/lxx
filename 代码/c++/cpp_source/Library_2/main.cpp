#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Book.h"
#include "User.h"
#include "Administrator.h"

using namespace std;

int main()
{
    cout << "**************************************************" << endl;
    cout << "************                          ************" << endl;
    cout << "********                                  ********" << endl;
    cout << "****       欢迎来到190665的图书管理系统       ****" << endl;
    cout << "********                                  ********" << endl;
    cout << "************                          ************" << endl;
    cout << "**************************************************" << endl;
    vector<User> u;
    vector<book> b;
    fetchBook(b);
    fetchUser(u);
    Begin(b, u);
    return 0;
}