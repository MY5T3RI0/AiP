#include <iostream>
#include <time.h>
using namespace std;

template<typename T>
void getRandValues(T* Numbers, int size);
template<typename T>
void printMultiply(T* Numbers, int size);
template<typename T>
void printSum(T* Numbers, int size);
template<typename T>
void reorder(T* Numbers, int size);
template<typename T>
void print(T* Numbers, int size);

int main()
{
	srand(time(0));
	int size;
	cout << "size = "; cin >> size;
	float* Numbers = new float[size];

	getRandValues(Numbers, size);
	print(Numbers, size);
	printMultiply(Numbers, size);
	printSum(Numbers, size);
	reorder(Numbers, size);
	cout << "Sorted ";
	print(Numbers, size);
}

template<typename T>
void getRandValues(T* Numbers, int size) {

	for (size_t i = 0; i < size; i++)
	{
		Numbers[i] = rand() * (T)11 / RAND_MAX - 5;
	}
}

template<typename T>
void printMultiply(T* Numbers, int size) {

	T result = 1;

	for (size_t i = 0; i < size; i++)
	{
		if (i % 2 == 0)
			result *= Numbers[i];
	}

	cout << "Multiply = " << result << endl;
}

template<typename T>
void printSum(T* Numbers, int size) {

	int end = size;
	int start = 0;
	T result = 0;

	for (size_t i = size; i > 0; i--)
	{
		if (Numbers[i] == 0)
		{
			end = i;
			break;
		}
	}

	for (size_t i = 0; i < size; i++)
	{
		if (Numbers[i] == 0) {
			start = i;
			break;
		}
	}

	for (size_t i = start; i < end; i++)
		result += Numbers[i];

	cout << "Sum = " << result << endl;
}

template<typename T>
void reorder(T* Numbers, int size) {

	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (Numbers[j] < Numbers[j + 1])
			{
				swap(Numbers[j], Numbers[j + 1]);
			}
		}
	}
}

template<typename T>
void print(T* Numbers, int size) {

	cout << "Mass: ";

	for (size_t i = 0; i < size; i++)
	{
		cout << Numbers[i] << " ";
	}

	cout << endl;
}