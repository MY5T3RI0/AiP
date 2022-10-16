#include <iostream>

using namespace std;
int main()
{
    double x, y, z;

    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    cout << "z = ";
    cin >> z;

    if (x + y + z > x * y * z)
        cout << "max(x + y + z, xyz) = " << x + y + z << endl;
    else
        cout << "max(x + y + z, xyz) = " << x * y * z << endl;

    if (x + y / 2 + z < x / y * z)
        cout << "min^2(x + y/2 + z, x/yz) + 1 = " << pow(x + y / 2 + z, 2) + 1 << endl;
    else
        cout << "min^2(x + y/2 + z, x/yz) + 1 = " << pow(x / y * z, 2) + 1 << endl;
}
