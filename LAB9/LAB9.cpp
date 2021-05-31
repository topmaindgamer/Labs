#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	setlocale(0, "rus");
	string line, word1 ;
	int k;

	ifstream file1("F1.txt");
	ofstream file2("F2.txt");

	if (!(file1.is_open() and file2.is_open())) {
		cout << "Один из файлов не открыт";
	}
	else {
		cout << "Файлы читаемы" << endl;
	}

	for (int i = 1; !file1.eof(); i++) {
		getline(file1, word1, ' ');
		getline(file1, line);
		

		cout << "word:" << word1 << endl;
		cout << "line:" << line << endl;
		

		k = line.find(word1 + ' ');

		if (k == -1) {
			cout << "Не найдено" << endl << endl;
		}
		else {
			cout << "Найдено" << endl << endl;
			file2 << word1 + ' ' + line + " \n";
		}
	}

	file1.close();

	int sgl=0;
	line = word1 +' '+ line;
	for (int i = 0; i < size(line); i++) {
		if (line[i] == 'b' || 'c' || 'd' || 'f' || 'g' || 'h' || 'j' || 'k' || 'l' || 'm' || 'n' || 'p' || 'q' || 'r' || 's' || 't' || 'v' || 'w' || 'x' || 'y' || 'z') {
			sgl++;
		}
	}
	cout << "Согласных в последней строке файла F2:" << sgl;

}