#include <iostream>
using namespace std;
string LowToUpForKey(string key) {
    for (auto& i : key) {
        if (i >= 97 && i <= 122) {
            i = ((int)i - 97) + 65;
        }
    }
    return key;
}
string Encrypt7(string m, string k) {
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
string Decrypt7(string m, string k) {
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
int main()
{
    cout << "all letters are converted to uppercase automatically.\n";
    string text = "BrUTe-force method is a method of random encryption key generation and matching them with the correct one.";
    string key = "AfffB";
    string encr, decr;
    cout << text << endl;
    //getline(cin, text);
    key = LowToUpForKey(key);
    encr = Encrypt7(text, key);
    cout << encr << endl;
    decr = Decrypt7(encr, key);
    cout << decr << endl;
}