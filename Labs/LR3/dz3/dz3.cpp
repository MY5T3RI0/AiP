#include <iostream>

using namespace std;

void bubleSort(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (a[j] < a[j+1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    int n, m;

    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;

    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Value of " << i << " element a is ";
        cin >> a[i];
    }

    bubleSort(a, n);

    int* b = new int[m];
    for (int i = 0; i < m; i++) {
        cout << "Value of " << i << " element b is ";
        cin >> b[i];      
    }

    bubleSort(b, m);

    if (abs(b[m-1]) > 5)
        cout << "min( b1 ... bm) + max( a1 ... an) = " << b[m-1] + a[0];
    else cout << "1 + (max( b1 ... bm))^2 = " << 1 + pow(b[0], 2);
}
