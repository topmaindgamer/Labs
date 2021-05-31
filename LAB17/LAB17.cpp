
#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>

using namespace std;

struct person
{
	string surname;
	string name;
	string patronymic;
	string birthday;
	string passport;
	person* next = NULL;
};

int Hash_task(int key, int size)
{
	double intptr;

	modf(size * (modf((double)key * 0.6180339887, &intptr)), &intptr); //хеш-функция
	return intptr;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int data, size = -1, adress, error = 0;
	person x, * p = nullptr, * q;
	string user_search;

	while (size < 2 || size>100)
	{
		cout << "Введите размер таблицы\n";
		cin >> size;
	}
	const int N = size;

	cin.get();
	person* key = new person[size];

	for (int i = 0; i < size; i++)
	{
		key[i].surname = '0';
		key[i].name = '0';
		key[i].patronymic = '0';
		key[i].birthday = '0';
		key[i].passport = '0';
		key[i].next = NULL;
	}

	for (int i = 0; i < N; i++)
	{
		cout << "surname:\n";
		cin >> x.surname;
		cout << "name:\n";
		cin >> x.name;
		cout << "patronymic:\n";
		cin >> x.patronymic;
		cout << "birthday:\n";
		cin >> x.birthday;
		cout << "passport:\n";
		cin >> x.passport;
		cin.ignore();
		x.next = NULL;
		int date = stoi(x.birthday);
		adress = Hash_task(date, N);

		while (adress >= size || key[size - 1].surname != "0")
		{
			person* key_new = new person[size * 2];

			for (int i = 0; i < size; i++)
			{
				key_new[i].surname = key[i].surname;
				key_new[i].name = key[i].name;
				key_new[i].patronymic = key[i].patronymic;
				key_new[i].birthday = key[i].birthday;
				key_new[i].passport = key[i].passport;
				key_new[i].next = key[i].next;
			}

			for (int i = size; i < size * 2; i++)
			{
				key_new[i].surname = '0';
				key_new[i].name = '0';
				key_new[i].patronymic = '0';
				key_new[i].birthday = '0';
				key_new[i].passport = '0';
				key_new[i].next = NULL;
			}

			delete[] key;
			key = key_new;
			size++;
		}
		if (key[adress].surname != "0" && key[adress].next == NULL)
		{
			p = key[adress].next;
			p = new person;
			*p = x;
			key[adress].next = p;
			error++;
		}
		else if (key[adress].next != NULL)
		{
			p = key[adress].next;
			q = p;
			while (p != NULL)
			{
				q = p;
				p = p->next;
			}
			p = new person;
			*p = x;
			q->next = p;
			error++;
		}
		else
		{
			key[adress] = x;
		}
	}

	int k;
	int j;
	cout << "\nХэш-таблица : " << endl << endl;
	for (int i = 0; i < size; i++)
	{
		k = 1;
		p = key[i].next;
		if (key[i].surname != "0")
		{
			cout << "ФИО            - " << key[i].surname << " " << key[i].name << " " << key[i].patronymic << endl;
			cout << "Дата рождения  - " << key[i].birthday << endl;
			cout << "Номер паспорта - " << key[i].passport << endl << endl;
		}
		while (p != NULL)
		{
			if (p->surname != "0")
			{
				j = k;
				while (j > 0) { cout << "     "; j--; } cout << "ФИО: " << p->surname << " " << p->name << " " << p->patronymic << endl;
				j = k;
				while (j > 0) { cout << "     "; j--; } cout << "Дата рождения: " << p->birthday << endl;
				j = k;
				while (j > 0) { cout << "     "; j--; } cout << "Номер паспорта: " << p->passport << endl << endl;
			}
			p = p->next;
			k++;
		}
	}
	cout << "Таблица создана. Коллизий: " << error << endl;
	cout << "Введите запрос ( Дату рождения ) \n";
	getline(cin, x.birthday);
	int date = stoi(x.birthday);
	adress = Hash_task(date, N);
	p = &key[adress];
	bool flag = false;

	while (p != NULL)
	{
		if (p->birthday == x.birthday)
		{
			cout << "\nОбъект найден:\n";
			cout << "Фио: " << p->surname << " " << p->name << " " << p->patronymic << endl;
			cout << "Дата рождения: " << p->birthday << endl;
			cout << "Номер паспорта: " << p->passport << endl;
			flag = true;
		}
		p = p->next;
	}
	cin.get();
	return 0;
}
