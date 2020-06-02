#include <bits/stdc++.h>
using namespace std;

string table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char hextodec(char c)
{
    c = tolower(c);
    if (c >= '0' && c <= '9')
        return c % '0';
    else if (c >= 'a' && c <= 'f')
        return (10 + c % 'a');
    else
    {
        cerr << "Not a Hexadecimal digit: " << c << endl;
        exit(1);
    }
}

string hextobase64(string hex)
{
    string base64;
    base64.reserve(hex.length() * 2 / 3);
    for (int i = 0; i < hex.length(); i += 3)
    {
        char c1 = hextodec(hex[i]), c2 = hextodec(hex[i + 1]), c3 = hextodec(hex[i + 2]);
        base64 += ::table[(c1 << 2) | (c2 >> 2)];
        base64 += ::table[((c2 & 3) << 4) | c3];
    }
    return base64;
}

int main()
{
    cout << hextobase64("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6f") << endl;
}