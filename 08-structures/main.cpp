#include <iostream>
#include <string>
#define N 8

using namespace std;

struct NOTE
{
	string first_name, second_name;
	string phone_number;
	int birthday[3];
};

void InputPersonalInfo(NOTE *pers_info) {
	for (int i = 0; i < N; i++) {
		cout << "Enter " << i + 1 << " member First Name: ";
		getline(cin, pers_info[i].first_name);
		cout << "Enter " << i + 1 << " member Second Name: ";
		getline(cin, pers_info[i].second_name);
		cout << "Enter " << i + 1 << " member Phone Number(+*-***-***-**-**): ";
		getline(cin, pers_info[i].phone_number);
		cout << "Enter " << i + 1 << " member Birth Day(**): ";
		cin >> pers_info[i].birthday[0];
		cout << "Enter " << i + 1 << " member Birth Month(**): ";
		cin >> pers_info[i].birthday[1];
		cout << "Enter " << i + 1 << " member Birth Year(****): ";
		cin >> pers_info[i].birthday[2];
		cin.ignore();
	}
}

void swapInfo(NOTE *pers_info, int j, int k) {
	if (pers_info[j].birthday[k] > pers_info[j + 1].birthday[k])
		swap(pers_info[j], pers_info[j + 1]);
	else if (pers_info[j].birthday[k] == pers_info[j + 1].birthday[k] && k != 0)
		swapInfo(pers_info, j, k - 1);
}

void SortPersonalInfo(NOTE *pers_info) {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++)
			swapInfo(pers_info, j, 2);
	}
}

void FindMember(string ph_num, NOTE *pers_info) {
	for (int i = 0; i < N; i++) {
		if (pers_info[i].phone_number == ph_num) {
			cout << "\nMember information:\n";
			cout << pers_info[i].first_name << " ";
			cout << pers_info[i].second_name << endl;
			cout << pers_info[i].phone_number << endl;
			cout << pers_info[i].birthday[0] << "."
				<< pers_info[i].birthday[1] << "."
				<< pers_info[i].birthday[2] << endl;
			break;
		}
		else if (i == N - 1)
			cout << "\nPhone Number not found...\n";
	}
}

void EnterNumber(NOTE *pers_info) {
	while (true) {
		string ph_num;
		cout << "\nEnter Phone Nmber(Enter 'exit' to close the program): ";
		getline(cin, ph_num);
		if (ph_num == "exit")
			break;
		else
			FindMember(ph_num, pers_info);
	}
 }

int main() {
	NOTE pers_info[N];
	InputPersonalInfo(pers_info);
	SortPersonalInfo(pers_info);
	EnterNumber(pers_info);
	return 0;
}