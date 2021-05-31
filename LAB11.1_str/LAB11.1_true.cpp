#include <iostream>
using namespace std;

struct point
{

    char inf;
    point* next;

};

point* make(int size) {

    point* first, * p;
    first = NULL;
    p = new point;
    cout << "Введите 1 элемент ";
    cin >> p->inf;
    first = p;

    for (int i = 1; i < size; i++) 
    {

        point* h = new point;
        p->next = h;
        p = p->next;
        cout << "Введите " << i + 1 << " элемент ";
        cin >> p-> inf;
        p->next = NULL;

    }

    return first;

}

void print(point* first) {

    if (first == NULL) {

        cout << "список пустой\n";

    }
    else {

        point* p = first;
        while (p != NULL) {

            cout << p->inf << " ";
            p = p->next;

        }
        cout << endl;

    }

}

void add(point* first)
{
    int num;
    cout << "Введите номер добавляемого элемента: ";
    cin >> num;
    while (num < 0)
    {
        cout << "Некорректный ввод. Попробуйте ещё раз: ";
        cin >> num;
    }

    point* a;
    a = first;
    int i = 2;
    while (i < num)
    {
        a = a->next;
        i++;
    }
    point* e = a->next;
    point* z = new point;
    a->next = z;
    z->next = e;
    cout << "Введите добавляемый элемент: ";
    cin >> z->inf;
}



int main()
{

    setlocale(LC_ALL, "RUS");
    int size;
    cout << "Введите количество элементов: ";  cin >> size;
    while (size <= 0) {

        cout << "Введите количество элементов: ";  cin >> size;

    }
    point* first = make(size);
    cout << "Ваш сипсок: ";
    print(first);
    add(first);
    print(first);
    
}