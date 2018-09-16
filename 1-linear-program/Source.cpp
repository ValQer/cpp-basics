#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a, z1, z2; /*
	Объявляем переменные,где a-значение задаваемое пользователем,
	а z1 и z2 результаты вычислений по формулам.
	*/
	
	cout << "Write a: \n";
	cin >> a;

	z1 = (sin(4 * a) * cos(2 * a)) / ((1 + cos(4 * a)) * (1 + cos(2 * a)));
	z2 = tan(a); // Из математических свойств ctg(270гр - а) = tg(a) 
	// Вычисляем z1 и z2 по заданным формулам
	
	cout << "z1 = " << z1 << endl;
	cout << "z2 = " << z2 << endl;

	/*Выводим получившиеся значения на экран*/
	
	return 0;

}
