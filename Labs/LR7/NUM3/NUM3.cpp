#include <iostream>

using namespace std;

void Hit(bool &win);
void Inside();
void Outside(int x, int y, int R2);
int GetD(int x, int y, int R2);

int main()
{
    int R1, R2, x, y;
    bool win = false;

    R1 = rand() % 100;

    R2 = rand() % 50 + R1;

    cout << "R1 = " << R1 << endl;
    cout << "R2 = " << R2 << endl;

    do
    {
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;

        if (pow(x, 2) + pow(y, 2) <= pow(R2, 2) && pow(x, 2) + pow(y, 2) > pow(R1, 2))
        {
            Hit(win);
        }
        else if (pow(x, 2) + pow(y, 2) <= pow(R2, 2))
        {
            Inside();
        }
        else
        {
            Outside(x, y, R2);
        }

        cout << "-------------\n";

    } while (!win);

}


void Hit(bool &win)
{
    cout << "hit\n";
    win = true;
}

void Inside()
{
    cout << "miss, inside the target\n";
}

int GetD(int x, int y, int R2)
{
    return sqrt(pow(x, 2) + pow(y, 2)) - R2;
}

void Outside(int x, int y, int R2)
{
    int d;
    d = GetD(x, y, R2);

    cout << "miss\n";
    cout << "d = " << d << endl;

    if (x < 0 && y < 0)
    {
        cout << "left|bottom\n";
    }
    else if (x < 0 && y > 0)
    {
        cout << "left|top\n";
    }
    else if (x > 0 && y > 0)
    {
        cout << "right|top\n";
    }
    else if (x > 0 && y < 0)
    {
        cout << "right|bottom\n";
    }
    else if (x > 0 && y == 0)
    {
        cout << "right\n";
    }
    else if (x < 0 && y == 0)
    {
        cout << "left\n";
    }
    else if (x == 0 && y < 0)
    {
        cout << "bottom\n";
    }
    else if (x == 0 && y >> 0)
    {
        cout << "top\n";
    }
}