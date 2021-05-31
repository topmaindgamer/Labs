#include <iostream>

using namespace std;

struct List {
	int data ;
	List* next;
	List* prev;
};

List* make(int size) {

	if (size <= 0) {
		cout << "список не может быть создан" << endl;
		return 0;
	}

	List* first, * p;
	first = NULL;
	p = new List;
	cout << "введите 1 элемент: ";
	cin >> p->data;
	p->next = NULL;
	p->prev = NULL;
	first = p;

	for (int i = 2; i <= size; i++) {
		List* h = new List;
		List* q = p;
		p->next = h;
		p = p->next;
		cout << "введите " << i << " элемент: ";
		cin >> p->data;
		p->next = NULL;
		p->prev = q;
	}

	return first;
}

void print(List* first) {
	if (first == NULL)
		cout << "список пустой\n";
	else {
		List* p = first;
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}

void del(List* first)
{
	List* p = first;
	while (p->next != NULL) {
		if (p->data % 2 == 0) {
			if (p->prev != NULL) {
				List* m = p->prev;
				m->next = p->next;
				p = p->next;
			}
		}
		else {
			p = p->next;
		}
	}

	if (p->data % 2 == 0) {
		List* m = p->prev;
		m->next = p->next;
		p = p->next;
	}
	else {
		p = p->next;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int size;
	cout << "введите количество элементов: ";
	cin >> size;
	List* list = make(size);
	print(list);
	del(list);
	print(list);
	return 0;
}


