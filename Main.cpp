#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include<map>
#include "sha256.h" 
using namespace std;
struct PswKeyText {
    string password;
    string key;
    vector<string> text;
};
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
        cout << '|' << setw(23) << ' ' << "Key entry menu" << setw(25) << "|\n";
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
        cout << " You cannot use such symbol! Press any key to continue";
        _getch();
        for (int i = 0; i < 54; i++) {
            cout << (char)8 << ' ' << (char)8;
        }
        break;
    }
    case (7): {//if it didn't work out, write to a file
        cout << "Error in working with the file!\nPress any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (8): {//the key was not entered 
        cout << "Error! The key must be entered!\nPress any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (9): {
        cout << "An error occurred while reading the file!\n";
        cout << "The file may be corrupted\n";
        cout << "Check the integrity of the password, key and text\n";
        cout << "Press any key to return to the main menu";
        _getch();//waiting for a key to be pressed
        break;
    }
    case (10): {//different passwords entered
        cout << "Error! Passwords are different!\nPress any key to try again";
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
    cout << "All characters except English letters and numbers are ignored!\n";
    cout << "Press \"1\": \x1b[31mencryption\x1b[0m\n"; //output red text with construction \x1b[31m...\x1b[0m
    cout << "Press \"2\": \x1b[31mdecryption\x1b[0m\n"; //output red text
    cout << "Press \"Esc\": \x1b[31mexit the programm\x1b[0m\n"; //output red text
    Separate();
}
void ChooseCypherMenu(int header) {//for printing the menu with choosing cyphers
    system("cls"); //clear the screen
    Header(header);
    cout << "1 - Шифр Гронсфельда" << setw(30) << "4 - Шифр Виженера*\n";
    cout << "2 - Тарабарская грамота" << setw(30) << "5 - Шифр XOR(Вернама)\n";
    cout << "3 - Шифр Атбаша" << setw(33) << "6 - Азбука Морзе\n";
    cout << "* lowercase letters become uppercase letters\n";
    cout << "Press the cypher number or press \"Esc\" to return\n";
    Separate();
}
void EntryPswMenu1(int header) { //Menu for first enter of password
    system("cls"); //clear screen
    Header(header);
    cout << "Please enter your password and press \"Enter\"\n";
    cout << "You \x1b[31mcan only use\x1b[0m numbers and letters of the English alphabet\n";
    cout << "Press \"Backspace\" to delete symbols or press \"Esc\" to return\n";
    Separate();
}
void EntryPswMenu2() {//Menu for second enter of password to confirm first
    Separate();
    cout << "Confirm your password >> \n";
    Separate();
}
void EntryPswMenuForDecr(int header, int count) { //Menu for enter of password for decryption
    system("cls"); //clear screen
    Header(header);
    cout << "Please enter your password and press \"Enter\"\n";
    cout << "You \x1b[31mcan only use\x1b[0m numbers and letters of the English alphabet\n";
    cout << "Press \"Backspace\" to delete symbols or press \"Esc\" to return\n";
    cout << "You have " << count << " attempts left!\n";
    Separate();
}
void EntryPathMenu() { //menu for path entering
    system("cls"); //clear screen
    Header(4);
    cout << "The file must have the .txt extension\n";
    cout << "If the file is located in the same folder with the project\n";
    cout << "You need only to enter the file name (including .txt)\n";
    cout << "Specify the path to the file (or just the file name) and press \"Enter\"\n";
    cout << "Press \"Backspace\" to delete symbols or press \"Esc\" to return\n";
    Separate();
}
bool CanUse(int option, char ch) {
    if (option == 1) {//letters n numbers
        string canUse = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
        if (canUse.find(char(ch)) != string::npos) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (option == 2) {//numbers
        if (isdigit(ch)) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (option == 3) { //letters
        string canUse = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if (canUse.find(char(ch)) != string::npos) {
            return true;
        }
        else {
            return false;
        }
    }
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

        } //1 - because we can only use numbers and english letters
        else if (!CanUse(1, char(ch))) {//if we cant use this symbol(not number or not english letter)
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
string PswForDecr(string psw1, int count, bool& go_out, bool& esc) { //Menu with password entering
    EntryPswMenuForDecr(3, count);
    psw1 = GetPsw(esc); //we get the password through the function    
    return psw1;
}
bool CheckPsw(string psw1, string psw2) { //the function checks whether the passwords entered are the same
    if (psw1 == psw2) { return true; }
    else { return false; }
}
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
string Path(string path, bool& go_out, bool& esc) { //function for getting path to file
    system("cls"); //clear screen
    Header(4);
    EntryPathMenu();//calling the menu function
    path = GetPath(esc);//we get the path through the function
    if (path.empty() && (!esc)) {//if the path is not entered, before that the go_out flag was not activated and escape wasnt pressed
        OutputError(4);
        go_out = true;
    }
    else if (esc) { go_out = true; }//if pressed escape
    return path;
}
void KeyMenu(int header, int option) {//For printing the main menu
    system("cls");//clear the screen
    Header(header);
    cout << "Please enter key for cypher and press \"Enter\"\n"; //output red text with construction \x1b[31m...\x1b[0m
    if (option == 1) { cout << "You \x1b[31mcan only use\x1b[0m numbers and letters of the English alphabet\n"; }
    else if (option == 2) { cout << "You \x1b[31mcan only use\x1b[0m numbers\n"; }
    else { cout << "You \x1b[31mcan only use\x1b[0m letters of the English alphabet\n"; }
    cout << "Press \"Backspace\" to delete symbols or press \"Esc\" to return\n";
    Separate();
}
string GetKey(bool& esc, int option) {//key entry function
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
        else if (!CanUse(option, char(ch))) {//
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
string Key(int option, string key, bool& go_out, bool& esc) {//Menu with key entering
    KeyMenu(5, option);
    key = GetKey(esc, option);
    if (esc) { go_out = true; }
    return key;
}
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
PswKeyText GetPswKeyTextFromCont(vector<string> contwithstr, bool& go_out, bool needkey) {
    PswKeyText pswkeytext;
    string str;
    //разделить строку по пробелам и записать в соотв ячейки
    stringstream strstream(contwithstr[0]);
    vector<string> buffer;
    int count = 0;
    while (getline(strstream, str, ' '))
    {
        count++;
        buffer.push_back(str);
    }
    if ((needkey && count != 2) || (!needkey && count != 1)) {
        OutputError(9);
        go_out = true;
    }
    else {
        pswkeytext.password = buffer[0];
        if (needkey) {
            pswkeytext.key = buffer[1];
        }
        contwithstr.erase(contwithstr.begin());
        //записать остальное в вектор
        pswkeytext.text = contwithstr;
    }
    return pswkeytext;
}
string NewPath(int option, string path) {//function for getting a new path to a new file
    for (auto i = 0; i < 4; i++) {//delete ".txt" from name
        path.pop_back();
    }
    if (option == 1) {  //new name for encrypted file
        path = path + "_encr.txt";
    }
    if (option == 2) { //new name for the decrypted file
        path = path + "_decr.txt";
    }
    return path;
}
void Ofstream(vector <string> contwithstr, const char* fileName, string password, bool needkey, string key, bool& go_out, bool decrypted) {//function for writing to a file
    ofstream output; //stream to write
    output.open(fileName); //opening the file for recording
    if (output.is_open())
    {
        if (decrypted) {
            for (auto i = 0; i < contwithstr.size(); i++) {//writing encrypted strings to a file
                output << contwithstr.at(i) << endl;
            }
        }
        else {
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
struct morse {
    string englow;
    string engup;
    string key;
};
string LowToUpForKey(string key) {
    for (auto& i : key) {
        if (i >= 97 && i <= 122) {
            i = ((int)i - 97) + 65;
        }
    }
    return key;
}
string Encrypt4(string m, string k) {
    string vig;
    char buffer;
    for (int ind = 0; ind < m.length(); ind++) {
        if (m[ind] >= 65 && m[ind] <= 90) {//for big letter
            vig += ((m[ind] + k[ind % k.length()]) % 26) + 65;//since we found the remainder of the division by the power of the alphabet
        } //add 65 to get the ciphertext letter itself
        else if (m[ind] >= 97 && m[ind] <= 122) {//if it's a small letter, make it big
            buffer = (m[ind] - 97) + 65;
            vig += (((int)buffer + k[ind % k.length()]) % 26) + 65;
        }
        else {
            vig += m[ind];
        }
    }
    return vig;
}
string EncryptForKey(string cEng) {
    int key = 5;
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
string DecryptForKey(string cEng) {
    int keyEng = 5;
    string cEngDeCrypted = cEng;  //crypted text
    int i = 0; //text position counter

    while (cEngDeCrypted[i] != '\0') { //value substitution
        if (cEng[i] >= 65 && cEng[i] <= 90) {
            if ((cEng[i] - keyEng) < 65) {
                cEngDeCrypted[i] = 91 - abs((cEng[i] - keyEng - 65)) % 26;
            }
            else {
                cEngDeCrypted[i] = cEng[i] - keyEng;
            }
        }
        else if (cEng[i] >= 97 && cEng[i] <= 122) {
            if ((cEng[i] - keyEng) < 97) {
                cEngDeCrypted[i] = 123 - abs((cEng[i] - keyEng - 97)) % 26;
            }
            else {
                cEngDeCrypted[i] = cEng[i] - keyEng;
            }
        }
        i++;
    }
    return cEngDeCrypted;
}
string Decrypt4(string m, string k) {
    string vig;
    for (int ind = 0; ind < m.length(); ind++) {
        if (m[ind] >= 65 && m[ind] <= 90) {
            vig += ((m[ind] - k[ind % k.length()]) + 26) % 26 + 65;
        }
        else {
            vig += m[ind];
        }
    }
    return vig;
}
vector<string> split(const string& inputstr, char delim)
{
    vector<string> buffer;
    stringstream strstream(inputstr);
    string str;
    while (getline(strstream, str, delim)) {
        buffer.push_back(str);
    }
    return buffer;
}
string Encrypt6(string text) {
    vector<morse> lang = {
    {"a","A", ".-"},
    {"b","B", "-..."},
    {"c","C", "-.-."},
    {"d","D", "-.."},
    {"e","E", "."},
    {"f","F", "..-."},
    {"g","G", "--."},
    {"h","H", "...."},
    {"i","I", ".."},
    {"j","J", ".---"},
    {"k","K", "-.-"},
    {"l","L", ".-.."},
    {"m","M", "--"},
    {"n","N", "-."},
    {"o","O", "---"},
    {"p","P", ".--."},
    {"q","Q", "--.-"},
    {"r","R", ".-."},
    {"s","S", "..."} ,
    {"t","T", "-"},
    {"u","U", "..-"},
    {"v","V", "...-"},
    {"w","W", ".--"},
    {"x","X", "-..-"},
    {"y","Y", "-.--"},
    {"z","Z", "--.."},
    {"0","0", "-----"},
    {"1","1", ".----"},
    {"2","2", "..---"},
    {"3","3", "...--"},
    {"4","4", "....-"},
    {"5","5", "....."},
    {"6","6", "-...."},
    {"7","7", "--..."},
    {"8","8", "---.."},
    {"9","9", "----."},
    {" ", " ", " "}
    };
    string ch;
    string encr;
    vector <string> morse;
    morse = split(text, ' ');
    for (auto str : morse) {
        for (auto instr = 0; instr < str.length(); instr++) {
            ch = str[instr];
            for (auto j = 0; j < lang.size(); j++) {
                if (lang[j].englow == ch || lang[j].engup == ch) {
                    encr += lang[j].key + " ";
                }
            }
        }
        encr += " ";
    }
    return encr;//äîäåëàòü ÷òîáû â ñòðîêó ïðîáåëû äîáàâëÿëèñü è
}
string Decrypt6(string text) {
    vector<morse> lang = {
    {"a","A", ".-"},
    {"b","B", "-..."},
    {"c","C", "-.-."},
    {"d","D", "-.."},
    {"e","E", "."},
    {"f","F", "..-."},
    {"g","G", "--."},
    {"h","H", "...."},
    {"i","I", ".."},
    {"j","J", ".---"},
    {"k","K", "-.-"},
    {"l","L", ".-.."},
    {"m","M", "--"},
    {"n","N", "-."},
    {"o","O", "---"},
    {"p","P", ".--."},
    {"q","Q", "--.-"},
    {"r","R", ".-."},
    {"s","S", "..."} ,
    {"t","T", "-"},
    {"u","U", "..-"},
    {"v","V", "...-"},
    {"w","W", ".--"},
    {"x","X", "-..-"},
    {"y","Y", "-.--"},
    {"z","Z", "--.."},
    {"0","0", "-----"},
    {"1","1", ".----"},
    {"2","2", "..---"},
    {"3","3", "...--"},
    {"4","4", "....-"},
    {"5","5", "....."},
    {"6","6", "-...."},
    {"7","7", "--..."},
    {"8","8", "---.."},
    {"9","9", "----."},
    {" ", " ", " "}
    };
    string decr;
    vector<string> morse;
    morse = split(text, ' ');
    for (auto i = 0; i < morse.size(); i++)
    {
        if (morse[i] == "")
        {
            decr += " ";
        }
        for (auto j = 0; j < lang.size(); j++)
        {
            if (lang[j].key == morse[i])
            {
                decr += lang[j].englow;
            }
        }
    }
    return decr;
}
string Encrypt5(string text, string key) {
    string encr;
    for (int ind = 0; ind < text.length(); ind++)
    {

        encr += text[ind] ^ key[ind % key.length()];
    }
    return encr;
}
string Decrypt5(string text, string key) {
    string decr;
    for (int ind = 0; ind < text.length(); ind++)
    {
        decr += text[ind] ^ key[ind % key.length()];

    }
    return decr;
}
string Encrypt1(string cEng, string keyEng) {
    string Crypted = cEng;  //crypted Crypted
    int i = 0, ii = 0; //Crypted position counter	
    while (Crypted[i] != '\0') { //value substitution		
        if (cEng[i] >= 65 && cEng[i] <= 90) {
            if ((cEng[i] + (int)keyEng[ii] - 48) > 90) {
                Crypted[i] = 64 + abs((cEng[i] + (int)keyEng[ii] - 48 - 90)) % 26;
            }
            else {
                Crypted[i] = cEng[i] + (int)keyEng[ii] - 48;
            }
        }
        else if (cEng[i] >= 97 && cEng[i] <= 122) {
            if ((cEng[i] + (int)keyEng[ii] - 48) > 122) {
                Crypted[i] = 96 + abs((cEng[i] + (int)keyEng[ii] - 48 - 122)) % 26;
            }
            else {
                Crypted[i] = cEng[i] + (int)keyEng[ii] - 48;
            }
        }
        ii++;
        i++;
        if (ii == keyEng.length()) { ii = 0; }
    }
    return Crypted;
}
string Decrypt1(string cEng, string keyEng) {
    string DeCrypted = cEng;  //DeCrypted Crypted
    int i = 0, ii = 0; //Crypted position counter	
    while (DeCrypted[i] != '\0') { //value substitution
        if (cEng[i] >= 65 && cEng[i] <= 90) {
            if ((cEng[i] - (int)keyEng[ii] + 48) < 65) {
                DeCrypted[i] = 91 - abs((cEng[i] - (int)keyEng[ii] + 48 - 65)) % 26;
            }
            else {
                DeCrypted[i] = cEng[i] - (int)keyEng[ii] + 48;
            }
        }
        else if (cEng[i] >= 97 && cEng[i] <= 122) {
            if ((cEng[i] - (int)keyEng[ii] + 48) < 97) {
                DeCrypted[i] = 123 - abs((cEng[i] - (int)keyEng[ii] + 48 - 97)) % 26;
            }
            else {
                DeCrypted[i] = cEng[i] - (int)keyEng[ii] + 48;
            }
        }
        ii++;
        i++;
        if (ii == keyEng.length()) { ii = 0; }
    }
    return DeCrypted;
}
string Encrypt2(string cEng) {
    string Crypted = cEng;  //crypted Crypted
    int i = 0, ii = 0; //Crypted position counter	
    string Alphabet = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
    string cryptoAlphabet = "ZXWVTSRQPNMLKJHGFDCBzxwvtsrqpnmlkjhgfdcb";
    while (Crypted[i] != '\0') { //value substitution		
        for (char symbol : Alphabet) {
            if (cEng[i] == symbol) {
                Crypted[i] = cryptoAlphabet[ii];
            }
            ii++;
        }
        i++;
        ii = 0;
    }
    return Crypted;
}
string Decrypt2(string cEng) {
    string DeCrypted = cEng;  //DeCrypted Crypted
    int i = 0, ii = 0; //Crypted position counter	
    string Alphabet = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
    string cryptoAlphabet = "ZXWVTSRQPNMLKJHGFDCBzxwvtsrqpnmlkjhgfdcb";
    while (DeCrypted[i] != '\0') { //value substitution		
        for (char symbol : Alphabet) {
            if (cEng[i] == symbol) {
                DeCrypted[i] = cryptoAlphabet[ii];
            }
            ii++;
        }
        i++;
        ii = 0;
    }
    return DeCrypted;
}
string Encrypt3(string cEng) {
    string Crypted = cEng;  //DeCrypted Crypted
    int i = 0; //Crypted position counter		
    while (Crypted[i] != '\0') { //value substitution			
        Crypted[i] = cEng[cEng.length() - i - 1];
        i++;
    }
    return Crypted;
}
string Decrypt3(string cEng) {

    string DeCrypted = cEng;  //DeCrypted Crypted
    int i = 0; //Crypted position counter		
    while (DeCrypted[i] != '\0') { //value substitution			
        DeCrypted[i] = cEng[cEng.length() - i - 1];
        i++;
    }
    return DeCrypted;
}
vector <string> Encryption(vector <string>& contwithstr, string key, int numbofcyph) {//encryption with the selected cypher
    for (auto i = 0; i < contwithstr.size(); i++) {
        switch (numbofcyph)//depending on the chosen cipher
        {
        case (1): {
            contwithstr.at(i) = Encrypt1(contwithstr.at(i), key);
            break;
        }
        case (2): {
            contwithstr.at(i) = Encrypt2(contwithstr.at(i));
            break;
        }
        case (3): {
            contwithstr.at(i) = Encrypt3(contwithstr.at(i));
            break;
        }
        case (4): {
            key = LowToUpForKey(key);
            contwithstr.at(i) = Encrypt4(contwithstr.at(i), key);
            break;
        }
        case (5): {
            contwithstr.at(i) = Encrypt5(contwithstr.at(i), key);
            break;
        }
        case (6): {
            contwithstr.at(i) = Encrypt6(contwithstr.at(i));
            break;
        }
        default:
            break;
        }
    }
    return contwithstr;
}
void EncryptCase(int keyoption, int numbofcyph, string& psw, string& psw_confirm, string& path, string& key, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr) {
    bool key_received = true;
    if (needkey) {
        key = Key(keyoption, key, go_out, esc);
        if (key.empty()) {
            key_received = false;
            OutputError(8);
        }
    }
    if (!go_out && key_received) {
        psw = Psw(psw, psw_confirm, go_out, esc);
        if ((psw.empty() || psw_confirm.empty()) && (!go_out)) //if one of the passwords is not entered
        {
            OutputError(2);
        }
        else if ((CheckPsw(psw, psw_confirm) == false) && (!go_out)) { //different passwords entered
            OutputError(3);
        }
        else if (!go_out) {//if successfully
            string hashpsw = SHA256::hashString(psw);
            path = Path(path, go_out, esc);
            if (!go_out) {//if successfully
                contwithstr = OpenNReadFile(contwithstr, path, go_out);
                if (!go_out) {//if successfully
                    Encryption(contwithstr, key, numbofcyph);
                    key = EncryptForKey(key);
                    string newpath = NewPath(1, path);//get new name and path to this new file from old one
                    const char* b = newpath.c_str(); //its for using autoopen function(system("") dont work with strings)
                    Ofstream(contwithstr, b, hashpsw, needkey, key, go_out, false);//false, because we are recording encrypted text
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
    int keyoption = 2, nymbofcyph = 1;
    ChooseCypherMenu(2);
    char choise_cypher = _getch();//waiting for a key to be pressed
    switch (choise_cypher) {//depending on the key pressed
    case '1': {
        needkey = true;//the cypher need a key
        keyoption = 3;//we can enter only letters for this key
        nymbofcyph = 1;//Number of cypher we want to use
        EncryptCase(keyoption, nymbofcyph, psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr);
        break;
    }
    case '2': {
        needkey = false;//the cypher does not need a key    
        nymbofcyph = 2;//Number of cypher we want to use
        EncryptCase(keyoption, nymbofcyph, psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr);
        break;
    }
    case '3': {
        needkey = false;//the cypher does not need a key
        nymbofcyph = 3;//Number of cypher we want to use
        EncryptCase(keyoption, nymbofcyph, psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr);
        break;
    }
    case '4': {
        needkey = true;//the cypher does not need a key
        keyoption = 3;//we can enter only numbers for this key
        nymbofcyph = 4;//Number of cypher we want to use
        EncryptCase(keyoption, nymbofcyph, psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr);
        break;
    }
    case '5': {
        needkey = true;//the cypher does not need a key
        keyoption = 3;//we can enter only numbers for this key
        nymbofcyph = 5;//Number of cypher we want to use
        EncryptCase(keyoption, nymbofcyph, psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr);
        break;
    }
    case '6': {
        needkey = false;//the cypher does not need a key
        nymbofcyph = 6;//Number of cypher we want to use
        EncryptCase(keyoption, nymbofcyph, psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr);
        break;
    }
    case 27: { break; } //if pressed esc
    default: {//if the wrong key is pressed
        OutputError(1);
        break;
    }
    };
}
vector <string> Decryption(vector <string>& contwithstr, string key, int numbofcyph) {//encryption with the selected cypher
    for (auto i = 0; i < contwithstr.size(); i++) {
        switch (numbofcyph)//depending on the chosen cipher
        {
        case (1): {
            contwithstr.at(i) = Decrypt1(contwithstr.at(i), key);
            break;
        }
        case (2): {

            contwithstr.at(i) = Decrypt2(contwithstr.at(i));
            break;
        }
        case (3): {
            contwithstr.at(i) = Decrypt3(contwithstr.at(i));
            break;
        }
        case (4): {
            key = LowToUpForKey(key);
            contwithstr.at(i) = Decrypt4(contwithstr.at(i), key);
            break;
        }
        case (5): {
            contwithstr.at(i) = Decrypt5(contwithstr.at(i), key);
            break;
        }
        case (6): {
            contwithstr.at(i) = Decrypt6(contwithstr.at(i));
            break;
        }
        default:
            break;
        }
    }
    return contwithstr;
}
void DecryptCase(PswKeyText& pswkeytext, string& psw, string& psw_confirm, string& path, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr, int numbofcyph) {
    path = Path(path, go_out, esc);
    if (!go_out) {//if successfully
        contwithstr = OpenNReadFile(contwithstr, path, go_out);
        if (!go_out) {//if successfully
            pswkeytext = GetPswKeyTextFromCont(contwithstr, go_out, needkey);
            if (!go_out) {//if successfully
                string hashpsw;
                for (auto attempts = 5; attempts > 0; attempts--) {
                    psw = PswForDecr(psw, attempts, go_out, esc);
                    if (!psw.empty() && (!esc)) //if the string with password is not empty- continue
                    {
                        //хэшируем
                        hashpsw = SHA256::hashString(psw);
                        if (CheckPsw(hashpsw, pswkeytext.password)) {
                            break;
                        }
                        else {
                            OutputError(10);
                            continue;
                        }
                    }
                    if (esc) { //if pressed escape- flag for returning
                        go_out = true;
                        break;
                    }
                }
                if (!go_out && CheckPsw(hashpsw, pswkeytext.password)) {//if successfully
                    pswkeytext.key = DecryptForKey(pswkeytext.key);
                    Decryption(pswkeytext.text, pswkeytext.key, numbofcyph);
                    string newpath = NewPath(2, path);//get new name and path to this new file from old one
                    const char* b = newpath.c_str(); //its for using autoopen function(system("") dont work with strings)
                    Ofstream(pswkeytext.text, b, psw, needkey, pswkeytext.key, go_out, true); //true, because we are recording decrypted text
                    if (!go_out) {//if successfully
                        AutoOpen(b);//open this file with notepad
                        //clear all because we will work again with text
                        pswkeytext.password.clear();
                        pswkeytext.key.clear();
                        pswkeytext.text.clear();
                        contwithstr.clear();//clear container if we want to work with program again
                    }
                }
            }
        }
    }
}
void DecryptCases(PswKeyText& pswkeytext, string& psw, string& psw_confirm, string& path, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr) {
    int keyoption = 2, nymbofcyph = 1;
    ChooseCypherMenu(2);
    char choise_cypher = _getch();//waiting for a key to be pressed
    switch (choise_cypher) {//depending on the key pressed
    case '1': {
        needkey = true;//the cypher need a key
        nymbofcyph = 1;//Number of cypher we want to use
        DecryptCase(pswkeytext, psw, psw_confirm, path, go_out, esc, needkey, contwithstr, nymbofcyph);
        break;
    }
    case '2': {
        needkey = true;//the cypher need a key
        nymbofcyph = 2;//Number of cypher we want to use
        DecryptCase(pswkeytext, psw, psw_confirm, path, go_out, esc, needkey, contwithstr, nymbofcyph);
        break;
    }
    case '3': {
        needkey = true;//the cypher need a key
        nymbofcyph = 3;//Number of cypher we want to use
        DecryptCase(pswkeytext, psw, psw_confirm, path, go_out, esc, needkey, contwithstr, nymbofcyph);
        break;
    }
    case '4': {
        needkey = true;//the cypher need a key
        nymbofcyph = 4;//Number of cypher we want to use
        DecryptCase(pswkeytext, psw, psw_confirm, path, go_out, esc, needkey, contwithstr, nymbofcyph);
        break;
    }
    case '5': {
        needkey = true;//the cypher need a key
        nymbofcyph = 5;//Number of cypher we want to use
        DecryptCase(pswkeytext, psw, psw_confirm, path, go_out, esc, needkey, contwithstr, nymbofcyph);
        break;
    }
    case '6': {
        needkey = true;//the cypher need a key
        nymbofcyph = 6;//Number of cypher we want to use
        DecryptCase(pswkeytext, psw, psw_confirm, path, go_out, esc, needkey, contwithstr, nymbofcyph);
        break;
    }
    case 27: {break; }//if pressed esc
    default: { //if the wrong key is pressed
        OutputError(1);
        break;
    }
    };
}
void MainMenuCases(string& psw, string& psw_confirm, string& path, string& key, bool& go_out, bool& esc, bool& needkey, vector <string>& contwithstr, PswKeyText pswkeytext) {
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
            DecryptCases(pswkeytext, psw, psw_confirm, path, go_out, esc, needkey, contwithstr);
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
    setlocale(LC_ALL, "Rus");
    PswKeyText pswkeytext;
    vector <string> contwithstr;
    bool go_out, esc, needkey;//go_out - for errors and break cycles, esc - if pressed escape
    string psw, psw_confirm, path, key; //password and confirmation of password, path to file, history of entering paths
    MainMenuCases(psw, psw_confirm, path, key, go_out, esc, needkey, contwithstr, pswkeytext);
}