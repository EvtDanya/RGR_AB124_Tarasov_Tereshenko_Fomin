#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;
void Separate() {
    cout << "+------------------------------------------------------------+\n";
}
void OutTextForHeader(int header) { //Stroka menu s viborom teksta
    switch (header)
    {
    case (1): { //main menu
        cout << '|' << setw(26) << ' ' << "Main menu" << setw(27) << "|\n";
        break;
    }
    case (2): { //cipher selection menu
        cout << '|' << setw(20) << ' ' << "Cipher selection menu" << setw(21) << "|\n";
        break;
    }
    case (3): { //language selection menu
        cout << '|' << setw(19) << ' ' << "Language selection menu" << setw(20) << "|\n";
        break;
    }
    default:
        break;
    };
}
void Header(int header) {//shapka
    Separate();
    OutTextForHeader(header);
    Separate();
}
void Picture() { //output picture 
    char a[255];
    ifstream F;
    F.open("doh.txt"); //open file with picture(must be in the same folder with the .cpp)
    system("cls");//clear the screen
    cout << setw(10) << ' ' << "Thanks for using our program!\n";
    while (!F.eof())
    {
        F.getline(a, sizeof(a));
        cout << a << "\n";
    }
    Sleep(2000);//wait for 2 seconds
    system("cls");//clear the screen
}
void ChooseCypherMenu(int header) {
    system("cls"); //clear the screen
    Header(header);
    cout << "1 - " << setw(20) << "4 - " << setw(30) << "7 - \n";
    cout << "2 - " << setw(20) << "5 - " << setw(30) << "8 - \n";
    cout << "3 - " << setw(20) << "6 - " << setw(30) << "9 - \n";
    cout << "Press the cypher number or press \"Esc\" to return\n";
    Separate();
}
void ChooseLangMenu(int header) {
    system("cls"); //  clear screen
    Header(header);
    cout << "Press '1' for English or '2' for Russian\n";
    Separate();
}
//bool CheckLang() {
//    bool lang;
//    lang = _getch();
//    switch (lang) {
//    case '1': {lang = true; }
//    case '2': {lang = false; }
//    case 27: { }
//    }
//    
//    return lang;
//}
void  MainMenu(int header) {
    system("cls");//clear the screen
    Header(header);
    cout << "Press \"1\" for encryption\nPress \"2\" for decryption\nPress \"Esc\" to exit the programm\n";
    Separate();
}
string GetPassword() {
    string passw;
    cout << "Enter password";
    cin >> passw;
    return passw;
}
int main() {
START: //for returning to the main menu
    MainMenu(1);
    char choise_from_main_menu, choise_cypher;
    choise_from_main_menu = _getch();//waiting for a key to be pressed
    switch (choise_from_main_menu) //depending on the key pressed
    {
    case '1': {
        ChooseCypherMenu(2);
        choise_cypher = _getch();//waiting for a key to be pressed
        switch (choise_cypher) {//depending on the key pressed
        //get language(if need) +
        //get password
        //get text
        //encrypt and write all into txt? file
        case '1': {
            system("cls");//clear the screen
            ChooseLangMenu(3);
            break;
        }
        case '2': {
            system("cls");//clear the screen

            break;
        }
        case '3': {
            system("cls");//clear the screen

            break;
        }
        case '4': {
            system("cls");//clear the screen

            break;
        }
        case '5': {
            system("cls");//clear the screen

            break;
        }
        case '6': {
            system("cls");//clear the screen

            break;
        }
        case '7': {
            system("cls");//clear the screen

            break;
        }
        case '8': {
            system("cls");//clear the screen

            break;
        }
        case '9': {
            system("cls");//clear the screen

            break;
        }
        case 27: {goto START; } //if pressed esc
        default: {//if the wrong key is pressed
            cout << "Incorrect input!\nPress any key to return to the main menu";
            _getch();//waiting for a key to be pressed
            goto START; }
        };
        break;
    }
    case '2': {
        ChooseCypherMenu(2);
        choise_cypher = _getch();//waiting for a key to be pressed
        switch (choise_cypher) {//depending on the key pressed
        case '1': {
            system("cls");//clear the screen
            break;
        }
        case '2': {
            system("cls");//clear the screen

            break;
        }
        case '3': {
            system("cls");//clear the screen

            break;
        }
        case '4': {
            system("cls");//clear the screen

            break;
        }
        case '5': {
            system("cls");//clear the screen

            break;
        }
        case '6': {
            system("cls");//clear the screen

            break;
        }
        case '7': {
            system("cls");//clear the screen

            break;
        }
        case '8': {
            system("cls");//clear the screen

            break;
        }
        case '9': {
            system("cls");//clear the screen

            break;
        }

        case 27: {goto START; }//if pressed esc
        default: { //if the wrong key is pressed
            cout << "Incorrect input!\nPress any key to return to the main menu";
            _getch();//waiting for a key to be pressed
            goto START; }
        };
        //get language(if need)
        //get path to file
        //check password
        //decrypt text and output it
        break;
    }
    case 27: {//if pressed esc
        Picture();
        return 0;//program shutdown
    }
    default: {//if the wrong key is pressed
        cout << "Incorrect input!\nPress any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        goto START;
    }
    };
}