#include <iostream>

using namespace std;
int main()
{
    int Z;
    int timeOfYear;

    cout << "Z = ";
    cin >> Z;

    cout << "Select time of year:" << endl;
    cout << "1 - winter" << endl;
    cout << "2 - spring" << endl;
    cout << "3 - summer" << endl;
    cout << "4 - autumn" << endl;

    cin >> timeOfYear;

    switch (timeOfYear)
    {
        case 1:
            cout << "You salary is " << Z * 0.2;
            break;

        case 2:
            cout << "You salary is " << Z * 1.1;
            break;

        case 3:
            cout << "You salary is " << Z * 1.2;
            break;

        case 4:
            cout << "You salary is " << Z;
            break;
    }
}