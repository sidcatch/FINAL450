#include <iostream>

using namespace std;

void merge(int arr[], int temp[], int left, int middle, int right)
{
    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= middle)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int i = left; i <= right; i++)
        arr[i] = temp[i];
}

void _mergesort(int arr[], int temp[], int left, int right)
{

    if (left < right)
    {
        int middle = (left + right) / 2;
        _mergesort(arr, temp, left, middle);
        _mergesort(arr, temp, middle + 1, right);
        merge(arr, temp, left, middle, right); // if you pass middle + 1 instead, then merge() should change a bit!
    }
}

void mergesort(int arr[], int size)
{

    int temp[size];

    _mergesort(arr, temp, 0, size - 1);
}

int main()
{

    int a[] = {23, 523, 12, 342, 2, 4, 1, 52};

    for (int i = 0; i < 8; i++)
        cout << a[i] << ", ";
    cout << endl;

    mergesort(a, 8);

    for (int i = 0; i < 8; i++)
        cout << a[i] << ", ";
    cout << endl;

    return 0;
}