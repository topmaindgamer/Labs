#include <iostream>
using namespace std;


struct list
{
	int info;
	list* next;
};


list* first = NULL;
list* last = NULL;


list* make( int size ) 
{
	list* time = new list;
	first = time;
	last = time;
	cout << "Введите значение 1 элемента : ";
	cin >> time->info;
	time->next = NULL;
	for (int i = 2; i <= size; i++) {
		list* z = new list;
		cout << "Введите значение " << i << " элемента : ";
		cin >> z->info;
		time->next = z;
		time = z;
		last = time;
	}
	
	time->next = NULL;
	return(first);
}


void print(list* mylist)
{
	list* time = mylist;

	while (time != NULL) {
		cout << time->info << endl;
		time = time->next;
	}
	cout << "first=" << first->info << endl;
	cout << "last=" << last->info << endl;
}


list* del(list* mylist) 
{
	list* time = mylist;



	while (time->info % 2 == 0) {
		mylist = time->next;
		first = time->next;
		time = time->next;
	}
	
	
	list* x = time;
	list* x1 = time->next;
	
	while (x1 != NULL) {
		if (x1->info % 2 == 0) {
			x1 = x1->next;
			x->next = x1;
		}
		else {
			x1 = x1->next;
			x = x->next;
		}

	}
	last->info = x->info;
	
	return mylist;
}


int main()
{
	setlocale(LC_ALL, "rus");

	int size;
	cout << "Введите количество элементов в очереди : "; cin >> size;
	
	
	list* mylist = make(size);

	print(mylist);

	list* mylist1 = del(mylist);

	print(mylist1);

	





}
