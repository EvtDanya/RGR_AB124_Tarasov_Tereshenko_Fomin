#include <iostream>
#include<map>
#include<vector>
#include <string>
#include <sstream>
using namespace std;
string Encrypt8(string text, string key) {
    string encr;
    for (int ind = 0; ind < text.length(); ind++)
    {

        encr += text[ind] ^ key[ind % key.length()];
    }
    return encr;
}
string Decrypt8(string text, string key) {
    string decr;
    for (int ind = 0; ind < text.length(); ind++)
    {
        decr += text[ind] ^ key[ind % key.length()];

    }
    return decr;
}
int main()
{
    cout << "all letters are converted to uppercase automatically.\n";
    string text = "BrUTe-force method is a method of random encryption key generation and matching them with the correct one.*@@)($!@_)+!@";
    string key = "AfffB";
    string encr, decr;
    cout << text << endl;
    //getline(cin, text);
    encr = Encrypt8(text, key);
    cout << encr << endl;
    decr = Decrypt8(encr, key);
    cout << decr << endl;

}
