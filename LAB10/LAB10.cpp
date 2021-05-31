#include <iostream>
using namespace std;
int main()
{
    system("chcp 1251");
    int size, x;
    cout << "Введите размер массива: "; cin >> size;

    while (size < 1) {
        cout << "Введите корректный размер массива: ";
        cin >> size;
    }

    string* ara = new string[size];

    cout << "Заполните массив" << endl;

    for (int i = 0; i < size; i++) {
        cout << i << ')';
        cin >> ara[i];
    }

    cout << "Введите номер элемента для удаления: "; cin >> x;

    string* araara = new string[size - 1];

    for (int i = 0; i < size ; i++) {
        if (i < x) {
            araara[i] = ara[i];
        }

        if (i > x) {
            araara[i - 1] = ara[i];
        }
    }

    for (int i = 0; i < size-1; i++) {
        cout << i << ')';
        cout << araara[i];
        cout << endl;
    }
}
