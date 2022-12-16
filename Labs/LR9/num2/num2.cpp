#include <iostream>
#include <time.h>
using namespace std;

const double PI = acos(-1);

void getCoords(pair<int, int>* coords, int size);
void getVectors(pair<int, int>* coords, int size, pair<int, int>* vectors);
bool isConvex(pair<int, int>* vectors, int size);

int main()
{
    srand(time(0));
    int n;
    for (size_t i = 0; i < 100000; i++)
    {
        //n = rand() % 3 + 4;
        n = 6;

        pair<int, int>* coords = new pair<int, int>[n];
        getCoords(coords, n);

        for (size_t i = 0; i < n; i++)
        {
            //cout << "(" << coords[i].first << "; " << coords[i].second << ")" << endl;
        }

        pair<int, int>* vectors = new pair<int, int>[n];
        getVectors(coords, n, vectors);

        //cout << "------------------\n";
        for (size_t i = 0; i < n; i++)
        {
            //cout << "(" << vectors[i].first << "; " << vectors[i].second << ")" << endl;
        }
    }
}

void getCoords(pair<int, int>* coords, int size) {
    for (size_t i = 0; i < size; i++)
    {
        coords[i].first = rand() % 6 - 2;
        coords[i].second = rand() % 6 - 3;
    }
}

void getVectors(pair<int, int>* coords, int size, pair<int, int>* vectors) {

    for (size_t i = 0; i < size; i++)
    {
        if (i == size - 1) {
            vectors[i].first = coords[0].first - coords[i].first;
            vectors[i].second = coords[0].second - coords[i].second;
            return;
        }
        vectors[i].first = coords[i+1].first - coords[i].first;
        vectors[i].second = coords[i + 1].second - coords[i].second;
    }
}

bool isConvex(pair<int, int>* vectors, int size) {

    float anglesSum = 0;

    for (size_t i = 0; i < size; i++)
    {
        double vectorsMultiply = vectors[i].first * vectors[i + 1].first + vectors[i].second * vectors[i + 1].second;
        double vector1Length = sqrt(pow(vectors[i].first, 2) + pow(vectors[i].second, 2));
        double vector2Length = sqrt(pow(vectors[i+1].first, 2) + pow(vectors[i+1].second, 2));
        double cosa = vectorsMultiply / vector1Length / vector2Length;

        anglesSum += (acos(cosa) * 180 / PI);

        if (i = size-1)
        {
            double vectorsMultiply = vectors[i].first * vectors[0].first + vectors[i].second * vectors[0].second;
            double vector1Length = sqrt(pow(vectors[i].first, 2) + pow(vectors[i].second, 2));
            double vector2Length = sqrt(pow(vectors[0].first, 2) + pow(vectors[0].second, 2));
            double cosa = vectorsMultiply / vector1Length / vector2Length;

            anglesSum += (acos(cosa) * 180 / PI);
        }
    }

    if (anglesSum > 350 && anglesSum < 750)
    {
        cout << anglesSum << " SO CLOSE!\n";
    }

    if (anglesSum == 180 * (size - 2))
        return true;
    else
        return false;
}