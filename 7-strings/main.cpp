#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	string sentence, file_name;

	cout << "Enter file name (*.txt): ";
	getline(cin, file_name);
	ifstream fin(file_name);

	if (!fin.is_open()) {
		cout << "ERROR!!!! Wrong name of file...";
		return 1;
	}
	else {
		while (getline(fin, sentence, '.')) {
			switch (sentence[0]) {
				case '-':
					cout << sentence << endl;
					break;
				case ' ':
					if (sentence[1] == '-')
						cout << sentence << endl;
					break;
			}
		}
		return 0;
	}
}