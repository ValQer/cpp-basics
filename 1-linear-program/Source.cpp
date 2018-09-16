#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double a, z1, z2; // объявляем переменные,где a-значение задаваемое пользователем, z1 и z2 результаты вычислений по формулам.
	
	cout << "Введите значение a: \n";
	cin >> a;

	z1 = (sin(4 * a) * cos(2 * a)) / ((1 + cos(4 * a)) * (1 + cos(2 * a))); // Вычисляем z1 и z2 по заданным формулам
	z2 = tan(a); // Из математических свойств ctg(270гр - а) = tg(a) 
	
	cout << "z1 = " << z1 << endl; /*Выводим получившиеся значения на экран*/
	cout << "z2 = " << z2 << endl;
	
	system("pause");
	return 0;

}
