#include <iostream>
#include <string>
using namespace std;

void getSymbolsCount(string str, char symbol);

int main()
{
    string str;
    char symbol;

    cout << "symbol: "; cin >> symbol;
    cout << "Input string: ";
    cin.ignore();
    getline(cin, str);

    getSymbolsCount(str, symbol);
}

void getSymbolsCount(string str, char symbol) {

    int count = 0;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == symbol)
            count++;
    }

    cout << "\nFrequency = " << (float)count / str.length() << endl;

}