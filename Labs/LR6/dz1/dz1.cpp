#include <iostream>

using namespace std;
int main()
{
	float eps;
	int a, x = 0, k = 0;
	cout << "x = "; cin >> x;
	cout << "a = "; cin >> a;
	cout << "eps = "; cin >> eps;

	float y = a, temp = 0;
	do
	{
		k = k + 1;
		temp = y;
		y = (y + x / y)/2;

		cout << "\n y" << k  << " = " << y << endl;
	} while (abs(pow(y, 2) - pow(temp, 2)) > eps);

	cout << endl << "result: " << y;
}