#include <iostream>
#include <time.h>
using namespace std;

struct statement {
    string FIO;
    string job;
    int birthdayYear;
    string birthday;
    int pay;
};

string getRandFio();

string getRandJob();

string getRandDate();

void GetWorkers(statement* workers, int count);

int getMaxPay(statement* workers);

int main()
{   
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    statement* workers = new statement[10];

    GetWorkers(workers, 10);

    for (size_t i = 0; i < 10; i++)
    {
        cout << i + 1 << ") FIO: " << workers[i].FIO << endl;
        cout << "\t Job: " << workers[i].job << endl;
        cout << "\t Birthday: " << workers[i].birthday << " " << workers[i].birthdayYear << "г." << endl;
        cout << "\t Pay: " << workers[i].pay << endl;
    }

    cout << "\nMax pay = " << getMaxPay(workers) << endl;

}

string getRandFio() {
    string fios[10] = { "Пестов Давид Лукьянович",
                        "Авдеев Виктор Игоревич",
                        "Филатов Борис Михаилович",
                        "Самойлов Вольдемар Альбертович",
                        "Русаков Максимилиан Матвеевич",
                        "Харитонов Михаил Святославович",
                        "Галкин Лаврентий Святославович",
                        "Лобанов Рудольф Кириллович",
                        "Шарапов Велорий Михаилович",
                        "Корнилов Любовь Дамирович" };

    return fios[rand() % 10];

}

string getRandJob() {
    string jobs[10] = { "разработчик",
                        "архитектор",
                        "аналитик",
                        "веб-дизайнер",
                        "тестировщик",
                        "инженер",
                        "системный администратор",
                        "специалист по работе с Big Data",
                        "специалисты в области искусственного интеллекта",
                        "юрист" };

    return jobs[rand() % 10];
}

string getRandDate() {
    string dates[10] = { "1 декабря",
                       "2 января",
                       "3 февраля",
                       "4 марта",
                       "5 апреля",
                       "6 мая",
                       "7 июня",
                       "8 июля",
                       "9 августа",
                       "10 сентября" };

    return dates[rand() % 10];
}

void GetWorkers(statement* workers, int count) {

    for (size_t i = 0; i < 10; i++)
    {
        workers[i].FIO = getRandFio();
        workers[i].job = getRandJob();
        workers[i].birthdayYear = rand() % 50 + 1950;
        workers[i].birthday = getRandDate();
        workers[i].pay = rand() % 50000 + 30000;
    }
}

int getMaxPay(statement* workers) {

    int maxPay = 0;

    for (size_t i = 0; i < 10; i++)
    {
        if (workers[i].pay > maxPay)
            maxPay = workers[i].pay;
    }

    return maxPay;
}