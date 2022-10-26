#include <iostream>

using namespace std;
int main()
{
    unsigned int X, Y, Z;

    cout << "Z = "; cin >> Z;

    unsigned int resultX = Z & 0x1f;

    unsigned int resultY = (Z & 0x7e0) >> 5;

    cout << "result X = " << resultX << endl;
    cout << "result Y = " << resultY;
}