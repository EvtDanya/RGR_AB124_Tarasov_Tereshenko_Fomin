#include <iostream>
#include<map>
using namespace std;
string LowToUpForKey(string key) {
    for (auto& i : key) {
        if (i >= 97 && i <= 122) {
            i = ((int)i - 97) + 65;
        }
    }
    return key;
}
string Encrypt8(string text, string key) {
    string encr;
    for (int x = 0; x < text.length(); x++)
    {

        encr += text[x] ^ key[x % key.length()];
    }
    return encr;
}
string Decrypt8(string text, string key) {
    string decr;
    for (int x = 0; x < text.length(); x++)
    {
        decr += text[x] ^ key[x % key.length()];

    }
    return decr;
}
int main() {
    cout << "all letters are converted to uppercase automatically.\n";
    string text = "Brute-force method is a method of random encryption key generation and matching them with the correct one.";
    string key = "abcs";
    string encr, decr;
    key = LowToUpForKey(key);
    encr = Encrypt8(text, key);
    cout << encr << endl;
    decr = Decrypt8(encr, key);
    cout << decr << endl;
}