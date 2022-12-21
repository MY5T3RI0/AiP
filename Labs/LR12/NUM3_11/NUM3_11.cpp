#include <iostream>
#include <time.h>
#include <list>
#include <fstream>
using namespace std;

ofstream fout;

struct room {
    string surname;
    string faculty;
    int number;
    int square;
};

struct smallestRoom {
    string surname;
    int square;
};

string getRandSurname();
string getRandFaculty();
void getRandRooms(room* rooms, int count);
void printRooms(room* rooms, int size);
void getSmallestRoom(room* rooms, smallestRoom* room);

int main()
{
    fout.open("result.txt");
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    room* rooms = new room[10];

    getRandRooms(rooms, 10);

    cout << "---------------------------------------\n";
    cout << "Rooms:\n";
    cout << "---------------------------------------\n";
    fout << "---------------------------------------\n";
    fout << "Rooms:\n";
    fout << "---------------------------------------\n";

    printRooms(rooms, 10);

    smallestRoom smallRoom;
    getSmallestRoom(rooms, &smallRoom);

    cout << "---------------------------------------\n";
    cout << "Smallest room:\n";
    cout << "---------------------------------------\n";

    cout << "Surname: " << smallRoom.surname << endl;
    cout << "Square: " << smallRoom.square << " кв.м." << endl;

    fout << "---------------------------------------\n";
    fout << "Smallest room:\n";
    fout << "---------------------------------------\n";

    fout << "Surname: " << smallRoom.surname << endl;
    fout << "Square: " << smallRoom.square << " кв.м." << endl;
}

string getRandSurname() {
    string surnames[10] = { "Пестов",
                        "Авдеев",
                        "Филатов",
                        "Самойлов",
                        "Русаков",
                        "Харитонов",
                        "Галкин",
                        "Лобанов",
                        "Шарапов",
                        "Корнилов" 
    };

    return surnames[rand() % 10];

}

string getRandFaculty() {
    string faculties[10] = { "Педагогический",
                        "Медицинский",
                        "Политехнический",
                        "Экономический",
                        "Исторический"
    };

    return faculties[rand() % 5];
}

void getRandRooms(room* rooms, int count) {

    for (size_t i = 0; i < 10; i++)
    {
        rooms[i].surname = getRandSurname();
        rooms[i].faculty = getRandFaculty();
        rooms[i].number = rand() % 100 + 1;
        rooms[i].square = rand() % 20 + 20;
    }
}

void printRooms(room* rooms, int size) {
    for (size_t i = 0; i < size; i++)
    {
        cout << i + 1 << ") Surname: " << rooms[i].surname << endl;
        cout << "\t Number: " << rooms[i].number << endl;
        cout << "\t Faculty: " << rooms[i].faculty << endl;
        cout << "\t Square: " << rooms[i].square << " кв.м." << endl;

        fout << i + 1 << ") Surname: " << rooms[i].surname << endl;
        fout << "\t Number: " << rooms[i].number << endl;
        fout << "\t Faculty: " << rooms[i].faculty << endl;
        fout << "\t Square: " << rooms[i].square << " кв.м." << endl;
    }
}

void getSmallestRoom(room* rooms, smallestRoom* room) {

    room->square = 99;

    for (size_t i = 0; i < 10; i++)
    {
        if (rooms[i].square < room->square)
        {
            room->square = rooms[i].square;
            room->surname = rooms[i].surname;
        }
    }
}