#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
void Header() {
    cout << "+----------------------------+\n";
    cout << '|' << setw(18) << "Main menu" << setw(12) << "|\n";
    cout << "+----------------------------+\n";
}
string GetPassword() {
    string passw;
    cout << "Enter password";
    cin >> passw;
    return passw;
}
void CheckInput() {

}
int Mode() {
    int mode;
    system("cls"); // очистка экрана
    cout << "What do you want to do?\nEnter '1' for encryption or '2' for decryption";
    cin >> mode;
    return mode;
}
bool CheckLang() {
    int lang;
    system("cls"); // очистка экрана
    cout << "Choose language\nEnter '1' for English or '2' for Russian";
    cin >> lang;
    switch (lang)
    {
    case (1): {
        return true;
        break;
    }
    case (2): {
        return false;
        break;
    }
    default:
        cout << "Incorrect input!";
        break;
    }
}
void ChooseCode() {
    system("cls"); // очистка экрана
    cout << "Choose one of the ciphers\n";
    cout << "1 - " << setw(20) << "4 - " << setw(30) << "7 - \n";
    cout << "2 - " << setw(20) << "5 - " << setw(30) << "8 - \n";
    cout << "3 - " << setw(20) << "6 - " << setw(30) << "9 - \n";
}
void Interface() {
    system("cls"); // очистка экрана
    Header();
    cout << setw(18) << "Hello\n";
    cout << "Enter \"1\" for encryption\nEnter \"2\" for decryption\nPress \"Esc\" to exit the programm\n";
    cout << "+----------------------------+\n";
}
int main() {
    int a;
START:
    Interface();
    cin >> a;
    switch (a)
    {
    case (1): {
        ChooseCode();
        break;
    }
    case (2): {
        ChooseCode();
        break;
    }
    default:
        cout << "Incorrect input!\nPress any key to return to the main menu";
        _getch();
        goto START;
    }
    //system("cls"); // очистка экрана
   //cout << "Hello";
   //int a = Mode();
   //switch (a) {
   //case (1): {
   //    cout << "Encr";
   //    break;
   //}
   //case (2): {
   //    cout << "Decr";
   //    break;
   //}
   //default: 
   //    cout << "Incorrect input!";
   //}
}