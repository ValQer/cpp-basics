#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double a, z1, z2; // ��������� ����������,��� a-�������� ���������� �������������, z1 � z2 ���������� ���������� �� ��������.
	
	cout << "������� �������� a: \n";
	cin >> a;

	z1 = (sin(4 * a) * cos(2 * a)) / ((1 + cos(4 * a)) * (1 + cos(2 * a))); // ��������� z1 � z2 �� �������� ��������
	z2 = tan(a); // �� �������������� ������� ctg(270�� - �) = tg(a) 
	
	cout << "z1 = " << z1 << endl; /*������� ������������ �������� �� �����*/
	cout << "z2 = " << z2 << endl;
	
	system("pause");
	return 0;

}
