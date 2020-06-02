#include <bits/stdc++.h>
using namespace std;

int maxsubarr(vector<int> v)
{
    int max = INT_MIN, sum = 0;
    for (auto x : v)
    {
        sum += x;
        if (x > max)
            max = x;
        if (sum < 0)
            sum = 0;
        else if (x > 0 && sum > max)
            max = sum;
    }
    return max;
}

int main()
{
    vector<int> v = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    vector<int> v1 = {-13, -8, -99, -1, 0, -9, -5};
    cout << maxsubarr(v1) << endl;
}