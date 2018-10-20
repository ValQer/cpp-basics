#include <iostream>
#include <cmath> 

using namespace std;

void sortArray(double a, double b, int n, double* arr) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a <= (int) arr[i] && (int) arr[i] <= b ) {
			for (int l = i; l > j; l--)
				swap(arr[l], arr[l-1]);
			j++;
		}
	}
}

int main() {
	int n;
	double a, b;
	cout << fixed;

	cout << "Enter N: ";
	cin >> n;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;

	if (n > 0 && a < b) {
		double *arr = new double [n];
		cout << "Enter array: \n";
		bool check = false;
		int first_pos_elem_i;
		for (int i = 0; i < n; i++) {
			cout << "[" << i + 1 << "]";
			cin >> arr[i];
			if (!check && arr[i] > 0) {
				first_pos_elem_i = i;
				check = true;
			}
		}
		int imax = 0;
		double max = arr[0];
		for (int i = 1; i < n; i++) {
			if (abs(arr[i]) > max) {
				max = abs(arr[i]);
				imax = i;
			}
		}
		cout << "Index of the absolute maximum element of the array: " << imax + 1 << endl;

		if (check) {
			double sum = 0;
			for (int i = first_pos_elem_i + 1; i < n; i++) {
				sum += arr[i];
			}
			cout << "Sum after first positive element is: " << sum << endl;
		}
		else 
			cout << "Array doesn't contain any positive elements..." << endl;

		sortArray(a, b, n, arr);
		for (int i = 0; i < n; i++) {
			cout << "[" << i + 1 << "] " << arr[i] << endl;
		}
	}
	else {
		cout << "\nInvalid value of N or (a; b) !!!";
	}
}