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
    case (4): {
        cout << '|' << setw(21) << ' ' << "Password entry menu" << setw(22) << "|\n";
    }
    case (5): {
        cout << '|' << setw(17) << ' ' << "Entering the file path menu" << setw(18) << "|\n";
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
void MainMenu(int header, bool lang) {
    system("cls");//clear the screen
    Header(header);
    cout << "Selected language: ";
    if (lang == true) { cout << "\x1b[31mEnglish\x1b[0m\n"; }
    else { cout << "\x1b[31mRussian\x1b[0m\n"; }
    cout << "Press \"1\": \x1b[31mencryption\x1b[0m\n";
    cout << "Press \"2\": \x1b[31mdecryption\x1b[0m\n";
    cout << "Press \"3\": \x1b[31mchange language\x1b[0m\n";
    cout << "Press \"Esc\": \x1b[31mexit the programm\x1b[0m\n";
    Separate();
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
void ChooseLangMenu(int header, bool lang) {
    system("cls"); //  clear screen
    Header(header);
    cout << "Selected language is ";
    if (lang == true) { cout << "\x1b[31mEnglish\x1b[0m\n"; }
    else { cout << "\x1b[31mRussian\x1b[0m\n"; }
    cout << "Press \"1\" for English, \"2\" for Russian or \"Esc\" to return\n";
    Separate();
}
void EntryPswMenu1(int header) {
    system("cls"); //clear screen
    Header(header);
    cout << "Your password must be less than 15 characters\n";
    cout << "Please enter your password >> \n";
    Separate();
}
void EntryPswMenu2() {
    Separate();
    cout << "Confirm your password >> \n";
    Separate();
}
string GetPsw() {
    string passw;
    cin >> passw;
    return passw;
}
bool CheckPsw(string psw1, string psw2) {
    if (psw1 == psw2) { return true; }
    else { return false; }
}
bool PswMenu() {
    EntryPswMenu1(1);
    string psw1 = GetPsw();
    EntryPswMenu2();
    string psw2 = GetPsw();
    Separate();
    return CheckPsw(psw1, psw2);
}
void ChooseFileMenu() {
    system("cls"); //clear screen
    Header(5);
    cout << "The file must have the .txt extension\nSpecify the path to the file with text you need to work with >>\n";
    Separate();
}
string PathToFile() {
    string path;
    cin >> path;
    return path;
}
int main() {
    bool lang = true;
    string pwd1, pwd2; //password and confirmation of password
    while (1) { //for returning to the main menu
    START:
        MainMenu(1, lang);
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
            // check password
            //get text
            //encrypt and write all into txt? file
            case '1': {
                system("cls");//clear the screen
                if (PswMenu() == false) { //different passwords entered
                    cout << "Passwords are different!\nPress any key to return to the main menu";
                    _getch();//waiting for a key to be pressed
                    break;
                }
                else {
                    ChooseFileMenu();
                    PathToFile();
                }
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
            case 27: {break; } //if pressed esc
            default: {//if the wrong key is pressed
                cout << "Incorrect input!\nPress any key to return to the main menu";
                _getch();//waiting for a key to be pressed
                break;
            }
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

            case 27: {break; }//if pressed esc
            default: { //if the wrong key is pressed
                cout << "Incorrect input!\nPress any key to return to the main menu";
                _getch();//waiting for a key to be pressed
                break;
            }
            };
            //get language(if need)
            //get path to file
            //check password
            //decrypt text and output it
            break;
        }
        case '3': {
            ChooseLangMenu(3, lang);
            char choise_lang = _getch();
            switch (choise_lang)
            {
            case '1': {
                lang = true;
                goto START;
                break;
            }
            case '2': {
                lang = false;
                goto START;
                break;
            }
            case 27: {//if pressed esc
                goto START;
                break;
            }
            default: {//if the wrong key is pressed
                cout << "Incorrect input!\nPress any key to return to the main menu";
                _getch();//waiting for a key to be pressed
                break;
            }
            };
        }
        case 27: {//if pressed esc
            Picture();
            return 0;//program shutdown
        }
        default: {//if the wrong key is pressed
            cout << "Incorrect input!\nPress any key to return to the main menu";
            _getch();//waiting for a key to be pressed
            break;
        }
        };
    }
}
