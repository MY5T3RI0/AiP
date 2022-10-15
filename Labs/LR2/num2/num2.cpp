#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    double a = 4;
    double b = 7;
    double c = 2;
    double d = 11;
    double x;
    const double e = 2.718281828182818281828;

    cout << "Enter x\n";

    cin >> x;

    const double arctg3_x = pow(atan(x), 3);
    const double e_2x = pow(e, 2 * x);
    const double e__mx = pow(e, -sqrt(x));
    const double ctgx3 = 1 / tan(pow(x,3));

    cout << "y = " << arctg3_x - 0.75*pow(10,-15) + e_2x - e__mx + ctgx3;
}