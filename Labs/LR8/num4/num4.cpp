#include <iostream>
using namespace std;
void P(int& a, char* b, float c);
int main()
{
    char symb = '5';
    int a = 1; char* b = &symb, *c = &symb; float d = 0.1, x = 0.2;

    /*P(a, b, c);
    P(3, b, x);*/
    P(a, b + 5, d - a);
    P(a, c, d - x / 2);

}

void P(int& a, char* b, float c) {
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << "------------------\n";
}