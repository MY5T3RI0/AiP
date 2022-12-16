#include <iostream>

using namespace std;

float* getSum(float x);
long double factorial(int i);
bool getN(float* array);
int getMaxN(float* array);

int main()
{
    float x;

    cout << "x = "; cin >> x;

    float * results;
    results = getSum(x);

    if (!getN(results)) {
        cout << "maxN = " << getMaxN(results) << endl;
    }
    
    system("pause");
    return 0;
}

float* getSum(float x) {
    float pi = acos(-1);
    float U;
    float S;
    int i;
    long double cosix, fact;
    float *result = new float[5];

    for (size_t N = 5; N <= 25; N +=5)
    {
        U = -1;
        S = 0;
        for (i = 1, S = 0; i <= N; i++)
        {
            U = -U;
            cosix = cos(i * x / 180 * pi);
            fact = factorial(i * 2);
            S += U * cosix / fact;
        }
        cout << "\n S(" << x << ',' << N << ")= " << S << endl;
        result[N / 5 - 1] = S;
    }

    cout << endl;

    return &result[0];

}

long double factorial(int i)
{
    if (i == 0) return 1;
    else return i * factorial(i - 1);

}

bool getN(float* array) {
    int maxN = 0;
    bool result = false;
    for (size_t i = 1; i < 5; i++)
    {
        if (abs(array[i] - array[i - 1]) > 0.1 * array[i - 1])
        {
            maxN = i + 1 * 5;
            result = true;
        }
    }
    if (maxN != 0)
        cout << "N = " << maxN << endl;

    return result;
}

int getMaxN(float* array) {

    int N[]{5, 10, 15, 20, 25};

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4 - i; j++)
        {
            if (array[j] > array[j+1])
            {
                swap(array[j], array[j + 1]);
                swap(N[j], N[j+1]);
            }
        }
    }

    return N[4];
}