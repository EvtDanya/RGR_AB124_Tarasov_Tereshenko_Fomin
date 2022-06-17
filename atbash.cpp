//in ascii en: A = 65 Z = 90 a = 97 z = 122, 0 = 48, 9 = 57

#include <iostream>
#include <string>
using namespace std;

string Encrypt6(string cEng) {
	string Crypted = cEng;  //DeCrypted Crypted
	int i = 0; //Crypted position counter		
	while (Crypted[i] != '\0') { //value substitution
		if (cEng[i] >= 65 && cEng[i] <= 90) {
			Crypted[i] = 90 - cEng[i] % 65;
		}
		if (cEng[i] >= 97 && cEng[i] <= 122) {
			Crypted[i] = 122 - cEng[i] % 97;
		}			
		i++;		
	}
	return Crypted;
}
string Decrypt6(string cEng) {
	
	string DeCrypted = cEng;  //DeCrypted Crypted
	int i = 0; //Crypted position counter		
	while (DeCrypted[i] != '\0') { //value substitution
		if (cEng[i] >= 65 && cEng[i] <= 90) {
			DeCrypted[i] = 90 - cEng[i] % 65;
		}
		if (cEng[i] >= 97 && cEng[i] <= 122) {
			DeCrypted[i] = 122 - cEng[i] % 97;
		}
		i++;
	}
	return DeCrypted;
}

int main() {
	string Crypted, cryptedCrypted, decryptedCrypted, key; //original Crypted
	cout << "enter Crypted: ";
	cin >> Crypted;	
	cryptedCrypted = Encrypt6(Crypted);
	cout << cryptedCrypted << endl;
	decryptedCrypted = Decrypt6(cryptedCrypted);
	cout << decryptedCrypted;
}