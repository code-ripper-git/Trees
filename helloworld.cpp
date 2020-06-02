

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int x = 97;

constexpr auto print(double c)
{
    return c * c;
}

int main()
{
    vector<string> msg{"Hello", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    int var = 17;
    const int b = 17;
    constexpr double s = print(b);
    cout << s << endl;
    int x = ::x;
    int d(2.5);
    int v[3] = {1, 2, 3};
    int *const p = &v[2];
    *p = v[1];
    cout << x << *p << d << endl;
}