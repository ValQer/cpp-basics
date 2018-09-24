#include <iostream>
#include <cmath>

using namespace std;

int main() {
	/*
	* Объявляем переменные:
	*   - a задается пользователем;
	*   - z1 и z2 вычисляются по формулам.
	*/
	double a, z1, z2;
	
	cout << "Write a: \n";
	cin >> a;

	// Вычисляем z1 и z2 по заданным формулам.
	z1 = (sin(4 * a) * cos(2 * a)) / ((1 + cos(4 * a)) * (1 + cos(2 * a)));
	z2 = tan(a); // Мат. свойство: ctg(3/2*pi - а) = tg(a)
	
	// Выводим получившиеся значения на экран.
	cout << "z1 = " << z1 << endl;
	cout << "z2 = " << z2 << endl;
	
	return 0;

}
