#include <iostream>
#include <string>
using namespace std;

bool passwordCheck(string passCh, string password) { //proverka parol'ya gthtl shifrovkoy/deshifrovkoy
	if (passCh == password) { return true; }
	return false;
}

int main() {
	string trpassword = "a7", passIncome;//zadayom parol'
	int flag = -1;
	while (flag == -1) {
		cin >> passIncome;
		if (passwordCheck(passIncome, trpassword) == true) {
			cout << "true";  //tyt proizvodit'cya shifrovka/deshifrovka
			flag == 1; //peremennaya priznak
		}
		else {
			cout << "password is wrong, try again"<<endl;
		}
	}
}