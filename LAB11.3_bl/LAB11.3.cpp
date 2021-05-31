#include <iostream>
#include <stack>
using namespace std;



void creat(stack<char> st) {
	char a;
	int n;
	cout << "введите количество элементов стека: ";
	cin >> n;
	cout << "введите элементы стека: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		st.push(a);
		cout << "st.top = " << st.top()<< endl;
	}
}


void print(stack<char> st) {
	int lol = st.size();
	for (int i = 0; i < lol; i++) {
		cout << st.top() << endl;
		st.pop();
	}
}


int main()
{
	setlocale(0, "");
	stack<char> st1;
	stack<char> st2;
	char a;
	int n;
	cout << "введите количество элементов стека: ";
	cin >> n;
	cout << "введите элементы стека: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		st1.push(a);
	}
	cout << "стек: " << endl;
	print(st1);

	char isk;
	cout << "Введите искомый элемент: " << endl;
	cin >> isk;
	
	char el;
	cout << "Введите элемент: ";
	cin >> el;

	for (int i = 0; i < n; i++) {
		if (st1.top() != isk) {
			st2.push(st1.top());
			st1.pop();
		}
		else {
			st2.push(el);
			st2.push(st1.top());
			st1.pop();
		}
	}

	for (int i = 0; i < st1.size(); i++) {
		st1.pop();
	}
	int z = st2.size();
	for (int i = 0; i < z; i++) {
		st1.push(st2.top());
		st2.pop();
	}

	print(st1);

}