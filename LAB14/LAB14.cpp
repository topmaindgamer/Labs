#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;


struct stud
{
    string name;
    string group;
    short int rang;
};


stud make_arr(stud* arr, int size)
{
    string str;


    ifstream name;

    name.open("names.txt");
    for (int i = 0; i < size; i++) {
        getline(name, str);
        arr[i].name = str;
    }
    name.close();



    ifstream group;

    group.open("group.txt");
    for (int i = 0; i < size; i++) {
        getline(group, str);
        arr[i].group = str;
    }
    group.close();



    for (int i = 0; i < size; i++) {
        arr[i].rang = rand() % 31;
    }

    return *arr;
}



void show_arr(stud *arr, int size) 
{
    for ( int i = 0; i < size; i++) {
        cout << "Элемент " << i+1 << ':'<< endl;
        cout << "Имя  \t\t" << arr[i].name << endl;
        cout << "Группа  \t" << arr[i].group << endl;
        cout << "Рейтинг  \t" <<  arr[i].rang << endl;
        cout << endl;
    }
    
}



void preKMP(string pattern, int f[])
{
    int m = pattern.length(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}


bool KMP(string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    int* f = new int[m];
    preKMP(pattern, f);
    int i = 0;
    int k = 0;
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return 1;
        }
        else
            k = f[k];
    }
    return 0;
}




# define NO_OF_CHARS 256




bool BM(char* txt, char* pat)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int badchar[NO_OF_CHARS];

    int i;


    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;


    for (i = 0; i < m; i++)
        badchar[(int)pat[i]] = i;

    int s = 0;
    int k = 0;
    while (s <= (n - m))
    {
        int j = m - 1;
        k++;
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            return 1;

            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

        }

        else
            s += fmax(1, j - badchar[txt[s + j]]);
    }
    return 0;
   
}


int main()
{
    
    setlocale(LC_ALL, "RUS");

    int x;
    cout << "Введите количество студентов: ";
    cin >> x;
    cout << endl;

    stud* arr = new stud[x];
    

    make_arr(arr,x);

    show_arr(arr,x);


    cout << "Введите имя для поиска: ";
    string search;
    cin.ignore();
    getline(cin, search);
    char* cs = &search[0];

    int h;
    cout << "Введите метод поиска:"<< endl;
    cout << "1) Метод Кнута-Морриса-Пратта " << endl;
    cout << "2) Метод Бойера-Мура" << endl;
    cin >> h;

    if (h == 1) {
        for (int i = 0; i < x; i++) {
            string s = arr[i].name;
            if (KMP(s, search)) {
                cout << "Элемент " << i + 1 << ':' << endl;
                cout << "Имя  \t\t" << arr[i].name << endl;
                cout << "Группа  \t" << arr[i].group << endl;
                cout << "Рейтинг  \t" << arr[i].rang << endl;
                cout << endl;
            }
        }
    }
    if (h == 2) {
        for (int i = 0; i < x; i++) {
            string s = arr[i].name;
            char* txt = &s[0];
            if (BM(txt, cs) == 1) {
                cout << "Элемент " << i + 1 << ':' << endl;
                cout << "Имя  \t\t" << arr[i].name << endl;
                cout << "Группа  \t" << arr[i].group << endl;
                cout << "Рейтинг  \t" << arr[i].rang << endl;
                cout << endl;
            }

        }
        
    }
}
