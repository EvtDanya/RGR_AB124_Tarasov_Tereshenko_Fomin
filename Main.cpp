#include <iostream>
#include <iomanip>
using namespace std;

string GetPassword() {
    string passw;
    cout << "Enter password";
    cin >> passw;
    //if () {}
    //else
    return passw;
}
void CheckInput() {

}
bool Mode() {
    bool mode;
    cout << "What do you want to do?\nEnter '1' for encryption or '2' for decryption";
    cin >> mode;
    return mode;
}
bool CheckLang() {
    int lang;
    cout << "Choose language\nEnter '1' for English or '2' for Russian";
    cin >> lang;
    if (lang == 1) { return true; }
    else if (lang == 2) { return false; }
    else { CheckInput(); }
}
void Interface(bool lang) {
    cout << setw(20) << "Hello\n";
    cout << "The selected language is ";
    if (lang == 1) { cout << "English"; }
    else { cout << "Russian"; }
    //clrscr();
    //cout << "";
}
int main() {
    bool lang = 1;
    Interface(lang);
}