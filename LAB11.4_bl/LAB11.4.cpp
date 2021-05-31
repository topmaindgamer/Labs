#include<iostream>
#include<queue>
using namespace std;


void print(queue<int> qu, int s)
{
	int* arr = new int[s];

	for (int i = 0; i < s; i++)
	{
		arr[i] = qu.front();
		cout << qu.front() << " ";
		qu.pop();
	}

	for (int i = 0; i < s; i++)
		qu.push(arr[i]);
	cout << endl;
}


int main()
{
	setlocale(0, "");

	cout << "введите количество элементов в очереди: ";
	int s1;
	cin >> s1;

	queue<int> qu1;
	cout << "Введите элементы" << endl;
	for (int i = 0; i < s1; i++)
	{
		int a;
		cin >> a;
		qu1.push(a);
	}

	cout << "Ваша очередь: ";
	print(qu1, s1);


	
	queue<int> qu2;

	for (int i = 0; i < s1; i++) {
		if (qu1.front() % 2 != 0) {
			
			qu2.push(qu1.front());
			qu1.pop();
		}
		else
		{
			qu1.pop();
		}
	}
	cout << endl;

	int s2 = qu2.size();

	cout << "Новая очередь ";
	print(qu2, s2);

	return 0;
}
