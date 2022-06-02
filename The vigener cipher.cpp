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
        if (m[ind] >= 65 && m[ind] <= 90) {//for small letter
            vig += ((m[ind] + k[ind % k.length()]) % 26) + 65;//since we found the remainder of the division by the power of the alphabet
        } //add 65 to get the ciphertext letter itself
        else if (m[ind] >= 97 && m[ind] <= 122) {//if it's a big letter, make it small
            buffer = (m[ind] - 97) + 65;
            vig += (((int)buffer + k[ind % k.length()]) % 26) + 65;
        }
    }
    return vig;
}
string Decrypt7(string m, string k) {
    string vig;
    for (int ind = 0; ind < m.length(); ind++) {
        vig += ((m[ind] - k[ind % k.length()]) + 26) % 26 + 65;
    }
    return vig;
}
int main()
{
    string srctext, key, encrypted, decrypted;
    cout << "Enter string >> ";
    cin >> srctext;
    cout << "Enter key >> ";
    cin >> key;
    key = LowToUpForKey(key);
    encrypted = Encrypt7(srctext, key);
    cout << "Encrypted text >> " << encrypted;
    decrypted = Decrypt7(encrypted, key);
    cout << "\nDecrypted text >> " << decrypted;
}