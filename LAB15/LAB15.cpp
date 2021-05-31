#include <iostream>
using namespace std;


struct BUS
{
    int num;
    int longg;
};


void Hoar(BUS mas[], int first, int last) 
{
    int mid, count;
    int f = first, l = last;
    mid = mas[(f + l) / 2].longg; 
    do
    {
        while (mas[f].longg < mid) f++;
        while (mas[l].longg > mid) l--;
        if (f <= l) 
        {
            count = mas[f].longg;
            mas[f].longg = mas[l].longg;
            mas[l].longg = count;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) Hoar(mas, first, l);
    if (f < last) Hoar(mas, f, last);
}


void Shell(BUS A[], int n) 
{
    int d = n;
    d = d / 2;
    while (d > 0)
    {
        for (int i = 0; i < n - d; i++)
        {
            int j = i;
            while (j >= 0 && A[j].longg > A[j + d].longg)
            {
                int count = A[j].longg;
                A[j] = A[j + d];
                A[j + d].longg = count;
                j--; 
            }
        }
        d = d / 2;
    }
}

void Print(int kol, BUS Bus[]) 
{
    for (int i = 0; i < kol; i++) {
        cout << endl;
        cout << i + 1 << ") Маршрут #" << Bus[i].num << " c длинной маршрута " << Bus[i].longg;
    }
}


int main()
{
    

    setlocale(LC_ALL, "RUS");

    int kol;
    cout << "Введите колличество маршрутов автобуса:"; cin >> kol;
    BUS* Bus = new BUS[kol];
    for (int i = 0; i < kol; i++) {
        cout << endl;
        cout << "Введите " << i + 1 << " номер маршрута: #"; cin >> Bus[i].num;
        cout << "Введите " << i + 1 << " длинну маршрута: "; cin >> Bus[i].longg;
    }
    cout << endl;


    short sort;
    cout << "Введите метод сортировки: " << endl; 
    cout << "1) Метод Хоара" << endl;
    cout << "2) Метод Шелла" << endl;
    cin >> sort;
    switch (sort)
    {
    case 1:
        Hoar(Bus,0,kol-1);
        break;
    case 2:
        Shell(Bus,kol);
        break;
    default:
        cout << "Введите коректный номер:"; cin >> sort;
        break;
    }
    
    Print(kol, Bus); 

    
}
