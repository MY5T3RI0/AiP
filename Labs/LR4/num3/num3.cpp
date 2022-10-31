#include <iostream>

using namespace std;
int main()
{
    int num = 0;

    while (true)
    {
        cout << "Input num\n";
        cin >> num;

        int result = num | (num + 1);

        cout << "Result = " << result << endl;
    }
}