
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    random_device randi;
    //swap(arr[low + (high - low) / 2], arr[low + randi() % ((high - low) + 1)]);
    int pivot = arr[low + (high - low) / 2];
    cout << pivot << endl;
    low--;
    high++;
    while (true)
    {
        while (arr[++low] < pivot)
            ;
        while (arr[--high] > pivot)
            ;
        if (low >= high)
            return high;
        swap(arr[low], arr[high]);
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi);
    quickSort(arr, pi + 1, high);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5, 12, 3, 89, 34, 12, 67, 4, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}