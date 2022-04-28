//in ascii en: A = 65 Z = 90 a = 97 z = 122  ru: а для русского придется строку соответствий делать
#include <iostream>
#include <string>
using namespace std;

string ceasarEng(string cEng) {
	string cEngCrypted = cEng;  //crypted text
	int i = 0; //text position counter
	int keyEng;
	cout << "input key for ceasar: ";
	cin >> keyEng;
	while (cEngCrypted[i] != '\0') {
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
//string ceasarRu(string cRu) {}
int main() {
	bool lang = true; //opredelyaets'a v fynktsii vibora yazika
	string text; //original text
	int key; //key for ceasar 
	cout << "enter text: ";
	cin >> text;
	switch (lang) //language definitions
	{
	case true: {
		cout << ceasarEng(text); //needs to be converted to work with a file
	}
	case false: {
	}
	}
}