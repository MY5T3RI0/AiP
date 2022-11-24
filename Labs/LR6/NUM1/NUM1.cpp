#include <iostream>
#include <string> 
#include <sstream>

using namespace std;

void reverseNum(int num);

template <typename T>
string toString(T val);

int main()
{
    int num;

    cout << "num = "; cin >> num;

    reverseNum(num);
}

void reverseNum(int num)
{
    int temp = num;
    int j = 1;

    string str = toString(num);

    cout << "reverse num = ";

    for (size_t i = 1; i < str.length() + 1; i++)
    {
        cout << str[str.length() - i];
    }
}

template <typename T>
string toString(T val)
{
    ostringstream oss;
    oss << val;
    return oss.str();
}