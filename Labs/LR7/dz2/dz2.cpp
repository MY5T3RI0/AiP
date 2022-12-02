#include <iostream>
#include <time.h>

using namespace std;

struct coordinates {
    pair <float, float> coord1;
    pair <float, float> coord2;
    pair <float, float> coord3;
};

coordinates getCoords();
coordinates get_ab(coordinates coords);
void drawTriangle(coordinates ab);

int main()
{
    srand(time(0));
    coordinates coords = getCoords();
    coordinates ab = get_ab(coords);

    drawTriangle(ab);
}

coordinates getCoords() {
    coordinates coords;
    coords.coord1 = make_pair(rand() % 15 + 15, rand() % 8);
    coords.coord2 = make_pair(rand() % 15, rand() % 8 + 16);
    coords.coord3 = make_pair(rand() % 15 + 30, rand() % 8 + 8);

    return coords;
}

coordinates get_ab(coordinates coords) {
    coordinates ab;
    float a1 = float((coords.coord2.second - coords.coord1.second)) / (coords.coord2.first - coords.coord1.first);
    float b1 = coords.coord1.second - a1 * coords.coord1.first;
    ab.coord1 = make_pair(a1, b1);
    float a2 = float((coords.coord3.second - coords.coord2.second)) / (coords.coord3.first - coords.coord2.first);
    float b2 = coords.coord2.second - a2 * coords.coord2.first;
    ab.coord2 = make_pair(a2, b2);
    float a3 = float((coords.coord1.second - coords.coord3.second)) / (coords.coord1.first - coords.coord3.first);
    float b3 = coords.coord1.second - a3 * coords.coord1.first;
    ab.coord3 = make_pair(a3, b3);

    return ab;
}

void drawTriangle(coordinates ab) {
    for (size_t i = 0; i < 24; i++)
    {
        for (size_t j = 0; j < 44; j++)
        {
            if (i > ab.coord1.first * j + ab.coord1.second &&
                i < ab.coord2.first * j + ab.coord2.second &&
                i > ab.coord3.first * j + ab.coord3.second
                )
                cout << " ";
            else
                cout << ".";
        }
        cout << endl;
    }
}