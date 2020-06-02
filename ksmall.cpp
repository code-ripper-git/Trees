#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    random_device randi;
    int pivot = low + (high - low + 1) / 3 + randi() % ((high - low) / 3 + 1);
    low--;
    high++;
    while (true)
    {
        while (arr[++low] < arr[pivot])
            ;
        while (arr[--high] > arr[pivot])
            ;
        if (low >= high)
            return high;
        swap(arr[low], arr[high]);
    }
}

int kthSmallest(int arr[], int l, int r, int k)
{

    if (k > 0 && k <= r - l + 1)
    {
        int pos = partition(arr, l, r);
        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }

    return INT_MAX;
}
int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]), k = 5;
    cout << "K'th smallest element is " << kthSmallest(arr, 0, n - 1, k) << endl;
    return 0;
}