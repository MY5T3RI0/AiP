#include <iostream>
#include <list>

using namespace std;

const double PI = acos(-1);

struct radiuses {
	float R_inside;
	float R_outside;
};

class Triangle
{

private:
	int A;
	int B;
	int C;
	float half_p;
	float square;

public:
	radiuses* rad = new radiuses();

public:
	Triangle(int a, int b, int c)
	{
		A = a;
		B = b;
		C = c;
		half_p = getHalf_P(a, b, c);
		square = getSquare(a, b, c);
		getRadiuses(*rad);
	};

private:
	void getRadiuses(radiuses &rad)
	{
		rad.R_inside = sqrt((half_p - A)*(half_p - B)*(half_p - C)/half_p);
		rad.R_outside = A * B * C / 4 / square;
	}

	float getHalf_P(int a, int b, int c)
	{
		return (a + b + c) / 2;
	}

	float getSquare(int a, int b, int c)
	{
		return sqrt(half_p * (half_p - a) * (half_p - b) * (half_p - c));
	}

};

bool TriangleExists(int a, int b, int c);

void getSum(Triangle t1, Triangle t2, Triangle t3);

int main()
{
	int a, b, c;
	Triangle *trs[3];

	for (size_t i = 0; i < 3; )
	{
		a = rand() % 100;
		b = rand() % 100;
		c = rand() % 100;

		if (TriangleExists(a, b, c))
		{
			cout << "a = " << a << endl;
			cout << "b = " << b << endl;
			cout << "c = " << c << endl;
			trs[i] = new Triangle(a, b, c);
			cout << "inside radius = " << trs[i]->rad->R_inside << endl;
			cout << "outside radius = " << trs[i]->rad->R_outside << endl;
			cout << "-------------------\n";
			i++;
		}
	}

	getSum(*trs[0], *trs[1], *trs[2]);

}

bool TriangleExists(int a, int b, int c) {
	if (a + b > c && a + c > b && b + c > a)
		return true;
	else
		return false;
}

void getSum(Triangle t1, Triangle t2, Triangle t3)
{
	cout << "Sum of inside radiuses = " << t1.rad->R_inside + t2.rad->R_inside + t3.rad->R_inside << endl;

	cout << "Sum of outside radiuses = " << t1.rad->R_outside + t2.rad->R_outside + t3.rad->R_outside << endl;
}