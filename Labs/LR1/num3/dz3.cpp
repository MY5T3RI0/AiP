#include <iostream>

using namespace std;
int main()
{
	const int a1 = 150000000;
	const int T1 = 1;
	const double MPm1 = 1 + 3.02 * 10 * pow(10, -6);
	const double MPm2 = 1 + 9.55 * 10 * pow(10, -4);
	const double a2 = 5.2 * 149597870.7;

	cout << "a2 = " << a2 << " km\n";
	cout << "T2 = " << sqrt(pow(a2, 3)* pow(T1, 2) * MPm1 / MPm2 / pow(a1, 3)) << "\n";

	system("pause");
}
