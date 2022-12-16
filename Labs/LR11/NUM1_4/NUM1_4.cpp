#include <iostream>

using namespace std;

string BracketsCheck(char *str, int length) {
    int balance = 0;
    int n = sizeof(str);
    for (size_t i = 0; i < length; i++)
    {
        if (str[i] == '(')
            balance++;
        else if (str[i] == ')')
            balance--;

        if (balance < 0)
            return "Incorrect";
    }

    if (balance != 0)
        return "Incorrect";
    else
        return "Correct";
}

int main()
{

    char str[256];

    cout << "string = ";
    cin.getline(str, 256);

    cout << "Brackets are " << BracketsCheck(str, sizeof(str)/sizeof(int));
}