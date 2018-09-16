#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
	setlocale(0, "");
	double a, z1, z2;
	double pi = acos(-1.0);
	cout << "¬ведите значение a: \n";
	cin >> a;
	z1 = (sin(4.0 * a) * cos(2.0 * a)) / ((1.0 + cos(4.0 * a)) * (1.0 + cos(2.0 * a)));
	z2 = 1.0 / (tan(2.0 * pi / 3.0 - a));
	cout << z1 << " " << z2 << endl;
	system("pause");
	return 0;

}
