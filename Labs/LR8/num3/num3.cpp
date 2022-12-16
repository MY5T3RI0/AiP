#include <iostream>

using namespace std;

void getCoords(int& x, int& y);
bool isHit(int x, int y);

int main()
{
    int a1 = -5;
    int a2 = 5;
    int b1 = -7;
    int b2 = 7;
    int x, y;

    getCoords(x, y);

    cout << "0 - Shot\n";
    cout << "1 - Stop\n\n";

    int action;
    cin >> action;

    while (action != 1)
    {
        getCoords(x, y);

        if (isHit(x, y))
        {
            cout << "hit!\n";
            cout << "x = " << x << " y = " << y << endl;
            cout << "--------\n";
        }
        else
        {
            cout << "miss!\n";
            cout << "x = " << x << " y = " << y << endl;
            cout << "--------\n";
        }

        cout << "0 - Shot\n";
        cout << "1 - Stop\n\n";
        cin >> action;
    }
}

void getCoords(int& x, int& y) {
    x = rand() % 10 - 5;
    y = rand() % 15 - 7;
}

bool isHit(int x, int y) {
    if (sqrt(pow((float)x, 2) + pow(y, 2)) >= 3 && x <= 4 && y <= 3 && x >= -4 && y >= -3)
        return true;
    else
        return false;
}
