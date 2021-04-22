#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class MobileHD
{
private:
    int Capacity;
    float Size, Interface;
    string Origin;

public:
    MobileHD();
    MobileHD(int, float, float, string);
    ~MobileHD();
    void showinfo();
};

MobileHD::MobileHD() : Capacity(1024), Size(2.5), Interface(3.0), Origin("中国")
{
    cout << "Create a New MobileHD!" << endl;
}

MobileHD::MobileHD(int cap, float s, float inter, string ori) : Capacity(cap), Size(s), Interface(inter), Origin(ori)
{
    cout << "Create a New MobileHD!" << endl;
}
MobileHD::~MobileHD()
{
    cout << "Destruct a MobileHD!" << endl;
}

void MobileHD::showinfo()
{
    cout << "Capacity: " << Capacity << "GB" << endl;
    cout << "Size: ";
    cout << setiosflags(ios::fixed) << setprecision(1) << Size;
    cout << "-inch" << endl;
    cout << "Interface: USB ";
    cout << setiosflags(ios::fixed) << setprecision(1) << Interface << endl;
    cout << "Origin: " << Origin << endl;
}

int main()
{
    MobileHD m1(120, 1.8, 2.0, "泰国/马来西亚");

    cout << "MobileHD m1 parameter is: " << endl;
    m1.showinfo(); //显示性能参数
    cout << endl;

    MobileHD m2;
    cout << "MobileHD m2 parameter is: " << endl;
    m2.showinfo(); //显示性能参数

    cout << endl;
    return 0;
}
