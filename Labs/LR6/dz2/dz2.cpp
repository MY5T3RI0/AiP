#include <iostream>

using namespace std;
int main()
{
	int M, x = 0, k = 0;
	cout << "x = "; cin >> x;
	cout << "M = "; cin >> M;

	if (M < 1000)
	{
		cout << "M must be > 1000";
		return 0;
	}

	if (x < M)
	{
		cout << "x must be > M";
		return 0;
	}

	float result = 1, temp = 0;
	while(k < x-M)
	{
		k = k + 1;
		temp = (x - (k + 1.)) / (x - k);
		result *= temp;

		cout << "\n k=" << k << " temp = " <<temp << " result = " << result << endl;
	}

	cout << endl << "result: " << result;
}