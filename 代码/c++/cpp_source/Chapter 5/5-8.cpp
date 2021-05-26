#include <iostream>
using namespace std;

template <typename T>
class Array
{
private:
    T a[100];
    int size = 0;

public:
    void set_Array(T b[]);
    void array();
    void sum();
};
template <typename T>
void Array<T>::set_Array(T b[])
{

    for (int i = 0;; i++)
    {
        if (b[i] == 0 || b[i] == '0')
            break;
        else
        {
            a[i] = b[i];
            size++;
        }
    }
}

template <typename T>
void Array<T>::array()
{
    T temp;
    for (int i = 0; i < size; i++) //冒泡排序
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    cout << "[";
    for (int i = 0; i < size; i++)
    {

        if (i != (size - 1))
            cout << a[i] << ",";
        else
            cout << a[i] << "]" << endl;
    }
}

template <typename T>
void Array<T>::sum()
{
    T sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += a[i];
    }
    cout << sum << endl;
}

int main()
{
    int x;
    cin >> x;
    for (int i = 0;; i++)
    {
        if (x == -1)
        {
            break;
        }
        else if (x == 1)
        {
            int b[100];
            for (int i = 0;; i++)
            {
                cin >> b[i];
                if (b[i] == 0)
                {
                    break;
                }
            }
            Array<int> z;
            z.set_Array(b);
            z.array();
            z.sum();
        }
        else if (x == 2)
        {
            double b[100];
            for (int i = 0;; i++)
            {
                cin >> b[i];
                if (b[i] == 0)
                {
                    break;
                }
            }
            Array<double> y;
            y.set_Array(b);
            y.array();
            y.sum();
        }
        else if (x == 3)
        {
            char b[100];
            for (int i = 0;; i++)
            {
                cin >> b[i];
                if (b[i] == '0')
                {
                    break;
                }
            }
            Array<char> t;
            t.set_Array(b);
            t.array();
        }
        else
        {
            break;
        }
        cin >> x;
    }

    return 0;
}
