#include <iostream>

using namespace std;
int main()
{
    unsigned int a = 0, b = 0;

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;

    unsigned int a3x8 = a & 0xff0000;
    unsigned int a2x8 = a & 0xff00;

    unsigned int b2x8 = b & 0xff00;
    unsigned int b1x8 = b & 0xff;

    unsigned int resulta = a & 0xff00ffff & 0xffff00ff | b2x8 | b1x8 << 16;
    unsigned int resultb = b & 0xffff00ff & 0xffffff00 | a3x8 >> 16 | a2x8;

    cout << "result a = " << resulta;
    cout << endl;
    cout << "result b = " << resultb;
}