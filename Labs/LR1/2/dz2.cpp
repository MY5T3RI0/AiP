#include <iostream>
using namespace std;
int main()
{
    int V1, V2, T1, T2;

    cout << "Input V1\n";
    cin >> V1;
    cout << "Input V2\n";
    cin >> V2;
    cout << "Input T1\n";
    cin >> T1;
    cout << "Input T2\n";
    cin >> T2;

    cout << "Tc = " << (T1 * V1 + T2 * V2) / (V1 + V2) << endl;
    cout << "Volume = " << V1 + V2;
}
