#include "func.h"

int main() {
	int n;
	double a, b;
	cout << fixed;

	InputValues(a, b, n);

	if (n > 0 && a < b) {
		double *arr = new double[n];
		bool check = false;
		int first_pos_elem_i;
		
		InputArray(n, arr, check, first_pos_elem_i);

		FindMaxElem(n, arr);

		SumAfterFirstPosElem(n, arr, check, first_pos_elem_i);

		sortArray(a, b, n, arr);

		PrintArray(n, arr);
	}
	else {
		cout << "\nInvalid value of N or (a; b) !!!";
	}
	return 0;
}