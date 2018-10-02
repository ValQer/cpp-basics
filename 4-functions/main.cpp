#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

void tablehead() {
	cout << string(60, '-') << "\n|"
		<< setw(8) << "X" << setw(7)
		<< "|" << setw(12) << "arctg(x)"
		<< setw(3) << "|" << setw(12)
		<< "atan(x)" << setw(3) << "|" << setw(12) 
		<< "Iterations" << setw(3) << "|\n"
		<< string(60, '-') << endl;
}

double NextElement(double x, int n) {

	double CurentN = pow(-1, n + 1) / ((2 * n + 1)*pow(x, 2 * n + 1));

	return CurentN;
}

double arctg(double x, double Eps, int &n) {
	long MAxIters = 10000000;

	double arc1 = 0, arc2 = -M_PI_2;

	for (n = 0; n < MAxIters; n++) {
		arc2 += NextElement(x, n);

		if (abs(arc2 - arc1) < Eps) {
			break;
		}


		if (MAxIters - n < 2) {
			break;
			return 0;
		}

		arc1 = arc2;
	}
	return arc2;
}


int CreateRow(double x, double Eps) {
	int n = 0;
	if (arctg(x, Eps, n) == 0) {
		cout << "ERROR!!!! Too small Eps!!!\n";
		return 0;
		
	}
	else {
		cout << "|" << setw(14) << x
			<< "|" << setw(14) << arctg(x, Eps, n)
			<< "|" << setw(14) << atan(x)
			<< "|" << setw(13) << n << "|\n";
		return 1;
	}
}


int main() {

	double x1, x2, dx, Eps;


	cout << fixed;
	cout << "X must be less than -1\n";
	cout << "Please, enter X (start): ";
	cin >> x1;
	cout << "Please, enter X (end): ";
	cin >> x2;
	cout << "Please, enter dX: ";
	cin >> dx;
	cout << "Please, enter Eps: ";
	cin >> Eps;


	if (dx > 0 && x2 < -1) {

		tablehead();
		for (double x = x1; x <= x2; x += dx) {

			if (CreateRow(x, Eps)) {
				continue;
			}
			else {
				break;
			}

		}
		cout << string(60, '-');

	}

	else {
		cout << "\nInvalid values";
	}

	return 0;
}