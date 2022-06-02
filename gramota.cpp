//in ascii en: A = 65 Z = 90 a = 97 z = 122, 0 = 48, 9 = 57

#include <iostream>
#include <string>
using namespace std;

string Encrypt5(string cEng) {
	string Crypted = cEng;  //crypted Crypted
	int i = 0, ii = 0; //Crypted position counter	
	string Alphabet = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
	string cryptoAlphabet = "ZXWVTSRQPNMLKJHGFDCBzxwvtsrqpnmlkjhgfdcb";
	while (Crypted[i] != '\0') { //value substitution		
		for (char symbol : Alphabet) {
			if (cEng[i] == symbol) {
				Crypted[i] = cryptoAlphabet[ii];
			}
			ii++;
		}
		i++;
		ii = 0;
	}
	return Crypted;
}
string Decrypt5(string cEng) {
	string DeCrypted = cEng;  //DeCrypted Crypted
	int i = 0, ii = 0; //Crypted position counter	
	string Alphabet = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
	string cryptoAlphabet = "ZXWVTSRQPNMLKJHGFDCBzxwvtsrqpnmlkjhgfdcb";
	while (DeCrypted[i] != '\0') { //value substitution		
		for (char symbol : Alphabet) {
			if (cEng[i] == symbol) {
				DeCrypted[i] = cryptoAlphabet[ii];
			}
			ii++;
		}
		i++;
		ii = 0;
	}
	return DeCrypted;
}

int main() {
	string Crypted, cryptedCrypted, decryptedCrypted; //original Crypted
	cout << "enter Crypted: ";
	cin >> Crypted;	
	cryptedCrypted = Encrypt4(Crypted);
	cout << cryptedCrypted << endl;
	decryptedCrypted = Decrypt4(cryptedCrypted);
	cout << decryptedCrypted;

}