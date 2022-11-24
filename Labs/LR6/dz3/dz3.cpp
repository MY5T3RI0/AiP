#include <iostream>

using namespace std;
int main()
{

    long long count = 5345453567;
    int counter = 0;
    long double x = 3452;

    while (count > 0)
    {
        count -= x / 5;
        counter += 1;

        if (counter % 5 == 0)
        {
            x += x * 0.05;
        }
    }

    cout << counter / 60 << " hours\n";
    cout << counter % 60 << " minutes";
}