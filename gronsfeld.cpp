//in ascii en: A = 65 Z = 90 a = 97 z = 122  ru: A = -64 a = -32  = -88 ß = -33 ÿ = -1 ¸= -72
// 0 = 48 9 = 57

#include <iostream>
#include <string>
#include <windows.h>
#include <clocale>
using namespace std;

string Encrypt4(string cEng) {
	string cEngCrypted = cEng;  //crypted text
	int i = 0, ii = 0; //text position counter
	string keyEng;
	cout << "input key for Gronsfeldonly numbers: ";
	cin >> keyEng;
	while (cEngCrypted[i] != '\0') { //value substitution
		if (cEng[i] >= 65 && cEng[i] <= 90) {
			if ((cEng[i] + (int)keyEng[ii] - 48) > 90) {
				cEngCrypted[i] = (cEng[i] + (int)keyEng[ii]) % 90 + 64 - 48;
			}
			else {
				cEngCrypted[i] = cEng[i] + (int)keyEng[ii] - 48;
			}
		}
		else {
			if ((cEng[i] + (int)keyEng[ii] - 48) > 122) {
				cEngCrypted[i] = (cEng[i] + (int)keyEng[ii]) % 122 + 96 - 48;
			}
			else {
				cEngCrypted[i] = cEng[i] + (int)keyEng[ii] - 48;
			}
		}
		ii++;
		i++;
		if (ii == keyEng.length()) { ii = 0; }
	}
	return cEngCrypted;
}
/*string GronsfeldRu(string cRu) {

	//string alphabetRu = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞßàáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ"; //RuAlphabet for cryption

	int i = 0, ii = 0;//text position counter
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
	string text; //original text
	cout << "enter text: ";
	cin >> text;	
	cout << Encrypt4(text); //needs to be converted to work with a file
	

}