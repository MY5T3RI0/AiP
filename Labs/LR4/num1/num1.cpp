#include <iostream>

using namespace std;
int main()
{
    int num = 0;

    while (true)
    {
        cout << "Input num\n";
        cin >> num;

        for (; (num & 0xf) != 0; num <<= 1);

        cout << "Answer = " << num << endl << endl;
    }
}