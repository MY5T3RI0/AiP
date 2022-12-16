#include<iostream>
#include<cmath>
using namespace std;
float d(float x, float e);
int main()
{
	float x, eps, z;
	cout << "\nInput argument << 1:"; cin >> x;
	cout << "\nInput accuracy:"; cin >> eps;
	z = d(x, eps);
	cout << "\nFor x = " << x << " z(x) = " << z << endl;
	system("pause");
	return 0;
}
float d(float x, float e)
{
	float sum = 1., u = 2., cf = -1;
	for (int i = 1; abs(u) > e; i++)
	{
		u *= x * x;
		sum += cf * u;
		cf = -cf;
		cout << "\n i = " << i << endl;
	}
	return sum;
}