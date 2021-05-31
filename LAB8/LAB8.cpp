#include <iostream>
#include <string>
using namespace std;


struct Auto
{
    string mark;
    int num;
    int reg;
    int year;
};


void print(int skolko,Auto a[]) 
{
    
    for (int i = 0; i < skolko; i++)
    {
        int j = i + 1;
        cout << "№" << j << endl;
        cout << "Марка: " << a[i].mark << endl;
        cout << "Номер: " << a[i].num << endl;
        cout << "Регестрационный номер: " << a[i].reg << endl;
        cout << "Год: " << a[i].year << endl << endl;
    }
    for (int k = 0; k < 30; k++) {
        cout << "-";
    }
    cout << endl;

}


void del(int skolko, Auto a[]) 
{
    cout << "Удалим 3 элемента из начала" << endl << endl;
    for (int i = 3; i<skolko ; i++) {
        a[i - 3] = a[i];
    }
}


void add(int skolko, Auto a[])
{
    int p;
    cout << "Введите номер после которого добавить элемент" << endl; cin >> p; p--;
    Auto* last;
    int ls_s = skolko + 1;
    last = new Auto[ls_s];
    
    for (int i = 0; i < ls_s; i++) {
        if (i <= p) {
            last[i] = a[i];
        }
        if (i > p + 1) {
            last[i] = a[i - 1];
        }
    }

    delete[] a;

    cout << "Введите марку машины:"; cin >> last[p+1].mark;
    cout << "Введите номер машины машины:"; cin >> last[p+1].num;
    cout << "Введите регестрационный номер машины:"; cin >> last[p+1].reg;
    cout << "Введите год выпуска машины:"; cin >> last[p+1].year;

    cout << endl;

    print(ls_s, last);
}


int main()
{
    setlocale(LC_ALL, "Rus");


    cout << "Если вы хотите ввести информацию сами введите 1" << endl;
    cout << "Если вы воспользоваться готовой базой введите 2" << endl;


    int zxc; cin >> zxc;
    while (zxc != 1 && zxc != 2) {
        cout << "Некорректное значение" << endl;
        cin >> zxc;
    }

    
    switch (zxc)
    {
    case 1:

        int comeback;
        cout << "Введите количество машин" << endl; cin >> comeback;

        while (comeback < 4) {
            cout << "Пожалуйста, для дальнейших операций введите хотя бы 4 машины " << endl;
            cin >> comeback;
        }

        Auto* a;
        a = new Auto[comeback];

        for (int i = 0; i < comeback; i++) {
            cout << "Введите марку автомобиля" << endl;
            cin >> a[i].mark;
            cout << "Введите номер автомобиля " << endl;
            cin >> a[i].num;
            cout << "Введите регистрационный номер автомобиля " << endl;
            cin >> a[i].reg;
            cout << "Введите год выпуска автомобиля " << endl;
            cin >> a[i].year;
            cout << endl;
        }

        print(comeback,a);

        del(comeback,a);
        Auto* b;
        b = new Auto[comeback - 3];
        for (int i = 0; i < comeback - 3; i++) {
            b[i] = a[i];
        }
        delete[] a;

        print(comeback-3, b);

        add(comeback-3,b);

        break;

    case 2:

        Auto * a1;
        int cb = 7;
        a1 = new Auto[cb];

        a1[0].mark = "BMW";
        a1[0].num = 856412;
        a1[0].reg = 00321512;
        a1[0].year = 2011;

        a1[1].mark = "Volkswagen";
        a1[1].num = 124783;
        a1[1].reg = 0053224;
        a1[1].year = 2014;

        a1[2].mark = "Toyota";
        a1[2].num = 589013;
        a1[2].reg = 00561342;
        a1[2].year = 2013;

        a1[3].mark = "Honda";
        a1[3].num = 908142;
        a1[3].reg = 00325753;
        a1[3].year = 2007;

        a1[4].mark = "Ford";
        a1[4].num = 894120;
        a1[4].reg = 00712512;
        a1[4].year = 1991;

        a1[5].mark = "Fiat";
        a1[5].num = 182591;
        a1[5].reg = 00134576;
        a1[5].year = 2021;

        a1[6].mark = "Nissan";
        a1[6].num = 125893;
        a1[6].reg = 00235715;
        a1[6].year = 1999;

        print(cb,a1);
        
        del(cb,a1);
        Auto* b1;
        int b1_size = cb - 3;
        b1 = new Auto[b1_size];

        for (int i = 0; i < b1_size; i++) {
            b1[i] = a1[i];
        }
        delete[] a1;

        print(b1_size, b1);

        add(b1_size, b1);

        break;
    }
}