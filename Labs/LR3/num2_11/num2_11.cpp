#include <iostream>

using namespace std;
int main()
{
    int numbers[4], max1, max2;
    cout << "Enter 4 numbers" << endl;
	for (int i = 0; i < 4; i++)
	{
		cin >> numbers[i];
	}

	max1 = 0; max2 = 0;
	for (int i = 0; i < 4; i++)
	{
		if (numbers[i] > max1)
		{
			max2 = max1;
			max1 = numbers[i];
		}
		else if (numbers[i] > max2)
		{
			max2 = numbers[i];
		}
	}

	cout << "Max numbers: " << max1 << " " << max2;
}
