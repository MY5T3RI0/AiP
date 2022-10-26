#include <iostream>

using namespace std;
int main()
{
    unsigned short int X, Y, Z;

    cout << "X = "; cin >> X;
    cout << "Y = "; cin >> Y;
    cout << "Z = "; cin >> Z;

    if (X >= 64 || Y >= 128)
        cout << "Invalid data\n";

    Z &= 0xE000;

    Z |= X;

    Z |= (Y << 6);

    cout << "RESULT Z = " << Z;
}