#include <iostream>

using namespace std;
void DosToWin(char d, char& w)
{
    if ((d >= -128) && (d <= -81)) // А...Я а...п
        w = d + 64;
    if ((d >= -32) && (d <= -17)) // р...я
        w = d + 16;
    if (d == -16) w = -88; // Ё
    if (d == -15) w = -72; // ё
}
void convert(char* s, char* sw)
{
    for (int i = 0; i < strlen(s); i++) DosToWin(s[i], s[i]);
} 

int main()
{
    setlocale(LC_ALL, "Russian");
    char fruit[] = "яблоко";
    char answer[80];
    do
    {
        cout << "Угадайте мой любимый фрукт! >> ";
        cin >> answer;
        convert(answer, answer);
    } while (strcmp(fruit, answer) != 0);
    cout << "Правильный ответ!\n";
    system("pause");
    return 0;
}