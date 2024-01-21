#include <iostream>

using namespace std;

int merge(int arr[], int temp[], int left, int middle, int right)
{
    int i = left;
    int j = middle + 1;
    int k = left;
    int inversionCount = 0;

    while (i <= middle && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            inversionCount += (middle - i + 1);
        }
    }

    while (i <= middle)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int i = left; i <= right; i++)
        arr[i] = temp[i];

    return inversionCount;
}

int _mergesort(int arr[], int temp[], int left, int right)
{

    int inversionCount = 0;

    if (left < right)
    {
        int middle = (left + right) / 2;
        inversionCount += _mergesort(arr, temp, left, middle);
        inversionCount += _mergesort(arr, temp, middle + 1, right);
        inversionCount += merge(arr, temp, left, middle, right); // if you pass middle + 1 instead, then merge() should change a bit!
    }

    return inversionCount;
}

int mergesort(int arr[], int size)
{

    int temp[size];

    return _mergesort(arr, temp, 0, size - 1);
}

int main()
{

    int a[] = {2, 3, 4, 1, 3, 5};
    int size = 6;

    for (int i = 0; i < size; i++)
        cout << a[i] << ", ";
    cout << endl;

    cout << mergesort(a, size);
    cout << endl;

    for (int i = 0; i < size; i++)
        cout << a[i] << ", ";
    cout << endl;

    return 0;
}