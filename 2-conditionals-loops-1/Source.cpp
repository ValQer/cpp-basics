#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	double a, b, c, X1, X2, dX, F;
	cout << "Please, Enter a, b, c: ";
	cin >> a >> b >> c;
	cout << "Please, Enter Xstart, Xend, dX: ";
	cin >> X1 >> X2 >> dX;

	cout << "------------------------------------\n"; 
	cout << "|" << setw(9) << "X" << setw(9)
		 << "|" << setw(9) << "F" << setw(9)<< "|\n";
	cout << "------------------------------------\n";

	if (((int)a | (int)b) & (int)c) {
		cout << "yes";
	}
	else {
		cout << "not";
	}

	system("pause");
	return 0;
}