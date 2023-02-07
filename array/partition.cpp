#include <iostream>
#include <utility>

using namespace std;

void partition(int a[], int l, int r, int x)
{
    int i;
    for (i = l; i < r; i++)
    {
        if (a[i] == x)
            break;
    }

    swap(a[i], a[r]);

    i = l;

    for (int j = l; j < r; j++)

    {
        if (a[j] <= x)
        {
            swap(a[i], a[j]);
            i++;
        }
    }

    swap(a[i], a[r]);
}

void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
        cout << a[i] << ", ";
    cout << a[i];
    cout << endl;
}

int main()
{
    int a[] = {3, 4, 5, 2, 6, 8, 1, 9, 7};

    int n = 9;

    printArray(a, n);

    partition(a, 0, n - 1, 5);

    printArray(a, n);

    return 0;
}