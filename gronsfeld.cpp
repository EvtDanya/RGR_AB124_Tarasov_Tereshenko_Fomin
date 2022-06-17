//in ascii en: A = 65 Z = 90 a = 97 z = 122  ru: A = -64 a = -32  = -88 ß = -33 ÿ = -1 ¸= -72
// 0 = 48 9 = 57

#include <iostream>
#include <string>
using namespace std;

string Encrypt4(string cEng, string keyEng) {
	string Crypted = cEng;  //crypted Crypted
	int i = 0, ii = 0; //Crypted position counter	
	while (Crypted[i] != '\0') { //value substitution		
		if (cEng[i] >= 65 && cEng[i] <= 90) {
			Crypted[i] = 64 + abs((cEng[i] + (int)keyEng[ii] - 48 - 64)) % 26;
		}
		else if (cEng[i] >= 97 && cEng[i] <= 122) {
			Crypted[i] = 96 + abs((cEng[i] + (int)keyEng[ii] - 48 - 96)) % 26;
		}
		ii++;
		i++;
		if (ii == keyEng.length()) { ii = 0; }
	}
	return Crypted;
}
string Decrypt4(string cEng, string keyEng) {
	string DeCrypted = cEng;  //DeCrypted Crypted
	int i = 0, ii = 0; //Crypted position counter	
	while (DeCrypted[i] != '\0') { //value substitution
		if (cEng[i] >= 65 && cEng[i] <= 90) {
			DeCrypted[i] = 90 - abs((cEng[i] - (int)keyEng[ii] + 48 - 90)) % 26;
		}
		else if (cEng[i] >= 97 && cEng[i] <= 122) {
			DeCrypted[i] = 122 - abs((cEng[i] - (int)keyEng[ii] + 48 - 122)) % 26;
		}
		ii++;
		i++;
		if (ii == keyEng.length()) { ii = 0; }
	}
	return DeCrypted;
}
/*string GronsfeldRu(string cRu) {

	//string alphabetRu = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿ"; //RuAlphabet for cryption

	int i = 0, ii = 0;//Crypted position counter
	string keyRu;
	cout << "input key for Gronsfeld(only numbers): ";
	cin >> keyRu; //key for GronsfeldRu

	while (cRu[i] != '\0') {

		if (cRu[i] >= -64 && cRu[i] <= -33) {
			if ((cRu[i] + (int)keyRu[ii] - 48) > -33) {
				cRu[i] = (-cRu[i] + (int)keyRu[ii]) % 33 - 65 - 48;
			}
			else {
				cRu[i] = cRu[i] + (int)keyRu[ii] - 48;
			}
		}
		else {
			if ((cRu[i] < 0) && ((cRu[i] + (int)keyRu[ii] - 48) > -1)) {
				cRu[i] = (-cRu[i] + (int)keyRu[ii]) % 33 - 34 - 48;
			}
			else {
				cRu[i] = cRu[i] + (int)keyRu[ii] - 48;
			}
		}
		ii++;
		if (ii == keyRu.length()) { ii = 0; }
		i++;

		/*posInRu = -1;  //test version of RuGronsfeld
		for (int t = 0; t < 66; t++) { //search for a value in the Ru alphabet
			if (cRu[i] == alphabetRu[t]) {
				posInRu = t;
				break;
			}
		}
		if (posInRu == -1) { cRu[i] = cRu[i] + keyRu; }
		if (posInRu >= 0 && posInRu <= 32) { // value substitution
			if ((posInRu + keyRu) > 32) { cRu[i] = alphabetRu[(posInRu + keyRu) % 32 - 1]; }
			else { cRu[i] = alphabetRu[posInRu + keyRu]; }
		}
		else {
			if ((posInRu + keyRu) > 65) { cRu[i] = alphabetRu[(posInRu + keyRu) % 65 - 1]; }
			else { cRu[i] = alphabetRu[posInRu + keyRu]; }
		}

	}
	return cRu;
}*/
int main() {
	string Crypted, cryptedCrypted, decryptedCrypted; //original Crypted
	cout << "enter Crypted: ";
	cin >> Crypted;
	string key;
	cout << "input key for Gronsfeldonly numbers: ";
	cin >> key;
	cryptedCrypted = Encrypt4(Crypted, key);
	cout << cryptedCrypted << endl;
	decryptedCrypted = Decrypt4(cryptedCrypted, key);
	cout << decryptedCrypted;

}