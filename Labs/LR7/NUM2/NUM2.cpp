#include <iostream>

using namespace std;

void ShiftRight3(float *A, float *B, float *C);

int main()
{
    float A, B, C;

    A = rand();
    B = rand();
    C = rand();

    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "C = " << C << endl;

    ShiftRight3(&A, &B, &C);

    cout << "-----------------\n";
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "C = " << C << endl;

}

void ShiftRight3(float *A, float *B, float *C)
{
    float temp = *A;

    *A = *B;
    *B = *C;
    *C = temp;
}