#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    double a, b, c, d, s, t, u, z1, z2;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << "d = ";
    cin >> d;
    cout << "s = ";
    cin >> s;
    cout << "t = ";
    cin >> t;
    cout << "u = ";
    cin >> u;

    z1 = s * a + t * b + u;
    z2 = s * c + t * d + u;

    if (z1 * z2 < 0)
        cout << "Принадлежат разным полуплоскостям";
    else
        cout << "Принадлежат одной полуплоскости";
}