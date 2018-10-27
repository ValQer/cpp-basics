#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Delete_Rows(int &rows, int cols, double** arr) {
	for (int i = 0; i < rows; i++) {
		bool is_null = false;

		// Проверяем строку на наличие отличных от нуля элементов
		for (int j = 0; j < cols; j++) {
			const double eps = 1e-15;
			if (abs(arr[i][j]) < eps)
				is_null = true;
			else {
				is_null = false;
				break;
			}
		}

		/* Если строка состоит только из нулевых элементов
		Переносим ее в конец и сокращаем число строк на 1 */
		if (is_null) {
			for (int l = i; l < rows - 1; l++) {
				for (int j = 0; j < cols; j++)
					swap(arr[l][j], arr[l + 1][j]);
			}
			i--; // Перепроверяем строку массива, т.к. она изменилась после сортировки
			rows -= 1;
		}
	}
}

void Delete_Cols(int rows, int &cols, double** arr) {
	for (int i = 0; i < cols; i++) {
		bool is_null = false;

		// Проверяем столбец на наличие отличных от нуля элементов
		for (int j = 0; j < rows; j++) {
			const double eps = 1e-15;
			if (abs(arr[j][i]) < eps)
				is_null = true;
			else {
				is_null = false;
				break;
			}
		}

		/* Если столбец состоит только из нулевых элементов
		Переносим его в конец и сокращаем число столбцов на 1 */
		if (is_null) {
			for (int l = i; l < cols - 1; l++) {
				for (int j = 0; j < rows; j++)
					swap(arr[j][l], arr[j][l + 1]);
			}
			i--; // Перепроверяем столбец массива, т.к. он изменился после сортировки
			cols -= 1;
		}
	}
}

int Find_Row(int rows, int cols, double** arr) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (arr[i][j] > 0)
				return i + 1;
		}
	}
	return 0;
}

int main() {
	int rows, cols;
	
	/*
	* Вводим количесто строк и столбцов
	* в нашей матрице
	*/
	cout << fixed;
	cout << "Number of rows: ";
	cin >> rows;
	cout << "\nNumber of cols: ";
	cin >> cols;
	cin.ignore();

	if (rows > 0 && cols > 0) {
		// Создаем двумерный динамический массив
		double **arr = new double*[rows];
		for (int i = 0; i < rows; i++)
			arr[i] = new double[cols];

		// Вводим имя файла, содержащего нашу матрицу
		string file_name;
		cout << "Enter file name (*.txt): ";
		getline(cin, file_name);

		ifstream matrix(file_name);

		// Проверяем открытие файла
		if (!matrix.is_open())
			cout << "ERROR!!!! Wrong name of file...";
		else {
			// Вводим значения матрицы в массив
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) 
					matrix >> arr[i][j];
			}
			matrix.close();

			// Удаляем нулевые строки и столбцы
			Delete_Rows(rows, cols, arr);
			Delete_Cols(rows, cols, arr);

			// Выводим массив на экран
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++)
					cout << arr[i][j] << "\t";
				cout << endl;
			}

			// Выводим информацию о первой строке содержащей положительный элемент
			int first_row_with_pos_element = Find_Row(rows, cols, arr);
			if (!first_row_with_pos_element)
				cout << "\n Array doesn't contain any positive elements...\n";
			else
				cout << "\n The number of the first row containing the positive element: " << first_row_with_pos_element;
		}
	}
	else
		cout << "\n Invalid value of rows(cols)....";
	return 0;
}