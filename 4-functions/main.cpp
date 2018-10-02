#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

double X() {
	double x;
	cout << "X must be less than -1\n";
	cout << "Please, enter X (start): ";
	cin >> x;
	return x;
}

double Eps() {
	double Eps;
	cout << "Please, enter Eps: ";
	cin >> Eps;
	return Eps;
}

double X2() {
	double x2;
	cout << "Please, enter X (end): ";
	cin >> x2;
	return x2;
}

double dX() {
	double dx;
	cout << "Please, enter dX: ";
	cin >> dx;
	return dx;
}

void tablehead() {
	cout << string(60, '-') << "\n|"
		<< setw(8) << "X" << setw(7)
		<< "|" << setw(12) << "arctg(x)"
		<< setw(3) << "|" << setw(12)
		<< "atan(x)" << setw(3) << "|" << setw(12) << "Iterations" << setw(3) << "|\n"
		<< string(60, '-') << endl;
}

int tableString(double x, double Eps) {
	long MAxIters = 10000000;

	double arc1 = 0, arc2 = -M_PI_2;

	for (int n = 0; n < MAxIters; n++) {

		arc2 += pow(-1, n + 1) / ((2 * n + 1)*pow(x, 2 * n + 1));

		if (abs(arc2 - arc1) < Eps) {
			cout << "|" << setw(14) << x
				<< "|" << setw(14) << arc2 << "|" << setw(14) << atan(x)
				<< "|" << setw(13) << n << "|\n";
			break;
			return 1;
		}


		if (MAxIters - n < 2) {
			cout << "ERROR!!!! Too small Eps!!!\n";
			break;
			return 0;
		}

		arc1 = arc2;
	}
}

void tablebody(double X1, double X2, double dX, double Eps) {

	for (double x = X1; x <= X2; x += dX) {

		if (tableString(x, Eps)) {
			continue;
		}
		else {
			break;
		}

	}
}

void table(double Eps, double dX, double X2, double X1) {
	
	cout << fixed;
	
	if (dX > 0 && X2 < -1) {

		tablehead();
		tablebody(X1,X2,dX,Eps);
		cout << string(60, '-');
		
	}

	else {
		cout << "\nInvalid values";
	}

}

int main() {
	table(Eps(), dX(), X2(), X());

	return 0;
}