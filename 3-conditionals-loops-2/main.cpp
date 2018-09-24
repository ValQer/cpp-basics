#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	double X1, X2, dX, E;
	long MAxIters = 10000000;

	cout << fixed;
	cout << "X must be less than -1\n";
	cout << "Please, enter X (start) and X (end): ";
	cin >> X1 >> X2;
	cout << "Please, enter dX and E: ";
	cin >> dX >> E;

	if (dX > 0 && X2 < -1) {
		cout << string(60, '-') << "\n|"
			<< setw(8) << "X" << setw(7)
			<< "|" << setw(12) << "arctg(x)"
			<< setw(3) << "|" << setw(12)
			<< "atan(x)" << setw(3) << "|" << setw(12) << "Iterations" << setw(3) << "|\n"
			<< string(60, '-') << endl;
		for (double x = X1; x <= X2; x += dX) {
			double arc1 = 0, arc2 = -3.14159265359 / 2;
			for (int n = 0; n < MAxIters; n++) {
				arc2 += pow(-1, n + 1) / ((2 * n + 1)*pow(x, 2 * n + 1));
				if (abs(abs(arc1) - abs(arc2)) < E) {
					cout << "|" << setw(14) << x 
						<< "|" << setw(14) << arc2 << "|" << setw(14) << atan(x)
						<< "|" << setw(13) << n << "|\n";
					break;
				}
				if (MAxIters - n < 2) {
					cout << "ERROR!!!! Too small E!!!\n";
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