#include <iostream>
using namespace std;
//Объявление (прототипы) функций:
void tab(int b, int e, int s);
float res1(int x, int st);
float res2(int x, int st);
int main()
{
	int xn = -8, xk = 8, dx = 4;
	cout << "\n Construction table of selected function\n";
	tab(xn, xk, dx);
	system("pause");
	return 0;
}
void tab(int b, int e, int s)
{
	for (int i = b; i <= e; i += s)
	{
		float result;
		if (i < 0) result = res1(i, 2);
		else if (i > 0) result = res2(i, 3);
		else result = 0;
		cout << "\t" << i << "\t" << result << endl;
	}
	return;
}
float res1(int x, int st)
{
	return x / st;
}
float res2(int x, int st)
{
	return (float)x / st;
}