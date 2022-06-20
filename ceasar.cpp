#include <iostream>
#include <string>
#include <windows.h>
#include <clocale>
#include <math.h>
using namespace std;
string ceasarEng(string cEng, int keyEng) {
	string cEngCrypted = cEng;  //crypted text
	int i = 0; //text position counter

	while (cEngCrypted[i] != '\0') { //value substitution
		if (cEng[i] >= 65 && cEng[i] <= 90) {
			if ((cEng[i] + keyEng) > 90) { cEngCrypted[i] = (cEng[i] + keyEng) % 90 + 64; }
			else { cEngCrypted[i] = cEng[i] + keyEng; }
		}
		else if (cEng[i] >= 97 && cEng[i] <= 122) {
			if ((cEng[i] + keyEng) > 122) { cEngCrypted[i] = (cEng[i] + keyEng) % 122 + 96; }
			else { cEngCrypted[i] = cEng[i] + keyEng; }
		}
		else if (cEng[i] >= 48 && cEng[i] <= 57) {
			if ((cEng[i] + keyEng) > 57) { cEngCrypted[i] = (cEng[i] + keyEng) % 57 + 48; }
			else { cEngCrypted[i] = cEng[i] + keyEng; }
		}
		i++;
	}
	0 = 48 9 = 57

	return cEngCrypted;
}
string DeceasarEng(string cEng, int keyEng) {
	string cEngDeCrypted = cEng;  //crypted text
	int i = 0; //text position counter

	while (cEngDeCrypted[i] != '\0') { //value substitution
		if (cEng[i] >= 65 && cEng[i] <= 90) {
			if ((cEng[i] - keyEng) < 65) {
				cEngDeCrypted[i] = 91 - abs((cEng[i] - keyEng - 65)) % 26;
			}
			else {
				cEngDeCrypted[i] = cEng[i] - keyEng;
			}
		}
		else if (cEng[i] >= 97 && cEng[i] <= 122) {
			if ((cEng[i] - keyEng) < 97) {
				cEngDeCrypted[i] = 123 - abs((cEng[i] - keyEng - 97)) % 26;
			}
			else {
				cEngDeCrypted[i] = cEng[i] - keyEng;
			}
		}
		else if (cEng[i] >= 48 && cEng[i] <= 57) {
			if ((cEng[i] + keyEng) < 48) { 
				cEngDeCrypted[i] = (cEng[i] + keyEng) % 57 + 48; }
			else { cEngDeCrypted[i] = 58 - abs((cEng[i] - keyEng - 48))%10; }
		}
		i++;
	}
	return cEngDeCrypted;
}

	int main() {
		string Crypted, cryptedCrypted, decryptedCrypted; //original Crypted
		cout << "enter Crypted: ";
		cin >> Crypted;
		int key;
		cin >> key;
		cryptedCrypted = ceasarEng(Crypted,key);
		cout << cryptedCrypted << endl;
		decryptedCrypted = DeceasarEng(cryptedCrypted,key);
		cout << decryptedCrypted;
	}
	