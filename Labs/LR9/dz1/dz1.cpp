#include <iostream>
#include <ctime>
using namespace std;

float* getValues();
float aT(int t);
int getMaxN(float* array);
int getMinN(float* array);
void getIntervals(float* array);

int main()
{
    float* values = new float[30];
	srand(time(0));

	values = getValues();

	for (size_t i = 0; i < 30; i++)
	{
		cout << i << " " << values[i] << "\n";
	}

	cout << "\nmaxN = " << getMaxN(values) << endl;
	cout << "minN = " << getMinN(values) << endl;

	getIntervals(values);
}

float* getValues() {

	float* values = new float[30];
	int kd;
	for (size_t i = 1; i < 31; i++)
	{
		kd = rand() % 10;
		float coseat = abs(cos(exp(aT(i))));
		float chis = 5 * aT(i);
		float znam = aT(i) + sqrt(abs(aT(i)));
		float Ut = coseat + chis / znam;
		float d = kd * Ut / 100;

		if (rand() % 2)
			values[i] = Ut + d;
		else
			values[i] = Ut - d;

	}

	return &values[0];
}

float aT(int t) {
	return pow(sin(3*t), 2);
}

int getMaxN(float* array) {
	float max = -9999999;
	int maxN = 0;
	for (size_t i = 0; i < 30; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
			maxN = i;
		}

	}

	return maxN;
}

int getMinN(float* array) {
	float min = 99999999;
	int minN = 0;
	for (size_t i = 0; i < 30; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
			minN = i;
		}

	}

	return minN;
}

void getIntervals(float* array) {

	pair<int, int>* intervals = new pair<int, int>[30];

	for (size_t i = 0; i < 30; i++)
	{
		if (array[i] > 2)
		{
			intervals[i].first = i;
			for (size_t j = i; j < 30; j++)
			{
				if (j == 29 && array[j] > 2)
				{
					intervals[i].second = j;
					cout << "(" << intervals[i].first << ";" << intervals[i].second << ")\n";
					i = j;
				}
				else if (array[j] < 2)
				{
					intervals[i].second = j-1;
					cout << "(" << intervals[i].first << ";" << intervals[i].second << ")\n";
					i = j;
					break;
				}
			}
		}
	}
}
