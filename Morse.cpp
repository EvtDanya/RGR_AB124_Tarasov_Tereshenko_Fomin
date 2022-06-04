#include <iostream>
#include<map>
#include<vector>
#include <string>
#include <sstream>
using namespace std;
struct morse {
    string englow;
    string engup;
    string key;
};
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
string Encrypt9(string text) {
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
    return encr;//доделать чтобы в строку пробелы добавлялись и
}
string Decrypt9(string text) {
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
int main()
{
    /*cout << "all letters are converted to uppercase automatically.\n";
    string text = "Brute-force method is a method of random encryption key generation and matching them with the correct one.";
    string key = "abcs";
    string encr, decr;
    key = LowToUpForKey(key);
    encr = Encrypt8(text,key);
    cout << encr << endl;
    decr = Decrypt8(encr, key);
    cout << decr << endl;*/
    string encr, text, decr;
    getline(cin, text);
    encr = Encrypt9(text);
    cout << encr << endl;
    decr = Decrypt9(encr);
    cout << decr;
}
