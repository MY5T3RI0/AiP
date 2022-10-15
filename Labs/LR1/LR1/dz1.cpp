#include <iostream>

using namespace std;

const double PI = acos(-1.0);

double getSideSquare(int radius, int height)
{
    double generaticOfAcone = sqrt(pow(radius, 2) + pow(height, 2));

    return generaticOfAcone * PI * radius;
}

double getCircleSquare(int radius)
{
    return PI * pow(radius, 2);
}

double getConeVolume(int radius, int height)
{
    return PI * pow(radius, 2) * height / 3;
}

int main()
{
    int radius;
    int height;
    cout << "Input radius\n";
    cin >> radius;
    cout << "Input height\n";
    cin >> height;
    
   double sideSquare = getSideSquare(radius, height);
   double circleSquare = getCircleSquare(radius);

   cout << "Full surface square = " << sideSquare + circleSquare << "\n";
   cout << "Volume = " << getConeVolume(radius, height);
}

