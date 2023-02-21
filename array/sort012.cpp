#include <bits/stdc++.h>
using namespace std;

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

void sort012(int a[], int size)
{
    int l = -1;
    int m = 0;
    int h = size;

    while (m < h)
    {
        switch (a[m])
        {
        case 0:
            swap(a[++l], a[m++]);
            break;
        case 1:
            m++;
            break;
        case 2:
            swap(a[--h], a[m]);
            break;

        default:
            break;
        }
    }
}

int main()
{

    int a[] = {1, 2, 1, 0, 2};
    int n = 5;

    printArray(a, n);
    sort012(a, n);
    printArray(a, n);

    return 0;
}