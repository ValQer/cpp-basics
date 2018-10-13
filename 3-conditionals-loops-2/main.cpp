#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	double X1, X2, dX, Eps;
	const int kMaxIters = 10000000;

	cout << fixed;
	cout << "X must be less than -1\n";
	cout << "Please, enter X (start): ";
	cin >> X1;
	cout << "Please, enter X (end): ";
	cin >> X2;
	cout << "Please, enter dX: ";
	cin >> dX;
	cout << "Please, enter Eps: ";
	cin >> Eps;

	if (dX > 0 && X1 < X2 && X2 < -1 && Eps > 0) {

		cout << string(60, '-') << "\n|"
			<< setw(8) << "X" << setw(7)
			<< "|" << setw(12) << "arctg(x)"
			<< setw(3) << "|" << setw(12)
			<< "atan(x)" << setw(3) << "|" << setw(12) << "Iterations" << setw(3) << "|\n"
			<< string(60, '-') << endl;

		for (double x = X1; x <= X2; x += dX) {

			double arc1 = 0, arc2 = -M_PI_2;

			for (int n = 0; n < kMaxIters; n++) {

				arc2 += pow(-1, n + 1) / ((2 * n + 1)*pow(x, 2 * n + 1));

				if (abs(arc2 - arc1) < Eps) {
					cout << "|" << setw(14) << x
						<< "|" << setw(14) << arc2 << "|" << setw(14) << atan(x)
						<< "|" << setw(13) << n << "|\n";
					break;
				}

				if (kMaxIters - n < 2) {
					cout << "ERROR!!!! Too small Eps!!!\n";
					return 2;
				}

				arc1 = arc2;
			}
		}
		cout << string(60, '-');
	}

	else {
		cout << "\nInvalid values";
	}

	return 0;
}