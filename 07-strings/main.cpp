#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    string file_name;
    cout << "Enter file name: ";
    cin >> file_name;
    ifstream fin(file_name);
    if (!fin.is_open()) {
        cout << "ERROR!!! Can't open file: " << file_name << endl;
        return 1;
    }
    cout << endl;

    string sentence;
    while (getline(fin, sentence, '.')) {
        if (sentence[0] == '\n')
            sentence = sentence.substr(1, sentence.length());

        if (sentence.substr(0, 2) == " -") {
            replace(sentence.begin(), sentence.end(), '\n', ' ');
            cout << sentence << endl;
        }
    }

    fin.close();
    return 0;
}