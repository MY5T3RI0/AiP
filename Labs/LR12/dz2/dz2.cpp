#include <iostream>
using namespace std;

struct domino {
    int left;
    int right;
};

void getRandDominoes(domino* dominos, int size);
void printDominoes(domino* dominos, int size);
void removeDomino(domino* dominos, int index, int& size);
void removeCollision(domino* dominos, int& size);
void addRandDominoes(domino* dominos, int& size);
void sortDominoes(domino* dominos, int size);

int main()
{
    int size = 28;
    domino* dominos = new domino[size];

    getRandDominoes(dominos, size);

    cout << "---------------------------------------\n";
    cout << "Dominos:\n";
    cout << "---------------------------------------\n";

    printDominoes(dominos, size);

    removeCollision(dominos, size);

    while (size != 28)
    {
        addRandDominoes(dominos, size);

        removeCollision(dominos, size);
    }

    cout << "---------------------------------------\n";
    cout << "Unique dominos:\n";
    cout << "---------------------------------------\n";

    printDominoes(dominos, size);

    sortDominoes(dominos, size);

    cout << "---------------------------------------\n";
    cout << "Sorted dominos:\n";
    cout << "---------------------------------------\n";

    printDominoes(dominos, size);
}

void getRandDominoes(domino* dominos, int size) {

    for (size_t i = 0; i < size; i++)
    {
        dominos[i].left = rand() % 7;
        dominos[i].right = rand() % 7;
    }
}

void printDominoes(domino* dominos, int size) {

    for (size_t i = 0; i < size; i++)
    {
        cout << "#" << i + 1 << endl;
        cout << "-----\n";
        cout << "|" << dominos[i].left << "|" << dominos[i].right << "|\n";
        cout << "-----\n";
    }
}

void removeDomino(domino* dominos, int index, int& size) {

    for (size_t i = index; i < size; i++)
    {
        dominos[i] = dominos[i + 1];
    }
    size--;
}

void removeCollision(domino* dominos, int& size) {

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (dominos[i].left == dominos[j].left && dominos[i].right == dominos[j].right ||
                dominos[i].left == dominos[j].right && dominos[i].right == dominos[j].left) {
                removeDomino(dominos, i, size);
                i--;
            }
        }
    }
}

void addRandDominoes(domino* dominos, int& size) {

    for (size_t i = size; i < 28; i++)
    {
        dominos[i].left = rand() % 7;
        dominos[i].right = rand() % 7;
    }

    size = 28;
}

void sortDominoes(domino* dominos, int size) {

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (dominos[i].right == dominos[j].left)
                swap(dominos[i + 1], dominos[j]);
        }
    }
}