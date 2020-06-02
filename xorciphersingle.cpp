#include <bits/stdc++.h>
using namespace std;

multimap<char, int> frequency;

void mapstring(string hex)
{
    unordered_map<char, int> freq;
    for (int i = 0; i < hex.length(); i += 2)
    {
        char c = (char)stoi(hex.substr(i, 2), nullptr, 16);
        freq[c] = freq[c] + 1;
    }
    for (auto itr = freq.begin(); itr != freq.end(); itr = freq.erase(itr))
    {
        ::frequency.insert(make_pair(itr->second, itr->first));
    }
    freq.clear();
}

void decodexor(string hex)
{
    string s;
    s.reserve(hex.length() / 2 + 1);
    mapstring(hex);
    auto it = frequency.rbegin();
    char ch = it->second;
    ch = ch ^ ' ';
    for (int i = 0; i < hex.length(); i += 2)
    {
        s += (char)(stoi(hex.substr(i, 2), nullptr, 16) ^ ch);
    }
    cout << s << endl;
}

int main()
{
    decodexor("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736");
}