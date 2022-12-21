#include <iostream>
#include <time.h>
#include <list>
#include <fstream>
using namespace std;

ofstream fout;

struct hostel {
    string Name;
    string comfort;
    int number;
    int capacity;
    int price;
};

string getRandName();
string getRandComfort();
void GetHostels(hostel* hostels, int count);
list<hostel> GetHostelsP(hostel* hostels);
void Sort(hostel* hostels, int size);
void printHostels(hostel* hostels, int size);

int main()
{
    fout.open("result.txt");
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    hostel* hostels = new hostel[10];

    GetHostels(hostels, 10);

    cout << "---------------------------------------\n";
    cout << "Hotels:\n";
    cout << "---------------------------------------\n";
    fout << "---------------------------------------\n";
    fout << "Hotels:\n";
    fout << "---------------------------------------\n";

    printHostels(hostels, 10);

    list<hostel> hostelsList = GetHostelsP(hostels);
    hostel* sortedHostels = new hostel[hostelsList.size()];
    int j = 0;

    for ( auto i = hostelsList.begin(); i != hostelsList.end(); i++)
    {
        sortedHostels[j++] = *i;
    }

    Sort(sortedHostels, hostelsList.size());

    cout << "---------------------------------------\n";
    cout << "Sorted hotels:\n";
    cout << "---------------------------------------\n";
    fout << "---------------------------------------\n";
    fout << "Sorted hotels:\n";
    fout << "---------------------------------------\n";

    printHostels(sortedHostels, hostelsList.size());
}

string getRandName() {
    string fios[10] = { "Джузеппе",
                        "Ибис",
                        "Парк Инн Рэдиссон",
                        "Максим Горький",
                        "Хаял",
                        "Раймонд Отель",
                        "Шаляпин Палас Отель",
                        "Берисон Худякова",
                        "Давыдов",
                        "Рубин Апарт" 
    };

    return fios[rand() % 10];

}

string getRandComfort() {
    string jobs[10] = { "люкс",
                        "полулюкс",
                        "стандарт",
                        "эконом"
    };

    return jobs[rand() % 4];
}

void GetHostels(hostel* hostels, int count) {

    for (size_t i = 0; i < 10; i++)
    {
        hostels[i].Name = getRandName();
        hostels[i].comfort = getRandComfort();
        hostels[i].number = rand() % 100 + 1;
        hostels[i].capacity = rand() % 5 + 1;
        hostels[i].price = rand() % 2500 + 500;
    }
}

list<hostel> GetHostelsP(hostel* hostels) {

    list<hostel> hostelsList;

    for (size_t i = 0; i < 10; i++)
    {
        int temp = (int)hostels[i].Name[0];
        int answer = -48;

        if (temp == answer) {
            hostelsList.push_front(hostel{ hostels[i].Name,
                                        hostels[i].comfort,
                                        hostels[i].number,
                                        hostels[i].capacity,
                                        hostels[i].price
            });
        }

    }

    return hostelsList;
}

void Sort(hostel* hostels, int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1; j++) {
            if (hostels[j].price > hostels[j + 1].price) {
                swap(hostels[j], hostels[j + 1]);
            }
        }
    }
}

void printHostels(hostel* hostels, int size) {

    for (size_t i = 0; i < size; i++)
    {
        cout << i + 1 << ") Name: " << hostels[i].Name << endl;
        cout << "\t Number: " << hostels[i].number << endl;
        cout << "\t Comfort: " << hostels[i].comfort << endl;
        cout << "\t Capacity: " << hostels[i].capacity << " чел." << endl;
        cout << "\t Price: " << hostels[i].price << " в день" << endl;

        fout << i + 1 << ") Name: " << hostels[i].Name << endl;
        fout << "\t Number: " << hostels[i].number << endl;
        fout << "\t Comfort: " << hostels[i].comfort << endl;
        fout << "\t Capacity: " << hostels[i].capacity << " чел." << endl;
        fout << "\t Price: " << hostels[i].price << " в день" << endl;
    }
}