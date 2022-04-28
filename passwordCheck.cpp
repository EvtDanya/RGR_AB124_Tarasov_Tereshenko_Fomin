#include <iostream>
#include <string>
using namespace std;

bool passwordCheck(string passCh, string password) { //проверка пароля перед шифровкой или дешифровкой файла
	if (passCh == password) { return true; }
	return false;
}

int main() {
	string trpassword = "a7", passIncome;
	int flag = -1;
	while (flag == -1) {
		cin >> passIncome;
		if (passwordCheck(passIncome, trpassword) == true) {
			cout << "true";  //тут производится шифровка/дешифровка файла
			flag == 1; //переменная признак после которой после первого удачного ввода пароля выйдет из цикла
		}
		else {
			cout << "пароль неверный, попробуйте снова"<<endl;
		}
	}
}