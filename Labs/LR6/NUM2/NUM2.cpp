#include<iostream>
#include<cmath>
#include <ctime> 

using namespace std;
int main()
{
	float x;
	int k;
	srand(time(NULL));

	for (size_t i = 0; i < 4; i++)
	{
		k = 0;
		x = 0.01 * (rand() % 100);

		cout << "x = " << x << endl;
		float Q, R = pow(x, 3) / 3, s = 0, eps = 0.0000001;
		do
		{
			k = k + 1;
			s += R;
			Q = pow(x, 2) * (2 * k + 1) / (2 * (k + 1) + 1);
			R *= Q;
		} while (abs(R) > eps);

		s += x;

		cout << "\nSum = " << s << " number of iterations = " << k << endl;

		cout << "expected " << atanh(x) << endl;

		cout << "---------------------------------\n\n";
	}



	system("pause");
	return 0;
}
