#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

void error(double X) {
	cout << "|" << setw(17) << X << "|"
		<< setw(16) << "ERROR / 0" << "|\n";
	cout << string(36, '-') << endl;
}

int main() {
	/*
	* - Объявляем переменные
	* - Просим пользователя ввести исходные данные
	*/
	double a, b, c, X1, X2, dX, F;
	cout << "Please, Enter a, b, c: ";
	cin >> a >> b >> c;
	cout << "Please, Enter X.start, X.end, dX: ";
	cin >> X1 >> X2 >> dX;

	/*
	* Проверяем корректность шага функции,
	* во избежание образования бесконечного цикла
	*/
	if (dX > 0) {
		// Создаем шапку таблицы
		cout << string(36,'-') << endl;
		cout << "|" << setw(9) << "X" << setw(9)
			 << "|" << setw(9) << "F" << setw(9) << "|\n";
		cout << string(36,'-') << endl;

		/*
		* Выводим на экран таблицу и заполняем
		* её значениями, вычисленными по заданным
		* формулам
		*/
		for (double x = X1; x <= X2; x += dX) {
			if (x < 0.6 && b + c != 0) {
				F = a * pow(x, 3) + pow(b, 2) + c;
			}
			else if (x > 0.6 && b + c == 0) {
				if (x - c != 0) {
					F = (x - a) / (x - c);
				}
				else {
					error(x);
					continue;
				}
			}
			else {
				if (c != 0 && a != 0) {
					F = x / c + x / a;
				}
				else {
					error(x);
					continue;
				}
			}
			if ((((int)a | (int)b) & (int)c) == 0) {
				cout << "|" << setw(17) << x << "|"
					<< setw(16) << (int)F << "|\n";
				cout << string(36, '-') << endl;
			}
			else {
				cout << "|" << setw(17) << x << "|"
					<< setw(16) << F << "|\n";
				cout << string(36, '-') << endl;
			}
		}
	}
	else {
		cout << "Incorrect value of dX!!!";
	}
	system("pause");
	return 0;
}