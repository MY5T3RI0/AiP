#include <iostream>
#include <time.h>
using namespace std;

struct complex {
	double a;
	double b;
};

void getRealNumbers(double** matrix, int sizeX, int sizeY);
void getComplexNumbers(complex** matrix, int sizeX, int sizeY);
void printComplexMatrix(complex** matrix, int sizeX, int sizeY);
void printRealMatrix(double** matrix, int sizeX, int sizeY);
double sumNumbers(double a, double b, int k);
complex sumNumbers(complex a, complex b, int k);
template <typename T> 
void getMatrixSum(T** matrix1, T** matrix2,
	T** sumMatrix, int sizeX,
	int sizeY, int k);

int main()
{
	srand(time(0));
	int sizeX = 3;
	int sizeY = 3;
	double** realMatrix1 = new double*[sizeY];
	double** realMatrix2 = new double* [sizeY];
	double** realMatrixSum = new double* [sizeY];
	complex** complexMatrix1 = new complex* [sizeY];
	complex** complexMatrix2 = new complex * [sizeY];
	complex** complexMatrixSum = new complex* [sizeY];

	cout << "-------------------------COMPLEX-MATRICES-------------------------\n";
	cout << endl;
	getComplexNumbers(complexMatrix1, sizeX, sizeY);
	printComplexMatrix(complexMatrix1, sizeX, sizeY);
	cout << "------------------------------------------------------------------\n";
	getComplexNumbers(complexMatrix2, sizeX, sizeY);
	printComplexMatrix(complexMatrix2, sizeX, sizeY);
	cout << endl;
	cout << "--------------------------REAL-MATRICES---------------------------\n";
	cout << endl;
	getRealNumbers(realMatrix1, sizeX, sizeY);
	printRealMatrix(realMatrix1, sizeX, sizeY);
	cout << "------------------------------------------------------------------\n";
	getRealNumbers(realMatrix2, sizeX, sizeY);
	printRealMatrix(realMatrix2, sizeX, sizeY);
	cout << "------------------------------------------------------------------\n";
	cout << "******************************************************************\n";
	cout << "-------------------------COMPLEX-MATRICES-------------------------\n";
	cout << endl;
	cout << "--------------------------------SUM-------------------------------\n";
	cout << endl;
	getComplexNumbers(complexMatrixSum, sizeX, sizeY);
	getMatrixSum(complexMatrix1, complexMatrix2, complexMatrixSum, sizeX, sizeY, 1);
	printComplexMatrix(complexMatrixSum, sizeX, sizeY);
	cout << endl;
	cout << "----------------------------DIFFERENCE----------------------------\n";
	cout << endl;
	getMatrixSum(complexMatrix1, complexMatrix2, complexMatrixSum, sizeX, sizeY, -1);
	printComplexMatrix(complexMatrixSum, sizeX, sizeY);
	cout << endl;
	cout << "--------------------------REAL-MATRICES---------------------------\n";
	cout << endl;
	cout << "-------------------------------SUM--------------------------------\n";
	cout << endl;
	getRealNumbers(realMatrixSum, sizeX, sizeY);
	getMatrixSum(realMatrix1, realMatrix2, realMatrixSum, sizeX, sizeY, 1);
	printRealMatrix(realMatrixSum, sizeX, sizeY);
	cout << endl;
	cout << "----------------------------DIFFERENCE----------------------------\n";
	cout << endl;
	getMatrixSum(realMatrix1, realMatrix2, realMatrixSum, sizeX, sizeY, -1);
	printRealMatrix(realMatrixSum, sizeX, sizeY);
	cout << "------------------------------------------------------------------\n";
}

void getRealNumbers(double** matrix, int sizeX, int sizeY) {

	for (size_t i = 0; i < 3; i++)
	{
		matrix[i] = new double[sizeX];
	}

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t j = 0; j < sizeX; j++)
		{
			matrix[i][j] = rand() * 10. / RAND_MAX;
		}
	}
}

void getComplexNumbers(complex** matrix, int sizeX, int sizeY) {

	for (size_t i = 0; i < 3; i++)
	{
		matrix[i] = new complex[sizeX];
	}

	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t j = 0; j < sizeX; j++)
		{
			matrix[i][j].a = rand() * 10. / RAND_MAX;
			matrix[i][j].b = rand() * 10. / RAND_MAX;
		}
	}
}

void printComplexMatrix(complex** matrix, int sizeX, int sizeY) {
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t j = 0; j < sizeX; j++)
		{
			printf("%.5f", matrix[i][j].a);
			cout << " + ";
			printf("%.5f", matrix[i][j].b);
			cout << "i\t";
		}
		cout << endl;
	}
}

void printRealMatrix(double** matrix, int sizeX, int sizeY) {
	for (size_t i = 0; i < sizeY; i++)
	{
		for (size_t j = 0; j < sizeX; j++)
		{
			printf("%.5f", matrix[i][j]);
			cout << " \t";
		}
		cout << endl;
	}
}

double sumNumbers(double a, double b, int k) {
	return a + b * k;
}

complex sumNumbers(complex a, complex b, int k) {
	complex c;
	c.a = a.a + b.a * k;
	c.b = a.b + b.b * k;
	return c;
}

template <typename T>
void getMatrixSum(T** matrix1, T** matrix2,
	T** sumMatrix, int sizeX,
	int sizeY, int k) {

	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			sumMatrix[i][j] = sumNumbers(matrix1[i][j], matrix2[i][j], k);
		}
	}
}