//in ascii en: A = 65 Z = 90 a = 97 z = 122  ru: À = -64 à = -32 ¨ = -88 ß = -33 ÿ = -1 ¸= -72
#include <iostream>
#include <string>
#include <windows.h>
#include <clocale>
#include <math.h>
using namespace std;

string ceasarEng(string cEng) {
	string cEngCrypted = cEng;  //crypted text
	int i = 0; //text position counter
	int keyEng;
	cout << "input key for ceasar: ";
	cin >> keyEng;
	while (cEngCrypted[i] != '\0') { //value substitution
		if (cEng[i] >= 65 && cEng[i] <= 90) {
			if ((cEng[i] + keyEng) > 90) { cEngCrypted[i] = (cEng[i] + keyEng) % 90 + 64; }
			else { cEngCrypted[i] = cEng[i] + keyEng; }
		}
		else {
			if ((cEng[i] + keyEng) > 122) { cEngCrypted[i] = (cEng[i] + keyEng) % 122 + 96; }
			else { cEngCrypted[i] = cEng[i] + keyEng; }
		}
		i++;
	}
	return cEngCrypted;
}
string ceasarRu(string cRu) {

	//string alphabetRu = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞßàáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ"; //RuAlphabet for cryption

	int i = 0, keyRu;//text position counter
	char;
	cout << "input key for ceasar: ";
	cin >> keyRu; //key for ceasarRu

	while (cRu[i] != '\0') {

		if (cRu[i] >= -64 && cRu[i] <= -33) {
			if ((cRu[i] + keyRu) > -33) { cRu[i] = (-cRu[i] + keyRu) % 33 - 65; }
			else { cRu[i] = cRu[i] + keyRu; }
		}
		else {
			if ((cRu[i] < 0) && ((cRu[i] + keyRu) > -1)) { cRu[i] = (-cRu[i] + keyRu) % 33 - 34; }
			else { cRu[i] = cRu[i] + keyRu; }
		}
		i++;

		/*posInRu = -1;  //test version if RuCeasar
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
		}*/

	}
	return cRu;
}
int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool lang = false; //opredelyaets'a v fynktsii vibora yazika
	string text; //original text

	cout << "enter text: ";
	cin >> text;
	if (lang == true) //language definitions
	{
		cout << ceasarEng(text); //needs to be converted to work with a file
	}
	else {
		cout << ceasarRu(text);
	}

}