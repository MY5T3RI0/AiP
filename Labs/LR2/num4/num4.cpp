#include <iostream>

using namespace std;
int main()
{
    int a, b;
    string opr;

    cout << "First number: ";
    cin >> a;
    cout << "Operator: ";
    cin >> opr;
    cout << "Second number: ";
    cin >> b;

    if (opr == "+")
    {
        cout << a + b;
    }
    else if (opr == "-")
    {
        cout << a - b;
    }
    else if (opr == "*")
    {
        cout << a * b;
    }
    else if (opr == "/")
    {
        cout << a / b;
    }
}