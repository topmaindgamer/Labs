#include <iostream>
#include <cstdlib>
#include <string>
#include <List>
#include <iterator>

using namespace std;

list<int> mylist;
list<int> mylist1;

void creat (int size)
{
	
	int b;
	for (int i = 0; i < size; i++)
	{
		
		cout << "введите " << i + 1 << " элемент: ";
		cin >> b;
		mylist.push_back(b);

	}

}

void add()
{
	for (auto iter = mylist.begin(); iter != mylist.end(); iter++) {
		cout << *iter << " ";
		if (*iter % 2 != 0) {
			mylist1.push_back(*iter);
		}
	}
	cout << endl;
}

int main()
{
	system("chcp 1251");
	int size;
	cout << "введите кол-во элементов: ";
	cin >> size;
	while (size <= 0) {

		cout << "введите кол-во элементов: ";
		cin >> size;

	}
	creat(size);
	add();
	cout << "ваш список: " << endl;
	copy(mylist1.begin(), mylist1.end(), ostream_iterator<int>(cout, " "));
	mylist.clear();
	return 0;
}


