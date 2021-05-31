#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

struct List
{
    string name;
    string group;
    string rang;
};

void random(List array_of_elements[], int size)
{

    for (int i = 0; i < size; i++) {
        ifstream name("List.txt");
        string point;
        int count = -1;
        int rnd = rand() % 10;

        while (count != rnd)
        {
            getline(name, point);
            count++;
        }
        array_of_elements[i].name = point;
        name.close();

        ifstream date("group.txt");
        rnd = rand() % 15;
        count = -1;

        while (count != rnd)
        {
            getline(date, point);
            count++;
        }
        array_of_elements[i].group = point;
        date.close();

        ifstream passport("rang.txt");
        rnd = rand() % 25;
        count = -1;

        while (count != rnd)
        {
            getline(passport, point);
            count++;
        }
        array_of_elements[i].rang = point;
        date.close();
    }
}



void print_list(List array_of_elements[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << "\nФИО:" << array_of_elements[i].name;
        cout << "\nГруппа: " << array_of_elements[i].group;
        cout << "\nРейтинг: " << array_of_elements[i].rang << "\n";
    }
}


void direct_search(string name, List array_of_elements[], int size)
{
    cout << "\n\n\nМетод прямого поиска: \n";

    string temp;
    int j = 0;
    bool flag = false;
    for (int i = 0; i < size; i++) {
        temp = array_of_elements[i].name;
        while (name[j] == array_of_elements[i].name[j] && j < name.length()) j++;
        if (j == name.length()) {
            flag = true;
            cout << "\nЭлемент с заданым именем и фамилией:\n\n";
            cout << "\nФИО:" << array_of_elements[i].name;
            cout << "\nГруппа: " << array_of_elements[i].group;
            cout << "\nРейтинг: " << array_of_elements[i].rang << "\n";
        }
        j = 0;
    }
    if (flag == false)
        cout << "Элементы с заданным именем и фамилией не найдены!";

}



void linear_search(string name, List array_of_elements[], int size)
{
    bool flag = false;
    cout << "\n\n\nМетод линейного поиска:\n ";

    for (int i = 0; i < size; i++) {
        if (name == array_of_elements[i].name)
        {
            cout << "\nЭлемент с заданым именем и фамилией:\n\n";
            cout << "\nФИО:" << array_of_elements[i].name;
            cout << "\nГруппа: " << array_of_elements[i].group;
            cout << "\nРейтинг: " << array_of_elements[i].rang << "\n";
            flag = true;
        }
    }
    if (flag == false)
        cout << "Элементы с заданным именем и фамилией не найдены!";
}



void interpolating_search(string name, List array_of_elements[], int size)
{
    int check = 0;
    for (int i = 0; i < size; i++) {
        if (name == array_of_elements[i].name)
        {
            cout << "\nСтудент с заданной фамилией :\n";
            cout << "\nФИО:" << array_of_elements[i].name;
            cout << "\nГруппа: " << array_of_elements[i].group;
            cout << "\nРейтинг: " << array_of_elements[i].rang << "\n";
            check++;
        }
    }
    if (check == 0)
        cout << "Студентов с заданной фамилией нет!";
}



int main()
{
    setlocale(LC_ALL, "RUS");
    


    int size;
    string name_st = "BOB";
    char choice_of_method;

    cout << "Введите количество элементов:";
    cin >> size;

    srand(time(NULL));
    while (size <= 0)
    {
        cout << "Ошибка! Введите корректное количество элементов:";
        cin >> size;
    }

    cout << endl;
    List* array_of_elements = new List[size];
    random(array_of_elements, size);
    print_list(array_of_elements, size);

    cout << "\nВведите имя студента: ";
    cin >> name_st;
    cout << "\nВведите фамилию студента: ";
    string name1;
    cin >> name1;
    name_st = name_st + ' ' + name1;



    cout << "Выберите метод поиска:\n\n\t1.Прямой поиск\n\t2.Линейный поиск\n\t3.Интерполяционный поиск\n";
    cin >> choice_of_method;

    switch (choice_of_method)
    {
    case '1':
        direct_search(name_st, array_of_elements, size);
        break;
    case '2':
        linear_search(name_st, array_of_elements, size);
        break;
    case '3':
        interpolating_search(name_st, array_of_elements, size);
        break;
    default:
        cout << "Выберите один из вариантов";
    }
    delete[] array_of_elements;
};
