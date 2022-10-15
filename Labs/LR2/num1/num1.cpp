#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int V, M;
    cout << "Enter M\n";
    cin >> M;
    cout << "Enter V\n";
    cin >> V;

    int result = V * 1024 * 1024 / M / 1;
    double result2 = V * 1024. * 1024. / M;

    if (result < result2)
    {
        result ++;
    }

    cout << "The number of clusters is " << result;

}