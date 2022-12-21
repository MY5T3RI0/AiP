#include <iostream>

using namespace std;

void fillMass(int mass[19]) {

	for (size_t i = 0; i < 19; i++)
	{
		mass[i] = 7 * i + 11;
	}
}

void getNumbers(int mass[19], int numbers[19]) {

	int kbit; // описание типов переменных

	for (size_t i = 0; i < 19; i++)
	{
		kbit = 0;
		for (int j = 0; j < 8 * sizeof(int); j++) // цикл по битам
			if ((mass[i] & (1L << j)) != 0)
				kbit++;

		numbers[i] = 32 - kbit;
	}
}

void sortNumbers(int numbers[19], int mass[19]) {
	for (size_t i = 0; i < 18; i++)
	{
		for (size_t j = 0; j < 18-i; j++)
		{
			if (numbers[j] > numbers[j + 1])
			{
				swap(numbers[j], numbers[j+1]);
				swap(mass[j], mass[j + 1]);
			}
		}
	}
}

int main()
{
    int mass[19];
	int numbers[19];

	fillMass(mass);

	getNumbers(mass, numbers);

	cout << "mass: ";

	for (size_t i = 0; i < 19; i++)
	{
		cout << mass[i] << " ";
	}

	cout << endl;

	cout << "null bit count in mass: ";

	for (size_t i = 0; i < 19; i++)
	{
		cout << numbers[i] << " ";
	}

	cout << "\n-----------------------------------------------------";

	sortNumbers(numbers, mass);

	cout << endl;

	cout << "sorted null bit count in mass: ";

	for (size_t i = 0; i < 19; i++)
	{
		cout << numbers[i] << " ";
	}

	cout << endl;

	cout << "sorted mass: ";

	for (size_t i = 0; i < 19; i++)
	{
		cout << mass[i] << " ";
	}

	cout << endl;
}