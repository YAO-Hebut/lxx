#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Book.h"
#include "User.h"
#include "Administrator.h"

using namespace std;


int main()
{
    vector<User> u;
    vector<book> b;
    fetchBook(b);
    fetchUser(u);
    Begin(b, u);
    return 0;
}