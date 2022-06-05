//in ascii en: A = 65 Z = 90 a = 97 z = 122, 0 = 48, 9 = 57

#include <iostream>
#include <string>
using namespace std;

string Encrypt6(string cEng) {
	string Crypted = cEng;  //DeCrypted Crypted
	int i = 0; //Crypted position counter		
	while (Crypted[i] != '\0') { //value substitution			
			Crypted[i] = cEng[cEng.length()-i-1];
		i++;		
	}
	return Crypted;
}
string Decrypt6(string cEng) {
	
	string DeCrypted = cEng;  //DeCrypted Crypted
	int i = 0; //Crypted position counter		
	while (DeCrypted[i] != '\0') { //value substitution			
		DeCrypted[i] = cEng[cEng.length() - i - 1];
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