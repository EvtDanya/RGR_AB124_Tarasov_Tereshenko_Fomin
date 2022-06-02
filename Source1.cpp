//in ascii en: A = 65 Z = 90 a = 97 z = 122, 0 = 48, 9 = 57

#include <iostream>
#include <string>
using namespace std;

string Encrypt4(string cEng, string keyEng) {
	string Crypted = cEng;  //crypted Crypted
	int i = 0, counter = 0; //Crypted position counter	
	string Alphabet = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
	string cryptoAlphabet = "ZXWVTSRQPNMLKJHGFDCBzxwvtsrqpnmlkjhgfdcb";
	while (Crypted[i] != '\0') { //value substitution		

		counter++;
		i++;
		if (counter == keyEng.length()) { i = 0; }
	}
	return Crypted;
}
string Decrypt4(string cEng, string keyEng) {
	string DeCrypted = cEng;  //DeCrypted Crypted
	int i = 0, ii = 0; //Crypted position counter	
	while (DeCrypted[i] != '\0') { //value substitution

		ii++;
		i++;
		if (ii == keyEng.length()) { ii = 0; }
	}
	return DeCrypted;
}

int main() {
	string Crypted, cryptedCrypted, decryptedCrypted; //original Crypted
	cout << "enter Crypted: ";
	cin >> Crypted;
	string key;
	cryptedCrypted = Encrypt4(Crypted, key);
	cout << cryptedCrypted << endl;
	decryptedCrypted = Decrypt4(cryptedCrypted, key);
	cout << decryptedCrypted;

}