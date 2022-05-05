#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
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
    case (4): {//menu for password
        cout << '|' << setw(21) << ' ' << "Password entry menu" << setw(22) << "|\n";
    }
    case (5): {//menu for path entering
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
void MainMenu(int header) {
    system("cls");//clear the screen
    Header(header);
    cout << "Press \"1\": \x1b[31mencryption\x1b[0m\n"; //output red text with construction \x1b[31m...\x1b[0m
    cout << "Press \"2\": \x1b[31mdecryption\x1b[0m\n"; //output red text
    cout << "Press \"Esc\": \x1b[31mexit the programm\x1b[0m\n"; //output red text
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
void EntryPswMenu1(int header) { //Menu for first enter of password
    system("cls"); //clear screen
    Header(header);
    cout << "Please enter your password and press \"Enter\"\n";
    cout << "Press \"Backspace\" to delete symbols or press \"Esc\" to return\n";
    Separate();
}
void EntryPswMenu2() {//Menu for second enter of password to confirm first
    Separate();
    cout << "Confirm your password >> \n";
    Separate();
}
string GetPsw() { //password entry function
    string passw;
    int ch = 0; //symbol variable for entering
    while (true)
    {
        ch = _getch(); //put the code of the pressed key in the ch
        if (ch == 13) // Enter - interrupt
        {
            cout << '\n';
            break;
        }
        else if (ch == 27) //Esc return to main menu
        {
            break;
        }
        else if (ch == 8) //Backspace - delete symbols
        {
            cout << (char)8 << ' ' << (char)8;
            //offset one symbol to the left, output whitespace instead of a symbol
            //offset one symbol to the left once again 
            //this means that we have deleted the entered symbol
            if (!passw.empty()) //if our string is not empty
                passw.pop_back(); //delete the last symbol from the string

        }
        else //if pressed symbol for password
        {
            cout << '*';  //output * instead of a symbol 
            passw += (char)ch;  //Turning a code from an integer into a symbol 
        }
    }
    return passw;
}
string Psw(string psw1, string& psw2) { //Menu with password entering
    EntryPswMenu1(1);
    psw1 = GetPsw();
    EntryPswMenu2();
    psw2 = GetPsw();
    Separate();
    return psw1;
}
bool CheckPsw(string psw1, string psw2) { //the function checks whether the passwords entered are the same
    if (psw1 == psw2) { return true; }
    else { return false; }
}
string GetPath() { //path to file entry function
    string path;
    int ch = 0; //symbol variable for entering
    while (true)
    {
        ch = _getch(); //put the code of the pressed key in the ch
        if (ch == 13) // Enter - interrupt
        {
            cout << '\n';
            break;
        }
        else if (ch == 27) //Esc return to main menu
        {
            break;
        }
        else if (ch == 8) //Backspace - delete symbols
        {
            cout << (char)8 << ' ' << (char)8;
            //offset one symbol to the left, output whitespace instead of a symbol
            //offset one symbol to the left once again 
            //this means that we have deleted the entered symbol
            if (!path.empty()) //if our string is not empty
                path.pop_back(); //delete the last symbol from the string
        }
        else
        {
            cout << (char)ch;       //output of the symbol that was entered
            path += (char)ch;       //Turning a code from an integer into a symbol
        }
    }
    return path;
}
void EntryPathMenu() { //menu for path entering
    system("cls"); //clear screen
    Header(5);
    cout << "The file must have the .txt extension\nSpecify the path to the file with text you need to work with\n";
    Separate();
}
string Path() { //function for getting path to file
    EntryPathMenu();
    string path = GetPath();
    return path;
}
void OpenFile(string path) {

}
int main() {
    string psw1, psw2, path; //password and confirmation of password
    while (1) { //for returning to the main menu
        MainMenu(1);
        char choise_from_main_menu, choise_cypher;
        choise_from_main_menu = _getch();//waiting for a key to be pressed
        switch (choise_from_main_menu) //depending on the key pressed
        {
        case '1': {
            ChooseCypherMenu(2);
            choise_cypher = _getch();//waiting for a key to be pressed
            switch (choise_cypher) {//depending on the key pressed
            //get password+
            //check password+
            //get path to txt file+
            //Если пароль не ввели или путь вернуться в главное меню
            //encrypt and write with password into new txt file
            case '1': {
                system("cls");//clear the screen
                psw1 = Psw(psw1, psw2);
                if (CheckPsw(psw1, psw2) == false) { //different passwords entered
                    cout << "Passwords are different!\nPress any key to return to the main menu";
                    _getch();//waiting for a key to be pressed
                    break;
                }
                else {
                    path = Path();

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
