#include <iostream>
#include <string>
using namespace std;

bool passwordCheck(string passCh, string password) { //�������� ������ ����� ��������� ��� ����������� �����
	if (passCh == password) { return true; }
	return false;
}

int main() {
	string trpassword = "a7", passIncome;
	int flag = -1;
	while (flag == -1) {
		cin >> passIncome;
		if (passwordCheck(passIncome, trpassword) == true) {
			cout << "true";  //��� ������������ ��������/���������� �����
			flag == 1; //���������� ������� ����� ������� ����� ������� �������� ����� ������ ������ �� �����
		}
		else {
			cout << "������ ��������, ���������� �����"<<endl;
		}
	}
}