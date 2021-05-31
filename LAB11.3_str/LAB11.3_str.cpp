#include <iostream>

using namespace std;


struct st
{
    char data;
    st *past;
};


st* make(int size) 
{
    st * up;
    up = new st;
    cout << "Введите значение 1 элемента : ";
    cin >> up->data;
    up->past = NULL;
    for (int i = 2; i <= size; i++) {
        st* zzz = new st;
        cout << "Введите значение " << i << " элемента : "; 
        cin >> zzz->data;
        zzz->past = up;
        up = zzz;
    }
    
    return up;
}


void print(st* stack) 
{
    cout << endl;
    st* time = stack;
    while (time->past != NULL) {
        cout << time->data << endl;
        time = time->past;
    }
    cout << time->data << endl << endl;
}


st* add_el(st* stack) 
{
    char el0;
    cout << "Введите искомое информационное поле : "; cin >> el0;

    char el1;
    cout << "Введите символ для добавления : "; cin >> el1;

    st* up_time = NULL;
    st* time = stack;
    while (time->past != NULL) {
        
        if (time->data == el0) {
            st* new_el = new st;
            new_el->data = el1;
            new_el->past = time;
            up_time->past = new_el;
            break;
        }
        up_time = time;
        time = time->past;
        
    }

    return(stack);
}


int main()
{
    setlocale(LC_ALL, "RUS");

    int size;
    cout << "Введите количество элементов стека : "; cin >> size;

    st* mystack = make(size);

    print(mystack);

    st* mystack1 = add_el(mystack);

    print(mystack1);
}
