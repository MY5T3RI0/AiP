#include <iostream>
#include <time.h>
using namespace std;

void getRandValues(int* intNumbers, float* floatNumbers);
float getSrArifm(int* intValues);
float getSrArifm(float* floatValues);
float getSrGeom(int* intValues);
float getSrGeom(float* floatValues);

int main()
{
	srand(time(0));
	int *intNumbers = new int[3];
	float *floatNumbers = new float[3];

	getRandValues(intNumbers, floatNumbers);

	cout << getSrArifm(intNumbers) << endl << getSrGeom(intNumbers) << endl;

	if (getSrArifm(intNumbers) > getSrGeom(intNumbers))
		cout << "SrArifm of int numbers bigger\n";
	else
		cout << "SrGeom of int numbers bigger\n";

	if (getSrArifm(floatNumbers) > getSrGeom(floatNumbers))
		cout << "SrArifm of float numbers bigger\n";
	else
		cout << "SrGeom of float numbers bigger\n";
}

void getRandValues(int* intNumbers, float* floatNumbers) {
	for (size_t i = 0; i < 3; i++)
	{
		floatNumbers[i] = rand() * 100.0 / RAND_MAX;
	}

	for (size_t i = 0; i < 3; i++)
	{
		intNumbers[i] = rand() % 100;
	}

}

float getSrArifm(int* intValues) {

	float result = 0;

	for (size_t i = 0; i < 3; i++)
	{
		result += intValues[i];
	}

	return result / 3;
}

float getSrArifm(float* floatValues) {

	float result = 0;

	for (size_t i = 0; i < 3; i++)
	{
		result += floatValues[i];
	}

	return result / 3;
}

float getSrGeom(int* intValues) {

	float result = 1;

	for (size_t i = 0; i < 3; i++)
	{
		result *= intValues[i];
	}

	return pow(result, 1. / 3);
}

float getSrGeom(float* floatValues) {

	float result = 1;

	for (size_t i = 0; i < 3; i++)
	{
		result *= floatValues[i];
	}

	return pow(result, 1. / 3);
}