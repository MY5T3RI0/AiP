#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    int x;
    double b;
    double c;
    const double PI = acos(-1.0);

    cout << "Enter x\n";
    cin >> x; 
    cout << "Enter b\n";
    cin >> b; 
    cout << "Enter c\n";
    cin >> c;

    if (b > c)
    {
        cout << "b Должно быть больше c" << endl;
        return 0;
    }

    if (c == 0)
    {
        cout << "Знаменатель не должен быть = 0";
        return 0;
    }

    double xrad = x * PI / 180;

    const double arctgx = atan(xrad);

    const double cosxbc = cos(pow(xrad, b / c));
    if (cosxbc == 0)
    {
        cout << "Знаменатель не должен быть = 0";
        return 0;
    }

    if (b / c <= 0)
    {
        cout << "Под знаком логарифма должно стоять положительное число";
        return 0;
    }
    const double lnbc = log2(b / c);

    const double arctgxpi8 = arctgx - PI / 8;
    if (arctgxpi8 < 0)
    {
        cout << "Подкоренное выражение не должно быть отрицательно";
        return 0;
    }

    if (pow(arctgxpi8, 1 / 6) <= 0)
    {
        cout << "Под знаком логарифма должно стоять положительное число";
        return 0;
    }
    const double lns = log2(pow(arctgxpi8, 1. / 6.));

    if (lns == 0)
    {
        cout << "Знаменатель не должен быть = 0";
        return 0;
    }
    const double logr = lns / lnbc;

    cout << logr / cosxbc << endl;
}