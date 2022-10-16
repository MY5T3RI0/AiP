#include <iostream>

using namespace std;
int main()
{
    int M, D, T, number = 0;

    cout << "Number of year: ";
    cin >> T;
    cout << "Number of month: ";
    cin >> M;
    cout << "Number of day: ";
    cin >> D;

    int months[12];

    for (int i = 0; i < 7; i++)
    {
        if (i == 1)
        {
            if(T % 4 == 0)
                months[i] = 29;
            else
                months[i] = 28;
        }
        else if (i % 2 == 0)
        {
            months[i] = 31;
        }
        else
        {
            months[i] = 30;
        }
    }

    for (int i = 7; i < 12; i++)
    {
        if (i % 2 == 0)
        {
            months[i] = 30;
        }
        else
        {
            months[i] = 31;
        }
    }

    for (int i = 0; i < M-1; i++)
    {
        number += months[i];
    }

    cout << "Number of day in year: " << number + D;
}