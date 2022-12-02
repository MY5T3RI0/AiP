﻿#include <iostream>
#include <random>

using namespace std;

double getAkPlus(int k, int t);

double getAkMinus(int k, int t);

double getZ(int t, int n, int m);

int main()
{
    int t, n, m;
    random_device random_device;
    std::mt19937 generator(random_device());
    uniform_int_distribution<> distribution(-9, 4);

    cout << "t = ";
    cin >> t;

    m = distribution(generator);
    cout << "m = " << m << endl;

    uniform_int_distribution<> distribution2(-9, m);

    n = distribution2(generator);
    cout << "n = " << n << endl;

    getZ(t, n ,m);
}

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

double getZ(int t, int n, int m) 
{
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
            cout << "Z(t) = " << getAkMinus(n, t);
    }
    else
    {
        if (m > 0)
            cout << "Z(t) = " << getAkPlus(m, t);
        else
            cout << "Z(t) = " << getAkMinus(m, t);
    }
}