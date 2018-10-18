#include <iostream>
#include <cmath> 

using namespace std;

void sortArray(double a, double b, int n, double* arr);

void InputValues(double &a, double &b, int &n);

void InputArray(int n, double *arr, bool &check, int &first_pos_elem_i);

void FindMaxElem(int n, double *arr);

void SumAfterFirstPosElem(int n, double *arr, bool check, int first_pos_elem_i);

void PrintArray(int n, double *arr);