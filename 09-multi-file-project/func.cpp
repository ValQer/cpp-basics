#include "func.h"

void sortArray(double a, double b, int n, double* arr) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a <= (int)arr[i] && (int)arr[i] <= b) {
			for (int l = i; l > j; l--)
				swap(arr[l], arr[l - 1]);
			j++;
		}
	}
}

void InputValues(double &a, double &b, int &n) {
	cout << "Enter N: ";
	cin >> n;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
}

void InputArray(int n, double *arr, bool &check, int &first_pos_elem_i) {
	cout << "Enter array: \n";
	for (int i = 0; i < n; i++) {
		cout << "[" << i + 1 << "]";
		cin >> arr[i];
		if (!check && arr[i] > 0) {
			first_pos_elem_i = i;
			check = true;
		}
	}
}

void FindMaxElem(int n, double *arr) {
	int imax = 0;
	double max = arr[0];
	for (int i = 1; i < n; i++) {
		if (abs(arr[i]) > max) {
			max = abs(arr[i]);
			imax = i;
		}
	}
	cout << "Index of the absolute maximum element of the array: " << imax + 1 << endl;
}

void SumAfterFirstPosElem(int n, double *arr, bool check, int first_pos_elem_i) {
	if (check) {
		double sum = 0;
		for (int i = first_pos_elem_i + 1; i < n; i++)
			sum += arr[i];
		cout << "Sum after first positive element is: " << sum << endl;
	}
	else
		cout << "Array doesn't contain any positive elements..." << endl;
}

void PrintArray(int n, double *arr) {
	for (int i = 0; i < n; i++)
		cout << "[" << i + 1 << "] " << arr[i] << endl;
}