#include <iostream>
#include <time.h>
using namespace std;

struct point {
	int x;
	int y;
	int z;
};

struct sphere {
	int a;
	int b;
	int c;
	int R;
};

void getSphere(sphere* sphere);

void getPoint(point* point);

void Shots(sphere sphere);

void main() {
	srand(time(0));
	sphere sphere;

	int maxX = 50;
	int maxY = 50;
	int maxZ = 50;

	getSphere(&sphere);

	cout << "Sphere:\n";
	cout << "a = " << sphere.a << endl;
	cout << "b = " << sphere.b << endl;
	cout << "c = " << sphere.c << endl;
	cout << "R = " <<sphere.R << endl << endl;

	Shots(sphere);
}

void getSphere(sphere* sphere) {
	sphere->R = rand() % 20 + 5;
	sphere->a = rand() % (50 - 2 * sphere->R) + sphere->R;
	sphere->b = rand() % (50 - 2 * sphere->R) + sphere->R;
	sphere->c = rand() % (50 - 2 * sphere->R) + sphere->R;
}

void getPoint(point* point) {
	point->x = rand() % 50;
	point->y = rand() % 50;
	point->z = rand() % 50;
}

void Shots(sphere sphere) {

	point point;
	int hit = 0;
	int miss = 0;

	for (int i = 0; i < 100; i++)
	{
		getPoint(&point);

		if (pow(point.x - sphere.a, 2) + pow(point.y - sphere.b, 2) + pow(point.z - sphere.c, 2) <= pow(sphere.R, 2))
			hit++;
		else
			miss++;
	}

	cout << "Shots count = " << hit + miss << endl;
	cout << "Misses cout = " << miss << endl;
}