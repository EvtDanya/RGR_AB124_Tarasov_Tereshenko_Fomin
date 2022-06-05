//in ascii en: A = 65 Z = 90 a = 97 z = 122, 0 = 48, 9 = 57

#include <iostream>
#include <string>
using namespace std;

string Encrypt6(string cEng, string keyEng) {
	string Crypted = cEng;  //DeCrypted Crypted
	int i = 0; //Crypted position counter		
	while (Crypted[i] != '\0') { //value substitution			
			Crypted[i] = cEng[i]^keyEng[i%keyEng.length()];						
		i++;		
	}
	return Crypted;
}
string Decrypt6(string cEng, string keyEng) {
	string DeCrypted = cEng;  //DeCrypted Crypted
	int i = 0; //Crypted position counter	
	while (DeCrypted[i] != '\0') { //value substitution				
			DeCrypted[i] = cEng[i] ^ keyEng[i % keyEng.length()];
		i++;
	}
	return DeCrypted;
}

int main() {
	string Crypted, cryptedCrypted, decryptedCrypted, key; //original Crypted
	cout << "enter Crypted: ";
	cin >> Crypted;
	cout << "input key for Vernam: ";
	cin >> key;
	cryptedCrypted = Encrypt6(Crypted, key);
	cout << cryptedCrypted << endl;
	decryptedCrypted = Decrypt6(cryptedCrypted, key);
	cout << decryptedCrypted;
}