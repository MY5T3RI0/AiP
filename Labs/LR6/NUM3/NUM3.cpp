#include <iostream>
#include <ctime> 

using namespace std;
int main()
{
    float U, R[10], I;
    srand(time(NULL));
    U = rand() % 1000;
    I = rand() % 100;

    cout << "U = " << U << endl;
    cout << "I = " << I << endl;

    for (size_t i = 0; i < 10; i++)
    {
        R[i] = rand() % 10;
        cout << "R" << i+1 << " = " << R[i] << endl;
    }

    int i = 10;
    float R_sum;
    float maxR = 0;

    do
    {
        R_sum = 0;

        for (int j = 0; j < i; j++)
        {
            R_sum += R[j];
        }

        if (R[i] > maxR)
        {
            maxR = R[i];
        }

        i--;

    } while ( (U / R_sum) < I);

    cout << 10 - i - 2 << " Rs can remove\n";
    cout << "max removed R = " << maxR;
}