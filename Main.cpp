#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#define canUse "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
using namespace std;
void Separate() {
    cout << "+------------------------------------------------------------+\n";
}
void OutputTextForHeader(int header) { //Stroka menu s viborom teksta
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
    case (3): {//menu for password
        cout << '|' << setw(21) << ' ' << "Password entry menu" << setw(22) << "|\n";
        break;
    }
    case (4): {//menu for path entering
        cout << '|' << setw(20) << ' ' << "File path entry menu" << setw(22) << "|\n";
        break;
    }
    case (5): {//key entering
        cout << '|' << setw(23) << ' ' << "key entry menu" << setw(25) << "|\n";
        break;
    }
    default:
        break;
    };
}
void OutputError(int numboferror) {
    switch (numboferror)
    {
    case (1): { //wrong key is pressed
        cout << "Incorrect input!\nPress any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (2): { //the password was not entered
        cout << "Error! The password must be entered!\nPress any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (3): {//different passwords entered
        cout << "Error! Passwords are different!\nPress any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (4): {//the path was not entered
        cout << "Error! The path must be entered!\nPress any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (5): {//Error opening file
        cout << "Error opening file!\nYou may have specified the path to a non-existent file\nPress any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (6): {//if pressend space
        cout << " You cannot use spaces! Press any key to continue";
        _getch();
        for (int i = 0; i < 49; i++) {
            cout << (char)8 << ' ' << (char)8;
        }
        break;
    }
    case (7): {
        cout << "Error in working with the file!\nPress any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    default:
        break;
    };
}
void Header(int header) {//shapka
    Separate();
    OutputTextForHeader(header);
    Separate();
}
void Picture() { //output picture 
    string str;
    ifstream input;
    input.open("doh.txt");
    system("cls");//clear the screen
    cout << setw(10) << ' ' << "Thanks for using our program!\n";
    while (getline(input, str)) {
        cout << str << endl;
    }
    if (!input.eof()) { //if the file could not be opened
        exit(0);
    }
    input.close();
    Sleep(2000);//wait for 2 seconds
    system("cls");//clear the screen
}
void MainMenu(int header) { //For printing the main menu
    system("cls");//clear the screen
    Header(header);
    cout << "Press \"1\": \x1b[31mencryption\x1b[0m\n"; //output red text with construction \x1b[31m...\x1b[0m
    cout << "Press \"2\": \x1b[31mdecryption\x1b[0m\n"; //output red text
    cout << "Press \"Esc\": \x1b[31mexit the programm\x1b[0m\n"; //output red text
    Separate();
}
void KeyMenu(int header) {//For printing the main menu
    system("cls");//clear the screen
    Header(header);
    cout << "Please enter key for cypher and press \"Enter\"\n"; //output red text with construction \x1b[31m...\x1b[0m
    cout << "The key \x1b[31mmust not contain\x1b[0m spaces!\n";
    cout << "Press \"Backspace\" to delete symbols or press \"Esc\" to return\n";
    Separate();
}
string GetKey(bool& esc) {
    string key;
    int ch = 0; //symbol variable for entering
    while (true)
    {
        ch = _getch(); //put the code of the pressed key in the ch
        if (ch == 13) // Enter - interrupt
        {
            cout << '\n';
            break;
        }
        else if (ch == 27) //Esc return to the main menu
        {
            esc = true;
            break;
        }
        else if (ch == 8) //Backspace - delete symbols
        {
            cout << (char)8 << ' ' << (char)8;
            //offset one symbol to the left, output whitespace instead of a symbol
            //offset one symbol to the left once again 
            //this means that we have deleted the entered symbol
            if (!key.empty()) //if our string is not empty
                key.pop_back(); //delete the last symbol from the string

        }
        else if (ch == 32) {//space - output error
            OutputError(6);
        }
        else //if pressed symbol for password
        {
            cout << (char)ch;  //output * instead of a symbol 
            key += (char)ch;  //Turning a code from an integer(ascii-code) into a symbol 
        }
    }
    return key;
}
string Key(string key, bool& go_out, bool& esc) {
    KeyMenu(5);
    key = GetKey(esc);
    if (esc) { go_out = true; }
    return key;
}
void ChooseCypherMenu(int header) {//for printing the menu with choosing cyphers
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
    cout << "The password \x1b[31mmust not contain\x1b[0m spaces!\n";
    cout << "Press \"Backspace\" to delete symbols or press \"Esc\" to return\n";
    Separate();
}
void EntryPswMenu2() {//Menu for second enter of password to confirm first
    Separate();
    cout << "Confirm your password >> \n";
    Separate();
}
string GetPsw(bool& esc) { //password entry function
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
        else if (ch == 27) //Esc return to the main menu
        {
            esc = true;
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
        else if (ch == 32) {//space - output error
            OutputError(6);
        }
        else //if pressed symbol for password
        {
            cout << '*';  //output * instead of a symbol 
            passw += (char)ch;  //Turning a code from an integer(ascii-code) into a symbol 
        }
    }
    return passw;
}
string Psw(string psw1, string& psw2, bool& go_out, bool& esc) { //Menu with password entering
    EntryPswMenu1(3);
    psw1 = GetPsw(esc); //we get the password through the function
    if (!psw1.empty() && (!esc)) //if the string with password is not empty- continue
    {
        EntryPswMenu2();
        psw2 = GetPsw(esc); //we get the password through the function
        Separate();
    }
    if (esc) { go_out = true; } //if pressed escape- flag for returning
    return psw1;
}
bool CheckPsw(string psw1, string psw2) { //the function checks whether the passwords entered are the same
    if (psw1 == psw2) { return true; }
    else { return false; }
}
/*int FindCurrent(vector <string>& v, string& current) {
    int i;
    for (i = 0; i < v.size(); i++) {
        if (v.at(i) == current) {
            break;
        }
    }
    return i;
}*/
/*bool OriginalityCheck(string check, vector <string> history_path) {
    bool orig = true;
    for (string i : history_path) {
        if (i == check) {
            orig == false;
            break;
        }
    }
    return orig;
}*/
/*string ForArrows(string arrow, int& position, vector <string> history_path) {
    string path;
    if (arrow == "up") {
        if (history_path.size() == 1) { position = 0; }
        else if (position > 0) {
            position--;
        }
        else if (position == 0) {
            position = history_path.size() - 1;
        }
    }
    else if (arrow == "down") {

    }
    return history_path.at(position);
}*/
string GetPath(bool& esc) { //path to file entry function
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
            esc = true;
            break;
        }
        /*if (ch == 224) //Проверка нажатия клавиши
        {
            ch = _getch();
            if (!history_path.empty()) {
                if (ch == 72) {
                    path = ForArrows("up", position, history_path);
                }
                else if (ch == 80) {
                    path = ForArrows("down", position, history_path);
                }
            }
        }*/
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
void EntryPathMenu(int option) { //menu for path entering
    system("cls"); //clear screen
    Header(4);
    cout << "The file must have the .txt extension\n";
    if (option == 1) {
        cout << "Enter the file name (including .txt) and press \"Enter\"\n";
    }
    else {
        cout << "Specify the path to the file and press \"Enter\"\n";
    }
    cout << "Press \"Backspace\" to delete symbols or press \"Esc\" to return\n";
    Separate();
}
string Path(string path/*, vector <string>& history_path, string& current*/, bool& go_out, bool& esc) { //function for getting path to file
    system("cls"); //clear screen
    Header(4);
    cout << "Choose one of the options \n";
    cout << "Press \"1\": the file is located in the same folder with the project\n";
    cout << "Press \"2\": enter the path manually\n";
    Separate();
    char choise_option = _getch();
    switch (choise_option) {
    case '1': {
        EntryPathMenu(1);//calling the menu function
        path = GetPath(esc/*, history_path, current*/);//we get the path through the function
        break;
    }
    case '2': {
        EntryPathMenu(2);//calling the menu function
        path = GetPath(esc/*, history_path, current*/); //we get the path through the function
        break;
    }
    case 27: {//if pressed esc
        go_out = true;
        break;
    }
    default: {//if the wrong key is pressed
        OutputError(1);
        go_out = true;
        break;
    }
    };
    if (path.empty() && (!go_out) && (!esc)) {//if the path is not entered, before that the go_out flag was not activated and escape wasnt pressed
        OutputError(4);
        go_out = true;
    }
    else if (esc) { go_out = true; }//if pressed escape
    //if (OriginalityCheck(path, history_path)) { //for remembering
    //   history_path.push_back(path);
    //}
    return path;
}
/*void OpenFile(const string& path) {
    ifstream ifs(path);
    if (ifs.is_open()) {
        char c = ifs.get();
        while (ifs.good()) {
            cout << c;
            c = ifs.get();
        }
    }
    else {
        OutputError(5);
    }
}*/
vector<string> OpenNReadFile(vector <string> contwithstr, const string& fileName, bool& go_out) {//open file and read strings we need to encrypt
    string str;
    ifstream input;
    input.open(fileName);
    while (getline(input, str)) {
        //str = str + "\n";
        contwithstr.push_back(str);
    }
    if (!input.eof()) { //if the file could not be opened
        OutputError(5);
        go_out = true;
    }
    input.close();
    return contwithstr;
}
struct PswKeyText {
    string password;
    string key;
    vector<string> text;
};
bool OpenNCheck(const string& fileName) {
    bool is_ok = true;

    return is_ok;
}
PswKeyText OpenNReadPswKeyText(PswKeyText pswkeytext, const string& fileName, bool& go_out) {
    string str;
    vector<string> contwithstr;
    ifstream input;
    input.open(fileName);
    while (getline(input, str)) {
        //str = str + "\n";
        contwithstr.push_back(str);
    }
    if (!input.eof()) { //if the file could not be opened
        OutputError(5);
        go_out = true;
    }
    input.close();
    //разделить строку по пробелам и записать в соотв ячейки
    pswkeytext.password = contwithstr[0];
    //записать остальное в вектор

    return pswkeytext;
}
string Encrypt1(string cEng, int key) {//1 cypher
    string cEngCrypted = cEng;  //crypted text
    int i = 0; //text position counter
    while (cEngCrypted[i] != '\0') { //value substitution
        if (cEng[i] >= 65 && cEng[i] <= 90) {
            if ((cEng[i] + key) > 90) { cEngCrypted[i] = (cEng[i] + key) % 90 + 64; }
            else { cEngCrypted[i] = cEng[i] + key; }
        }
        else {
            if ((cEng[i] + key) > 122) { cEngCrypted[i] = (cEng[i] + key) % 122 + 96; }
            else { cEngCrypted[i] = cEng[i] + key; }
        }
        i++;
    }
    return cEngCrypted;
}
vector <string> Encryption(vector <string>& contwithstr, string key, int numbofcyph) {//encryption with the selected cypher
    for (auto i = 0; i < contwithstr.size(); i++) {
        switch (numbofcyph)//depending on the chosen cipher
        {
        case (1): {
            int intkey = atoi(key.c_str());
            contwithstr.at(i) = Encrypt1(contwithstr.at(i), intkey);
            break;
        }
                /*/case (2): {
                    contwithstr.at(i) = Encrypt2(contwithstr.at(i));
                    break;
                }
                case (3): {
                    contwithstr.at(i) = Encrypt3(contwithstr.at(i));
                    break;
                }
                case (4): {
                    contwithstr.at(i) = Encrypt4(contwithstr.at(i));
                    break;
                }
                case (5): {
                    contwithstr.at(i) = Encrypt5(contwithstr.at(i));
                    break;
                }
                case (6): {
                    contwithstr.at(i) = Encrypt6(contwithstr.at(i));
                    break;
                }
                case (7): {
                    contwithstr.at(i) = Encrypt7(contwithstr.at(i));
                    break;
                }
                case (8): {
                    contwithstr.at(i) = Encrypt8(contwithstr.at(i));
                    break;
                }
                case (9): {
                    contwithstr.at(i) = Encrypt9(contwithstr.at(i));
                    break;
                }*/
        default:
            break;
        }
    }
    return contwithstr;
}
string NewPath(int option, string path) {//function for getting a new path to a new file
    for (auto i = 0; i < 4; i++) {//delete ".txt" from name
        path.pop_back();
    }
    if (option == 1) {  //new name for encrypted file
        path = path + "_encrypted.txt";
    }
    if (option == 2) { //new name for the decrypted file
        path = path + "_decrypted.txt";
    }
    return path;
}
void Ofstream(vector <string> contwithstr, const char* fileName, string password, bool needkey, string key, bool& go_out) {//function for writing to a file
    ofstream output; //stream to write
    output.open(fileName); //opening the file for recording
    if (output.is_open())
    {
        if (needkey) {
            output << password << ' ' << key << endl; //writing a password to a file
        }
        else {
            output << password << endl; //writing a password to a file
        }
        for (auto i = 0; i < contwithstr.size(); i++) {//writing encrypted strings to a file
            output << contwithstr.at(i) << endl;
        }
    }
    else { //if it was not possible to write to a file
        OutputError(7);
        go_out = true;
    }
    output.close();
}
void AutoOpen(const char* pathtotxt) {//open with notepad.exe
    system(pathtotxt);
}
void EncryptCase(string& psw, string& psw_confirm, string& path, string& key, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr, int numbofcyph) {
    if (needkey) {
        key = Key(key, go_out, esc);
    }
    if (!go_out) {
        psw = Psw(psw, psw_confirm, go_out, esc);
        if ((psw.empty() || psw_confirm.empty()) && (!go_out)) //if one of the passwords is not entered
        {
            OutputError(2);
        }
        else if ((CheckPsw(psw, psw_confirm) == false) && (!go_out)) { //different passwords entered
            OutputError(3);
        }
        else if (!go_out) {//if successfully
            path = Path(path/*, history_path, current*/, go_out, esc);
            if (!go_out) {//if successfully
                OpenNReadFile(contwithstr, path, go_out);
                if (!go_out) {//if successfully
                    Encryption(contwithstr, key, numbofcyph);
                    string newpath = NewPath(1, path);//get new name and path to this new file from old one
                    const char* b = newpath.c_str(); //its for using autoopen function(system("") dont work with strings)
                    Ofstream(contwithstr, b, psw, needkey, key, go_out);
                    if (!go_out) {//if successfully
                        AutoOpen(b);//open this file with notepad
                        contwithstr.clear();//clear container if we want to work with program again
                    }
                }
            }
        }
    }
}
void EncryptCases(string& psw, string& psw_confirm, string& path, string& key, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr) {
    ChooseCypherMenu(2);
    char choise_cypher = _getch();//waiting for a key to be pressed
    switch (choise_cypher) {//depending on the key pressed
    case '1': {
        needkey = true;//the cipher does not need a key
        EncryptCase(psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr, 1);
        break;
    }
    case '2': {
        needkey = false;//the cipher does not need a key
        EncryptCase(psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr, 1);
        break;
    }
    case '3': {
        needkey = false;//the cipher does not need a key
        EncryptCase(psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr, 1);
        break;
    }
    case '4': {
        needkey = false;//the cipher does not need a key
        EncryptCase(psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr, 1);
        break;
    }
    case '5': {
        needkey = false;//the cipher does not need a key
        EncryptCase(psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr, 1);
        break;
    }
    case '6': {
        needkey = false;//the cipher does not need a key
        EncryptCase(psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr, 1);
        break;
    }
    case '7': {
        needkey = false;//the cipher does not need a key
        EncryptCase(psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr, 1);
        break;
    }
    case '8': {
        needkey = false;//the cipher does not need a key
        EncryptCase(psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr, 1);
        break;
    }
    case '9': {
        needkey = false;//the cipher does not need a key
        EncryptCase(psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr, 1);
        break;
    }
    case 27: { break; } //if pressed esc
    default: {//if the wrong key is pressed
        OutputError(1);
        break;
    }
    };
}
void DecryptCase(string& psw, string& psw_confirm, string& path, string& key, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr, int numbofcyph) {
    //получить путь к файлу
    // проверить на целостность файл(пароль и ключ правильно записаны)
    //ввести с клавы пароль, захешировать и сравнить с тем, Что в файле 
    //
    //с этой же строки взять ключ
    //расшифровать и в новый файл
}
void DecryptCases(string& psw, string& psw_confirm, string& path, string& key, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr) {
    ChooseCypherMenu(2);
    char choise_cypher = _getch();//waiting for a key to be pressed
    switch (choise_cypher) {//depending on the key pressed
    case '1': {


        break;
    }
    case '2': {


        break;
    }
    case '3': {


        break;
    }
    case '4': {


        break;
    }
    case '5': {


        break;
    }
    case '6': {


        break;
    }
    case '7': {


        break;
    }
    case '8': {


        break;
    }
    case '9': {


        break;
    }

    case 27: {break; }//if pressed esc
    default: { //if the wrong key is pressed
        OutputError(1);
        break;
    }
    };
}
void MainMenuCases(string& psw, string& psw_confirm, string& path, string& key, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr) {
    while (1) { //for returning to the main menu
        go_out = false;//if the flags have already been activated, then reset
        esc = false;
        MainMenu(1);
        char choise_from_main_menu = _getch();//waiting for a key to be pressed
        switch (choise_from_main_menu) //depending on the key pressed
        {
        case '1': {
            EncryptCases(psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr);
            break;
        }
        case '2': {
            DecryptCases(psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr);
            break;
        }
        case 27: {//if pressed esc
            Picture();
            exit(0);//program shutdown
        }
        default: {//if the wrong key is pressed
            OutputError(1);
            break;
        }
        };
    }
}
int main() {
    //vector <string> history_path;
    vector <string> contwithstr;
    bool go_out, esc, needkey;//go_out - for errors and break cycles, esc - if pressed escape
    string psw, psw_confirm, path, key; //password and confirmation of password, path to file, history of entering paths
    MainMenuCases(psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr);
}
