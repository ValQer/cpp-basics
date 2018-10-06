#include <iostream>
#include <cmath> 

using namespace std;

void sortArray(double a, double b, int n, double* arr) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a <= (int) arr[i] && (int) arr[i] <= b ) {
			swap(arr[j], arr[i]);
			j++;
		}
	}
}

int main() {
	int n, imax = 0;
	double max, a, b, sum = 0;
	cout << fixed;

	cout << "Enter N: ";
	cin >> n;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;


	if (n >= 0 && a < b) {
		double *arr = new double [n];
		cout << "Enter array: \n";
		for (int i = 0; i < n; i++) {
			cout << "[" << i + 1 << "]";
			cin >> arr[i];
		}

		max = arr[0];
		for (int i = 1; i < n; i++) {
			if (abs(arr[i]) > max) {
				max = abs(arr[i]);
				imax = i;
			}
		}
		cout << "Number of maximum element: " << imax + 1 << endl;


		bool check = false;
		for (int i = 0; i < n; i++) {
			if (arr[i] > 0) 
				check = true;
			if (check) 
				sum += arr[i];
		}
		if (check)
			cout << "Sum after first positive element is: " << sum << endl;
		else 
			cout << "Array doesn't contain positive elements...." << endl;


		sortArray(a, b, n, arr);
		for (int i = 0; i < n; i++) {
			cout << "[" << i + 1 << "] " << arr[i] << endl;
		}
	}
	else {
		cout << "\nInvalid value of N or (a; b) !!!";
	}
}