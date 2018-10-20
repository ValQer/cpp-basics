#include <iostream>
#include <fstream>
#include <string>
#define N 10

using namespace std;

template <class type>
void Delete_Rows(int &rows, int cols, type (&arr)[N][N]) {
	for (int i = 0; i < rows; i++) {
		bool is_null = false;
		for (int j = 0; j < cols; j++) {
			const double eps = 1e-15;
			if (abs(arr[i][j]) < eps)
				is_null = true;
			else {
				is_null = false;
				break;
			}
		}
		if (is_null) {
			for (int l = i; l < rows - 1; l++) {
				for (int j = 0; j < cols; j++)
					swap(arr[l][j], arr[l + 1][j]);
			}
			i--;
			rows--;
		}
	}
}

template <class type>
void Delete_Cols(int rows, int &cols, type (&arr)[N][N]) {
	for (int i = 0; i < cols; i++) {
		bool is_null = false;
		for (int j = 0; j < rows; j++) {
			const double eps = 1e-15;
			if (abs(arr[j][i]) < eps)
				is_null = true;
			else {
				is_null = false;
				break;
			}
		}
		if (is_null) {
			for (int l = i; l < cols - 1; l++) {
				for (int j = 0; j < rows; j++)
					swap(arr[j][l], arr[j][l + 1]);
			}
			i--;
			cols--;
		}
	}
}

template <class type>
void InputMatrix(type (&arr)[N][N]) {
	while (true) {
		string file_name;
		cout << "Enter file name(*.txt): ";
		getline(cin, file_name);
		ifstream fin(file_name);

		if (!fin.is_open())
			cout << "Wrong name of file...\n";
		else {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++)
					fin >> arr[i][j];
			}
			fin.close();
			break;
		}
	}
}

template <class type>
void PrintMatrix(int rows, int cols, type(&arr)[N][N]) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
}

template <class type>
void Find_Row(int rows, int cols, type (&arr)[N][N]) {
	int first_row_with_pos_element = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (arr[i][j] > 0)
				first_row_with_pos_element = i + 1;
		}
		if (first_row_with_pos_element != 0) {
			cout << "The number of the first row containing the positive element: " << first_row_with_pos_element;
			break;
		}
	}
	if (first_row_with_pos_element == 0)
		cout << "Array doesn't contain any positive elements...\n";
}

int main() {
	while (true) {
		char type;
		cout << "Select type(1 - int, 2 - float, 3 - double, e - to close the program): ";
		cin >> type;
		cin.ignore();

		int rows = N, cols = N;
		switch (type) {
			case 'e':
				return 1;
			case '1': {
				int arr[N][N];
				InputMatrix(arr);
				Delete_Rows(rows, cols, arr);
				Delete_Cols(rows, cols, arr);
				PrintMatrix(rows, cols, arr);
				Find_Row(rows, cols, arr);
				return 0;
			}
			case '2': {
				float arr[N][N];
				InputMatrix(arr);
				Delete_Rows(rows, cols, arr);
				Delete_Cols(rows, cols, arr);
				PrintMatrix(rows, cols, arr);
				Find_Row(rows, cols, arr);
				return 0;
			}
			case '3': {
				double arr[N][N];
				InputMatrix(arr);
				Delete_Rows(rows, cols, arr);
				Delete_Cols(rows, cols, arr);
				PrintMatrix(rows, cols, arr);
				Find_Row(rows, cols, arr);
				return 0;
			}
			default:
				cout << "ERROR...Enter correct character.....\n";
		}
	}
}