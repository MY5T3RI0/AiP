#include <iostream>

using namespace std;

double getAkPlus(int k, int t)
{
    if (k == 0)
    {
        return t;
    }
    else
    {
        return getAkPlus(k - 1, t) * sqrt(t);
    }
}

double getAkMinus(int k, int t)
{
    if (k == 0)
    {
        return t;
    }
    else
    {
        return getAkMinus(k + 1, t) * sqrt(t);
    }
}

int main()
{
    int t, n, m;

    cout << "t = ";
    cin >> t;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;

    if (n > m || m >= 4)
    {
        cout << "Incorrect value of m or n";
        return 0;
    }

    if (t < 0)
    {
        cout << "Z(t) = " << t;
    }
    else if (t >= 0 && t < 10)
    {
        if (n > 0)
            cout << "Z(t) = " << getAkPlus(n, t);
        else
            cout << "Z(t) = " <<  getAkMinus(n, t);
    }
    else
    {
        if (m > 0)
            cout << "Z(t) = " << getAkPlus(m, t);
        else
            cout << "Z(t) = " << getAkMinus(m, t);
    }
}